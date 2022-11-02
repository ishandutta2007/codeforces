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
#include <chrono>
#include <random>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef long double ld;
typedef vector<int> vi;
typedef pair<ld, ld> pld;

const int MAX_K = 20, MAX_N = 1e5 + 5;
ll dp[MAX_K][MAX_N];
ll phi[MAX_N], phi_pre[MAX_N], lp[MAX_N];
vector<int> divs[MAX_N];

void precsieve() {
    vector<int> pr;
    for (int i = 2; i < MAX_N; i++) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back(i);
            phi[i] = i - 1;
        }
        for (int j = 0; j < (int)pr.size() && pr[j] <= lp[i] && i * pr[j] < MAX_N; ++j) {
            lp[i * pr[j]] = pr[j];
            if (i % pr[j] == 0)phi[i * pr[j]] = phi[i] * pr[j];
            else phi[i * pr[j]] = phi[i] * (pr[j] - 1);
        }
    }
    phi[1] = 1;
    for (int i = 1; i < MAX_N; i++)phi_pre[i] = phi_pre[i - 1] + phi[i];
    for (int i = 1; i < MAX_N; i++) {
        vector<int> tmp;
        for (int j = 1; j * j <= i; j++) {
            int x = i / j;
            tmp.push_back(x);
            if (x != j)divs[i].push_back(j);
        }
        reverse(tmp.begin(), tmp.end());
        for (int x : tmp)divs[i].push_back(x);
    }
}

ll calc2(ll l, ll r) {
    ll tot = 0;
    ll x = l;
    while (x <= r) {
        ll amt = r / x;
        tot += (phi_pre[amt]);
        x++;
    }
    return tot;
}

ll calc(ll l, ll r) {
    ll tot = 0;
    ll x = r / l;
    int idx = lower_bound(divs[r].begin(), divs[r].end(), x) - divs[r].begin();
    ll prv = l;
    ford(j, idx, 0) {
        ll fstnxt = r / divs[r][j] + 1;
        tot += (fstnxt - prv) * phi_pre[divs[r][j]];
        prv = fstnxt;
    }
    return tot;
}


void dnc(int l, int r, int optl, int optr, int k) { //opt is when to close
    if (l > r)return;
    int m = (l + r) / 2;
    int bsti = optr;
    ll bst = 1e18;
    int st = min(m, optr);
    ll stval = calc(st, m);
    for (int i = st; i >= optl; i--) {
        if (stval + dp[k - 1][i - 1] < bst) {
            bst = stval + dp[k - 1][i - 1];
            bsti = i;
        }
        int nxt = i - 1;
        if (nxt) {
            ll x = m / nxt;
            stval += phi_pre[x];
        }
    }
    dp[k][m] = bst;
    if (l == r)return;
    dnc(l, m - 1, optl, bsti, k);
    dnc(m + 1, r, bsti, optr, k);
}


void prec() {
    for (int i = 1; i < MAX_N; i++) {
        dp[1][i] = ((ll)i * (i + 1)) / 2;
    }
    for (int k = 2; k < MAX_K; k++) {
        dnc(k, MAX_N - 1, k, MAX_N - 1, k);
    }
}

int main() {
    fast;
    precsieve();
    prec();
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        if (k >= MAX_K)cout << n << '\n';
        else cout << dp[k][n] << '\n';
    }
    return 0;
}