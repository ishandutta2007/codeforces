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
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0);
	int s, b;
    cin >> s >> b;
    vector<int> a(s);
    vector<pair<int, int>> c(b);
    rep(i, s)
        cin >> a[i];
    rep(i, b)
        cin >> c[i].first >> c[i].second;
    sort(all(c));
    vector<int> ps(b + 1);
    rep(i, b)
        ps[i + 1] = ps[i] + c[i].second;
    rep(i, s)
        cout << ps[lower_bound(all(c), make_pair(a[i] + 1, 0)) - c.begin()] << ' ';
}