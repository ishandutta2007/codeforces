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
#define bend(_x) (_x).begin(), (_x).end()
#define szof(_x) ((int) (_x).size())

using namespace std;
typedef long long LL;
const int MAXN = 505;
const LL MOD = 1e9 + 7;

int n;
int inp[MAXN];
LL d[MAXN][MAXN];

LL rec(int l, int r) {
    if (r - l == 0) {
        return 1;
    }
    if (d[l][r] != -1) {
        return d[l][r];
    }
    LL ret = 0;
    if (inp[l] < inp[l + 1]) {
        ret = rec(l + 1, r) % MOD;
    }
    for (int i = l + 1; i < r; ++i) {
        if (inp[l] < inp[i + 1]) {
            ret = (ret + rec(l + 1, i) * rec(i + 1, r)) % MOD;
        }
    }
    ret = (ret + rec(l + 1, r)) % MOD;
    return d[l][r] = ret;
}

int main() {    
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
    memset(d, -1, sizeof d);

    cin >> n;
    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }

    for (int i = 0; i < n; ++i) {
        cin >> inp[i];
    }

    //d[n][n - 1] = 1;
    cout << rec(1, n - 1) << endl;

    return 0;
}