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
    int n,m; cin>>n>>m;
    vvi a(n, vi(m));
    loop(i,0,n){
        loop(j,0,m) {
            cin>>a[i][j];
            
        }
    }
    if (a[0][0]>2 || a[n-1][0]>2 || a[n-1][m-1]>2 || a[0][m-1]>2)
        return cout<<"NO"<<endl,0;
    loop(i,1,n-1) if(a[i][0]>3 || a[i][m-1]>3) return cout<<"NO"<<endl,0;
    loop(j,1,m-1) if(a[0][j]>3 || a[n-1][j]>3) return cout<<"NO"<<endl,0;
    loop(i,0,n) loop(j,0,m) if (a[i][j]>4) return cout<<"NO"<<endl,0;
    cout<<"YES"<<endl;
    loop(i,0,n){
        loop(j,0,m){
            int x =4 - (i==0 || i==n-1) - (j==0 || j==m-1);
            cout<<x<<" ";
        }
        cout<<endl;
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
g++ b.cpp -o a & a
5
3 4
0 0 0 0
0 1 0 0
0 0 0 0
2 2
3 0
0 0
2 2
0 0
0 0
2 3
0 0 0
0 4 0
4 4
0 0 0 0
0 2 0 1
0 0 0 0
0 0 0 0

*/