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

const int MAXN = 3e5 + 5;

int a[MAXN];
LL f[MAXN][2];
#define lc ((x)<<1)
#define rc ((x)<<1|1)
struct Node{
    LL a[2][2];
    Node(LL x=0){
        CLR(a,0);
        a[0][1] = x;a[1][0] = -x;
    }
    Node operator * (const Node &t) const {
        Node res;
        FOR(i,0,1){
            FOR(j,0,1){
                res.a[i][j] = -1e18;
                FOR(k,0,1){
                    res.a[i][j] = std::max(res.a[i][j],a[i][k]+t.a[k][j]);
                }
            }
        }
        return res;
    }
}sm[MAXN<<2];

inline void build(int x,int l,int r){
    if(l == r){
        sm[x] = Node(a[l]);
        return;
    }
    int mid = (l + r) >> 1;
    build(lc,l,mid);build(rc,mid+1,r);
    sm[x] = sm[lc]*sm[rc];
}

inline void update(int x,int l,int r,int p){
    if(l == r){
        sm[x] = Node(a[l]);return;
    }
    int mid = (l + r) >> 1;
    if(p <= mid) update(lc,l,mid,p);
    else update(rc,mid+1,r,p);
    sm[x] = sm[lc]*sm[rc];
}

inline void Solve(){
    int n,q;scanf("%d%d",&n,&q);
    FOR(i,1,n) scanf("%d",a+i);//f[i][0] = f[i][1] = -1e18;
    build(1,1,n);
    printf("%lld\n",std::max(sm[1].a[0][1],sm[1].a[1][1]));
    while(q--){
        int x,y;scanf("%d%d",&x,&y);
        std::swap(a[x],a[y]);
        update(1,1,n,x);update(1,1,n,y);
        printf("%lld\n",std::max(sm[1].a[0][1],sm[1].a[1][1]));
    }
}

int main(){
    int T;scanf("%d",&T);
    while(T--) Solve();
    return 0;
}