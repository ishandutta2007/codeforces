#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 5e2+10, MOD = 1e9+7;

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


int n, m, b;
int a[MAXN];

int pre[MAXN][MAXN], cur[MAXN][MAXN];

void solve() {
    cin >> n >> m >> b >> M;
    for (int i = 0; i < n; i++) cin >> a[i];

    // adding the ith task, can use a programmer >= j, with x bugs
    pre[0][0] = 1;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            for (int x = 0; x <= b; x++) {
                // assign to this programmer
                if (x + a[j] <= b)
                    add_self(cur[j][x + a[j]], pre[j][x]);
                // skip this one
                if (j < n)
                    add_self(pre[j+1][x], pre[j][x]);
            }
        }
        for (int j = 0; j < n; j++) for (int x = 0; x <= b; x++) {
            pre[j][x] = cur[j][x], cur[j][x] = 0;
        }
    }
    int ans = 0;
    for (int x = 0; x <= b; x++) for (int i = 0; i < n; i++) add_self(ans, pre[i][x]);
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    // cin >> T;
    while (T--) solve();
}