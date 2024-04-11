#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e5 + 10;
const int K = 202;
const int MOD = (int)1e9 + 7;
vector<int> T[N];
int dp[N][K];
int nex[K];
int sub[N];
int pwr[N];

int n,k;

int S[K];

void add(int &x, int y){
    x += y;
    if(x >= MOD) x -= MOD;
}

void dfs(int u, int pa){
    sub[u] = 1;
    dp[u][0] = 1;
    int total = 1;
    for(auto x : T[u]){
        if(x == pa) continue;
        dfs(x, u);
        total += sub[x];
    }
    for(auto x : T[u]){
        if(x == pa) continue;
        for(int i = 0 ;i <= k ; i ++ ){
            nex[i] = 0;
        }
        for(int now = min(k, sub[u] + sub[x]); now >= 0; now -- ){
            for(int q = min(now, sub[x]); q >= 0 && now - q <= sub[u]; q -- ){
                nex[now] =  (nex[now] + (dp[u][now - q] * 1ll * dp[x][q]) % MOD) % MOD;

                if(now > 0 && q > 0){
                    if(now - q == 0){
                        S[now] = (S[now] + (dp[x][q] * 1ll * (pwr[total - 1 - sub[x]] - 1)) % MOD) % MOD;
                    }

                    else{
                        S[now] = (S[now] + (((dp[u][now - q] * 1ll * dp[x][q]) % MOD) * 1ll * pwr[total - sub[u] - sub[x]]) % MOD) % MOD;
                    }

                }

            }
        }
        for(int now = 0 ; now <= k ; now ++ ){
            dp[u][now] = nex[now];
        }

        sub[u] += sub[x];
    }
    for(int i = 1; i <= k ; i ++ ){
        add(S[i], dp[u][i]);
    }
    for(int i = 0; i <= k ; i ++ ){
        dp[u][i] = (dp[u][i] * 2ll) % MOD;
    }
    for(int i = k ; i >= 1; i -- ){
        if(i == 1){
            dp[u][i] = (dp[u][i] + (dp[u][i - 1] + MOD - 1) % MOD) % MOD;
        }
        else{
            dp[u][i] = (dp[u][i] + dp[u][i - 1]) % MOD;
        }
    }
}

int coeff[K][K];
int fac[N];

int main(){
    fastIO;
    //freopen("in.txt", "r", stdin);
    cin >> n >> k;
    pwr[0]=1;
    fac[0]=1;
    for(int i = 1; i <= n; i ++ ){
        pwr[i]=(pwr[i-1]*2ll)%MOD;
        fac[i]=(fac[i-1]*1ll*i)%MOD;
    }
    int u, v;
    for(int i = 1; i < n; i ++ ){
        cin >> u >> v;
        T[u].push_back(v);
        T[v].push_back(u);
    }
    dfs(1, -1);
    coeff[0][0] = 1;
    for(int i = 1; i <= k ; i ++ ){
        for(int j = 1; j <= i ; j ++ ){
            add(coeff[i][j], coeff[i-1][j-1]);
            add(coeff[i][j], (coeff[i-1][j] * 1ll * j) % MOD);
        }
    }
    int res = 0;
    int F;
    for(int i = 1; i <= k ; i ++ ){
        F = S[i];
        F = (F * 1ll * coeff[k][i]) % MOD;
        F = (F * 1ll * fac[i]) % MOD;
        add(res, F);
    }
    cout << res << "\n";
    return 0;
}