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

const int MAXN = 4e4+5;
const int MAXM = 2e5+5;
const int ha = 998244353;

inline int qpow(int a,int n=ha-2){
	int res = 1;
	while(n){
		if(n & 1) res = 1ll*res*a%ha;
		a = 1ll*a*a%ha;
		n >>= 1;
	}
	return res;
}

int n,a[MAXN],b[MAXN];
int sz[MAXN];
int f[2][MAXN],now;
int fac[MAXM],inv[MAXM];

inline int C(int n,int m){
    return n < 0 || m < 0 || n < m ? 0 : 1ll*fac[n]*inv[m]%ha*inv[n-m]%ha;
}

inline void add(int &x,int y){
    x += y-ha;x += x>>31&ha;
}

int r[MAXN<<2],N;
int W[MAXN<<2];

inline void init(int n){
    N = 1;int len = 0;while(N <= n) N <<= 1,++len;
    FOR(i,0,N-1) r[i] = (r[i>>1]>>1)|((i&1)<<(len-1));
}

inline void mod(int &x){
    x += x>>31&ha;
}

inline void NTT(int A[]){
    FOR(i,0,N-1) if(i < r[i]) std::swap(A[i],A[r[i]]);
    int *w = W;
    for(int mid = 1;mid < N;mid <<= 1){
        for(int i = 0;i < N;i += (mid<<1)){
            for(int j = 0,*x = A+i,*y = A+i+mid;j < mid;++j,++x,++y){
                int t = 1ll*w[j]*(*y)%ha;
                *y = *x-t;*x += t-ha;
                mod(*x);mod(*y);
            }
        }
        w += (mid<<1);
    }
}

int tmp[MAXN];

inline void mul(int A[],int B[],int C[],int n,int m){
    init(n+m);
    NTT(A);NTT(B);FOR(i,0,N-1) C[i] = 1ll*A[i]*B[i]%ha;
    NTT(C);std::reverse(C+1,C+N);int inv = qpow(N);
    FOR(i,0,n+m) C[i] = 1ll*C[i]*inv%ha;FOR(i,n+m+1,N-1) C[i] = 0;
}

int F[MAXN],G[MAXN],ans[MAXN];

int main(){
//    freopen("A.in","r",stdin);
    fac[0] = 1;FOR(i,1,MAXM-1) fac[i] = 1ll*fac[i-1]*i%ha;
    int *w = W;for(int n = 2,i = 0;i <= 15;++i,n <<= 1) FOR(j,0,n-1) *w = qpow(3,((ha-1)/n)*j),++w;
    inv[MAXM-1] = qpow(fac[MAXM-1]);ROF(i,MAXM-2,0) inv[i] = 1ll*inv[i+1]*(i+1)%ha;
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d%d",a+i,b+i);
    sz[0] = 1;ans[1] = 1;
    FOR(i,1,n){
        sz[i] = sz[i-1]+a[i]-b[i];
        int l = std::max(-b[i],1-sz[i-1]),r = std::min(a[i],sz[i-1]+a[i]-b[i]-1);
        FOR(j,1,sz[i-1]) F[j] = ans[j];
        FOR(j,0,r-l) G[j] = C(a[i]+b[i],b[i]+j+l);
        mul(F,G,tmp,sz[i-1],r-l);
        FOR(j,1,sz[i-1]) ans[j] = 0;
        FOR(j,1,sz[i]) if(j >= l) ans[j] = tmp[j-l];
        FOR(j,0,N) F[j] = G[j] = tmp[j] = 0;
    }
    int res = 0;FOR(i,1,sz[n]) add(res,ans[i]);
    printf("%d\n",res);
    return 0;
}