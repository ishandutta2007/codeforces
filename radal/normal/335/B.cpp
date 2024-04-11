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
const ll N = 5e4 + 30;
vector <int> ind[30];
int dp[N][110];
pll par[N][110];
int binary(int i, int val){
    int l,m,r;
    l = 0; 
    r = ind[i].size();
    if (ind[i][l] >= val) return -1;
    while (r-l > 1){
        m = (l+r)/2;
        if (ind[i][m] < val) l = m;
        else r = m;
    }
    return ind[i][l];
}
int main(){
    memset(dp,-1,sizeof dp);
    int n;
    string s;
    cin >> s;
    n = s.size();
    rep(i,0,n){
        ind[int(s[i])-int('a')].pb(i);
    }
    rep(i,0,n){
        dp[i][0] = n+2;
        dp[i][1] = i;
        par[i][1] = {-1,-1};
        par[i][0] = {-1,-1};
    }
    rep (i,1,n){
        rep (k,2,101){
            dp[i][k] = dp[i-1][k];
            par[i][k] = {i-1,k};
            if (dp[i-1][k-2] == -1) continue;
            int j = binary(int(s[i])-int('a'),min(dp[i-1][k-2],i));
            if (dp[i][k] < j){
                dp[i][k] = j;
                par[i][k] = {i-1,k-2};
            }
        }
    }
    pll st = {n-1,0};
    string p1="",p2="";
    repr(i,100,1){
        if (dp[n-1][i] != -1){
            st.Y = i;
            break;
        }
    }
    while (par[st.X][st.Y].X != -1){
        if (st.Y == par[st.X][st.Y].Y+2){
            p1 += s[st.X];
            p2 = s[st.X]+p2;
        }
        st = par[st.X][st.Y];
    }
    if (st.Y) p1+=s[st.X];
    cout << p1 << p2;
    return 0;
}