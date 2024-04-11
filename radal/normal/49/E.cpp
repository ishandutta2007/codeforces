#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("avx2,fma")
#define rep(i,l,r) for (int i = l; i < r; i++)
#define repr(i,r,l) for (int i = r; i >= l; i--)
#define X first
#define Y second
#define pb push_back
#define endl '\n'
#define debug(x) cerr << #x << " : " << x << endl;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pll;
const long long int N = 50+20,mod = 1e9+7,inf = 1e9+10,sq = 300,maxm= 700+2;
inline int mkay(int a,int b){
    if (a+b >= mod) return a+b-mod;
    if (a+b < 0) return a+b+mod;
    return a+b;
}

inline int poww(int a,int k){
    if (k < 0) return 0;
    int z = 1;
    while (k){
        if (k&1) z = 1ll*z*a%mod;
        a = 1ll*a*a%mod;
        k >>= 1;
    }
    return z;
}
bool dp[30][N][N][2];
int ans[N][N];
vector<pair<char,char> > ve[30];
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    memset(ans,63,sizeof ans);
    string s,t;
    int n,m,q;
    cin >> s >> t >> q;
    n = s.size();
    m = t.size();
    rep(i,0,q){
        string g;
        cin >> g;
        ve[g[0]-'a'].pb({g[3],g[4]});
    }
    repr(l,n-1,0){
        rep(r,l+1,n+1){
            rep(j,0,27){
                if (r-l == 1){
                    dp[j][l][r][0] = (s[l]-'a' == j);
                    continue;
                }
                for(auto p : ve[j]){
                    int d1 = p.X-'a',d2 = p.Y-'a';
                    rep(i,l+1,r){
                        if (dp[d1][l][i][0] && dp[d2][i][r][0]){
                            dp[j][l][r][0] = 1;
                            break;
                        }
                    }
                    if (dp[j][l][r][0]) break;
                }
            }
        }
    }
    repr(l,m-1,0){
        rep(r,l+1,m+1){
            rep(j,0,27){
                if (r-l == 1){
                    dp[j][l][r][1] = (t[l]-'a' == j);
                    continue;
                }
                for(auto p : ve[j]){
                    int d1 = p.X-'a',d2 = p.Y-'a';
                    rep(i,l+1,r){
                        if (dp[d1][l][i][1] && dp[d2][i][r][1]){
                            dp[j][l][r][1] = 1;
                            break;
                        }
                    }
                    if (dp[j][l][r][1]) break;
                }
            }
        }
    }
    rep(i,0,n){
        rep(j,0,m){
            rep(l,0,i+1){
                rep(r,0,j+1){
                    rep(k,0,26){
                        if (!dp[k][l][i+1][0] || !dp[k][r][j+1][1]) continue;
                        if (!l && !r){
                            ans[i][j] = 1;
                            break;
                        }
                        if (!l || !r) continue;
                        ans[i][j] = min(ans[i][j],1+ans[l-1][r-1]);
                    }
                }
            }
        }
    }
    if (ans[n-1][m-1] < inf) cout << ans[n-1][m-1];
    else cout << -1;
    return 0;
}