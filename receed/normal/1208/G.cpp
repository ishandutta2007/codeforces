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

const int N = 1000003;
ll mp[N], isp[N], cost[N];
vector<ll> pl;

int main() {
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n, k, ans = 0;
    cin >> n >> k;
    if ( k == 1) {
        cout << 3;
        return 0;
    }
    vector<ll> cl;
    k++;
    cost[1] = 1;
    for (ll i = 2; i <= n; i++) {
        if (!mp[i]) {
            mp[i] = i;
            pl.push_back(i);
        }
        for (ll j : pl) {
            if (j > mp[i] || i * j > n)
                break;
            mp[i * j] = j;
        }
        ll pw = 1;
        while (i % (pw * mp[i]) == 0)
            pw *= mp[i];
        cost[i] = cost[i / pw] * (pw / mp[i] * (mp[i] - 1));
        cl.push_back(cost[i]);
    }
    sort(all(cl));
    rep(i, k)
        ans += cl[i];
    cout << ans + 1;
}