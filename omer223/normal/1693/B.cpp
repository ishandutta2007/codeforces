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

const int sz = 5e5;
vector<int> adj[sz];
int n, p[sz];
pll lr[sz];
ll del[sz];

void reset() {
    foru(i, 0, n + 1)adj[i].clear();
    foru(i, 0, n)del[i] = 0;
}

void solve() { //if no inversions, then no. of leaves is the answer
    cin >> n;
    for (int i = 1; i < n; i++)cin >> p[i], p[i]--;
    for (int i = 0; i < n; i++)cin >> lr[i].ff >> lr[i].ss;
    reset();
    vector<int> updeg(n, 0);
    foru(i, 0, n - 1)updeg[p[i + 1]]++;
    queue<int> leaves;
    foru(i, 0, n) {
        if (updeg[i] == 0)leaves.push(i);
    }
    int ans = 0;
    while (!leaves.empty()) {
        int x = leaves.front(); leaves.pop();
        if (del[x] >= lr[x].ff) {
            del[x] = min(del[x], lr[x].ss);
        }
        else {
            del[x] = lr[x].ss;
            ans++;
        }
        if (x == 0)break;
        del[p[x]] += del[x];
        updeg[p[x]]--;
        if (updeg[p[x]] == 0) {
            leaves.push(p[x]);
        }
    }
    cout << ans << '\n';
}


int main() {
    fast;
    int t;
    cin >> t;
    while (t--)solve();
    return 0;
}