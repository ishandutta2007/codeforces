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
#define mp make_pair
#define loop(i,s,e) for(int i=s;i<e;i++)
#define loopr(i,s,e) for(int i=e-1;i>=s;i--)
#define chkmax(a,b) a = max((a),(b))
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int INF = 2e9;


int solve(){
    int n,x,m; cin>>n>>x>>m;
    int l=x,r=x;
    loop(i,0,m){
        int a,b; cin>>a>>b;
        if ((l<=b && b<=r)|| (l<=a && a<=r) || (a<=l && r<=b)){
            //has shared point
            chkmin(l, a);
            chkmax(r, b);
        }
    }
    cout<<(r-l+1)<<endl;
    return 0;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    int t; cin>>t;
    loop(i,0,t) solve();
    return 0;
}
/*
color a
cls
g++ tmp.cpp -o a & a
3
6 4 3
1 6
2 3
5 5
4 1 2
2 4
1 2
3 3 2
2 3
1 2


*/