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
const int MAXN = 5005;
const LL MOD = 1e9 + 7;

int n, a, b, k;
LL d[2][MAXN];

int main() {    
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
    cin >> n >> a >> b >> k;

    if (a > b) {
        a = n - a + 1;
        b = n - b + 1;
    }

    for (int i = 1; i < b; ++i) {
        d[0][i] = i;
    }

    for (int i = 0; i < k; ++i) {
        for (int j = 1; j < b; ++j) {            
            d[1 - i % 2][j] = ((d[i % 2][b - 1] - d[i % 2][max(j - (b - j), 0)] - d[i % 2][j] + d[i % 2][j - 1]) % MOD + MOD) % MOD;            
        }
        for (int j = 1; j < b; ++j) {
            //cout << d[1 - i % 2][j] << " ";
            d[1 - i % 2][j] = (d[1 - i % 2][j] + d[1 - i % 2][j - 1]) % MOD;
        }
        //cout << endl;
    }

    cout << ((d[k % 2][a] - d[k % 2][a - 1]) % MOD + MOD) % MOD << endl;
    return 0;
}