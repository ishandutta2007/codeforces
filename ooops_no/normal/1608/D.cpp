#include<bits/stdc++.h>

using namespace std;

#define ld long double
#define pb push_back
#define ll long long
#define int long long

mt19937 rnd(51);

const int MOD = 998244353, N = 2e5 + 10;
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
    if (k > n || k < 0) return 0;
    return mul(f[n], mul(inv_f[k], inv_f[n - k]));
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
    vector<string> s(n);
    int wb = 1, bw = 1, dif = 1, bal = 0, q = 0;
    for (int i = 0; i < n; i++){
        cin >> s[i];
        for (auto to : s[i]){
            if (to == 'W') bal++;
            if (to == '?') q++;
        }
        if (s[i][0] == 'B' || s[i][1] == 'W'){
            wb = 0;
        }
        if (s[i][0] == 'W' || s[i][1] == 'B'){
            bw = 0;
        }
        if (s[i][0] == s[i][1]){
            if (s[i][0] == '?') dif = mul(dif, 2);
            else dif = 0;
        }
    }
    if (bal > n){
        cout << 0 << endl;
    }
    else{
        cout << add(bw, add(wb, sub(cnk(q, n - bal), dif))) << endl;
    }
    return 0;
}