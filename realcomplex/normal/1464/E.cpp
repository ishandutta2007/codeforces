#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e5 + 10;
const int MOD = 998244353;
const int M = 512;
vector<int> T[N];
int grundy[N];
int cnt[N];
int cand[N];
int sys[M][M+1];
int cur[M+1];

int powr(int n, int k){
    if(k == 0) return 1;
    int p = powr(n,k/2);
    p = (p * 1ll * p) % MOD;
    if(k % 2 == 1)
        p = (p * 1ll * n) % MOD;
    return p;
}

int inv(int x){
    return powr(x,MOD-2);
}


void dfs(int u){
    if(grundy[u]!=-1) return;
    vector<int> aq;
    for(auto x : T[u]){
        dfs(x);
        aq.push_back(grundy[x]);
    }
    for(auto x : aq) cnt[x] ++ ;
    int mex = 0;
    while(cnt[mex]>0) mex++;
    grundy[u]=mex;
    for(auto x : aq) cnt[x] -- ;
}

int main(){
    fastIO;
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i ++ ){
        grundy[i]=-1;
    }
    int u, v;
    for(int i = 0 ; i < m ; i ++ ){
        cin >> u >> v;
        T[u].push_back(v);
    }
    for(int i = 1; i <= n;  i ++ ){
        dfs(i);
        cand[grundy[i]] ++ ;
    }
    for(int i = 0 ; i < M; i ++ ){
        if(i>0) sys[i][M] = inv(n+1);
        sys[i][i]=1;
        for(int j = 0; j < M ; j ++ ){
            sys[i][j]-=(cand[(i^j)]*1ll*inv(n+1))%MOD;
            if(sys[i][j]<0)sys[i][j]+=MOD;
        }
    }
    int it;
    int mm;
    for(int j = M - 1; j > 0 ; j -- ){
        it = -1;
        for(int i = 0 ; i < M ; i ++ ){
            if(sys[i][j] != 0){
                it = i;
            }
        }
        if(it == -1) continue;
        for(int i = 0 ; i < M ; i ++ ){
            if(sys[i][j] != 0){
                mm = inv(sys[i][j]);
                for(int t = 0; t <= M; t ++ ){
                    sys[i][t] = (sys[i][t] * 1ll * mm) % MOD;
                }
            }
        }
        for(int i = 0 ; i <= M ; i ++ ){
            cur[i]=(MOD-sys[it][i])%MOD;
        }
        for(int i = 0 ; i < M ; i ++ ){
            if(sys[i][j]>0){
                for(int t = 0 ; t <= M; t ++ ){
                    sys[i][t] += cur[t];
                    sys[i][t] %= MOD;
                }
            }
        }
    }
    int coeff=0, val=0;
    for(int i = 0 ; i < M ; i ++ ){
        if(sys[i][0]>0) {
            coeff = sys[i][0];
            val = sys[i][M];
        }
    }
    val = (val * 1ll * inv(coeff)) % MOD;
    cout << val << "\n";
    return 0;
}