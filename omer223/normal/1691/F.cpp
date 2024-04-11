#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define _CRT_SECURE_NO_WARNINGS
#define fast ios::sync_with_stdio(false); cin.tie(0);
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define ff first
#define ss second

#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
#include <stack>
#include <set>
#include <map>
#include <deque>
#include <queue>
#include <numeric>
#include <iomanip>
#include <string>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef long double ld;
typedef vector<int> vi;
typedef pair<ld, ld> pld;

const ll mod = 1e9 + 7;

void imult(ll& lhs, const ll& rhs) {
    lhs = (lhs * rhs) % mod;
}

void iadd(ll& lhs, const ll& rhs) {
    lhs = (lhs + rhs) % mod;
}

void isubt(ll& lhs, const ll& rhs) {
    ll ret = (lhs - rhs) % mod;
    lhs = ret + (ret < 0 ? mod : 0);
}

ll bpw(const ll& lhs, const ll& rhs) {
    if (rhs == 0)return 1;
    ll ret = bpw(lhs, rhs >> 1);
    imult(ret, ret);
    if (rhs & 1) imult(ret, lhs);
    return ret;
}

ll inv(const ll& x) {
    return bpw(x, mod - 2);
}

ll mult(const ll& lhs, const ll& rhs) {
    return (lhs * rhs) % mod;
}

ll add(const ll& lhs, const ll& rhs) {
    return (lhs + rhs) % mod;
}

ll subt(const ll& lhs, const ll& rhs) {
    ll ret = (lhs - rhs) % mod;
    return ret + (ret < 0 ? mod : 0);
}

ll divv(const ll& lhs, const ll& rhs) {
    return mult(lhs, inv(rhs));
}

const int sz = 5e5 + 5;
ll f[sz], finv[sz];

void initf() {
    f[0] = 1;
    foru(i, 1, sz)f[i] = mult(i, f[i - 1]);
    finv[sz - 1] = bpw(f[sz - 1], mod - 2);
    ford(i, sz - 2, 0)finv[i] = mult(finv[i + 1], i + 1);
}

ll chs(int n, int k) {
    if (n < k)return 0;
    else if (n < 0)return 0;
    return mult(f[n], mult(finv[k], finv[n - k]));
}





int n, k;
const int szt = 3e5 + 5;
vector<int> adj[szt];
ll tot = 0;
int st[szt], par[szt];

void dfs(int src, int prv) {
    st[src] = 1;
    par[src] = prv;
    for (int x : adj[src]) {
        if (x != prv) {
            dfs(x, src);
            st[src] += st[x];
        }
    }
}

void dfs1(int src, int prv) {
    for (int x : adj[src]) {
        if (x != prv)dfs1(x, src);
    }
    vector<ll> sts;
    if (prv != -1) {
        for (int x : adj[src]) {
            if (x != prv)sts.push_back(st[x]);
        }
        sts.push_back(n - st[src]);
    }
    else {
        for (int x : adj[src]) {
            sts.push_back(st[x]);
        }
    }
    ll all = n, chssm = 0;
    for (int x : sts) {
        iadd(chssm, chs(x, k));
    }
    for (int x : sts) {
        ll tsm = chssm - chs(x, k);
        ll tall = all - x;
        ll tmpt = subt(chs(tall, k), tsm);
        ll myt = n - x;
        ll possible = x;
        iadd(tot, mult(mult(myt, possible), tmpt));
    }
    iadd(tot, mult(n, subt(chs(n, k), chssm)));
}

int main() {
    fast;
    initf();
    cin >> n >> k;
    foru(i, 0, n - 1) {
        int x, y;
        cin >> x >> y;
        adj[--x].push_back(--y);
        adj[y].push_back(x);
    }
    dfs(0, -1);
    dfs1(0, -1);
    cout << tot << '\n';
    return 0;
}