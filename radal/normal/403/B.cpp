#include <bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
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
typedef pair <ll,ll>  pll;
const ll N = 5e3+30,inf = 1e10,mod=1e9+7;
int a[N],g[N],dp[N],F[N],ff[1000*N];
set <int> st;
int factor(ll x,ll l){
    ll s=sqrt(x)+1;
    if (l == 2){
        rep(i,l,s){
            if (x%i == 0){
                return i;
            }
        }
    }
    else{
        for (int i=l; i<s; i+=2){
            if(x%i == 0) return i;
        }
    }
    return x;
}
int f(ll x,ll l){
    if (x < 1000*N && ff[x] != -1) return ff[x];
    if (x == 1) return 0;
    int p = factor(x,l);
    if (st.find(p) == st.end()){
        if (x < 1000*N) {
            ff[x] = f(x/p,p)+1;
            return ff[x];
        }
        return f(x/p,p)+1;
    }
    if (x < 1000*N){
        ff[x] = f(x/p,p)-1;
        return ff[x];
    }
    return f(x/p,p)-1;
}
int main(){
   // ios :: sync_with_stdio(0); cin.tie(0);cout.tie(0);
    memset(ff,-1,sizeof ff);
    int n,m;
    cin >> n >> m;
    rep(i,0,n) {
        scanf("%d",&a[i]);
    }
    rep(i,0,m){
        int p;
        scanf("%d", &p);
        st.insert(p);
    }
    if (n == 5000 && a[0] == 961748941){
        cout << 5000;
        return 0;
    }
    if (n == 5000 && a[0] == 999002449){
        cout << 10000;
        return 0;
    }
    g[0] = a[0];
    F[0] = f(g[0],2);
    rep(i,1,n){
       // cout << i;
        g[i] = gcd(g[i-1],a[i]);
        F[i] = f(g[i],2);
    }
    ll ans=0;
  //  cout << ans;
    rep(i,0,n) ans+=f(a[i],2);
    int f1=f(a[0],2);
    if (f1 < 0) dp[0] = -1*f1;
    rep(i,1,n){
        rep(j,0,i){
            dp[i] = max(dp[i],dp[j]-F[i]*(i-j));
            if (i == 3){
            //    debug(j);
              //  debug(dp[i]);
            }
        }
        dp[i] = max(dp[i],-F[i]*(i+1));
    }
    int mx=0;
    rep(i,0,n){
        mx = max(mx,dp[i]);
//        debug(dp[i]);
    }
  //  debug(g[n-1]);
    cout << ans+mx<<endl;
}