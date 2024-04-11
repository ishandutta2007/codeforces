#include <bits/stdc++.h>
#define int int64_t
#define vi vector<int>
#define vb vector<bool>
#define ii pair<int,int>
#define vvi vector<vi>
#define vvb vector<vb>
#define vii vector<ii>
#define vvii vector<vii>
#define x first
#define y second
#define pb push_back
#define loop(i,s,e) for(int i=s;i<e;i++)
#define loopr(i,s,e) for(int i=e-1;i>=s;i--)
#define chkmax(a,b) a=max(a,b)
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int INF = 2e18, MOD=1e9+9;


int sum(int n){
    int res = 0;
    for(;n;n/=10) res+=n%10;
    return res;
}
int solve(){
    int n,s; cin>>n>>s;
    int mult = 1, ans = 0;
    while(1){
        if (sum(n)<=s) return cout<<ans<<endl,0;
        ans+= mult * (10 - n%10);
        n/=10; n++;
        mult*=10;
    }
    return 0;
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
g++ temp2.cpp -o a & a
4 2
bbaa
ab

*/