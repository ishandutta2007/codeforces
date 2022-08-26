#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <unordered_set>
#include <fstream>
#include <cstring>
#include <map>
#include <math.h>

#define ll long long
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()
using namespace std;

int d[200001];

void solve() {
    int n; cin >> n;
    vector<int> a(n - 1);
    vector<int> deg(n + 1, 0);
    range(i, n - 1) {
        cin >> a[i];
        deg[a[i]]++;
    }
    set<pair<int, pair<int, int>>> s;
    for(int i = 1; i <= n; ++i) {
        s.insert({deg[i], {i, i}});
        d[i] = i;
    }
    cout << a[0] << '\n';
    for(int i = n - 2; i >= 0; --i) {
        int u = s.begin()->second.second;
        s.erase(s.begin());
        s.erase({deg[a[i]], {d[a[i]], a[i]}});
        deg[a[i]]--;
        d[a[i]] = max(d[a[i]], d[u]);
        cout << u << ' ' << a[i] << '\n';
        s.insert({deg[a[i]], {d[a[i]], a[i]}});
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests;
    tests = 1;
    range(i, tests) {
        solve();
    }
    return 0;
}