#include <bits/stdc++.h>
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
const int INF = 4e18, MOD = 1e9+7;

struct Seg{ //persistent lazy propogation Segment tree
    int l,r,mid, amt;
    int v=0;
    int prop=0; bool resp=0;
    Seg *lp=NULL,*rp=NULL;
    Seg(int _l, int _r): l(_l), r(_r), mid((_l+_r)/2), amt(_r-_l+1){}
    Seg* copy(){
        return new Seg(*this);
    }
    Seg* setx(int x){
        Seg* ns = copy();
        ns->prop = x; 
        ns->resp = 1; 
        ns->v = x * ns->amt;
        return ns;
    }
    void fix(){
        if (!lp) lp = new Seg(l, mid);
        if (!rp) rp = new Seg(mid+1, r);
        if (resp){
            lp = lp->setx(prop); 
            rp = rp->setx(prop);
            resp = 0;
        }
        v = lp->v + rp->v;
    }
    Seg* update(int a, int b, int x){
        if (a>r || b<l) return this;
        if (a<=l && r<=b) return setx(x);
        fix();
        Seg* ns = copy();
        ns->lp = lp->update(a,b,x);
        ns->rp = rp->update(a,b,x);
        ns->fix();
        return ns;
    }
    int query(){
        return v;
    }
};


int n,m;
bool in(int x, int y){
    return x>=0 && x<n && y>=0 && y<m;
}
int conv(int x, int y){
    if (!in(x,y)) return -1;
    return x * m + y;
}
ii back_conv(int c){
    return {c/m,c%m};
}
map<char, int> mconv = {{'U',0},{'D',1},{'L',2},{'R',3}};
ii dir[] = {{1,0},{-1,0},{0,1},{0,-1}};

vi board;
vvi g;
vi degin;

vi tin, tout;
vi order;
void dfs(int cur){
    tin[cur] = order.size();
    order.pb(cur);
    for(int nei:g[cur])  dfs(nei);
    tout[cur] = order.size() - 1;
}
int64_t ans = 0;
void dfs2(int cur, Seg* seg){
    ii pos = back_conv(cur), d = dir[board[cur]];
    int other = conv(pos.x + d.x, pos.y + d.y);
    Seg* ns = seg->update(tin[other], tout[other], 1); 
    ans += ns->query();
    for(auto nei:g[cur]) dfs2(nei, ns);
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin>>n>>m;
    g.resize(n*m); degin.resize(n*m,0);
    board.resize(n*m);
    loop(i,0,n){
        string s; cin>>s;
        loop(j,0,m){
            int me = conv(i,j);
            board[me] = mconv[s[j]];
            ii& d = dir[board[me]];
            int ind = conv(i+2*d.x,j+2*d.y);
            if (ind!=-1){
                g[ind].pb(me), degin[me]++;
            } 
        }
    }
    tin.resize(n*m,-1); tout.resize(n*m,-1);
    loop(i,0,n) loop(j,0,m) if ((i+j)%2==1 && degin[conv(i,j)]==0) {
        dfs(conv(i,j));
    }
    loop(i,0,n) loop(j,0,m) if ((i+j)%2==1 && tin[conv(i,j)]==-1) cout<<"FUCK!"<<endl;
    Seg* seg = new Seg(0,order.size());
    loop(i,0,n) loop(j,0,m) if ((i+j)%2==0 && degin[conv(i,j)]==0) {
        dfs2(conv(i,j), seg);
    }
    cout<<ans<<endl;
    return 0;
}
/*
color a
cls
g++ g.cpp -o a & a
10 10
LRLRUUUULR
LRLRDDDDUU
UULRUULRDD
DDLRDDLRUU
UULRUUUUDD
DDUUDDDDLR
LRDDLRLRLR
ULRULRULRU
DLRDUUDLRD
LRLRDDLRLR
*/