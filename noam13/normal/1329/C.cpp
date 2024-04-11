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
int n,m;
vi a;
bool can(int i){
    if (i>=m) return a[i]!=0;
    if (a[2*i]>a[2*i+1]) return can(2*i);
    return can(2*i+1);
}
void out(int i){
    if (a[i]==0) return;
    if (i>=n/2){
        a[i] = 0; return;
    }
    if (a[2*i]>a[2*i+1]){
        a[i] = a[2*i]; out(2*i);
    }
    else{
        a[i] = a[2*i+1]; out(2*i+1);
    }
}
void solve(){
    cin>>n>>m;
    n = (1<<n); m = (1<<m);
    a.resize(2*n,0);
    loop(i,1,n) cin>>a[i];
    vi v;
    loop(i,1,n) while(can(i)) out(i), v.pb(i);
    int ans=0;
    loop(i,1,n) ans+=a[i];
    cout<<ans<<endl;
    for(auto x:v) cout<<x<<" "; cout<<endl;
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
g++ c.cpp -o a & a
2
3 2
7 6 3 5 4 2 1
3 2
7 6 5 4 3 2 1

*/