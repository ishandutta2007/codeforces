#include<bits/stdc++.h>

using namespace std;

#define ld long double
#define ll long long
#define pb push_back
#define int long long

mt19937 rnd(51);

const int MOD = 1e9 + 7, N = 1e6 + 10;
int f[N];
int cnt[N];

int add(int a, int b){
    return a + b >= MOD ? a + b - MOD : a + b;
}

int sub(int a, int b){
    return a - b < 0 ? a - b + MOD : a - b;
}

int mul(int a, int b){
    return (a * b % MOD);
}

int binpow(int a, int n){
    int res = 1;
    while(n){
        if (n & 1){
            res = mul(res, a);
        }
        a = mul(a, a);
        n /= 2;
    }
    return res;
}

int inv(int a){
    return binpow(a, MOD - 2);
}

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 0; i < N; i++){
        f[i] = (i == 0 ? 1 : mul(f[i - 1], i));
    }
    int n, m = 0;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
        cnt[a[i]]++;
        m += a[i];
    }
    int ans = 0, cntt = 1;
    for (int i = N - 1; i >= 1; i--){
        cntt = mul(cntt, f[cnt[i]]);
        if (i != 1) cntt = mul(cntt, f[cnt[i]]);
        ans = add(ans, mul(i - 1, mul(cnt[i], m - cnt[i])));
        m -= cnt[i] * 2;
        if (i - 2 >= 0) cnt[i - 2] += cnt[i];
    }
    cout << ans << ' ' << cntt << endl;
    return 0;
}