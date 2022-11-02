#include <bits/stdc++.h>

#define fi first
#define se second
#define db double
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

const int MAXN = 2e5 + 5;
std::mt19937 g(time(NULL));

int val[MAXN],ans[MAXN],tag1[MAXN],tag2[MAXN];
int ch[MAXN][2];unsigned rnd[MAXN];
#define lc (ch[x][0])
#define rc (ch[x][1])

inline void cover(int x,int d1,int d2){
    if(!x) return;
    val[x] += d1;tag1[x] += d1;
    ans[x] += d2;tag2[x] += d2;
}

inline void pushdown(int x){
    if(lc) cover(lc,tag1[x],tag2[x]);
    if(rc) cover(rc,tag1[x],tag2[x]);
    tag1[x] = tag2[x] = 0;
}

inline void split(int x,int &l,int &r,int k){
    if(!x){
        l = r = 0;
        return;
    }
    pushdown(x);
    if(val[x] <= k) l = x,split(rc,ch[l][1],r,k);
    else r = x,split(lc,l,ch[r][0],k);
}

int rt;

inline int merge(int x,int y){
    if(!x || !y) return x|y;
    pushdown(x);pushdown(y);
    if(rnd[x] < rnd[y]){
        ch[x][1] = merge(ch[x][1],y);
        return x;
    }
    else{
        ch[y][0] = merge(x,ch[y][0]);
        return y;
    }
}

inline void insert(int v){
    ch[v][0] = ch[v][1] = 0;
    int l=0,r=0;split(rt,l,r,val[v]);
    rt = merge(l,v);
    rt = merge(rt,r);
    //DEBUG(rt);DEBUG(ch[2][0]);
}

int n;
P a[MAXN];
int c[MAXN],b[MAXN];

inline bool cmp(P a,P b){
    if(a.se != b.se) return a.se > b.se;
    return a.fi < b.fi;
}

std::vector<int> S;

inline void dfs(int v){
    pushdown(v);
    if(ch[v][0]) dfs(ch[v][0]);
    S.pb(v);
    if(ch[v][1]) dfs(ch[v][1]);
}

inline void pushtag(int v){
    pushdown(v);
    if(ch[v][0]) pushtag(ch[v][0]);
    if(ch[v][1]) pushtag(ch[v][1]);
}

int main(){
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d%d",&a[i].fi,&a[i].se);
    std::sort(a+1,a+n+1,cmp);FOR(i,1,n) c[i] = a[i].fi;
    int k;scanf("%d",&k);
    FOR(i,1,k){
        scanf("%d",b+i);
        val[i] = b[i];
        rnd[i] = g();
       // rnd[i] = i;
        insert(i);
    }
    //exit(0);
    FOR(i,1,n){
        int v1=0,v2=0,v3=0,v;
        split(rt,v1,v3,2*c[i]);
        cover(v3,-c[i],1);
        v = v1;v1 = 0;
        split(v,v1,v2,c[i]-1);S.clear();
        dfs(v2);rt = v1;
        for(auto x:S) val[x] -= c[i],ans[x]++,insert(x);
        rt = merge(rt,v3);
       // if(i==2) break;
    }
    pushtag(rt);
    //FOR(i,1,k) DEBUG(val[i]);
    FOR(i,1,k) printf("%d ",ans[i]);puts("");
    return 0;
}