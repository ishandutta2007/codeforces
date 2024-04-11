#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 6002;
int dp[N][N];
int f[N];
vector<int> T[N];

int main(){
    fastIO;
    int tc;
    cin >> tc;
    for(int t = 0; t < tc; t ++ ){
        int n;
        cin >> n;
        vector<int> pi;
        vector<pii> in(n);
        for(int i = 0 ; i < n; i ++ ){
            cin >> in[i].fi >> in[i].se;
            pi.push_back(in[i].fi);
            pi.push_back(in[i].se);
        }
        sort(pi.begin(), pi.end());
        pi.resize(unique(pi.begin(), pi.end()) - pi.begin());
        int m = pi.size();
        for(int i = 1; i <= m ; i ++ )
            T[i].clear();
        for(auto &x : in){
            x.fi = lower_bound(pi.begin(), pi.end(), x.fi) - pi.begin();
            x.se = lower_bound(pi.begin(), pi.end(), x.se) - pi.begin();
            x.fi ++ ;
            x.se ++ ;
            if(x.fi != x.se){
                T[x.fi].push_back(x.se);
                T[x.se].push_back(x.fi);
            }
        }
        for(int i = 1; i <= m ; i ++ )
            T[i].push_back(i);
        for(int i = 0 ; i <= m; i ++ ){
            for(int j = 0; j <= m; j ++ ){
                dp[i][j]=0;
            }
            f[i]=0;
        }
        for(auto x : in)
            dp[x.fi][x.se] = 1;
        for(int sz = 2; sz <= m; sz ++ ){
            for(int i = 1 ; i + sz - 1 <= m; i ++ ){
                int j = i + sz - 1;
                int mx = 0;
                for(auto cut : T[i]){
                    if(cut >= i && cut < j){
                        mx = max(mx, dp[i][cut] + dp[cut + 1][j]);
                    }
                }
                for(auto cut : T[j]){
                    if(cut >= i && cut < j){
                        mx = max(mx, dp[i][cut] + dp[cut + 1][j]);
                    }
                }
                dp[i][j] +=mx;
            }
        }
        for(int i = 1; i <= m; i ++ ){
            f[i]=max(f[i],f[i-1]);
            for(int j = i ; j >= 1; j -- ){
                f[i]=max(f[i],f[j-1]+dp[j][i]);
            }
        }
        cout << f[m] << "\n";
    }
    return 0;
}