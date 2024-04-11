#include <bits/stdc++.h>

#define fi first
#define se second
#define db double
#define U unsigned
#define P std::pair<LL,LL>
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl
#define int LL
const int MAXN = 4e5+ 5;

LL sm[MAXN<<2];int sz[MAXN<<2];
#define lc ((x)<<1)
#define rc ((x)<<1|1)

inline void update(int x,int l,int r,int p,int d){
    if(l == r){
        sm[x] += d*l;
        sz[x] += d;
        return;
    }
    int mid = (l + r) >> 1;
    if(p <= mid) update(lc,l,mid,p,d);
    else update(rc,mid+1,r,p,d);
    sm[x] = sm[lc]+sm[rc];
    sz[x] = sz[lc]+sz[rc];
}

inline LL query(int x,int l,int r,int k){
    if(l == r) return 1ll*std::min(k,sz[x])*l;
    int mid = (l + r) >> 1;
    int ans = 0;
    if(sz[lc] < k) return sm[lc]+query(rc,mid+1,r,k-sz[lc]);
    else if(sz[lc] == k) return sm[lc];
    else return query(lc,l,mid,k);
}

int m;
std::vector<LL> S1,S2,S3,S4;
int t[MAXN],x[MAXN],y[MAXN];
int M = 1e4;

inline void Solve(){
    int n,k;scanf("%lld%lld%lld",&n,&m,&k);
    S1.pb(0);S2.pb(0);S3.pb(0);
    FOR(i,1,n){
        int t,x,y;scanf("%lld%lld%lld",&t,&x,&y);
        ::t[i] = t;::x[i] = x;::y[i] = y;
        if(x == 1 && y == 0) S1.pb(t);
        if(x == 0 && y == 1) S2.pb(t);
        if(x == 1 && y == 1) S3.pb(t),update(1,1,M,t,1);
        if(x == 0 && y == 0) update(1,1,M,t,1);
    }
    std::sort(all(S1));std::sort(all(S2));std::sort(all(S3));
    FOR(i,1,(int)S1.size()-1) S1[i] += S1[i-1];
    FOR(i,1,(int)S2.size()-1) S2[i] += S2[i-1];
    FOR(i,1,(int)S3.size()-1) S3[i] += S3[i-1];
    FOR(i,k+1,(int)S1.size()-1) update(1,1,M,S1[i]-S1[i-1],1);
    FOR(i,k+1,(int)S2.size()-1) update(1,1,M,S2[i]-S2[i-1],1);
    LL ans = 1e18,ps = -1;
    FOR(i,0,std::min(k,(int)S3.size()-1)){
        int t = k-i,tt = m-k*2+i;
        // cal
        if(tt >= 0 && tt <= sz[1] && t < S1.size() && t < S2.size()){
            if(i == 1){
//                DEBUG(query(1,1,M,tt));
            }
            LL res = query(1,1,M,tt)+S1[t]+S2[t]+S3[i];
            if(ans > res){
                ans = res;ps = i;
            }
        }
        if(t && t < S1.size()){
            update(1,1,M,S1[t]-S1[t-1],1);
        }
        if(t && t < S2.size()){
            update(1,1,M,S2[t]-S2[t-1],1);
        }
        if(i+1 < S3.size()) update(1,1,M,S3[i+1]-S3[i],-1);
    }
    if(ans == 1e18){
        puts("-1");return;
    }
    printf("%lld\n",ans);LL smm = 0;
    int t = k-ps,tt = m-k*2+ps;
    std::vector<P> S,ext;
    FOR(i,1,n) if(x[i] == 1 && y[i] == 0) S.pb(MP(::t[i],i));
    std::sort(all(S));
    FOR(i,0,t-1) printf("%lld ",S[i].se),smm += S[i].fi;
    FOR(i,t,(int)S.size()-1) ext.pb(S[i]);S.clear();
    FOR(i,1,n) if(x[i] == 0 && y[i] == 1) S.pb(MP(::t[i],i));
    std::sort(all(S));
    FOR(i,0,t-1) printf("%lld ",S[i].se),smm += S[i].fi;
    FOR(i,t,(int)S.size()-1) ext.pb(S[i]);S.clear();
    FOR(i,1,n) if(x[i] == 0 && y[i] == 0) ext.pb(MP(::t[i],i));
    FOR(i,1,n) if(x[i] == 1 && y[i] == 1) S.pb(MP(::t[i],i));
    std::sort(all(S));
    FOR(i,0,ps-1) printf("%lld ",S[i].se),smm += S[i].fi;
    FOR(i,ps,(int)S.size()-1) ext.pb(S[i]);
    std::sort(all(ext));
    FOR(i,0,tt-1) printf("%lld ",ext[i].se),smm += ext[i].fi;
    puts("");assert(smm==ans);
}

signed main(){
    Solve();
    return 0;
}