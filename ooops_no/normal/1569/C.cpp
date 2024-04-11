#include<iostream>
#include<algorithm>
#include<vector>
#include<random>
#include<map>
#include<set>
#include<deque>
#include<assert.h>
#include<bitset>
#include<unordered_map>

using namespace std;

#define pb push_back
#define ld long double
#define ll long long
#define int long long

mt19937 rnd(51);

const int MOD = 998244353, N = 2e5 + 10;
vector<int> f(N);

int mul(int a, int b){
    return (a * b % MOD);
}

int binpow(int a, int n){
    if (n == 0) return 1;
    if (n % 2 == 0){
        int g = binpow(a, n / 2);
        return mul(g, g);
    }
    else{
        return mul(binpow(a, n - 1), a);
    }
}

int dv(int a, int b){
    return mul(a, binpow(b, MOD - 2));
}

int sub(int a, int b){
    a -= b;
    if (a < 0) a += MOD;
    return a;
}

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    map<int,int> cnt;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        cnt[a[i]]++;
    }
    sort(a.begin(), a.end());
    if (a[n - 2] + 1 < a[n - 1]){
        cout << 0 << endl;
        return;
    }
    int ans = f[n];
    if (a[n - 2] == a[n - 1]){
        cout << ans << endl;
    }
    else{
        for (int i = 0; i < n; i++){
            if (i < cnt[a.back() - 1]) continue;
            int val = dv(f[i], f[i - cnt[a.back() - 1]]);
            val = mul(val, f[n - cnt[a.back() - 1] - 1]);
            ans = sub(ans, val);
        }
        cout << ans << endl;
    }
}

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    f[0] = 1;
    for (int i = 1; i < N; i++){
        f[i] = mul(f[i - 1], i);
    }
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}