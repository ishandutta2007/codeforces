#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename T, size_t size> ostream& operator<<(ostream &os, const array<T, size> &arr) { os << '{'; string sep; for (const auto &x : arr) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef NEAL_DEBUG
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

template<typename T>
void output_vector(const vector<T> &v, bool add_one = false, int start = -1, int end = -1) {
    if (start < 0) start = 0;
    if (end < 0) end = int(v.size());

    for (int i = start; i < end; i++)
        cout << v[i] + (add_one ? 1 : 0) << (i < end - 1 ? ' ' : '\n');
}


void run_case() {
    int N;
    cin >> N;
    vector<pair<int, int>> A(N);

    for (int i = 0; i < N; i++) {
        cin >> A[i].first;
        A[i].second = i;
    }

    vector<int> order(N);

    for (int i = 0; i < N; i++)
        order[i] = i;

    sort(order.begin(), order.end(), [&](int x, int y) {
        return A[x].first < A[y].first;
    });

    int inversions = 0;

    for (int i = 0; i < N; i++)
        for (int j = i + 1; j < N; j++)
            inversions += order[i] > order[j];

    if (inversions % 2 != 0) {
        bool equal = false;

        for (int i = 0; i < N - 1; i++)
            if (A[order[i]].first == A[order[i + 1]].first) {
                swap(order[i], order[i + 1]);
                equal = true;
                break;
            }

        if (!equal) {
            cout << -1 << '\n';
            return;
        }
    }

    vector<int> sequence;

    auto &&rotate_right = [&](int index) {
        sequence.push_back(index);
        swap(A[index + 1], A[index + 2]);
        swap(A[index], A[index + 1]);
    };

    auto &&rotate_left = [&](int index) {
        rotate_right(index);
        rotate_right(index);
    };

    for (int position = 0; position < N; position++) {
        int x = order[position];
        int which = -1;

        for (int i = 0; i < N; i++)
            if (A[i].second == x) {
                which = i;
                break;
            }

        dbg(position, x, which);
        assert(which >= position);

        while (which >= position + 2) {
            rotate_right(which - 2);
            which -= 2;
        }

        if (which > position)
            rotate_left(position);
    }

    cout << sequence.size() << '\n';
    output_vector(sequence, true);
}

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int tests;
    cin >> tests;

    while (tests-- > 0)
        run_case();
}