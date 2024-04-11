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
    vvb aaa = a;
    vector<vii> ans;
    loop(i,0,n-2){
        loop(j,0,m-2){
            if (a[i][j]){
                vii v = {{i,j},{i+1,j}, {i,j+1}};
                ans.pb(v);
                for(auto p:v) a[p.x][p.y] = !a[p.x][p.y];
            }
        }
    }
    loop(b,0,2){
        vector<vii> vec;
        int i = n-2;
        loop(j,0,m-2){
            vii v;
            if (a[i][j] && a[i+1][j]){
                v = {{i,j},{i+1,j}, {i,j+1}};
            }
            else if (a[i][j]){
                v = {{i,j},{i+1,j+1}, {i,j+1}};
            }
            else if (a[i+1][j]) v = {{i+1,j+1},{i+1,j}, {i,j+1}};
            if (v.size()){
                vec.pb(v);
                for(auto p:v) a[p.x][p.y] = !a[p.x][p.y];
            }
        }
        vvb aa(m, vb(n));
        loop(i,0,n) loop(j,0,m) aa[j][i] = a[i][j];
        a = aa;
        swap(n,m);
        if (b) for(auto &v:vec) for(auto &p:v) swap(p.x, p.y);
        for(auto &v:vec) ans.pb(v);
    }
    int i = n-2, j = m-2;
    vii inds = {{i,j}, {i+1,j}, {i,j+1}, {i+1,j+1}};
    vii z, o;
    for(auto p:inds){
        if (a[p.x][p.y]) o.pb(p);
        else z.pb(p);
    }
    if (o.size()==4){
        vii v = {o[0], o[1], o[2]};
        ans.pb(v);
        for(auto p:v) a[p.x][p.y] = !a[p.x][p.y];
        z.clear(), o.clear();
        for(auto p:inds){
            if (a[p.x][p.y]) o.pb(p);
            else z.pb(p);
        }
    }
    if (o.size()==1){
        vii v = {o[0], z[0], z[1]};
        ans.pb(v);
        for(auto p:v) a[p.x][p.y] = !a[p.x][p.y];
        z.clear(), o.clear();
        for(auto p:inds){
            if (a[p.x][p.y]) o.pb(p);
            else z.pb(p);
        }
    }
    if (o.size()==2){
        vii v = {o[0], z[0], z[1]};
        ans.pb(v);
        for(auto p:v) a[p.x][p.y] = !a[p.x][p.y];
        z.clear(), o.clear();
        for(auto p:inds){
            if (a[p.x][p.y]) o.pb(p);
            else z.pb(p);
        }
    }
    if (o.size()==3){
        vii v = o;
        ans.pb(v);
        for(auto p:v) a[p.x][p.y] = !a[p.x][p.y];
        z.clear(), o.clear();
        for(auto p:inds){
            if (a[p.x][p.y]) o.pb(p);
            else z.pb(p);
        }
    }
    for(auto v:ans){
        int minx = v[0].x, maxx = v[0].x, miny = v[0].y, maxy = v[0].y;
        for(auto p:v) {
            chkmin(minx, p.x), chkmin(miny, p.y), chkmax(maxx, p.x), chkmax(maxy, p.y);
            aaa[p.x][p.y] = !aaa[p.x][p.y];
        }
        /*if (maxx-minx>1 || maxy-miny>1) exit(1);
        if (minx<0 || miny<0 || maxx>=n || maxy>=m) exit(1);*/
    }
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
g++ aa.cpp -o b & b
1
4 4
1111
1111
1111
1111



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