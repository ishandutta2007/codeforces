//
// Created by Ormlis on 27.11.2019.
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

#define ll long long
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()
#define pb(el) push_back(el)
using namespace std;

ll MOD = 998244353;
ll INF = 1e18 * 2;
int INF2 = 1e9 * 2;
int n;

void solve() {
    int r, g, b;
    cin >> r >> g >> b;
    int s = r + g + b;
    int ma = max(r, max(g, b));
    int mi = min(r, min(g, b));
    int sr = s - ma - mi;
    int ans = 0;
    ans += min(ma - sr, mi);
    mi -= ans;
    ma -= ans;
    ans += mi;
    ma -= mi / 2 + mi % 2;
    sr -= mi / 2;
    ans += min(sr, ma);
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    //ifstream cin(".in");
    //ofstream cout(".out");
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}