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
    vvb a(n, vb(m)); 
    loop(i,0,n){
        string s; cin>>s;
        loop(j,0,m) a[i][j] = (s[j]=='1');
    }
    vvb aa = a;
    vector<vii> ans;
    loop(i,0,n){
        loop(j,0,m){
            if (a[i][j]){
                vii neis = {{i+1,j},{i,j+1}, {i+1,j+1}};
                for(auto &p:neis){
                    if (p.x>=n) p.x-=2;
                    if (p.y>=m) p.y-=2;
                }
                ans.pb({{i,j}, neis[0], neis[1]});
                ans.pb({{i,j}, neis[0], neis[2]});
                ans.pb({{i,j}, neis[2], neis[1]});
                //for(auto p:v) a[p.x][p.y] = !a[p.x][p.y];
            }
        }
    }
    for(auto v:ans) for(auto p:v) a[p.x][p.y] = !a[p.x][p.y];
    loop(i,0,n) loop(j,0,m) if(a[i][j]) cout<<"FUCK"<<endl;
    cout<<ans.size()<<endl;
    for(auto v:ans){
        for(auto p:v) cout<<p.x+1<<" "<<p.y+1<<" ";
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
g++ a1.cpp -o a & a
5
2 2
10
11
3 3
011
101
110
4 4
1111
0110
0110
1111
5 5
01011
11001
00010
11011
10000
2 3
011
101

*/