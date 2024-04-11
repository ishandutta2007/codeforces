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

const int N = 1000001;
vector<int> g[N], ord, rg[N];
int used[N], col[N], cc, cs[N], res[N];

void dfs(int v) {
    used[v] = 1;
    for (int u : g[v])
        if (!used[u])
            dfs(u);
    ord.push_back(v);
}

void rdfs(int v) {
    col[v] = cc;
    for (int u : rg[v])
        if (!col[u])
            rdfs(u);
}

int main() {
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0);
	int t, n, m, u, v;
    cin >> t;
    rep(z, t) {
        cin >> n >> m;
        rep(i, n + 1) {
            used[i] = 0;
            cs[i] = 0;
            col[i] = 0;
            g[i].clear();
            rg[i].clear();
        }
        ord.clear();
        rep(i, m) {
            cin >> u >> v;
            u--; v--;
            g[u].push_back(v);
            rg[v].push_back(u);
        }
        rep(i, n)
            if (!used[i])
                dfs(i);
        reverse(all(ord));
        cc = 0;
        for (int i : ord)
            if (!col[i]) {
                cc++;
                rdfs(i);
            }
        if (cc == 1) {
            cout << "No\n";
            continue;
        }
        rep(i, n)
            for (int j : g[i])
                if (col[i] != col[j])
                    cs[col[j]] = 1;
        vector<int> rj, rc;
        int ff = -1;
        for (int i = 1; i <= cc; i++)
            if (!cs[i]) {
                ff = i;
                break;
            }
        rep(i, n) {
            if (col[i] != ff)
                rj.push_back(i);
            else
                rc.push_back(i);
        }
        cout << "Yes\n" << rj.size() << ' ' << rc.size() << '\n';
        for (int i : rj)
            cout << i + 1 << ' ';
        cout << '\n';
        for (int i : rc)
            cout << i + 1 << ' ';
        cout << '\n';
    }
}