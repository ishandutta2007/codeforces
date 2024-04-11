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
#include <unordered_map>
#define puba push_back
#define mapa make_pair
#define ff first
#define ss second
#define bend(_x) (_x).begin(), (_x).end()
#define szof(_x) ((int) (_x).size())

using namespace std;
typedef long long LL;
typedef pair <int, int> pii;
const int MOD = 1e9 + 7, MAXN = 1e5 + 5;

LL gcd(LL a, LL b, LL &x, LL &y) {
    if (!b) {
        x = 1; y = 0;
        return a;
    }
    LL x1, y1;
    LL d = gcd(b, a % b, x1, y1);
    y = x1 - (a / b) * y1;
    x = y1;
    return d;
}

unordered_map <int, int> memrev;

LL rev(LL a) {
    if (memrev.count((int)a)) {
        return memrev[a];
    }
    LL x1, y1;
    a %= MOD;
    gcd(a, MOD, x1, y1);    

    LL ret = x1 % MOD;
    if (ret < 0) {
        ret += MOD;
    }
    return memrev[a] = ret;
}

LL s10[MAXN], factorial[MAXN];

LL cnk(int n, int k) {
    if (k > n) {
        return 0;
    }
    return ((factorial[n] * rev(factorial[k])) % MOD * rev(factorial[n - k])) % MOD;
}

int n, k;
string s;
LL byrest[2][MAXN], pref[MAXN];

int main() {    
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    cin >> n >> k;

    cin >> s;

    s10[0] = 1;
    factorial[0] = 1;
    for (LL i = 1; i < MAXN; ++i) {
        s10[i] = (s10[i - 1] * 10) % MOD;
        factorial[i] = (factorial[i - 1] * i) % MOD;
    }

    for (int j = 0; j < n; ++j) {
            //cout << i << " " << j << " " << (s10[j - i] * (s[i] - '0') % MOD) * cnk(n - 1 - j - i - 1, k - 1) << endl;
        int mi = 1;
        byrest[0][j] = (s10[j] * cnk(n - 1 - j - mi, k - mi)) % MOD;
        //cout << j << " " << byrest[0][j] << endl;
        mi = 0;
        byrest[1][j] = (s10[j] * cnk(n - 1 - j, k - mi)) % MOD;
        //cout << i << " " << j << " " << (s10[j - i] * (s[i] - '0') % MOD) * cnk(n - 1 - j + i - mi, k - mi) << endl;
    }

    //cout << byrest[1][1] << endl;

    for (int i = 0; i < n; ++i) {
        pref[i + 1] = (pref[i] + byrest[0][i]) % MOD;
    }
    //cout << pref[2] << " " << byrest[1][3] << endl;
    //cout << pref[0] << " " << byrest[1][1] << endl;

    LL ans = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '0') {
            continue;
        }
        ans = (ans + ((LL) s[i] - '0') * (pref[n - i - 1] + byrest[1][n - i - 1])) % MOD;
    }

    cout << ans << endl;

    return 0;
}