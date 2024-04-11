#include <bits/stdc++.h>

using namespace std;

#define sz(x) ((int) (x).size())

vector<pair<int, int>> ans;

void solve_one(int x, int m) {
    for (int i = 1; i <= m + 1 - i; ++i) {
        ans.emplace_back(x, i);
        if (m + 1 - i > i) {
            ans.emplace_back(x, m + 1 - i);
        }
    }
}

void solve(int x, int n, int m) {
    if (n == 0) {
        return;
    }
    if (n == 1) {
        solve_one(x, m);
        return;
    }
    for (int i = 1; i <= m; ++i) {
        ans.emplace_back(x, i);
        ans.emplace_back(x + n - 1, m + 1 - i);
    }
    solve(x + 1, n - 2, m);
}

void check(int n, int m) {
    set<pair<int, int>> d(begin(ans), end(ans));
    assert(sz(ans) == n * m);
    assert(sz(d) == n * m);
    for (auto [a, b]: ans) {
        assert(1 <= a && a <= n);
        assert(1 <= b && b <= m);
    }
    set<pair<int, int>> moves;
    auto prev = make_pair((int)-1e7, (int)-1e7);
    for (auto [a, b]: ans) {
        moves.insert(make_pair(a - prev.first, b - prev.second));
        prev = make_pair(a, b);
    }
    assert(sz(moves) == n * m);
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    solve(1, n, m);
    for (auto [a, b]: ans) {
        cout << a << ' ' << b << '\n';
    }
    /*for (int i = 1; i <= 50; ++i) {
        for (int j = 1; j <= 50; ++j) {
            ans.clear();
            solve(1, i, j);
            check(i, j);
        }
    }*/
}