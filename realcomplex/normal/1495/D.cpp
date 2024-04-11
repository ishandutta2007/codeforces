#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 601;
const int MOD = 998244353;
int u[N], v[N];
int d[N][N];
int deg[N];
int outp[N][N];

int main(){
    fastIO;
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i ++ ){
        for(int j = 1; j <= n; j ++ ){
            if(i == j) d[i][j] = 0;
            else d[i][j] = (int)1e9;
        }
    }
    for(int i = 0 ; i < m ; i ++ ){
        cin >> u[i] >> v[i];
        d[u[i]][v[i]]=1;
        d[v[i]][u[i]]=1;
    }
    for(int k = 1; k <= n; k ++ ){
        for(int i = 1; i <= n; i ++ ){
            for(int j = 1; j <= n; j ++ ){
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
            }
        }
    }
    bool aq, bq;
    int soln;
    int cnt;
    for(int x = 1; x <= n; x ++ ){
        for(int y = 1; y <= x; y ++ ){
            cnt = 0;
            soln = 1;
            for(int z = 1; z <= n; z ++ ) deg[z] = 0;
            for(int e = 0; e < m ; e ++ ){
                if(d[x][u[e]] > d[x][v[e]]) swap(u[e], v[e]);
                if(d[x][v[e]] + d[y][v[e]] == d[x][y]) continue;
                if(d[x][u[e]] + 1 == d[x][v[e]] && d[y][u[e]] + 1 == d[y][v[e]]){
                    deg[v[e]] ++ ;
                }
            }
            for(int z = 1; z <= n; z ++ ){
                if(d[x][z] + d[y][z] == d[x][y]){
                    cnt ++ ;
                }
                else{
                    soln = (soln * 1ll * deg[z]) % MOD;
                }
            }
            if(cnt != d[x][y] + 1){
                outp[x][y]=outp[y][x]=0;
                continue;
            }
            else{
                outp[x][y] = outp[y][x] = soln;
            }
        }
    }
    for(int i = 1; i <= n; i ++ ){
        for(int j = 1; j <= n; j ++ ){
            cout << outp[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}