// Solution to https://codeforces.com/contest/1042/problem/D
// Counts the number of nonempty array segments with sum less than T. See https://codeforces.com/blog/entry/11080
#include <iostream>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int N;
    int64_t T;
    cin >> N >> T;

    ordered_set<pair<int64_t, int>> tree;
    int64_t sum = 0, total = 0;
    tree.insert({sum, 0});

    for (int i = 1; i <= N; i++) {
        int a;
        cin >> a;
        sum += a;
        total += i - tree.order_of_key({sum - T, N});
        tree.insert({sum, i});
    }

    cout << total << '\n';
}