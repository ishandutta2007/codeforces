#include <bits/stdc++.h>

#define fi first
#define se second
#define DB double
#define U unsigned
#define P std::pair
#define LL long long
#define LD long double
#define pb emplace_back
#define MP std::make_pair
#define SZ(x) ((int)x.size())
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 35000 + 5;
int mn[MAXN<<2],tag[MAXN<<2];
int f[2][MAXN],now;
#define lc ((x)<<1)
#define rc ((x)<<1|1)

inline void build(int x,int l,int r){
    mn[x] = tag[x] = 0;
    if(l == r){
        mn[x] = f[now][l];
        return;
    }
    int mid = (l + r) >> 1;
    build(lc,l,mid);build(rc,mid+1,r);
    mn[x] = std::min(mn[lc],mn[rc]);
}

inline void cover(int x,int d){
    mn[x] += d;tag[x] += d;
}

inline void pushdown(int x){
    if(tag[x]){
        cover(lc,tag[x]);
        cover(rc,tag[x]);
        tag[x] = 0;
    }
}

inline void modify(int x,int l,int r,int L,int R,int d){
    if(l == L && r == R) return cover(x,d);
    int mid = (l + r) >> 1;pushdown(x);
    if(R <= mid) modify(lc,l,mid,L,R,d);
    else if(L > mid) modify(rc,mid+1,r,L,R,d);
    else modify(lc,l,mid,L,mid,d),modify(rc,mid+1,r,mid+1,R,d);
    mn[x] = std::min(mn[lc],mn[rc]);
}

inline int query(int x,int l,int r,int L,int R){
    if(l == L && r == R) return mn[x];
    int mid = (l + r) >> 1;pushdown(x);
    if(R <= mid) return query(lc,l,mid,L,R);
    if(L > mid) return query(rc,mid+1,r,L,R);
    return std::min(query(lc,l,mid,L,mid),query(rc,mid+1,r,mid+1,R));
}

int n,k,a[MAXN];
int lst[MAXN],pre[MAXN];

int main(){
    scanf("%d%d",&n,&k);
    FOR(i,1,n){
        scanf("%d",a+i);
        pre[i] = lst[a[i]];
        lst[a[i]] = i;
    }
    CLR(f[now=0],0x3f);f[now][0] = 0;
    FOR(i,1,k){
        build(1,0,n);
        CLR(f[now^1],0x3f);
        FOR(j,1,n){
            if(pre[j]) modify(1,0,n,0,pre[j]-1,j-pre[j]);
            f[now^1][j] = query(1,0,n,0,j-1);
        }
        now ^= 1;
//        if(i == 2){
//            DEBUG(f[now][2]);
//        }
    }
    printf("%d\n",f[now][n]);
    return 0;
}