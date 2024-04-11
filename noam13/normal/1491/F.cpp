#include <bits/stdc++.h>
#define int int64_t
#define vi vector<int>
#define ii pair<int,int>
#define vb vector<bool>
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
const int INF = 4e18, MOD = 1e9+7;

int ask(vi& a, vi& b){
    cout<<"? "<<a.size()<<" "<<b.size()<<endl;
    for(int x:a) cout<<x+1<<" ";
    cout<<endl;
    for(int x:b) cout<<x+1<<" ";
    cout<<endl;
    int v; cin>>v;
    return v;
}
int solve(){
    int n; cin>>n;
    int r = 1;
    vi ans;
    while(r<n){
        vi a = {r}, b;
        loop(i,0,r) b.pb(i);
        int v = ask(a,b);
        if (v!=0) break;
        r++;
    }
    loop(i,r+1,n){
        vi a = {i}, b = {r};
        int v = ask(a,b);
        if (!v) ans.pb(i);
    }
    int lo = 0, hi = r, mid, f=-1;
    while(lo<hi){
        mid = (lo+hi)/2;
        vi a = {r}, b;
        loop(i,0,mid+1) b.pb(i);
        int v =  ask(a,b);
        if (v) hi = f = mid;
        else lo = mid + 1;
    }
    loop(i,0,r) if(i!=f) ans.pb(i);
    cout<<"! "<<ans.size()<<" ";
    for(int x:ans) cout<<x+1<<" ";
    cout<<endl;
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
g++ f.cpp -o a & a


*/