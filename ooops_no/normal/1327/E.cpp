#include<vector>
#include<map>
#include<algorithm>
#include<set>
#include<iostream>
#include<string>
#include<set>
#include<queue>
#include<random>

using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")

#define pb push_back
#define int long long
#define ld long double
#define ll long long
#define mp make_pair

const int MOD = 998244353;

int binpow(int n, int p){
    if (p == 0){
        return 1;
    }
    if (p % 2 == 0){
        int g = binpow(n, p / 2) % MOD;
        return (g * g % MOD);
    }
    else{
        return (binpow(n, p - 1) * n % MOD);
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> v;
    v.pb(10);
    for (int i = 2; i <= n; i++){
        int k = i * 9 * binpow(10, i - 1);
        k %= MOD;
        if (i >= 3) k -= ((i - 2) * 9 * binpow(10, i - 2) % MOD);
        k += MOD;
        k %= MOD;
        v.pb(k);
    }
    for (int i = v.size() - 1; i > -1; i--){
        cout << v[i] << " ";
    }
    return 0;
}