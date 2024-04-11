
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

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vi;
typedef pair<ld, ld> pld;

const int sz = 3000;
int n;
vector<int> adj[sz];
vector<ll> cyc;
bitset<sz> vis;

ll solve() {
    ll tot = 0; //big cyc
    int m = cyc.size();
    foru(i, 0, m) {
        ll mnL = 1e9, mxR = -1e9, mnl = 1e9, mxr = -1e9, wrong = cyc[(i - 1 + m) % m];
        ll len = 0;
        foru(j, 0, m) {
            len++;
            ll idx = (i + j) % m;
            if (cyc[idx] < n) {
                mnl = min(mnl, cyc[idx]);
                mxr = max(mxr, cyc[idx]);
            }
            else {
                mnL = min(mnL, cyc[idx] - n);
                mxR = max(mxR, cyc[idx] - n);
            }
            if ((j & 1) && (j != m - 1)) {
                if (wrong < n) {
                    if (wrong < mnl) {
                        tot += (mnL + 1) * (n - mxR) * (mnl - wrong) * (n - mxr);
                    }
                    else if (wrong > mxr) {
                        tot += (mnL + 1) * (n - mxR) * (mnl + 1) * (wrong - mxr);
                    }
                }
                else {
                    ll nwrong = wrong - n;
                    if (nwrong < mnL) {
                        tot += (mnl + 1) * (n - mxr) * (mnL - nwrong) * (n - mxR);
                    }
                    else if (nwrong > mxR) {
                        tot += (mnl + 1) * (n - mxr) * (mnL + 1) * (nwrong - mxR);
                    }
                }
            }
        }
        if (i == 0) {
            tot += (m / 2) * (mnL + 1) * (n - mxR) * (mnl + 1) * (n - mxr);
        }
    }
    return tot;
}

void dfs(int src) {
    vis[src] = 1;
    cyc.push_back(src);
    for (int x : adj[src]) {
        if (!vis[x])dfs(x);
    }
}

int main() {
    fast;
    cin >> n;
    foru(i, 0, 2 * n) {
        int x, y;
        cin >> x >> y;
        adj[--x].push_back(--y);
        adj[y].push_back(x);
    }
    ll ans = 0;
    foru(i, 0, n) {
        if (vis[i])continue;
        cyc.clear();
        dfs(i);
        ans += solve();
    }
    cout << ans << '\n';
    return 0;
}