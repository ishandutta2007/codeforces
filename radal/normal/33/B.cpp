#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O3")
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
const long long int N=5e2+20,mod = 1e9+7,inf=8e18,maxk = 1e5+20;
const long double eps = 0.0001;
int n;
string s,t;
ll dp[100][100];
pll mat[50][50];
int main(){
    rep(i,0,100) rep(j,0,100) dp[i][j] = inf;
    cin >> s >> t >> n;
    rep(i,0,40) rep(j,0,40) mat[i][j] = {inf,inf};
    if (s.size() != t.size()){
        cout << -1;
        return 0;
    }
    rep(i,0,30) dp[i][i] = 0;
    rep(i,0,n){
        char a,b;
        ll c;
        cin >> a >> b >> c;
        dp[a-'a'][b-'a'] = min(c,dp[a-'a'][b-'a']);
    }
    rep(k,0,40){
        rep(i,0,30){
            rep(j,0,30){
                if (max(dp[i][k],dp[k][j]) != inf) dp[i][j] = min(dp[i][j],dp[i][k]+dp[k][j]);
            }
        }
    }
    rep(i,0,30){
        rep(j,0,30){
            rep(k,0,30){
                if (dp[i][k] < inf && dp[j][k] < inf && mat[i][j].X > dp[i][k]+dp[j][k]){
                    mat[i][j].X = dp[i][k]+dp[j][k];
                    mat[i][j].Y = k;
                }
            }
            if (i == j) mat[i][j] = {0,j};
        }
    }
    /*int len = s.size();
    ll ans = 0;
    char as[len + 1];
    as[len] = '\0';
    for(int i = 0;i < len;i ++){
        ll an = inf;
        for(int j = 0;j < 26;j ++){
            if(dp[s[i] - 'a'][j] < inf and dp[t[i] - 'a'][j] < inf){
                if(dp[s[i] - 'a'][j] + dp[t[i] - 'a'][j] < an){
                    an = min(an, dp[s[i] - 'a'][j] + dp[t[i] - 'a'][j]);
                    as[i] = char(j + 97);
                }
            }
        }
        if(an == inf){
            cout << -1 << '\n';
            return 0;
        }   
        else {
            ans += an;
        }
    }*/
    ll ans = 0,sz = s.size();
    string ss = "";
    rep(k,0,sz){
        int i = s[k]-'a',j = t[k]-'a';
        if (mat[i][j].X == inf){
            cout << -1;
            return 0;
        }
        ans += mat[i][j].X;
        ss += char(mat[i][j].Y+'a');
    }
    cout << ans << endl << ss;
    return 0;
}