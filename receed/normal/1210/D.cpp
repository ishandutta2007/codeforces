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

const int N = 100001, R = 300;
vector<int> g[N];
unordered_set<int> qq[N];
ll cc[N], cl[N], cr[N], used[N], x[N];
int ql[N], qc[N];

int main() {
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0);
	ll n, m, u, v, q;
    cin >> n >> m;
    rep(i, m) {
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    cin >> q;
    rep(i, q) {
        cin >> ql[i];
        ql[i]--;
        qc[ql[i]]++;
    }
    ll ca = 0;
    rep(i, n) {
        x[i] = i;
        for (int u : g[i]) {
            if (u < i) {
                cl[i]++;
                if (qc[u] >= R)
                    qq[u].insert(i);
            }
            else
                cr[i]++;
        }
        ca += cl[i] * cr[i];
    }
    cout << ca << '\n';
    rep(i, q) {
        v = ql[i];
        ca -= cl[v] * cr[v];
        int nx = n + i;
        if (qc[v] < R) {
            for (int j : g[v])
                if (x[j] > x[v] && x[j] < nx) {
                    ca += cl[j] - 1 - cr[j];
                    cl[j]--;
                    cr[j]++;
                    cl[v]++;
                    cr[v]--;
                    if (qc[j] >= R)
                        qq[j].insert(v);
                }
        }
        else {
            for (int j : qq[v])
                if (x[j] > x[v] && x[j] < nx) {
                    ca += cl[j] - 1 - cr[j];
                    cl[j]--;
                    cr[j]++;
                    cl[v]++;
                    cr[v]--;
                    if (qc[j] >= R)
                        qq[j].insert(v);
                }
            qq[v].clear();
        }
        x[v] = nx;
        cout << ca << '\n';
    }
}