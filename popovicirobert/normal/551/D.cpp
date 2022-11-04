#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 220
// 44

using namespace std;

int a[3][3], ans[3][3];
int m;

inline void multiply(int a[3][3], int b[3][3]) {
    int c[3][3];
    for(int i = 1; i <= 2; i++) {
        for(int j = 1; j <= 2; j++) {
            c[i][j] = 0;
            for(int k = 1; k <= 2; k++) {
                c[i][j] = (c[i][j] + 1LL * a[i][k] * b[k][j]) % m;
            }
        }
    }
    for(int i = 1; i <= 2; i++) {
        for(int j = 1; j <= 2; j++) {
            a[i][j] = c[i][j];
        }
    }
}

inline int lgput(ll b) {
    ans[1][1] = ans[2][2] = 1;
    a[1][2] = a[2][1] = a[2][2] = 1;
    while(b > 0) {
        if(b & 1)
            multiply(ans, a);
        b >>= 1;
        multiply(a, a);
    }
    return (ans[1][1] + ans[2][1]) % m;
}

inline int raise(int a, ll b) {
    int ans = 1;
    while(b > 0) {
        if(b & 1)
            ans = (1LL * ans * a) % m;
        b >>= 1;
        a = (1LL * a * a) % m;
    }
    return ans;
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int l;
    ll n, k;
    ios::sync_with_stdio(false);
    cin >> n >> k >> l >> m;
    int p2 = raise(2, n), ways = lgput(n + 1);
    int ans = 1;
    for(int bit = 0; bit < l; bit++) {
        if(k & (1LL << bit) && bit < 63) {
            ans = (1LL * ans * (p2 - ways + m)) % m;
        }
        else {
            ans = (1LL * ans * ways) % m;
        }
    }
    if(k >= (1LL << l) && l < 63) {
        ans = 0;
    }
    cout << ans % m;
    //cin.close();
    //cout.close();
    return 0;
}