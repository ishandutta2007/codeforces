#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pb push_back
#define ld long double
#define ll __int128

mt19937 rnd(51);

const int N = 1e5 + 10, MOD = 1e9 + 7;
vector<int> f(N, 1);

int pow(int a, int n, int MOD){
    if (n == 0){
        return 1;
    }
    if (n % 2 == 1){
        return (pow(a, n - 1, MOD) * a) % MOD;
    }
    else{
        int g = pow(a, n / 2, MOD);
        return (g * g % MOD);
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for (int i = 2; i < N; i++){
        f[i] = (f[i - 1] * i) % MOD;
    }
    int n, x = 0;
    cin >> n;
    vector<int> a(n);
    map<int,int> mp;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        x += a[i];
    }
    if (x % n != 0){
        cout << 0 << endl;
        return 0;
    }
    x /= n;
    int cnt = 0, cntt = 0;
    for (auto to : a){
        mp[to]++;
        if (to < x) cnt++;
        else if (to > x) cntt++;
    }
    if (cnt == 0 && cntt == 0){
        cout << 1 << endl;
        return 0;
    }
    if (cnt <= 1 || cntt <= 1){
        int ans = f[n];
        for (auto to : mp){
            if (to.first != x){
                ans = (ans * pow(f[to.second], MOD - 2, MOD)) % MOD;
            }
        }
        ans = (ans * pow(f[n - cnt - cntt], MOD - 2, MOD)) % MOD;
        cout << ans << endl;
    }
    else{
        int ans = 2;
        ans = (ans * f[cnt] * f[cntt]) % MOD;
        for (auto to : mp){
            if (to.first != x){
                ans = (ans * pow(f[to.second], MOD - 2, MOD)) % MOD;
            }
        }
        ans = (ans * f[n]) % MOD;
        ans = (ans * pow(f[cnt + cntt], MOD - 2, MOD) % MOD * pow(f[n - cnt - cntt], MOD - 2, MOD)) % MOD;
        cout << ans << endl;
    }
    return 0;
}