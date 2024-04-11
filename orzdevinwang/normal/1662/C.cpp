#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
#define uint unsigned int
using namespace std;
const int N = 207, mod = 998244353;
int n, m, t, cnt[N];
int pn, G[N][N], T[N][N];
int f[20][N][N];
int dp[N], new_dp[N];
int h[N][N];
int main () {
    ios :: sync_with_stdio(false);
    cin.tie (0); cout.tie (0);
    cin >> n >> m >> t, pn = n * 2;
    L(i, 1, n) G[i + n][i] = G[i][i + n] = 1;
    L(i, 1, m) {
        int u, v;
        cin >> u >> v;
        G[u][v] += 1;
        G[v][u] += 1;
        cnt[u] += 1, cnt[v] += 1;
    }
    L(i, 1, n) (G[i + n][i] += mod - cnt[i]) %= mod;
    L(i, 1, pn) L(j, 1, pn) f[0][i][j] = G[i][j];
    L(i, 1, 20) L(a, 1, pn) L(b, 1, pn) L(c, 1, pn) {
        int w = (ll) f[i - 1][a][c] * f[i - 1][c][b] % mod;
        f[i][a][b] = f[i][a][b] + w >= mod ? f[i][a][b] + w - mod : f[i][a][b] + w;
    }
    --t;
    int sum = 0;
    L(A, 1, n){
	    me(dp, 0);
	    dp[A] = 1;
	    R(i, 19, 0) if(t >> i & 1) {
	        me(new_dp, 0);
	        L(a, 1, pn)
	            L(b, 1, pn) {
	                int w = (ll) dp[a] * f[i][a][b] % mod;
	                new_dp[b] = new_dp[b] + w >= mod ? new_dp[b] + w - mod : new_dp[b] + w;
	            }
	        swap(dp, new_dp);
	    }
	    int ret = (mod - (ll) dp[A + n] * cnt[A] % mod) % mod;
	    L(i, 1, n) (ret += (ll) dp[i] * G[i][A] % mod) %= mod;
	    (sum += ret) %= mod; 
    }
    cout << sum << '\n';
    return 0;
}