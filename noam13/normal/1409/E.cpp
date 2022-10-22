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


vi get(vi& a, int k){
    int n = a.size();
    vi ans(n);
    int j = 0;
    loop(i,0,n){
        while(a[i]-a[j]>k) j++;
        ans[i] = i-j+1;
        if (i) chkmax(ans[i], ans[i-1]);
    }
    return ans;
}
int solve(){
    int n,k; cin>>n>>k;
    vi a(n); int tmp;
    loop(i,0,n) cin>>a[i];
    loop(i,0,n) cin>>tmp;
    sort(all(a));
    vi pref = get(a,k);
    reverse(all(a));
    loop(i,0,n) a[i] = -a[i];
    vi suf = get(a,k); reverse(all(suf));
    int ans = 1;
    loop(i,0,n-1) chkmax(ans, pref[i]+suf[i+1]);
    cout<<ans<<endl;
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