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

const int MAXN = 2000+5;
int n,m,k;

struct Node{
    int l,r;
    inline bool operator < (const Node &t) const {
        return ((l+r)>>1) < ((t.l+t.r)>>1);
    }
}a[MAXN];
int c1[MAXN],c2[MAXN],c[MAXN];

inline int calc(int l,int r,int L,int R){
    return std::max(0,std::min(r,R)-std::max(l,L)+1);
}

inline void gao(int x){
    int L = a[x].l,R = a[x].r;
    FOR(i,1,n) c[i] = 0;
    FOR(l,1,n-k+1){
        int r = l+k-1;
        c[l] = calc(l,r,L,R);
    }
}

int main(){
    scanf("%d%d%d",&n,&m,&k);
    FOR(i,1,m) scanf("%d%d",&a[i].l,&a[i].r);
    std::sort(a+1,a+m+1);
    FOR(i,1,m){
        gao(i);
        FOR(j,1,n) c2[j] += c[j];
    }
    int ans = 0;
    FOR(i,1,m){
        int mx1=0,mx2=0;
        FOR(i,1,n) mx1 = std::max(mx1,c1[i]),mx2 = std::max(mx2,c2[i]);
        ans = std::max(ans,mx1+mx2);
        gao(i);
        FOR(i,1,n) c1[i] += c[i],c2[i] -= c[i];
    }
    printf("%d\n",ans);
    return 0;
}