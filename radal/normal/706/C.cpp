#include <bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("Os")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define ll long long int
#define endl '\n'
#define mp make_pair
#define pb push_back
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
const long long int N=2e5+30,inf = 1e18;
ll c[N],dp[N][2];
string s[N];
bool shorter(string r,string t){
    if (r == t) return 0;
    ll n = min(r.size(),t.size());
    rep (i,0,n){
        if (int(r[i]) < int(t[i])){
            return 1;
        }
        if (int(r[i]) > int(t[i])){
            return 0;
        }
    }
    if (t.size() > r.size()) return 1;
    return 0;
}
int main(){
    ll n;
    cin >> n;
    rep (i,0,n){
        cin >> c[i];
        dp[i][0] = inf;
        dp[i][1] = inf;
    }
    rep(i,0,n) cin >> s[i];
    dp[0][0] = 0;
    dp[0][1] = c[0];
    rep (i,1,n){
        string t1=s[i],t0=s[i-1];
        reverse(t1.begin(),t1.end());
        reverse(t0.begin(),t0.end());
        bool f1,f2,f3,f4;
        f1 = !shorter(s[i],s[i-1]);
        f2 = !shorter(s[i],t0);
        f3 = !shorter(t1,s[i-1]);
        f4 = !shorter(t1,t0);
        //debug(f1);debug(f2);debug(f3);debug(f4);
        if (f1 && f2){
            dp[i][0] = min(dp[i-1][0],dp[i-1][1]);
        }
        if (f1 && !f2){
            dp[i][0] = dp[i-1][0];
        }
        if (f2 && !f1){
            dp[i][0] = dp[i-1][1];
        }
        if (f3 && f4){
            dp[i][1] = min(inf,min(dp[i-1][0],dp[i-1][1])+c[i]);
        }
        if (f3 && !f4){
            dp[i][1] = min(dp[i-1][0]+c[i],inf);
        }
        if (f4 && !f3){
            dp[i][1] = min(dp[i-1][1]+c[i],inf);
        }
    }
    if (min(dp[n-1][1],dp[n-1][0]) == inf){
        cout << -1;
        return 0;
    }
 //   debug(shorter("aaa","aa"));
    cout << min(dp[n-1][1],dp[n-1][0]);
    return 0;
}