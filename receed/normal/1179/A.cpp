#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <random>
#include <bitset>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <queue>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;
using ld = long double;

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, q;
    cin >> n >> q;
    deque<int> a(n);
    vector<pair<int, int>> ans;
    int mx = 0;
    rep(i, n) {
        cin >> a[i];
        mx = max(mx, a[i]);
    }
    while (a[0] != mx) {
        ans.push_back({a[0], a[1]});
        if (a[0] > a[1])
            swap(a[0], a[1]);
        a.push_back(a[0]);
        a.pop_front();
    }
    ll x;
    rep(i, q) {
        cin >> x;
        x--;
        if (x < ans.size()) {
            cout << ans[x].first << ' ' << ans[x].second << '\n';
            continue;
        }
        x -= ans.size();
        cout << mx << ' ' << a[1 + x % (n - 1)] << '\n';
    }
}