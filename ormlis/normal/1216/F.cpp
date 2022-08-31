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

ll arr[200001], dp[200001];

void solve() {
    int n, k; cin >> n >> k;
    char a;
    range(i, n) {
        cin >> a;
        arr[i] = a - '0';
    }
    multiset<ll> s;
    range(i, n) {
        dp[i] = INF;
        s.insert(INF);
    }
    dp[n] = 0;
    s.insert(0);
    for(int i = n - 1; i >= 0; --i) {
        if (arr[i]) {
            ll l = max(0, i - k);
            ll f = *s.begin();
            if (dp[l] > f + i + 1) {
                s.erase(s.find(dp[l]));
                dp[l] = f + i + 1;
                s.insert(dp[l]);
            }
        }
        if (dp[i] > dp[i + 1] + i + 1) {
            s.erase(s.find(dp[i]));
            dp[i] = dp[i + 1] + i + 1;
            s.insert(dp[i]);
        }
        if (i < n - k) {
            s.erase(s.find(dp[i + k + 1]));
        }
    }
    cout << dp[0];
}

int main() {
    ios::sync_with_stdio(false);
    //ifstream cin(".in");
    //ofstream cout(".out");
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t; t = 1;
    range(i, t) {
        solve();
    }
    return 0;
}