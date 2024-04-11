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
#include <cstring>

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
    ll n;
    cin >> n;
    ll cur = 0;
    vector<int> ans;
    vector<int> ans2;
    ans.push_back(0);
    for (int i = 1; i * i <= n; ++i) {
        ll cur_cur = n / i;
        if (cur != cur_cur) {
            cur = cur_cur;
            ans.push_back(i);
            if (cur_cur != i) {
                ans2.push_back(cur);
            }
        }
    }
    cout << ans.size() + ans2.size() << '\n';
    for(auto u: ans) {
        cout << u << ' ';
    }
    reverse(all(ans2));
    for(auto u: ans2) {
        cout << u << ' ';
    }
    cout << '\n';
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