#include <bits/stdc++.h>
 
using namespace std;
 
//#define aidar asadulin
 
#define int long long
#define ll long long
#define mp make_pair
#define pii pair<int, int>
#define pip pair<int, pii>
#define fi first
#define se second
#define all(_v) _v.begin(), _v.end()
#define sz(a) (int) (a.size())
#define chkmax(a, b) a = max(a, b)
#define chkmin(a, b) a = min(a, b)
#define ld long double
 
const int inf = 1e9 + 7;
const int max_n = 3e5 + 5;
const int mod = 998244353;

int binpow(int a, int b) {
    int res = 1;
    for(;b > 0;b /= 2, a = a * a % mod)
        if (b & 1) res = res * a % mod;
    return res;
}

signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;
    vector<int> a(2 * n);
    for(int i = 0;i < 2 * n;i++)
        cin >> a[i];

    sort(all(a));

    int sum = 0;
    for(int i = 0;i < n;i++)
        sum += a[i + n] - a[i];

    sum %= mod;
    
    int num = 1;
    for(int i = n + 1;i <= 2 * n;i++)
        num = num * i % mod;

    for(int i = 1;i <= n;i++)
        num = num * binpow(i, mod - 2) % mod;

    cout << (num * sum % mod + mod) % mod;
}