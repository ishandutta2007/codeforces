#pragma GCC optimize("Ofast")
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
#define int LL
inline char nc(){
    #define SIZE 1000000+3
    static char buf[SIZE],*p1 = buf+SIZE,*p2 = buf+SIZE;
    if(p1 == p2){
        p1 = buf;p2 = buf+fread(buf,1,SIZE,stdin);
        if(p1 == p2) return -1;
    }
    return *p1++;
    #undef SIZE
}

template <typename T>
inline void read(T &x){
    x = 0;int flag = 0;char ch = nc();
    while(!isdigit(ch)){
        if(ch == '-') flag = 1;
        ch = nc();
    }
    while(isdigit(ch)){
        x = (x<<1) + (x<<3) + (ch^'0');
        ch = nc();
    }
    if(flag) x = -x;
}

const int MAXN = 4e5 + 3;
const LL ha = 75161927681;
const int G = 3;
const LL iG = 25053975894ll;


inline LL mul(LL x,LL y){
    return (x*y-(LL)((long double)x/ha*y+0.5)*ha+ha)%ha;
}

inline LL qpow(LL a,LL n=ha-2){
	LL res = 1;
	while(n){
		if(n & 1) res = mul(res,a);
		a = mul(a,a);
		n >>= 1;
	}
	return res;
}

inline void add(LL &x,LL y){
    (x += y);if(x >= ha) x -= ha;
}

int r[MAXN],N;
LL inv;

inline void init(int n){
    int len = 0;N = 1;while(N <= n) N <<= 1,++len;
    FOR(i,0,N-1) r[i] = r[i>>1]>>1|((i&1)<<(len-1));
    inv = qpow(N);
}

LL W[MAXN],Wn[MAXN];

inline void prework(){
    FOR(i,0,20){
        W[i] = qpow(G,(ha-1)/(1<<(i+1)));
        Wn[i] = qpow(iG,(ha-1)/(1<<(i+1)));
    }
}

inline void NTT(LL A[],int opt){
    //A.ext(N);
    if(!W[0]) prework();
    FOR(i,0,N-1) if(i < r[i]) std::swap(A[i],A[r[i]]);
    for(int mid = 1,cnt = 0;mid < N;mid <<= 1,++cnt){
        LL W = opt==1?(::W[cnt]):(::Wn[cnt]);
        for(int i = 0;i < N;i += (mid<<1)){
            for(LL w=1,j = 0;j < mid;++j,w = mul(w,W)){
                LL x = A[i+j],y = mul(w,A[i+mid+j]);
                A[i+j] = x;add(A[i+j],y);
                A[i+mid+j] = x;add(A[i+mid+j],ha-y);
            }
        }
    }
    if(opt == -1) FOR(i,0,N-1) A[i] = mul(A[i],inv);
}

int n,m,q;
int a[MAXN],b[MAXN];
int mxa[MAXN],mxb[MAXN],mna[MAXN],mnb[MAXN];
// 1: >=  2: < 
//Poly D,H1,H2,L1,L2,G1,G2;
LL D[MAXN],H1[MAXN],H2[MAXN],L1[MAXN],L2[MAXN],G1[MAXN],G2[MAXN];
LL A[MAXN],B[MAXN],mxA[MAXN],mxB[MAXN],mnA[MAXN],mnB[MAXN];
// D: 
// H: 
// L: 
// G: 
signed main(){
    read(n);read(m);read(q);
    FOR(i,1,n) read(a[i]);
    FOR(i,1,m) read(b[i]);
    FOR(i,1,n-1) mxa[i] = std::max(a[i],a[i+1]),mna[i] = std::min(a[i],a[i+1]);
    FOR(i,1,m-1) mxb[i] = std::max(b[i],b[i+1]),mnb[i] = std::min(b[i],b[i+1]);
    init(2e5);
    FOR(i,1,n) A[a[i]]++;FOR(i,1,m) B[b[i]]++;
    FOR(i,1,n-1) mxA[mxa[i]]++,mnA[mna[i]]++;
    FOR(i,1,m-1) mxB[mxb[i]]++,mnB[mnb[i]]++;
    NTT(A,1);NTT(B,1);NTT(mxA,1);NTT(mxB,1);NTT(mnA,1);NTT(mnB,1);
    FOR(i,0,N-1){
        H1[i] = mul(A[i],mnB[i]);
        H2[i] = mul(A[i],mxB[i]);
        L1[i] = mul(mnA[i],B[i]);
        L2[i] = mul(mxA[i],B[i]);
        G1[i] = mul(mnA[i],mnB[i]);
        G2[i] = mul(mxA[i],mxB[i]);
        D[i] = mul(A[i],B[i]);
    }
    NTT(H1,-1);NTT(H2,-1);NTT(L1,-1);NTT(L2,-1);NTT(G1,-1);NTT(G2,-1);NTT(D,-1);
    ROF(i,2e5-1,0) H1[i] += H1[i+1],L1[i] += L1[i+1],G1[i] += G1[i+1],D[i] += D[i+1];
    FOR(i,1,2e5) H2[i] += H2[i-1],L2[i] += L2[i-1],G2[i] += G2[i-1];
    while(q--){
        int x;read(x);
        LL V1 = D[x],V2 = 1ll*n*m-D[x];
        LL E1 = H1[x]+L1[x],E2 = H2[x-1]+L2[x-1];
        LL Q1 = G1[x],Q2 = G2[x-1];
        printf("%lld\n",V1-V2-E1+E2+Q1-Q2);
    }
    return 0;
}