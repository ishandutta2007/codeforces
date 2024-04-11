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

const int MAXN = 5e4 + 5;
int ha;

inline void add(int &x,int y){
    x += y-ha;x += x>>31&ha;
}

inline int mod(int x){
    x -= ha;x += x>>31&ha;return x;
}

struct Node{
    int a[2][2];
    Node(){CLR(a,0);}

    inline Node operator * (const Node &t) const {
        Node res;
        res.a[0][0]=(1ll*a[0][0]*t.a[0][0]+1ll*a[0][1]*t.a[1][0])%ha;
		res.a[0][1]=(1ll*a[0][0]*t.a[0][1]+1ll*a[0][1]*t.a[1][1])%ha;
		res.a[1][0]=(1ll*a[1][0]*t.a[0][0]+1ll*a[1][1]*t.a[1][0])%ha;
		res.a[1][1]=(1ll*a[1][0]*t.a[0][1]+1ll*a[1][1]*t.a[1][1])%ha;
        return res;
    }

    friend std::ostream& operator << (std::ostream &out,Node x){
        out << '\n';
        FOR(i,0,1){
            out << '{';
            FOR(j,0,1){
                out << x.a[i][j];
                if(j == 0) out << ',';
            }
            out << '}' << '\n';
        }
        return out;
    }
}zero;

inline Node get(int a,int b){
    Node res;res.a[0][0] = a;res.a[0][1] = b;res.a[1][0] = 1;
    return res;
}

inline Node qpow(Node a,LL n){
    Node res=zero;
    while(n){
        if(n&1) res = res*a;
        a = a*a;
        n >>= 1;
    }
    return res;
}

LL k;
int n,m,s[MAXN];
Node a[MAXN],res,all;

Node sm[MAXN<<2];
#define lc ((x)<<1)
#define rc ((x)<<1|1)

inline void build(int x,int l,int r){
    if(l == r){
        sm[x] = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(lc,l,mid);build(rc,mid+1,r);
    sm[x] = sm[rc]*sm[lc];
}

inline Node query(int x,int l,int r,int L,int R){
    if(L > R) return zero;
    if(l == L && r == R) return sm[x];
    int mid = (l + r) >> 1;
    if(R <= mid) return query(lc,l,mid,L,R);
    if(L > mid) return query(rc,mid+1,r,L,R);
    return query(rc,mid+1,r,mid+1,R)*query(lc,l,mid,L,mid);
}

inline Node calc(LL l,LL r){// a[i] = a[i%n], prod(l..r) a[i]
    if(l > r) return zero;
    if(l/n == r/n) return query(1,0,n-1,l%n,r%n);
    return query(1,0,n-1,0,r%n)*qpow(all,r/n-l/n-1)*query(1,0,n-1,l%n,n-1);
}

LL pos[MAXN];
std::map<LL,int> S;

inline int val(LL x){
    if(S.find(x) != S.end()) return S[x];
    return s[x%n];
}

int main(){
//    freopen("A.in","r",stdin);
//    freopen("A.out","w",stdout);
    scanf("%lld%d",&k,&ha);zero.a[0][0] = zero.a[1][1] = 1;
    if(ha == 1){
        puts("0");
        return 0;
    }
    if(k == 0){
        puts("0");
        return 0;
    }
    if(k == 1){
        puts("1");
        return 0;
    }
    scanf("%d",&n);FOR(i,0,n-1) scanf("%d",s+i),s[i] %= ha;
    FOR(i,0,n-1) a[i] = get(s[(i+1)%n],s[i]);build(1,0,n-1);all = sm[1];
    res = zero;scanf("%d",&m);LL now = 0;--k;
    FOR(i,1,m){
        LL p;int v;scanf("%lld%d",&p,&v);S[p] = v;
        pos[i] = p;
    }
    std::sort(pos+1,pos+m+1);
    // 0..k-1
    FOR(i,1,m){
        LL p=pos[i];
        // (p-1,p)  (p,p+1)
        if(now <= p-2){
            res = calc(now,std::min(k-1,p-2))*res;
            now = p-1;
        }
        if(p-1 <= k-1 && now <= p-1){
            res = get(val(p),val(p-1))*res;
            now = p;
        }
        if(p <= k-1 && now <= p){
            res = get(val(p+1),val(p))*res;
            now = p+1;
        }
    }
    res = calc(now,k-1)*res;
    printf("%d\n",res.a[0][0]);
    return 0;
}