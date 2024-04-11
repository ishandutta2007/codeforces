/*
 * Author: RainAir
 * Time: 2019-10-07 09:07:55
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
#define P std::pair<int,int>
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 5e5 + 5;
int n,m,_q;

struct Node{
    int i,from,to;
    Node(int i=0,int from=0,int to=0) : i(i),from(from),to(to) {}
};
std::vector<Node> a[MAXN];
std::vector<int> q[MAXN];
std::vector<P> S[MAXN];
int _[MAXN],u[MAXN],v[MAXN];
int f[MAXN],sz[MAXN];
int ans[MAXN];

inline int find(int x){
    return x == f[x] ? x : find(f[x]);
}

std::stack<P> opt;

inline void Union(int x,int y){
    int fx = find(x),fy = find(y);
    if(fx == fy) return;
    if(sz[fx] < sz[fy]) std::swap(x,y),std::swap(fx,fy);
    opt.push(MP(fy,fx));
    f[fy] = fx;sz[fx] += sz[fy];
}

inline bool cmp(int x,int y){
    return _[x] < _[y];
}

inline void remove(){
    P t = opt.top();opt.pop();
    f[t.fi] = t.fi;sz[t.se] -= sz[t.fi];
}

inline bool chk(int id,int l,int r){
    bool ans = 1;int cnt = 0;
    FOR(i,l,r){
        int p = q[id][i];
        int fx = find(u[p]),fy = find(v[p]);
        if(fx != fy) Union(fx,fy),++cnt;
        else ans = 0;
    }
    FOR(i,1,cnt) remove();
    return ans;
}

int main(){
    scanf("%d%d",&n,&m);
    FOR(i,1,m){
        int u,v,w;scanf("%d%d%d",&u,&v,&w);
        ::u[i] = u;::v[i] = v;_[i] = w;S[w].pb(MP(u,v));
    }
    scanf("%d",&_q);
    FOR(i,1,_q){
        int k;scanf("%d",&k);
        FOR(_,1,k){
            int x;scanf("%d",&x);
            q[i].pb(x);
        }
        std::sort(all(q[i]),cmp);
        int t = 0;
        FOR(j,1,(int)q[i].size()-1){
            if(_[q[i][j]] != _[q[i][j-1]]){
                a[_[q[i][j-1]]].pb(Node(i,t,j-1));
                t = j;
            }
        }
        a[_[q[i][(int)q[i].size()-1]]].pb(Node(i,t,(int)q[i].size()-1));
    }
    FOR(i,1,n) f[i] = i,sz[i] = 1;
    FOR(i,1,MAXN-1){
        for(auto x:a[i]) if(!chk(x.i,x.from,x.to)) ans[x.i] = true;
        for(auto x:S[i]) Union(x.fi,x.se);
    }
    FOR(i,1,_q) puts(ans[i] ? "NO" : "YES");
    return 0;
}