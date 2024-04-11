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

const int N = 200002;
int f[N];

void add(int v) {
    for (int i = v + 1; i < N; i |= (i + 1))
        f[i]++;
}

ll gets(int v) {
    int res = 0;
    for (int i = v + 1; i; i &= (i - 1))
        res += f[i - 1];
    return res;
}

ll gets(int l, int r) {
    return gets(r) - gets(l);
}

ll c2(ll x) {
    return x * (x + 1) / 2;
}

int main() {
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    vector<int> lx;
    rep(i, n) {
        cin >> a[i].second >> a[i].first;
        lx.push_back(a[i].second);
    }
    sort(all(lx));
    lx.resize(unique(all(lx)) - lx.begin());
    map<int, vector<int>> m;
    rep(i, n) {
        a[i].second = lower_bound(all(lx), a[i].second) - lx.begin();
        m[-a[i].first].push_back(a[i].second);
    }
    ll ans = 0;
    for (auto &pp : m) {
        sort(all(pp.second));
        for (int i : pp.second)
            if (gets(i, i + 1) == 0)
                add(i);
        ans += c2(gets(0, N - 1));
        ans -= c2(gets(0, pp.second[0]));
        ans -= c2(gets(pp.second.back() + 1, N - 1));
        rep(i, (int) pp.second.size() - 1)
            ans -= c2(gets(pp.second[i] + 1, pp.second[i + 1]));
    }
    cout << ans;
}