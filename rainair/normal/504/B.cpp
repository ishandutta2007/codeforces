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

#define lc ((x)<<1)
#define rc ((x)<<1|1)
int sm[MAXN<<2];

inline void build(int x,int l,int r){
    sm[x] = r-l+1;
    if(l == r) return;
    int mid = (l + r) >> 1;
    build(lc,l,mid);build(rc,mid+1,r);
}

inline void update(int x,int l,int r,int p,int d){
    sm[x] += d;
    if(l == r) return;
    int mid = (l + r) >> 1;
    if(p <= mid) update(lc,l,mid,p,d);
    else update(rc,mid+1,r,p,d);
}

inline int query1(int x,int l,int r,int L,int R){
    if(l == L && r == R) return sm[x];
    int mid = (l + r) >> 1;
    if(R <= mid) return query1(lc,l,mid,L,R);
    else if(L > mid) return query1(rc,mid+1,r,L,R);
    else return query1(lc,l,mid,L,mid)+query1(rc,mid+1,r,mid+1,R);
}

inline int query2(int x,int l,int r,int k){
    if(l == r) return l;
    int mid = (l + r) >> 1;
    if(k <= sm[lc]) return query2(lc,l,mid,k);
    else return query2(rc,mid+1,r,k-sm[lc]);
}

int n,p[MAXN],q[MAXN],a[MAXN];

int main(){
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",p+i),++p[i];
    FOR(i,1,n) scanf("%d",q+i),++q[i];
    build(1,1,n);
    FOR(i,1,n){
        a[i] += query1(1,1,n,1,p[i])-1;
        update(1,1,n,p[i],-1);
    }
    build(1,1,n);
    FOR(i,1,n){
        a[i] += query1(1,1,n,1,q[i])-1;
        update(1,1,n,q[i],-1);
    }
    ROF(i,n-1,1){
        int b = n-i+1;
        a[i-1] += a[i]/b;a[i] %= b;
    }
    build(1,1,n);
    FOR(i,1,n){
        int v = query2(1,1,n,a[i]+1);
        update(1,1,n,v,-1);
        printf("%d%c",v-1," \n"[i==n]);
    }
    return 0;
}