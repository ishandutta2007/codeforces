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

#define pb emplace_back
#define ld long double
#define ll long long

mt19937 rnd(51);

const int N = 1e5 + 10, MOD = 998244353;
int col[N], take[N], sum[N], ans[N];
ll cnt[N];
vector<int> b[N];

int add(int a, int b){
    a += b;
    if (a >= MOD) a -= MOD;
    return a;
}

int sub(int a, int b){
    a -= b;
    if (a < 0) a += MOD;
    return a;
}

int mul(int a, int b){
    return ((ll)a * b % MOD);
}

int binpow(int a, ll n){
    if (n == 0) return 1;
    if (n & 1){
        return mul(binpow(a, n - 1), a);
    }
    else{
        int g = binpow(a, n / 2);
        return mul(g, g);
    }
}

int val(ll n){
    if (n == 1) return 0;
    if (n == 2) return 1;
    return mul(n % MOD, binpow(2, n - 3));
}

int vall(ll n){
    if (n == 1) return 0;
    return mul((n - 1) % MOD, binpow(2, n - 2));
}

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i){
        cin >> a[i];
        cin >> col[a[i]];
        take[a[i]] = mul(a[i], col[a[i]]);
        b[a[i]].pb(a[i]);
        cnt[a[i]] += col[a[i]];
        sum[a[i]] = add(sum[a[i]], take[a[i]]);
    }
    for (int i = N - 1; i >= 1; --i){
        ll cntt = 0, summ = 0;
        for (int j = i; j < N; j += i){
            cntt += cnt[j];
            summ = add(summ, sum[j]);
        }
        if (cntt == 0) continue;
        int first_val = val(cntt), second_val = vall(cntt);
        for (int j = i; j < N; j += i){
            for (auto t : b[j]){
                ans[i] = add(ans[i], mul(summ, mul(first_val, take[t])));
            }
            for (auto t : b[j]){
                ans[i] = add(ans[i], mul(col[t], mul(sub(second_val, first_val), mul(t, t))));
            }
        }
        for (int j = i * 2; j < N; j += i){
            ans[i] = sub(ans[i], ans[j]);
        }
    }
    cout << ans[1] << endl;
    return 0;
}