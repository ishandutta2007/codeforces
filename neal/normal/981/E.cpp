#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")

// Solution to https://codeforces.com/contest/981/problem/E
#include <algorithm>
#include <bitset>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

const int N_MAX = 10005;

struct query {
    int a, b, x;
};

int N, Q;
vector<query> queries;
bitset<N_MAX> answer;

void solve(int start, int end, const vector<query> &my_queries, bitset<N_MAX> sums) {
    int mid = (start + end) / 2;
    vector<query> left_queries, right_queries;

    for (const query &q : my_queries)
        if (q.a <= start && end <= q.b) {
            sums |= sums << q.x;
        } else {
            if (q.a < mid)
                left_queries.push_back(q);

            if (q.b > mid)
                right_queries.push_back(q);
        }

    if (end - start <= 1) {
        // sums is the set of reachable values at index `start`.
        answer |= sums;
        return;
    }

    solve(start, mid, left_queries, sums);
    solve(mid, end, right_queries, sums);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> Q;

    for (int q = 0; q < Q; q++) {
        int a, b, x;
        cin >> a >> b >> x;
        a--;
        queries.push_back({a, b, x});
    }

    bitset<N_MAX> sums;
    sums[0] = 1;
    solve(0, N, queries, sums);
    int count = 0;

    for (int i = 1; i <= N; i++)
        if (answer[i])
            count++;

    cout << count << '\n';
    int current = 0;

    for (int i = 1; i <= N; i++)
        if (answer[i])
            cout << i << (++current < count ? ' ' : '\n');
}