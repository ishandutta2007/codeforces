#include<bits/stdc++.h>

using namespace std;

#define ld long double
#define pb push_back
#define ll long long
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
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<int> a(n), cnt(30);
        vector<vector<int>> addik(n), del(n);
        for (int i = 0; i < m; i++){
            int l, r, x;
            cin >> l >> r >> x;
            l--, r--;
            addik[l].pb(x);
            del[r].pb(x);
        }
        int bal = 0;
        for (int i = 0; i < n; i++){
            bal += (int)addik[i].size();
            for (auto to : addik[i]){
                for (int j = 0; j < 30; j++){
                    if (to & (1 << j)){
                        cnt[j]++;
                    }
                }
            }
            for (int j = 0; j < 30; j++){
                if (cnt[j] == bal){
                    a[i] += (1 << j);
                }
            }
            bal -= (int)del[i].size();
            for (auto to : del[i]){
                for (int j = 0; j < 30; j++){
                    if (to & (1 << j)){
                        cnt[j]--;
                    }
                }
            }
        }
        int ans = 0;
        for (auto to : a){
            for (int j = 0; j < 30; j++){
                if (to & (1 << j)) cnt[j]++;
            }
        }
        vector<int> po(n + 1);
        po[0] = 1;
        for (int i = 1; i <= n; i++){
            po[i] = mul(po[i - 1], 2);
        }
        for (int i = 0; i < 30; i++){
            int val = cnt[i];
            for (int j = 1; j <= val; j += 2){
                ans = add(ans, mul((1 << i), mul(cnk(cnt[i], j), po[n - cnt[i]])));
            }
        }
        cout << ans << endl;
    }
    return 0;
}