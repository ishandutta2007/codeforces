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
#include <unordered_map>
#include <array>

#define ll long long
#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

using namespace std;

const ll INF = 1e18;
const int maxN = 200001;

void solve() {
    int n, m; cin >> n >> m;
    vector<string> a(n);
    vector<string> b(m);
    range(i, n) {
        cin >> a[i];
    }
    range(i, m) cin >> b[i];
    int q; cin >> q;
    while(q--) {
        int y; cin >> y; y--;
        cout << a[y % n];
        cout << b[y % m];
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests;
    //cin >> tests;
    tests = 1;
    range(_, tests) {
        solve();
    }
    return 0;
}