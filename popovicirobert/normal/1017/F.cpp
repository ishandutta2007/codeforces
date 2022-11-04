#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const ll MOD = (1LL << 32);
const int SIZE = 100000005;

inline void mod(ll &x) {
    if(x >= MOD)
        x -= MOD;
}

inline int get(int x) {
    return x - x / 2 - x / 3 + x / 6;
}

bitset <SIZE> vis;
int a, b, c, d;

inline ll f(int x) {
    ll ans = (1LL * c * x) % MOD;
    ans += d;
    mod(ans);
    ll pw = (1LL * x * x) % MOD;
    ans = ans + (1LL * b * pw) % MOD;
    mod(ans);
    pw = (1LL * pw * x) % MOD;
    ans = ans + (1LL * a * pw) % MOD;
    mod(ans);
    return ans;
}

inline ll solve(int x, int n) {
    ll pw = x;
    ll ans = 0;
    while(pw <= n) {
        ans += n / pw;
        mod(ans);
        pw *= x;
    }
    return (1LL * f(x) * ans) % MOD;
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, j;
    ios::sync_with_stdio(false);
    cin >> n >> a >> b >> c >> d;
    for(i = 5; i * i <= n; i += 2) {
        if(i % 3) {
            for(j = i * i; j <= n; j += i) {
                if(j % 2 && j % 3)
                    vis[get(j)] = 1;
            }
        }
    }
    ll ans = 0;
    ans += solve(2, n);
    mod(ans);
    ans += solve(3, n);
    mod(ans);
    for(i = 5; i <= n; i += 2) {
        if(i % 3 && vis[get(i)] == 0) {
            ans += solve(i, n);
            //printf("%d " ,i);
            mod(ans);
        }
    }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}