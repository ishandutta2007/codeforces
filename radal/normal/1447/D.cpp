#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define endl '\n'
#define pb push_back
#define mp make_pair
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
typedef long long  int ll;
typedef pair<int,int> pll;
const long long int N=5e3+30,mod = 1e9+7,inf=1e12;
short int lcs[N][N];
int dp[N][N],be[N][N];
int main(){
    int n,m;
    string a,b;
    cin >> n >> m >> a >> b;
    rep(i,0,n){
        if (a[i] == b[0]){
            lcs[i][0] = 1;
            be[i][0] = 2;
        }
        else{
            if (i){
                lcs[i][0] = lcs[i-1][0];
                be[i][0] = max(be[i-1][0]-1,0);
            }
            else lcs[i][0] = 0;
        }
        if (lcs[i][0]){
            dp[i][0] = 2;
        }
        else{
            dp[i][0] = 0;
            be[i][0] = 0;
        }
    }
    rep(i,1,m){
        if (a[0] == b[i]){
            lcs[0][i] = 1;
            be[0][i] = 2;
        }
        else{
           if (i){
                lcs[0][i] = lcs[0][i-1];
                be[0][i] = max(be[0][i-1]-1,0);
            }
            else lcs[0][i] = 0;
        }
        if (lcs[0][i]){
            dp[0][i] = 2;
        }
        else {
            dp[0][i] = 0;
            be[0][i] = 0;
        }
    }
    rep (i,1,n){
        rep(j,1,m){
            if (a[i] == b[j]){
                lcs[i][j] = lcs[i-1][j-1]+1;
                be[i][j] = max(2,2+be[i-1][j-1]);
                dp[i][j] = be[i][j];
            }
            else
                lcs[i][j] = max(lcs[i-1][j],lcs[i][j-1]);
            be[i][j] = max(max(-2,max(be[i][j-1]-1,be[i-1][j]-1)),be[i][j]);
            dp[i][j] = max(dp[i][j],max(dp[i-1][j],dp[i][j-1]));
        }
    }
    cout << dp[n-1][m-1] << endl;
    return 0;
}