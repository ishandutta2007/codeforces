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
using ul = unsigned long long;
using ld = long double;

int main() {
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    vector<int> b(n + 1);
    vector<string> ans(n + 1, string(n, '0'));
    rep(i, n) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(rall(a));
    rep(i, n) {
        rep(j, a[i].first) {
            ans[(i + j) % (n + 1)][a[i].second] = '1';
            b[(i + j) % (n + 1)] = 1;
        }
    }
    int res = 0;
    rep(i, n + 1)
        res += b[i];
    cout << res << '\n';
    rep(i, n + 1)
        if (b[i])
            cout << ans[i] << '\n';
}