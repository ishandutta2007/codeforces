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

const int MAXN = 2e5 + 5;
int n,a[MAXN];

struct Node{
    LL x,y;
    inline Node(LL x=0,LL y=0) : x(x),y(y) {}

    inline Node operator - (const Node &t) const {
        return Node(x-t.x,y-t.y);
    }

    inline LL operator * (const Node &t) const {
        return x*t.y-y*t.x;
    }
}st[MAXN];int tp;

LL sm[MAXN],smi[MAXN];

inline LL calc(Node p,int x){
    return -p.x*sm[x]+p.y+smi[x];
}

int main(){
    scanf("%d",&n);FOR(i,1,n) scanf("%d",a+i);
    FOR(i,1,n) sm[i] = sm[i-1]+a[i],smi[i] = smi[i-1]+1ll*a[i]*i;
    st[tp = 1] = Node(0,0);
    LL ans = 0;
    FOR(i,1,n){
//        FOR(j,1,tp) DEBUG(calc(st[j],i));
//        puts("");
        int l = 1,r = tp-1;ans = std::max(ans,calc(st[tp],i));
        while(l <= r){
            int mid = (l + r) >> 1;
            LL ls = calc(st[mid],i),rs = calc(st[mid+1],i);
            ans = std::max({ans,ls,rs});
            if(ls <= rs) l = mid+1;
            else r = mid-1;
        }
        Node p(i,i*sm[i]-smi[i]);
        while(tp >= 2 && (st[tp]-st[tp-1])*(p-st[tp]) >= 0) --tp;
        st[++tp] = p;
    }
    printf("%lld\n",ans);
    return 0;
}
/*
smi[r]-smi[l-1]-(l-1)*(sm[r]-sm[l-1])
smi[r]-smi[l]-l*sm[r]+l*sm[l]
-l*sm[r]-smi[l]+l*sm[l]+smi[r]
*/