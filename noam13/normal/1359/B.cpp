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

int get(int x, int a, int b){
    if (b>2*a) return a*x;
    return (x/2) * b + (x%2) * a;
}
int solve(){
    int n,m,x,y; cin>>n>>m>>x>>y;
    int ans = 0;
    loop(i,0,n){
        string s; cin>>s;
        int cnt = 0;
        loop(j,0,m){
            if (s[j]=='.') cnt++;
            else ans+=get(cnt,x,y), cnt=0;
        }
        ans+=get(cnt,x,y);
    }
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
g++ a.cpp -o a & a
4
1 1 10 1
.
1 2 10 1
..
2 1 10 1
.
.
3 3 3 7
..*
*..
.*.


*/