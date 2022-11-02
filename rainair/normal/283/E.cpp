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

const int MAXN = 1e5 + 5;
#define lc ((x)<<1)
#define rc ((x)<<1|1)

int sm0[MAXN<<2],sm1[MAXN<<2],tag[MAXN<<2];

inline void pushup(int x){
    sm0[x] = sm0[lc]+sm0[rc];
    sm1[x] = sm1[lc]+sm1[rc];
}

inline void reverse(int x){
    tag[x] ^= 1;std::swap(sm0[x],sm1[x]);
}

inline void pushdown(int x){
    if(tag[x]){
        reverse(lc);reverse(rc);tag[x] = 0;
    }
}

inline void build(int x,int l,int r){
    sm0[x] = r-l+1;sm1[x] = tag[x] = 0;
    if(l == r) return;
    int mid = (l + r) >> 1;
    build(lc,l,mid);build(rc,mid+1,r);
}

inline void modify(int x,int l,int r,int L,int R){
    if(l == L && r == R) {reverse(x);return;}
    int mid = (l + r) >> 1;pushdown(x);
    if(R <= mid) modify(lc,l,mid,L,R);
    else if(L > mid) modify(rc,mid+1,r,L,R);
    else modify(lc,l,mid,L,mid),modify(rc,mid+1,r,mid+1,R);
    pushup(x);
}

inline int query(int x,int l,int r,int L,int R){
    if(L > R) return 0;
    if(l == L && r == R) return sm1[x];
    int mid = (l + r) >> 1;pushdown(x);
    if(R <= mid) return query(lc,l,mid,L,R);
    if(L > mid) return query(rc,mid+1,r,L,R);
    return query(lc,l,mid,L,mid)+query(rc,mid+1,r,mid+1,R);
}

std::vector<int> S;
int a[MAXN],n,k;
std::vector<P> G[MAXN];

int main(){
    scanf("%d%d",&n,&k);
    FOR(i,1,n) scanf("%d",a+i),S.pb(a[i]);std::sort(all(S));
    FOR(i,1,n) a[i] = std::lower_bound(all(S),a[i])-S.begin()+1;
    FOR(i,1,k){
        int l,r;scanf("%d%d",&l,&r);
        l = std::lower_bound(all(S),l)-S.begin()+1;
        r = std::upper_bound(all(S),r)-S.begin();
        if(l > r) continue;
        G[l].pb(MP(l,r));G[r].pb(MP(l,r));
    }
    build(1,1,n);
    LL ans = 0;
    FOR(i,1,n){
        for(auto x:G[i]) if(x.fi == i) modify(1,1,n,x.fi,x.se);
        LL t = i-1-query(1,1,n,1,i-1)+query(1,1,n,i+1,n);
        if(t) ans += t*(t-1)/2;
        for(auto x:G[i]) if(x.se == i) modify(1,1,n,x.fi,x.se);
    }
//    DEBUG(ans);
    ans = -ans;ans += 1ll*n*(n-1)*(n-2)/6;
    printf("%lld\n",ans);
    return 0;
}
/*
  
(i-1-[1,i-1])+([i+1,n])
 */