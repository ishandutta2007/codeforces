#define _CRT_SECURE_NO_WARNINGS
#pragma GCC optimize("Ofast", "-funroll-loops", "-fdelete-null-poller-checks")
#pragma GCC target("ssse3", "sse3", "sse2", "sse", "avx2", "avx")
#pragma GCC optimize(3, "Ofast", "inline")
#define fast ios::sync_with_stdio(false); cin.tie(0);
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define ff first
#define ss second
#define pb push_back
#define CW 1
#define CCW 2
#define COLIN 3

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
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

void solve() { //n == 1
    int n;
    cin >> n;
    vector<pair<pii,int>> p(n);
    foru(i, 0, n)cin >> p[i].ff.ff;
    foru(i, 0, n)cin >> p[i].ff.ss;
    foru(i, 0, n)p[i].ss = i;
    sort(p.begin(), p.end());
    vector<bool> ans(n, false);
    int bstsuf = n - 1;
    int mny = p[n - 1].ff.ss;
    ans[p[n - 1].ss] = 1;
    ford(i, n - 2, 0) {
        if (p[i].ff.ss > mny) {
            foru(j, i, bstsuf) {
                ans[p[j].ss] = 1;
                mny = min(mny, p[j].ff.ss);
            }
            bstsuf = i;
        }
    }
    for (bool x : ans)cout << x;
    cout << '\n';
}

int main() {
    fast;
    int t;
    cin >> t;
    while (t--)solve();
    return 0;
}