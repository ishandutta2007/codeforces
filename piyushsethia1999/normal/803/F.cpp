#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair
#define int long long

using namespace std;

int powmod(int a, int b, int m) {
    int res = 1;
    while (b > 0) {
        if (b & 1) {
            res = (res * a) % m;
        }
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}

int32_t main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
    int n; cin >> n;
    int mod = 1e9 + 7;
    vector<int> a(100001, 0); for (int o = 0; o < n; o++) { 
        int p; cin >> p;
        a[p]++;
    }
    for (int i = 1; i <= 100000; ++i)
        for (int j = i * 2; j <= 100000; j += i)  
            a[i] += a[j];
    std::vector<int> ans(100001, 0);
    for (int i = 100000; i >= 1; --i) {
        ans[i] = (powmod(2, a[i], mod) - 1 + mod) % mod;
        for (int j = i * 2; j <= 100000; j += i) {
            ans[i] = ans[i] - ans[j];
            if (ans[i] < 0) ans[i] += mod; 
        }
    }
    cout << ans[1];
}