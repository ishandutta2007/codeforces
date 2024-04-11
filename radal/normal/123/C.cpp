#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define ll unsigned long long int
#define endl '\n'
#define pb push_back
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
const long long int N=1e2+30,mod = 1e9+7,inf=1e9;
ll C = 2e18;
int p[N][N],d[210];
ll dp[2*N][2*N];
char ans[2*N],table[N][N];
void ovf(ll& a){
    a = min(a,C);
}
int main(){
    int n,m; ll T;
    cin >> n >> m >> T;
    ovf(T);
    rep(i,0,n){
        rep(j,0,m){
            cin >> p[i][j];
        }
    }
    rep(i,0,n){
        d[i] = p[i][0];
        int x = 0,y = i;
        while(y >= 0 && x < m){
            d[i] = min(d[i],p[y][x]);
            y--;
            x++;
        }
      //  cout << d[i] << ' ';
    }
    rep(i,1,m){
        d[n+i-1] = p[n-1][i];
        int x = i,y = n-1;
        while(y >= 0 && x < m){
            d[n+i-1] = min(d[n+i-1],p[y][x]);
            y--;
            x++;
        }
     //   cout << d[n+i-1] << ' ';
    }
   // cout<<endl;
    ans[0] = '(';
    ans[n+m-2] = ')';
    int to=0;
    rep(i,1,m+n-2){
        memset(dp,0,sizeof dp);
        dp[0][1] = 1;
        int mi = inf,ind = -1;
        int t=0;
        rep(j,1,n+m-1)             
            if (ans[j] != ')' && ans[j] != '('){
                if (mi > d[j]){
                    mi = d[j];
                    ind = j;
                }
            }
        ans[ind] = '(';
        rep(j,1,n+m-1){
            rep(k,(j+1)/2+(j+1)%2,j+2){
                if (ans[j] == '('){
                    dp[j][k] = dp[j-1][k-1];
                    //t++;
                }
                else if (ans[j] == ')'){
                    if (k >= j-k) dp[j][k] = dp[j-1][k];
                    else dp[j][k] = 0;
                }
                else{
                    dp[j][k] = dp[j-1][k-1];
                    if (k >= j-k) dp[j][k] += dp[j-1][k];
                    ovf(dp[j][k]);
                 //   dp[j][k] = min(dp[j][k],2e18);
                }
               // if (i == 2){ debug(j); debug(k); debug(dp[j][k]);}
            }
        }
      /*  t = 0;
        rep(j,ind+1,n+m-1){
            if (ans[j] == '(') t++;
        }*/
        ll cnt=dp[n+m-2][(n+m-1)/2];
 //       debug(ind);
      //  rep(j,1,(n+m-1)/2-t){
          //  cnt+=dp[ind-1][j];
        //}
        if (cnt < T && i-to < (n+m-1)/2){
            T -= cnt;
            ans[ind] =')';
        }
        else{
            ans[ind] = '(';
            to++;
        }
      //  debug(t);
       // debug(T);
        //debug(mi);
        if (to == (m+n-1)/2-1) break;
     //   cout << ans[ind] << ' ';
    }
    rep(i,0,n+m){
        if (ans[i] != '(') ans[i] = ')';
    }
    rep(i,0,n){
        int x = 0, y = i;
        while (x < m && y >= 0){
            table[y][x] = ans[i];
            y--;
            x++;
        }
    }
    rep(i,1,m){
        int x = i, y = n-1;
        while (x < m && y >= 0){
            table[y][x] = ans[n+i-1];
            x++;
            y--;
        }
    }
    rep(i,0,n){
        rep(j,0,m) cout << table[i][j];
        cout << endl;

    }
}