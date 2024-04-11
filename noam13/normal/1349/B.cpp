#include <bits/stdc++.h>
#define int int64_t
#define vi vector<int>
#define ii pair<int,int>
#define vb vector<bool>
#define vvi vector<vi>
#define vvvi vector<vvi>
#define vvb vector<vb>
#define vii vector<ii>
#define vvii vector<vii>
#define x first
#define y second
#define pb push_back
#define loop(i,s,e) for(int i=s;i<e;i++)
#define loopr(i,s,e) for(int i=e-1;i>=s;--i)
#define chkmax(a,b) a = max((a),(b))
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int INF = 1e18, MOD = 1e9+7;


int solve(){
    int n,x; cin>>n>>x;
    vi a(n);
    vi pos;
    loop(i,0,n){
        cin>>a[i];
        if (a[i]==x) pos.pb(i);
        a[i] = (a[i]<x?-1:1);
    }
    if (pos.size()==0) return cout<<"no"<<endl,0;
    if (n==1) return cout<<"yes"<<endl,0;
    loop(i,0,n-1) if (a[i]==1 && a[i+1]==1) return cout<<"yes"<<endl,0;
    loop(i,0,n-2) if (a[i]==1 && a[i+2]==1) return cout<<"yes"<<endl,0;
    cout<<"no"<<endl;
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
5 3
1 5 2 6 1
1 6
6
3 2
1 2 3
4 3
3 1 2 3
10 3
1 2 3 4 5 6 7 8 9 10
3 2
2 1 2

*/