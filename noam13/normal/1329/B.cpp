#include <bits/stdc++.h>
#define int int64_t
#define vi vector<int>
#define vb vector<bool>
#define ii pair<int,int>
#define vvi vector<vi>
#define vvb vector<vb>
#define vii vector<ii>
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define loop(i,s,e) for(int i=s;i<e;i++)
#define chkmax(a,b) a = max((a),(b))
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int INF = 1e18, MOD=1e9+7;
int mod;
int pp(int b, int p){
    if (p==0) return 1;
    int v = pp(b, p/2);
    return ((v*v)%mod)*(p%2?b:1)%mod;
}
void add(int &a, int b){
    a = (a+b)%mod;
}
void solve(){
    int d; cin>>d>>mod;
    vi dig;
    for(int a=d;a;a>>=1) dig.pb(a&1);
    //cout<<"hi"<<endl;
    reverse(all(dig));
    int n = dig.size();
    int mask = (1<<n) - 1;
    vi dp(n+1,0);
    mask>>=1;
    dp[0] = 1 + ((d&mask) + 1);
    loop(i,0,n-1){
        dp[i+1] = (dp[i] * (1 + pp(2,n-i-2)))%mod;
    }
    //loop(i,0,n) cout<<dp[i]<<" "; cout<<endl;
    //loop(i,0,n) cout<<free[i+1]<<" "; cout<<endl;
    int ans = (dp[n-1]+mod-1)%mod;
    cout<<ans<<endl;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    int t; cin>>t;
    loop(i,0,t) solve();

    return 0;
}
/*
color a
cls
g++ b.cpp -o a & a
10
1 1000000000
2 999999999
3 99999998
4 9999997
5 999996
6 99995
7 9994
8 993
9 92
10 1

*/