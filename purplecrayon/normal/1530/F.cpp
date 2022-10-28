#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 21, MOD = 31607;

int add(int a, int b) {
    a += b;
    if (a >= MOD) a -= MOD;
    return a;
}
void add_self(int& a, int b){
    a += b;
    if (a >= MOD) a -= MOD;
}
int sub(int a, int b) {
    a -= b;
    if (a < 0) a += MOD;
    return a;
}
void sub_self(int& a, int b) {
    a -= b;
    if (a < 0) a += MOD;
}
int mul(int a, int b) {
    return a*b%MOD;
}
void mul_self(int& a, int b) {
    a *= b;
    a %= MOD;
}
int po(int b, int p) {
    int r = 1;
    for (; p; b=b*b%MOD, p>>=1) if (p&1) r=r*b%MOD;
    return r;
}
int inv(int x){ return po(x, MOD-2); }
int di(int a, int b){ return mul(a, inv(b)); }

int n, a[MAXN][MAXN], iv[MAXN][MAXN];

int ans = 0, col[MAXN], row[MAXN];
int col_mask[MAXN][1<<MAXN];

void solve(){
    cin >> n;
    fill(col, col+n, 1);
    fill(row, row+n, 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            a[i][j] = di(a[i][j], int(1e4));

            mul_self(col[j], a[i][j]);
            mul_self(row[i], a[i][j]);

            iv[i][j] = inv(a[i][j]);
        }
    }

    for (int j = 0; j < n; j++) {
        fill(col_mask[j], col_mask[j]+(1<<n), 1);
        for (int k = 1; k < (1<<n); k++) {
            int c = __builtin_ctz(k);
            col_mask[j][k] = mul(a[c][j], col_mask[j][k^(1<<c)]);
        }
    }

    for (int i = 0; i < (1<<n); i++) {
        int st = 1;
        for (int j = 0; j < n; j++) if ((i>>j)&1) mul_self(st, row[j]);
        
        for (int j = 0; j < 4; j++) {
            int cur = st;
            if (j&1) {
                for (int k = 0; k < n; k++) if ((i>>k)&1^1) 
                    mul_self(cur, a[k][k]);
            }
            if (j&2) {
                for (int k = 0; k < n; k++) if (((i>>k)&1^1) && ((j&1^1) || k != n-1-k)) 
                    mul_self(cur, a[k][n-1-k]);
            }

            int dp[2]={1, 0};
            for (int k = 0; k < n; k++) {
                int contrib = col_mask[k][((1<<n)-1)&(~i)];
                if ((j&1) && ((i>>k)&1^1)) mul_self(contrib, iv[k][k]);
                if ((j&2) && ((i>>(n-1-k))&1^1) && ((j&1^1)|| n-1-k != k)) mul_self(contrib, iv[n-1-k][k]);

                int pre[2]={dp[0], dp[1]};
                add_self(dp[0], mul(pre[1], contrib));
                add_self(dp[1], mul(pre[0], contrib));
            }


            int cur_par = (__builtin_popcount(i)^__builtin_popcount(j))&1;
            add_self(ans, mul(cur, dp[cur_par]));
            sub_self(ans, mul(cur, dp[cur_par^1]));
        }
    }
    cout << sub(1, ans) << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}