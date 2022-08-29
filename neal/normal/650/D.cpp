#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef NEAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif


struct query {
    int a, b, index;

    bool operator<(const query &other) const {
        return a < other.a;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;
    vector<int> H(N);

    for (int &h : H)
        cin >> h;

    vector<query> queries(Q);

    for (int q = 0; q < Q; q++) {
        query &qry = queries[q];
        cin >> qry.a >> qry.b;
        qry.a--;
        qry.index = q;
    }

    sort(queries.begin(), queries.end());
    vector<int> including_count(Q, 1);

    vector<int> ending_length(N, 0);
    vector<int> best_ending;

    for (int i = 0, q = 0; i < N; i++) {
        while (q < Q && queries[q].a == i) {
            including_count[q] += lower_bound(best_ending.begin(), best_ending.end(), queries[q].b) - best_ending.begin();
            q++;
        }

        auto it = lower_bound(best_ending.begin(), best_ending.end(), H[i]);
        ending_length[i] = it - best_ending.begin() + 1;

        if (it == best_ending.end())
            best_ending.push_back(H[i]);
        else
            *it = H[i];
    }

    int L = best_ending.size();
    best_ending.clear();
    vector<int> starting_length(N, 0);

    for (int i = N - 1, q = Q - 1; i >= 0; i--) {
        while (q >= 0 && queries[q].a == i) {
            including_count[q] += lower_bound(best_ending.begin(), best_ending.end(), queries[q].b, greater<int>()) - best_ending.begin();
            q--;
        }

        auto it = lower_bound(best_ending.begin(), best_ending.end(), H[i], greater<int>());
        starting_length[i] = it - best_ending.begin() + 1;

        if (it == best_ending.end())
            best_ending.push_back(H[i]);
        else
            *it = H[i];
    }

    vector<bool> part_of(N, false);
    vector<bool> necessary(N, false);
    vector<int> ending_freq(N + 1, 0);

    for (int i = 0; i < N; i++) {
        part_of[i] = ending_length[i] + starting_length[i] > L;

        if (part_of[i])
            ending_freq[ending_length[i]]++;
    }

    for (int i = 0; i < N; i++)
        necessary[i] = part_of[i] && ending_freq[ending_length[i]] == 1;

    vector<int> answers(Q);

    for (int q = 0; q < Q; q++) {
        int base = necessary[queries[q].a] ? L - 1 : L;
        answers[queries[q].index] = max(including_count[q], base);
    }

    for (int q = 0; q < Q; q++)
        cout << answers[q] << '\n';
}