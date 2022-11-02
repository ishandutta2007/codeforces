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
const int MAXM = 17;

int n,m;
LL h[MAXN],pre[MAXN];

struct Node{
    LL mx,cmx;
    int ps,cps;
    Node(LL mx=-1e18,int ps=-1,LL cmx=-1e18,int cps=-1) : mx(mx),ps(ps),cmx(cmx),cps(cps) {};
    
    inline Node operator + (const Node &t) const {
        Node res;
        if(mx > t.mx){
            res.mx = mx;res.ps = ps;
            if(cmx > t.mx){
                res.cmx = cmx;
                res.cps = cps;
            }
            else{
                res.cmx = t.mx;
                res.cps = t.ps;
            }
        }
        else{
            res.mx = t.mx;res.ps = t.ps;
            if(mx > t.cmx){
                res.cmx = mx;
                res.cps = ps;
            }
            else{
                res.cmx = t.cmx;
                res.cps = t.cps;
            }
        }
        return res;
    }
}sm[2][MAXN<<2];
#define lc ((x)<<1)
#define rc ((x)<<1|1)

inline void build(int x,int l,int r){
    if(l == r){
        sm[0][x] = Node(2*h[l]-pre[l],l);
        sm[1][x] = Node(2*h[l]+pre[l],l);
        return;
    }
    int mid = (l + r) >> 1;
    build(lc,l,mid);build(rc,mid+1,r);
    sm[0][x] = sm[0][lc]+sm[0][rc];
    sm[1][x] = sm[1][lc]+sm[1][rc];
}

inline Node query(int o,int x,int l,int r,int L,int R){
    if(l == L && r == R) return sm[o][x];
    int mid = (l + r) >> 1;
    if(R <= mid) return query(o,lc,l,mid,L,R);
    if(L > mid) return query(o,rc,mid+1,r,L,R);
    return query(o,lc,l,mid,L,mid)+query(o,rc,mid+1,r,mid+1,R);
}

int main(){
    scanf("%d%d",&n,&m);
    FOR(i,1,n) scanf("%lld",pre+i);
    FOR(i,1,n) scanf("%lld",h+i);
    FOR(i,n+1,2*n) pre[i] = pre[i-n],h[i] = h[i-n];
    ROF(i,2*n-1,1) pre[i+1] = pre[i];pre[1] = 0;
    FOR(i,1,2*n) pre[i] += pre[i-1];
    build(1,1,2*n);
    while(m--){
        int l,r;scanf("%d%d",&l,&r);
        if(l <= r){
            int tl=l,tr=r;
            l = tr+1;r = n+tl-1;
        }
        else{
            std::swap(l,r);
            ++l;--r;
        }
        Node m1 = query(0,1,1,2*n,l,r),m2 = query(1,1,1,2*n,l,r);
        LL ans = 0;
        if(m1.ps != m2.ps) ans = m1.mx+m2.mx;
        else ans = std::max(m1.cmx+m2.mx,m1.mx+m2.cmx);
        printf("%lld\n",ans);
    }
    return 0;
}