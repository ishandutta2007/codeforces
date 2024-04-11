#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define _CRT_SECURE_NO_WARNINGS
#define fast ios::sync_with_stdio(false); cin.tie(0);
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define ff first
#define ss second
#define chkmin(a, b) (a = ((a > b) ? b : a))
#define chkmax(a, b) (a = ((a < b) ? b : a))

#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
#include <queue>
#include <set>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef long double ld;
typedef vector<int> vi;
typedef pair<ld, ld> pld;
typedef pair<ll, int> pdi;


void solve() {
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> a(k);
    ll sm = 0;
    foru(i, 0, k)cin >> a[i], sm += a[i];
    if (sm < n * m) {
        cout << "No\n";
        return;
    }
    //can cross?
    bool can = 0;
    foru(rep, 0, 2) {
        vector<ll> b(k);
        foru(i, 0, k) {
            b[i] = a[i] / n;
            if (b[i] == 1)b[i] = 0;
        }
        ll sm = 0;
        foru(i, 0, k)sm += b[i];
        if (sm >= m) {
            if (m % 2 == 0)can = 1;
            else {
                foru(i, 0, k) {
                    if (b[i] >= 3)can = 1;
                }
            }
        }
        swap(n, m);
    }
    if (can)cout << "Yes\n";
    else cout << "No\n";
}

int main() {
    fast;
    int t;
    cin >> t;
    while (t--)solve();
    return 0;
}