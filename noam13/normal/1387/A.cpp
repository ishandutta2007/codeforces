#include <bits/stdc++.h>
#define vi vector<int>
#define vvi vector<vi>
#define ii pair<int, int>
#define vii vector<ii>
#define vvii vector<vii>
#define x first
#define y second
#define loop(i,s,e) for(int i=s;i<e;++i)
#define loopr(i,s,e) for(int i=e;i>=s;--i)
#define pb push_back
#define chkmax(a,b) a = max(a,b)
#define chkmin(a,b) a = min(a,b)
#define all(a) a.begin(), a.end()
using namespace std;
const int INF = 1e9;
const double eps = 1e-7;

void finish(){
    cout<<"NO"<<endl; exit(0);
}
bool eq(double a, double b){
    return abs(a-b)<=eps;
}
int n,m;
vvii g;
vi col;
void color(int cur){
    if (col[cur]!=-1) return;
    col[cur] = 1;
    for(auto nei:g[cur]) color(nei.x);
}
vii val;
double xx;
void fix(int cur, ii v){
    if (val[cur].x!=INF){
        if (val[cur]==v) return;
        if (val[cur].x==v.x) finish();
        double cura = -(val[cur].y-v.y)/(1.0*(val[cur].x-v.x));
        if (!eq(xx,INF) && !eq(cura, xx)) finish();
        xx = cura;
        return ;
    }
    val[cur] = v;
    for(auto nei:g[cur]){
        fix(nei.x, {-v.x, nei.y-v.y});
    }
}
vector<double> ans;

void fixxx(int cur){
    if (col[cur]==2) return ;
    col[cur] = 2;
    ans[cur] = xx * val[cur].x + val[cur].y;
    for(auto nei:g[cur]) fixxx(nei.x);
}
vector<double> points;
void enter(int cur){
    if (col[cur]==3) return ;
    col[cur] = 3;
    points.pb(val[cur].y / (-1.0 * val[cur].x));
    for(auto nei:g[cur]) enter(nei.x);
}
void solve(int s){
    color(s);
    xx = INF;
    fix(s, {1,0});
    if (eq(xx, INF)){  //not definetive
        enter(s);
        sort(all(points));
        int r = points.size();
        xx = points[r/2];
        points.clear();
    }
    fixxx(s); //fix xx
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>m;
    g.resize(n); col.resize(n,-1);
    loop(i,0,m){
        int a,b,c; cin>>a>>b>>c; a--; b--;
        g[a].pb({b,c}); g[b].pb({a,c});
    }
    val.resize(n,{INF, INF}); ans.resize(n);
    loop(i,0,n) if(col[i]==-1) solve(i);
    cout<<"YES"<<endl;
    loop(i,0,n) cout<<ans[i]<<" ";
    cout<<endl;
    return 0;
}
/*
color a
cls
g++ a.cpp -o a & a
4 4
1 2 1
2 3 2
3 4 2
1 4 1



*/