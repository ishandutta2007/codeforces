#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 4e6+10, MOD = 1e9+7;

int M;

#define MOD M
int add_self(int& a, int b) {
    a += b;
    if (a >= MOD) a -= MOD;
    return a;
}
int add(int a, int b) {
    return add_self(a, b);
}
int sub_self(int& a, int b) {
    a -= b;
    if (a < 0) a += MOD;
    return a;
}
int sub(int a, int b) {
    return sub_self(a, b);
}
int mul(int a, int b) {
    return (long long) a * b % MOD;
}
void mul_self(int& a, int b) {
    a = mul(a, b);
}
int po(int b, int p) {
    int r = 1;
    for (; p; b = mul(b, b), p >>= 1) if (p&1) mul_self(r, b);
    return r;
}
int inv(int x) {
    return po(x, MOD-2);
}
int di(int a, int b) {
    return mul(a, inv(b));
}
int di_self(int a, int b) {
    return a = di(a, b);
}
#undef MOD


int n, dp[MAXN], ps[MAXN];

void solve(){
    cin >> n >> M;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        add_self(ps[i], dp[i-1]);
        add_self(ps[i], dp[1]);
        add_self(ps[i], ps[i-1]);

        dp[i] = ps[i];

        for (int j = 2*i; j <= n; j += i) {
            add_self(ps[j], sub(dp[i], dp[i-1]));
        }
    }
    cout << dp[n] << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}