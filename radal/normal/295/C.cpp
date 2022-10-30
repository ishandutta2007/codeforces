#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O8")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define endl '\n'
#define pb push_back
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
typedef long long  int ll;
typedef pair<ll,ll> pll;
const long long int N=5e1+2,mod = 1e9+7,inf=2e8;
const long double eps = 0.0001;
int C[N][N];
int t1,t2;
int n,k;
pll dist[N][N][N][N][2];
ll y = 1;
void bfs(){
    dist[t1][t2][0][0][0].X = 1;
    dist[t1][t2][0][0][0].Y = 1;
    queue <pair<pair<pll,pll>,bool> > q;
    q.push({{{t1,t2},{0,0}},0});
    while (!q.empty()){
        auto p = q.front();
        q.pop();
        if (p.Y){
            ll s = k/100;
            ll s2 =  k/50;
            s = min(s,p.X.Y.Y);
            s2 = min(s2,p.X.Y.X);
            rep(i,0,s+1){
                rep(j,0,s2+1){
                    if(i+j == 0 || i*100+j*50 > k) continue;
                    if (!dist[p.X.X.X+j][p.X.X.Y+i][p.X.Y.X-j][p.X.Y.Y-i][0].X){
                        dist[p.X.X.X+j][p.X.X.Y+i][p.X.Y.X-j][p.X.Y.Y-i][0].X = dist[p.X.X.X][p.X.X.Y][p.X.Y.X][p.X.Y.Y][1].X+1;
                        dist[p.X.X.X+j][p.X.X.Y+i][p.X.Y.X-j][p.X.Y.Y-i][0].Y = (1ll*dist[p.X.X.X][p.X.X.Y][p.X.Y.X][p.X.Y.Y][1].Y*C[i][p.X.Y.Y])%mod;
                        dist[p.X.X.X+j][p.X.X.Y+i][p.X.Y.X-j][p.X.Y.Y-i][0].Y = (1ll*dist[p.X.X.X+j][p.X.X.Y+i][p.X.Y.X-j][p.X.Y.Y-i][0].Y*C[j][p.X.Y.X])%mod;
                        q.push({{{p.X.X.X+j,p.X.X.Y+i},{p.X.Y.X-j,p.X.Y.Y-i}},0});
                    }
                    else if(dist[p.X.X.X+j][p.X.X.Y+i][p.X.Y.X-j][p.X.Y.Y-i][0].X == dist[p.X.X.X][p.X.X.Y][p.X.Y.X][p.X.Y.Y][1].X+1){
    dist[p.X.X.X+j][p.X.X.Y+i][p.X.Y.X-j][p.X.Y.Y-i][0].Y += ((1ll*dist[p.X.X.X][p.X.X.Y][p.X.Y.X][p.X.Y.Y][1].Y*C[i][p.X.Y.Y]%mod)*C[j][p.X.Y.X])%mod;
    dist[p.X.X.X+j][p.X.X.Y+i][p.X.Y.X-j][p.X.Y.Y-i][0].Y %= mod;
                    }
                }
            }
        }
        else{
            ll s = k/100;
            ll s2 =  k/50;
            s = min(s,p.X.X.Y);
            s2 = min(s2,p.X.X.X);
            rep(i,0,s+1){
                rep(j,0,s2+1){
                    if(i+j == 0 || i*100+j*50 > k) continue;
                    if (!dist[p.X.X.X-j][p.X.X.Y-i][p.X.Y.X+j][p.X.Y.Y+i][1].X){
                        dist[p.X.X.X-j][p.X.X.Y-i][p.X.Y.X+j][p.X.Y.Y+i][1].X = dist[p.X.X.X][p.X.X.Y][p.X.Y.X][p.X.Y.Y][0].X+1;
                        dist[p.X.X.X-j][p.X.X.Y-i][p.X.Y.X+j][p.X.Y.Y+i][1].Y = (1ll*dist[p.X.X.X][p.X.X.Y][p.X.Y.X][p.X.Y.Y][0].Y*C[i][p.X.X.Y])%mod;
                        dist[p.X.X.X-j][p.X.X.Y-i][p.X.Y.X+j][p.X.Y.Y+i][1].Y = (1ll*dist[p.X.X.X-j][p.X.X.Y-i][p.X.Y.X+j][p.X.Y.Y+i][1].Y*C[j][p.X.X.X])%mod;
                        q.push({{{p.X.X.X-j,p.X.X.Y-i},{p.X.Y.X+j,p.X.Y.Y+i}},1});
                    }
                    else if(dist[p.X.X.X-j][p.X.X.Y-i][p.X.Y.X+j][p.X.Y.Y+i][1].X == dist[p.X.X.X][p.X.X.Y][p.X.Y.X][p.X.Y.Y][0].X+1){
    dist[p.X.X.X-j][p.X.X.Y-i][p.X.Y.X+j][p.X.Y.Y+i][1].Y += ((1ll*dist[p.X.X.X][p.X.X.Y][p.X.Y.X][p.X.Y.Y][0].Y*C[i][p.X.X.Y]%mod)*C[j][p.X.X.X])%mod;
    dist[p.X.X.X-j][p.X.X.Y-i][p.X.Y.X+j][p.X.Y.Y+i][1].Y %= mod;
                    }
                }
            }
        }
    }
    return;
}
int main(){
    rep(i,1,N){
        C[0][i] = 1;
        C[i][i] = 1;
    }
    rep(i,1,N){
        rep(j,i+1,N){
            C[i][j] = C[i-1][j-1] + C[i][j-1];
            C[i][j] %= mod;
        }
    }
    C[0][0] = 1;
    cin >> n >> k;
    rep(i,0,n){
        int x;
        cin >> x;
        if (x == 50) t1++;
        else t2++;
    }
    bfs();
    if (!dist[0][0][t1][t2][1].X){
        cout << -1 << endl << 0 << endl;
        return 0;
    }
    cout << dist[0][0][t1][t2][1].X-1 << endl << dist[0][0][t1][t2][1].Y;
    return 0;
}