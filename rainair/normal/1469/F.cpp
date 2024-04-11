#include <bits/stdc++.h>

#define fi first
#define se second
#define DB double
#define U unsigned
#define P std::pair
#define LL long long
#define LD long double
#define pb push_back
#define MP std::make_pair
#define SZ(x) ((int)x.size())
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 4e5 + 5;
int n,k;
int a[MAXN];
LL sm[MAXN<<2],tag[MAXN<<2];
#define lc ((x)<<1)
#define rc ((x)<<1|1)

inline void cover(int x,int l,int r,int d){
    sm[x] += (r-l+1)*d;tag[x] += d;
}

inline void pushdown(int x,int l,int r){
    if(tag[x]){
        int mid = (l + r) >> 1;
        cover(lc,l,mid,tag[x]);cover(rc,mid+1,r,tag[x]);tag[x] = 0;
    }
}

inline void modify(int x,int l,int r,int L,int R,int d){
    if(l == L && r == R) return cover(x,l,r,d);
    int mid = (l + r) >> 1;pushdown(x,l,r);
    if(R <= mid) modify(lc,l,mid,L,R,d);
    else if(L > mid) modify(rc,mid+1,r,L,R,d);
    else modify(lc,l,mid,L,mid,d),modify(rc,mid+1,r,mid+1,R,d);
    sm[x] = sm[lc]+sm[rc];
}

inline int query(int x,int l,int r,LL k){
    if(sm[x] < k) return -1;
    if(l == r) return l;
    int mid = (l + r) >> 1;pushdown(x,l,r);
    if(k <= sm[lc]) return query(lc,l,mid,k);
    else return query(rc,mid+1,r,k-sm[lc]);
}

int M = 4e5;

int main(){
    scanf("%d%d",&n,&k);
    FOR(i,1,n) scanf("%d",a+i);
    std::sort(a+1,a+n+1);std::reverse(a+1,a+n+1);
    modify(1,1,M,1,1,1);int ans = 1e9;
    FOR(i,1,n){
        int j = query(1,1,M,1);
        modify(1,1,M,j+2,j+2+(a[i]/2)-1,1);
        modify(1,1,M,j+2,j+2+((a[i]-1)/2)-1,1);
        modify(1,1,M,j,j,-1);
        int t = query(1,1,M,k);
        if(t != -1) ans = std::min(ans,t);
    }
    if(ans == 1e9) ans = 0;
    printf("%d\n",ans-1);
    return 0;
}