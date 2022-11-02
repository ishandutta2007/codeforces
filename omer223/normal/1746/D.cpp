#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define _CRT_SECURE_NO_WARNINGS
#define fast ios::sync_with_stdio(false); cin.tie(0);
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define ff first
#define ss second
#define pb push_back

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
#include <complex>
#include <random>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef long double ld;
typedef vector<int> vi;
typedef pair<ld, ld> pld;

const int sz = 5e5 + 5;
vector<int> adj[sz];
ll sc[sz];
int p[sz];
int n;
map<int, ll> dp[sz];
set<int> dpvals[sz];

void reset() {
    foru(i, 0, n)adj[i].clear(), dp[i].clear(), dpvals[i].clear();
}

void pdfs(int src, int prv = -1) {
    int sons = 0;
    for (int x : adj[src]) {
        if (x == prv)continue;
        sons++;
    }
    for (int x : adj[src]) {
        if (x == prv)continue;
        for (int z : dpvals[src]) {
            dpvals[x].insert(z / sons);
            dpvals[x].insert((z + sons - 1) / sons);
        }
        pdfs(x, src);
    }
}

void dfs(int src, int prv = -1) {
    int sons = 0;
    for (int x : adj[src]) {
        if (x == prv)continue;
        dfs(x, src);
        sons++;
    }
    if (sons==0) {
        for (int x : dpvals[src]) {
            dp[src][x] = sc[src] * x;
        }
    }
    else {
        for (int x : dpvals[src]) {
            int sm = x / sons, bg = sm + 1;
            int bgamt = x % sons;
            ll smsm = 0;
            priority_queue<ll, vector<ll>, greater<ll>> topkdiff;
            for (int y : adj[src]) {
                if (y == prv)continue;
                smsm += dp[y][sm];
                topkdiff.push(dp[y][bg] - dp[y][sm]);
                if (topkdiff.size() > bgamt)topkdiff.pop();
            }
            while (!topkdiff.empty()) {
                ll z = topkdiff.top(); topkdiff.pop();
                smsm += z;
            }
            dp[src][x] = smsm + sc[src] * x;
        }
    }
}

void solve() {
    //int n;
    int k;
    cin >> n >> k;
    reset();
    p[0] = -1;
    foru(i, 0, n-1) {
        cin >> p[i];
        adj[--p[i]].push_back(i + 1);
        adj[i + 1].push_back(p[i]);
    }
    foru(i, 0, n)cin >> sc[i];
    dpvals[0].insert(k);
    pdfs(0);
    dfs(0);
    cout << dp[0][k] << '\n';
}


int main() {
    fast;
    int t;
    cin >> t;
    while (t--)solve();
    return 0;
}