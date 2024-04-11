#include<iostream>
#include<algorithm>
#include<vector>
#include<random>
#include<map>
#include<set>
#include<deque>
#include<assert.h>
#include<bitset>

using namespace std;

#define pb push_back
#define ld long double
#define int long long
#define ll long long

mt19937 rnd(51);

const int MOD = 1e9 + 7;

int mul(int a, int b){
    return (a * b % MOD);
}

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

int binpow(int a, int n){
    if (n == 0) return 1;
    if (n % 2 == 1){
        return mul(binpow(a, n - 1), a);
    }
    else{
        int g = binpow(a, n / 2);
        return mul(g, g);
    }
}

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        if (k == 0){
            cout << 1 << endl;
            continue;
        }
        if (n % 2 == 1){
            int now = add(1, binpow(2, n - 1)), ans = 1;
            for (int i = 0; i < k; i++){
                ans = mul(ans, now);
            }
            cout << ans << endl;
        }
        else{
            int ans = binpow(2, n - 1);
            for (int f = 1; f < k; f++){
                ans = add(binpow(2, n * f), mul(ans, sub(binpow(2, n - 1), 1)));
            }
            cout << ans << endl;
        }
    }
    return 0;
}