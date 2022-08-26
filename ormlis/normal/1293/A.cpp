//
// Created by Ormlis on 05.11.2019.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <math.h>
#include <queue>
#include <unordered_set>
#include <fstream>
#include <map>
#include <fstream>

#define ll long long
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()
#define pb(el) push_back(el)

using namespace std;

ll MOD = 998244353;
ll INF = 1e18 * 2;
int INF2 = 1e9 * 2;

void solve() {
    int n, s, k;
    cin >> n >> s >> k;
    int a1 = INF2, a2 = -INF2;
    map<int, int> mp;
    range(i, k) {
        int a; cin >> a;
        mp[a] = 1;
    }
    for(int c = s; c <= n; ++c) if (!mp[c]) {
        a1 = c;
        break;
    }
    for(int c = s; c >= 1; --c) if (!mp[c]) {
        a2 = c;
        break;
    }
    cout << min(a1 - s, s - a2) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t; cin >> t;
    range(i, t) solve();
    return 0;
}