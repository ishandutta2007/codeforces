#include <cstdio>
#include <iostream>
#include <ctime>
#include <cassert>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <bitset>
#include <stack>
#define puba push_back
#define mapa make_pair
#define ff first
#define ss second
#define all(_x) _x.begin(), _x.end()
#define szof(_x) (int) _x.size()

using namespace std;
typedef long long LL;
const int MAXN = 1e5 + 5;
const LL MOD = 1e9 + 7;

int t, k;

LL d[MAXN], sum[MAXN];

LL fsum(int l, int r) {
    return (((sum[r] - sum[l - 1]) % MOD) + MOD) % MOD;
}  

int main() {    
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    cin >> t >> k;

    
    for (int i = 0; i < MAXN; ++i) {
        if (i < k) {
            d[i] = 1;
            continue;
        }        
        d[i] = (d[i - 1] + d[i - k]) % MOD;
        //cout << i << " " << d[i] << endl;
    }

    sum[0] = 1;
    for (int i = 1; i < MAXN; ++i) {
        sum[i] = (sum[i - 1] + d[i]) % MOD;
        //cout << i << " " << sum[i] << endl;
    }

    for (int i = 0; i < t; ++i) {
        int a, b;
        cin >> a >> b;
        
        cout << fsum(a, b) << endl;
    }
    return 0;
}