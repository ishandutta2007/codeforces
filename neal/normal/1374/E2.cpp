#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename T, size_t size> ostream& operator<<(ostream &os, const array<T, size> &arr) { os << '{'; string sep; for (const auto &x : arr) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T> ostream& operator<<(ostream &os, priority_queue<T> pq) { os << '{'; string sep; while (!pq.empty()) { os << sep << pq.top(); pq.pop(); sep = ", "; } return os << '}'; }
template<typename T> ostream& operator<<(ostream &os, priority_queue<T, vector<T>, greater<T>> pq) { os << '{'; string sep; while (!pq.empty()) { os << sep << pq.top(); pq.pop(); sep = ", "; } return os << '}'; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef NEAL_DEBUG
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

template<typename T, typename T_sum>
struct prefix_suffix_heap {
    priority_queue<T> lower;
    priority_queue<T, vector<T>, greater<T>> upper;
    T_sum lower_sum = 0, upper_sum = 0;

    int size() const {
        return int(lower.size()) + int(upper.size());
    }

    void insert(const T &x) {
        if (upper.empty() || x < upper.top()) {
            lower.push(x);
            lower_sum += x;
        } else {
            upper.push(x);
            upper_sum += x;
        }

        // assert(lower.empty() || upper.empty() || lower.top() <= upper.top());
    }

    void arrange(int prefix) {
        while (int(lower.size()) > prefix) {
            T x = lower.top(); lower.pop();
            lower_sum -= x;

            upper.push(x);
            upper_sum += x;
        }

        while (int(lower.size()) < prefix) {
            T x = upper.top(); upper.pop();
            upper_sum -= x;

            lower.push(x);
            lower_sum += x;
        }

        // assert(lower.empty() || upper.empty() || lower.top() <= upper.top());
    }

    T_sum query_prefix(int prefix) {
        arrange(prefix);
        return lower_sum;
    }
};


template<typename T1, typename T2>
bool maximize(T1 &a, const T2 &b) {
    if (a < b) {
        a = b;
        return true;
    }

    return false;
}

template<typename T1, typename T2>
bool minimize(T1 &a, const T2 &b) {
    if (b < a) {
        a = b;
        return true;
    }

    return false;
}

template<typename T>
void output_vector(const vector<T> &v, bool add_one = false, int start = -1, int end = -1) {
    if (start < 0) start = 0;
    if (end < 0) end = int(v.size());

    for (int i = start; i < end; i++)
        cout << v[i] + (add_one ? 1 : 0) << (i < end - 1 ? ' ' : '\n');
}


const int64_t INF64 = int64_t(2e18) + 5;

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int N, M, K;
    cin >> N >> M >> K;
    vector<pair<int, int>> A, B, both, neither;

    for (int i = 0; i < N; i++) {
        int t, a, b;
        cin >> t >> a >> b;

        if (a + b == 2)
            both.emplace_back(t, i);
        else if (a == 1)
            A.emplace_back(t, i);
        else if (b == 1)
            B.emplace_back(t, i);
        else
            neither.emplace_back(t, i);
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    sort(both.begin(), both.end());
    sort(neither.begin(), neither.end());

    vector<int64_t> A_sum(A.size() + 1, 0);
    vector<int64_t> B_sum(B.size() + 1, 0);

    for (int i = 0; i < int(A.size()); i++)
        A_sum[i + 1] = A_sum[i] + A[i].first;

    for (int i = 0; i < int(B.size()); i++)
        B_sum[i + 1] = B_sum[i] + B[i].first;

    prefix_suffix_heap<int, int64_t> heap;

    for (int i = K + 1; i < int(A.size()); i++)
        heap.insert(A[i].first);

    for (int i = K + 1; i < int(B.size()); i++)
        heap.insert(B[i].first);

    for (auto &pr : neither)
        heap.insert(pr.first);

    int64_t best = INF64;
    int best_x = -1;
    int64_t sum = 0;

    for (int x = 0; x <= int(both.size()); x++) {
        if (x > 0)
            sum += both[x - 1].first;

        int need = K - x;

        if (need >= 0 && need < int(A.size()))
            heap.insert(A[need].first);

        if (need >= 0 && need < int(B.size()))
            heap.insert(B[need].first);

        need = max(need, 0);

        if (int(A.size()) >= need && int(B.size()) >= need && x + 2 * need <= M) {
            int remain = M - (x + 2 * need);

            if (remain <= heap.size()) {
                int64_t extra = heap.query_prefix(remain);
                // dbg(remain, extra);

                if (minimize(best, sum + A_sum[need] + B_sum[need] + extra))
                    best_x = x;
            }
        }
    }

    if (best_x < 0) {
        cout << -1 << '\n';
        return 0;
    }

    cout << best << '\n';
    vector<int> books;

    for (int i = 0; i < best_x; i++)
        books.push_back(both[i].second);

    int need = max(K - best_x, 0);

    for (int i = 0; i < need; i++) {
        books.push_back(A[i].second);
        books.push_back(B[i].second);
    }

    vector<pair<int, int>> everything_else;

    for (int i = need; i < int(A.size()); i++)
        everything_else.push_back(A[i]);

    for (int i = need; i < int(B.size()); i++)
        everything_else.push_back(B[i]);

    for (auto &pr : neither)
        everything_else.push_back(pr);

    int remain = M - int(books.size());
    nth_element(everything_else.begin(), everything_else.begin() + remain, everything_else.end());

    for (int i = 0; i < remain; i++)
        books.push_back(everything_else[i].second);

    output_vector(books, true);
}