/*
 * Author: RainAir
 * Time: 2019-10-04 18:40:31
 */
#include <algorithm>
#include <iostream>
#include <cstring>
#include <climits>
#include <cstdlib>
#include <cstdio>
#include <bitset>
#include <vector>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <map>
#include <set>

#define fi first
#define se second
#define U unsigned
#define P std::pair
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 1e5 + 5;
const int MX = 1e5 + 103;
const int ha = 1e9 + 7;

struct Edge{
    int to,w,nxt;
}e[MAXN<<1];
int head[MAXN],n,m,cnt;

inline void add(int u,int v,int w){
    e[++cnt] = (Edge){v,w,head[u]};head[u] = cnt;
    e[++cnt] = (Edge){u,w,head[v]};head[v] = cnt;
}

int base[MAXN],S,T;
int root[(MAXN<<7)+3],sm[(MAXN<<7)+3],lc[(MAXN<<7)+3],rc[(MAXN<<7)+3],tot;

inline bool insert(int prev,int &v,int l,int r,int p){
    sm[v = ++tot] = sm[prev];lc[v] = lc[prev];rc[v] = rc[prev];
    if(l == r){
        sm[v] ^= 1;
        return sm[v] ^ 1;
    }
    int mid = (l + r) >> 1;
    bool flag = false;
    if(p <= mid){
        flag = insert(lc[prev],lc[v],l,mid,p);
        if(flag) flag = insert(rc[prev],rc[v],mid+1,r,mid+1);
    }
    else flag = insert(rc[prev],rc[v],mid+1,r,p);
    sm[v] = (1ll*sm[lc[v]]+1ll*sm[rc[v]]*base[mid-l+1]%ha)%ha;
    return flag;
}

inline bool compare(int x,int y,int l,int r){ // x < y ?
    if(l == r) return sm[x] < sm[y];
    int mid = (l + r) >> 1;
    return sm[rc[x]] == sm[rc[y]] ? compare(lc[x],lc[y],l,mid) : compare(rc[x],rc[y],mid+1,r);
}

struct Node{
    int v,rt;
    Node(int v=0,int rt=0) : v(v),rt(rt) {}

    inline bool operator < (const Node &t) const {
        return !compare(rt,t.rt,0,MX);
    }
};

int pre[MAXN];
bool sol;

inline void Dij(){
    std::priority_queue<Node> q;q.push(Node(S,root[S]));
    while(!q.empty()){
        Node _ = q.top();q.pop();
        int v = _.v,rt = _.rt;
        if(v == T) sol = true;
        if(rt != root[v]) continue;
        for(int i = head[v];i;i = e[i].nxt){
            int t = 0;
            insert(rt,t,0,MX,e[i].w);
            if(!root[e[i].to] || !compare(root[e[i].to],t,0,MX)){
                root[e[i].to] = t;
                q.push(Node(e[i].to,t));
                pre[e[i].to] = v;
            }
        }
    }
}

std::vector<int> ans;

signed main(){
    scanf("%d%d",&n,&m);
    FOR(i,1,m){
        int u,v,w;scanf("%d%d%d",&u,&v,&w);
        add(u,v,w);
    }
    base[0] = 1;FOR(i,1,MAXN-1) base[i] = (base[i-1]<<1ll)%ha;
    scanf("%d%d",&S,&T);
    Dij();
    if(!sol){
        puts("-1");
        return 0;
    }
    printf("%d\n",sm[root[T]]);
    int v = T;
    while(v != S){
        ans.pb(v);
        v = pre[v];
    }
    ans.pb(S);
    std::reverse(all(ans));
    printf("%d\n",(int)ans.size());
    for(auto x:ans) printf("%d ",x);puts("");
    return 0;
}