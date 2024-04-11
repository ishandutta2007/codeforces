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
    int n,k; cin>>n>>k;
    vi a(n); loop(i,0,n) cin>>a[i];
    bool az=1, hz=0;
    loop(i,0,n){
        if (a[i]) az = 0;
        else hz = 1;
    }
    if (az) return cout<<1<<endl,0;
    //if (hz && k==1) return cout<<-1<<endl,0;
    int v = 0;
    loop(i,1,n) if(a[i]!=a[i-1]) v++; //dif.pb(a[i]-a[i-1]);
    if (k==1) {
        if (v) return cout<<-1<<endl,0;
        else return cout<<1<<endl,0;
    }
    v = (v+k-2)/(k-1);
    chkmax(v,int(1));
    cout<<v<<endl;
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
g++ b.cpp -o a & a
6
4 1
0 0 0 1
3 1
3 3 3
11 3
0 1 2 2 3 3 3 4 4 4 4
5 3
1 2 3 4 5
9 4
2 2 3 5 7 11 13 13 17
10 7
0 1 1 2 3 3 4 5 5 6

*/