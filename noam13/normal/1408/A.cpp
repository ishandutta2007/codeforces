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
#define chkmax(a,b) a = max(a,b)
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int INF = 4e18;

int solve(){
    int n; cin>>n;
    vi a(n), b(n), c(n);
    loop(i,0,n) cin>>a[i];
    loop(i,0,n) cin>>b[i];
    loop(i,0,n) cin>>c[i];
    vi p(n); p[0] = a[0];
    loop(i,1,n-1){
        if (a[i]==p[i-1]) p[i] = b[i];
        else p[i] = a[i];
    }
    if (p[n-2]!=a[n-1] && p[0]!=a[n-1]) p[n-1]=a[n-1];
    if (p[n-2]!=b[n-1] && p[0]!=b[n-1]) p[n-1]=b[n-1];
    if (p[n-2]!=c[n-1] && p[0]!=c[n-1]) p[n-1]=c[n-1];
    loop(i,0,n) cout<<p[i]<<" ";
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
g++ a.cpp -o a & a

*/