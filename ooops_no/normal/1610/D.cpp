#include<bits/stdc++.h>

using namespace std;

#define ld long double
#define ll long long
#define pb push_back
#define int long long

mt19937 rnd(51);

const int MOD = 1e9 + 7, N = 2e5 + 10;
int f[N], inv_f[N];

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

int cnk(int n, int k){
    if (k > n) return 0;
    return mul(f[n], mul(inv_f[k], inv_f[n - k]));
}

int gcd(int a, int b){
    if (b == 0) return a;
    else return gcd(b, a % b);
}

int rec(vector<int> a, bool f = 0){
    if (f){
        int cnt = 0, ans = 0, now = 1;
        for (auto to : a) cnt += to % 2;
        for (auto to : a) if (to % 2 == 0) now = mul(now, 2);
        for (int i = 2; i <= cnt; i += 2){
            ans = add(ans, mul(now, cnk(cnt, i)));
        }
        return ans;
    }
    else{
        int now = 1;
        for (auto to : a){
            if (to % 2 == 0){
                now = mul(now, 2);
            }
        }
        return sub(binpow(2, a.size()), now);
    }
}

int solve(int n, vector<int> a){
    int ans = 0;
    for (int i = 0; i < 30; i++){
        ans = add(ans, rec(a, (i != 0)));
        vector<int> b;
        for (auto to : a){
            if (to % 2 == 0) b.pb(to / 2);
        }
        a = b;
    }
    return ans;
}

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 0; i < N; i++){
        f[i] = (i > 0 ? mul(f[i - 1], i) : 1);
        inv_f[i] = inv(f[i]);
    }
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    cout << solve(n, a) << endl;
    return 0;
}