#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <unordered_set>
#include <fstream>
#include <cstring>
#include <map>
#include <cmath>

#define ll long long
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

using namespace std;

set<int> cur;

pair<int, ll> req() {
    cout << '?' << ' ';
    for(auto x: cur) {
        cout << x << ' ';
    }
    cout << endl;
    pair<int, ll> p;
    cin >> p.first >> p.second;
    return p;
}

ll INF = 1e18;

void solve() {
    int n, k; cin >> n >> k;
    map<int, ll> ans;
    for(int i = 0; i < k; ++i) {
        cur.insert(i);
    }
    int prev = 0;
    for(int i = k; i <= n; ++i) {
        cur.erase(prev);
        cur.insert(i);
        auto p = req();
        prev = p.first;
        ans[prev] = p.second;
    }
    cur.erase(prev);
    vector<int> currrent2;
    for(auto x: cur) {
        currrent2.push_back(x);
    }
    ll mi = INF;
    ll ma = -INF;
    for(auto p: ans) {
        if (mi == INF) {
            cur.insert(p.first);
            mi = p.second;
        } else if(ma == -INF) {
            cur.insert(p.first);
            ma = p.second;
        } else {
            break;
        }
    }
    if (ma < mi) swap(ma, mi);
    int countma = 0, countmi = 0;
    range(i, k-1) {
        cur.erase(currrent2[i]);
        ll f = req().second;
        if (f == mi) countmi++;
        else countma++;
        cur.insert(currrent2[i]);
    }
    cout << "! " << countma + 1;
}

int main() {
    //ios::sync_with_stdio(false);
    //cin.tie(nullptr);
    //cout.tie(nullptr);
    solve();
    return 0;
}