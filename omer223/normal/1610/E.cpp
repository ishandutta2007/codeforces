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



int n;
const int sz = 2e5 + 5;
ll a[sz];
ll dp[sz][3];

void solve() {
    map<int, int> cnts;
	cin >> n;
    foru(i, 0, n) {
        cin >> a[i]; cnts[a[i]]++;
    }
    int bst = 0;
    vector<int> v;
    int prv = a[0];
    foru(i, 1, n) {
        if (prv != a[i])v.push_back(prv);
        prv = a[i];
    }
    v.push_back(prv); //all eq? m = 1
    int m = v.size();
    foru(st, 0, m) {
        int cur = st, cnt = 1;
        while (cur < m) {
            int l = cur + 1, r = m-1, mid, bsth = -1;
            while (l <= r) {
                mid = (l + r + 1) / 2;
                if (v[mid] - v[st] >= 2 * (v[cur]-v[st])) {
                    bsth = mid;
                    r = mid - 1;
                }
                else l = mid + 1;
            }
            if (bsth == -1)break;
            else {
                cnt++;
                cur = bsth;
            }
        }
        bst = max(bst, cnt + cnts[v[st]] - 1);
    }
    cout << n - bst << '\n';
}

int main() {
    fast;
    srand(time(NULL));
    int t;
    cin >> t;
    while (t--)solve();
    return 0;
}