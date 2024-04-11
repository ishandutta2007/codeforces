#pragma GCC optimize("Ofast", "-funroll-loops", "-fdelete-null-poller-checks")
#pragma GCC target("ssse3", "sse3", "sse2", "sse", "avx2", "avx")
#pragma GCC optimize(3, "Ofast", "inline")
#define fast ios::sync_with_stdio(false); cin.tie(0);
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define ff first
#define ss second
#define pb push_back

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <bitset>
#include <set>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <cmath>
#include <math.h>
#include <iomanip>
#include <numeric>
#include <random>
#include <time.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;


const int sz = 1e6 + 5, asz = 5e3 + 1;
int n;
int a[sz];
vector<int> occ[asz];
int dp[asz];
pii tmp[asz];

int main() {
    fast;
    cin >> n;
    foru(i, 0, n) {
        cin >> a[i]; occ[a[i]].pb(i);
    }
    foru(i, 1, asz)dp[i] = n + 1;
    foru(x, 0, asz) {
        if (occ[x].empty())continue;
        else dp[x] = min(dp[x], occ[x][0]);
        foru(y, 0, asz)tmp[y] = { dp[y],y };
        sort(tmp, tmp + asz);
        int msz = occ[x].size(), l = 0, r = 0;
        while (l < msz) {
            while (r<asz&&tmp[r].ff < occ[x][l]) {
                dp[x ^ tmp[r].ss] = min(dp[x ^ tmp[r].ss], occ[x][l]);
                r++;
            }
            l++;
        }
    }
    vector<int> ans;
    foru(y, 0, asz) {
        if (dp[y] < n)ans.push_back(y);
    }
    cout << ans.size() << '\n';
    for (int x : ans)cout << x << ' ';
    return 0;
}