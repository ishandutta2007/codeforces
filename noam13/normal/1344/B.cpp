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


bool check(vvb& b){
    int n = b.size(), m = b[0].size();
    vb col(m,0);
    loop(i,0,n) loop(j,0,m) if (b[i][j]) col[j] = 1;
    bool empc = 0;
    loop(j,0,m) if (col[j]==0) empc = 1;
    loop(i,0,n){
        bool in = 0, was = 0;
        loop(j,0,m){
            if (!b[i][j]) {
                if (in) was = 1;
                in = 0;
            }
            else{
                if (in) continue;
                if (was) return 0;
                in = 1;
            }
        }
        if (in) was = 1;
        if (!was & !empc) return 0; //empty row, and no empty col
    }
    return 1;
}

int n,m;
vvb b;
ii dir[] = {{1,0},{-1,0},{0,1},{0,-1}};
void dfs(ii p){
    if (p.x<0 || p.y<0 || p.x>=n || p.y>=m) return;
    if (!b[p.x][p.y]) return;
    b[p.x][p.y] = 0;
    loop(i,0,4){
        dfs({p.x+dir[i].x, p.y + dir[i].y});
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin>>n>>m;
    b.resize(n, vb(m));
    vvb b2(m, vb(n));
    loop(i,0,n){
        string s; cin>>s;
        loop(j,0,m) b[i][j] = b2[j][i] = s[j]=='#';
    }
    if (!check(b)) return cout<<-1<<endl,0;
    if (!check(b2)) return cout<<-1<<endl,0;
    int ans = 0;
    loop(i,0,n) loop(j,0,m) if (b[i][j]) dfs({i,j}), ans++;
    cout<<ans<<endl;
    return 0;
}
/*
color a
cls
g++ b.cpp -o a & a
3 3
.#.
###
##.

*/