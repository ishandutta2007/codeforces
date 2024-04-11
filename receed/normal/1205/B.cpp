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

const int N = 62, M = N * 2;
int c[N], d[M];
vector<int> g[M];

int main() {
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0);
	ll n, x;
    cin >> n;
    vector<ll> a;
    rep(i, n) {
        cin >> x;
        if (!x)
            continue;
        a.push_back(x);
        rep(j, N)
            if (x & (1ll << j))
                c[j]++;
    }
    rep(i, N)
        if (c[i] > 2) {
            cout << 3;
            return 0;
        }
    n = a.size();
    rep(i, n)
        rep(j, i)
            if (a[i] & a[j]) {
                g[i].push_back(j);
                g[j].push_back(i);
            }
    int ans = M;
    rep(i, n)
        for (int j : g[i]) {
            rep(k, n)
                d[k] = M;
            d[i] = 0;
            queue<int> q;
            q.push(i);
            while (!q.empty()) {
                int v = q.front();
                q.pop();
                for (int u : g[v])
                    if (d[u] == M && (u != i && v != i || u != j && v != j)) {
                        d[u] = d[v] + 1;
                        q.push(u);
                    }
            }
            ans = min(ans, d[j] + 1);
        }
    if (ans == M)
        ans = -1;
    cout << ans;
}