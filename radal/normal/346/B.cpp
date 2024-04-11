#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O8")
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
typedef long long ll;
typedef pair<int,int> pll;
const long long int N=2e2+20,mod = 1e9+7,inf=1e18,dlt = 12250,maxm = 2e6;
int poww(ll a,int k){
    if (!k) return 1;
    if (k == 1) return a;
    ll r = poww(a,k/2);
    return (((r*r)%mod)*poww(a,k&1))%mod;
}
int f[N];
pair <string,int> dp[N][N];
int func(string s,string t){
    int n = s.size(),m=t.size();
    string w = t+'#'+s;
    int k = 0,ans = 0;
    rep(i,1,m+n+1){
        while (k && w[i] != w[k]) k = f[k-1];
        k += (w[i] == w[k]);
        f[i] = k;
        ans = max(ans,k);
    }
    return ans;
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    string s,t,v;
    cin >> s >> t >> v;
    int d1,d2,d3;
    d1 = s.size(),d2=t.size(),d3=v.size();
    int ans=0;
    string out;
    rep(o,0,d3){
        rep(i,0,d1){
            if (!i){
                if (s[i] == t[0] && (o || s[i] != v[0])) dp[i][0] = mp(s[0],1);
                if ((dp[i][0].X).size() > ans){
                    ans = (dp[i][0].X).size();
                    out = dp[i][0].X;
                }
                continue;
            }
            dp[i][0] = dp[i-1][0];
            if (s[i] == t[0]){
                if (s[i] != v[0]) dp[i][0] = mp(s[i],0);
                if (o && dp[i][0].X == "") dp[i][0] = mp(s[i],1);
            }
            if (ans < (dp[i][0].X).size()){
                ans = (dp[i][0].X).size();
                out = dp[i][0].X;
            }
        }
        rep(i,1,d2){
            dp[0][i] = dp[0][i-1];
            if (s[0] == t[i]){
                if (s[0] != v[0]) dp[0][i] = mp(s[0],0);
                if (o && dp[0][i].X == "") dp[0][i] = mp(s[0],1);
            }
            if (ans < (dp[0][i].X).size()){
                ans = (dp[0][i].X).size();
                out = dp[0][i].X;
            }
        }
        rep(i,1,d1){
            rep(j,1,d2){
                dp[i][j] = dp[i-1][j];
                if((dp[i][j].X).size() < (dp[i][j-1].X).size()) dp[i][j] = dp[i][j-1];
                if ((dp[i][j].X).size() == (dp[i][j-1].X).size() && dp[i][j].Y > dp[i][j-1].Y) dp[i][j] = dp[i][j-1];
                if ((dp[i][j].X).size()  > ans){
                    out = dp[i][j].X;
                    ans = out.size();
                }
                if (s[i] == t[j]){
                    int mx = func(dp[i-1][j-1].X+s[i],v);
                    if (mx > o || (dp[i-1][j-1].X).size()+1 < (dp[i][j].X).size() || ((dp[i-1][j-1].X).size()+1 == (dp[i][j].X).size() && mx >= dp[i][j].Y)) continue;
                    dp[i][j] = mp(dp[i-1][j-1].X+s[i],mx);
                }
                if ((dp[i][j].X).size() > ans){
                    out = dp[i][j].X;
                    ans = out.size();
                }
            }
        }
    }
    if (!ans) cout << 0;
    else cout << out;
    return 0;
}