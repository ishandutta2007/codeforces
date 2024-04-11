#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
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
#include <string>
#include <map>
#include <math.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vi;
typedef pair<ld, ld> pld;

const int sz = 1e5 + 5;
const ll mod = 998244353;
ll b[sz];
int dp[sz];

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    foru(i, 0, n)cin >> a[i];
    ll mxa = 1e5, sqmxa = sqrtl(mxa) + 5;
    int bst = 1;
    for (ll d = -sqmxa; d <= sqmxa; d++) {
        foru(i, 0, n)b[i] = a[i] - d * i;
        sort(b, b + n);
        int bstt = 0, cur=1;
        foru(i, 1, n) {
            if (b[i] == b[i - 1])cur++;
            else cur = 1;
            bstt = max(bstt, cur);
        }
        bst = max(bst, bstt);
    }
    foru(i, 0, n) {
        map<ll, int> ds;
        foru(j, 1, sqmxa) {
            if (i + j >= n)break;
            if ((a[j + i] - a[i]) % j == 0) {
                ds[(a[j + i] - a[i]) / j]++;
            }
        }
        for (auto ii : ds)bst = max(bst, ii.ss + 1);
    }
    cout << n-bst << '\n';
}



int main() {
    fast;
    int t=1;
    //cin >> t;
    while (t--)solve();
    return 0;
}