/*
 * Author: RainAir
 * Time: 2020-03-06 10:49:54
 */
#include<bits/stdc++.h>

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

const int MAXN = 3e5 + 5;

int sm[MAXN<<5],lc[MAXN<<5],rc[MAXN<<5],root[MAXN],tot;

inline void insert(int prev,int &v,int l,int r,int p){
    sm[v=++tot] = sm[prev]+1;lc[v]=lc[prev];rc[v]=rc[prev];
    if(l == r) return;
    int mid=(l+r)>>1;
    if(p<=mid)insert(lc[prev],lc[v],l,mid,p);
    else insert(rc[prev],rc[v],mid+1,r,p);
}

inline int query(int x,int y,int l,int r,int L,int R){
    if(l == L && r == R) return sm[y]-sm[x];
    int mid = (l+r)>>1;
    if(R <= mid) return query(lc[x],lc[y],l,mid,L,R);
    if(L > mid) return query(rc[x],rc[y],mid+1,r,L,R);
    return query(lc[x],lc[y],l,mid,L,mid)+query(rc[x],rc[y],mid+1,r,mid+1,R);
}

struct BIT{
    int tree[MAXN];
    #define lb(x) ((x)&(-(x)))
    inline void add(int pos,int x){
        for(;pos<MAXN;pos+=lb(pos)) tree[pos] += x;
    }

    inline int qry(int pos){
        if(!pos) return 0;
        int res = 0;
        for(;pos;pos-=lb(pos)) res+=tree[pos];
        return res;
    }
    #undef lb
}T;

int n,m;
int a[MAXN];
int vis[MAXN],pre[MAXN];
int ans1[MAXN],ans2[MAXN];
int main(){
    scanf("%d%d",&n,&m);
    FOR(i,1,m) scanf("%d",a+i);
    FOR(i,1,n) ans1[i] = ans2[i] = i;
    FOR(i,1,m){
        if(!vis[a[i]]){
            ans2[a[i]] = std::max(ans2[a[i]],a[i]+T.qry(n)-T.qry(a[i]));
            T.add(a[i],1);
        }
        pre[i] = vis[a[i]];
        vis[a[i]] = i;
    }
    FOR(i,1,n) ans1[i] = vis[i]?1:i;
    FOR(i,1,n) if(!vis[i]) ans2[i] = i+T.qry(n)-T.qry(i);
    FOR(i,1,m) insert(root[i-1],root[i],0,m,pre[i]);
//                DEBUG(query(root[0],root[m],0,m,0,0));
//            FOR(i,1,m) DEBUG(pre[i]);
//            exit(0);
    FOR(i,1,m){
        if(!pre[i]) continue;
        int l = pre[i],r = i;
        ans2[a[i]] = std::max(ans2[a[i]],query(root[l-1],root[r-1],0,m,0,l-1));
    }
    FOR(i,1,n){
        if(vis[i] && vis[i] != m){
            int l = vis[i],r = m;
            ans2[i] = std::max(ans2[i],query(root[l-1],root[r],0,m,0,l-1));
        }
    }
    FOR(i,1,n) printf("%d %d\n",ans1[i],ans2[i]);
    return 0;
}