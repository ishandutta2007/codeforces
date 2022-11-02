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

const int MAXN = 3e5 + 5;
const int MAXM = 16;
const int ha = 1e9 + 7;
const DB pi = acos(-1);
LL n;int k;

inline int qpow(int a,int n=ha-2){
	int res = 1;
	while(n){
		if(n & 1) res = 1ll*res*a%ha;
		a = 1ll*a*a%ha;
		n >>= 1;
	}
	return res;
}

inline void add(int &x,int y){
    x += y-ha;x += x>>31&ha;
}

struct CP{
    DB x,y;// x+iy
    CP(DB x=0,DB y=0) : x(x),y(y) {}

    inline CP operator + (const CP &t) const {
        return CP(x+t.x,y+t.y);
    }

    inline CP operator - (const CP &t) const {
        return CP(x-t.x,y-t.y);
    }

    inline CP operator * (const CP &t) const {
        return CP(x*t.x-y*t.y,x*t.y+y*t.x);
    }

    inline CP operator / (const DB &t) const {
        return CP(x/t,y/t);
    }

    inline CP conj(){return CP(x,-y);}
}W[MAXM+1][MAXN];

int r[MAXN],N;

inline void init(int n){
    int len = 0;N = 1;while(N <= n) N <<= 1,++len;
    FOR(i,0,N-1) r[i] = (r[i>>1]>>1)|((i&1)<<(len-1));
}

inline CP Exp(double x){return CP(cos(x),sin(x));}

inline void FFT(CP A[]){
    FOR(i,0,N-1) if(i < r[i]) std::swap(A[i],A[r[i]]);
    for(int mid = 1,cnt = 0;mid < N;mid <<= 1,++cnt){
        CP *w = W[cnt];
        for(int i = 0;i < N;i += (mid<<1)){
            for(int j = 0;j < mid;++j){
                CP x = A[i+j],y = w[j]*A[i+mid+j];
                A[i+j] = x+y;A[i+mid+j] = x-y;
            }
        }
    }
}

const int BASE = 1<<15;
LL A[MAXN],B[MAXN],C[MAXN],D[MAXN];
CP tmp[MAXN],a[MAXN],b[MAXN],c[MAXN],d[MAXN];
CP ac[MAXN],ad[MAXN],bc[MAXN],bd[MAXN];

inline void DFT(LL A[],LL B[],CP a[],CP b[]){
    FOR(i,0,N-1) tmp[i] = CP(A[i],B[i]);
    FFT(tmp);
    FOR(i,0,N-1){
        CP x = tmp[i],y = tmp[i?N-i:0].conj();
        a[i] = (x+y)*CP(0.5,0);
        b[i] = (x-y)*CP(0,-0.5);
    }
}

inline void IDFT(CP a[],CP b[],LL A[],LL B[]){
    FOR(i,0,N-1) tmp[i] = a[i]+CP(0,1)*b[i];
    FFT(tmp);std::reverse(tmp+1,tmp+N);
    FOR(i,0,N-1) A[i] = (LL)(tmp[i].x/N+0.5),B[i] = (LL)(tmp[i].y/N+0.5);
}

inline void mul(int F[],int G[],int R[]){// R = F*G
    FOR(i,0,N-1){
        A[i] = F[i]>>15;B[i] = F[i]&(BASE-1);
        C[i] = G[i]>>15;D[i] = G[i]&(BASE-1);
    }
    DFT(A,B,a,b);DFT(C,D,c,d);
    FOR(i,0,N-1){
        ac[i] = a[i]*c[i];
        ad[i] = a[i]*d[i];
        bc[i] = b[i]*c[i];
        bd[i] = b[i]*d[i];
    }
    IDFT(ac,ad,A,B);IDFT(bc,bd,C,D);
    FOR(i,0,N-1){
//        assert(std::min({A[i],B[i],C[i],D[i]}) >= 0);
        R[i] = 0;
        add(R[i],D[i]%ha);
        add(R[i],B[i]%ha*BASE%ha);
        add(R[i],C[i]%ha*BASE%ha);
        add(R[i],A[i]%ha*BASE%ha*BASE%ha);
    }
}

int fac[MAXN],inv[MAXN];
int pw[MAXN];
int t1[MAXN],t2[MAXN];

inline void mul(int x,int F[],int y,int G[],int &z,int R[]){// F=x G=y
    int t = 1;
    FOR(i,0,k){
        t1[i] = 1ll*F[i]*t%ha*inv[i]%ha,t = 1ll*t*pw[y]%ha;
        t2[i] = 1ll*G[i]*inv[i]%ha;
    }
    mul(t1,t2,R);
    FOR(i,k+1,N-1) R[i] = 0;
    FOR(i,0,k) R[i] = 1ll*R[i]*fac[i]%ha;
    z = x+y;
}

int F[MAXN],G[MAXN];

int ttt[MAXN];

int main(){
  //  freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
/*    F[0] = 0;F[1] = 2;F[2] = 2;F[3] = 333333337;
    G[0] = 0;G[1] = 1;G[2] = 500000004;G[3] = 166666668;
    init(2*3);DEBUG(N);
    mul(F,G,ttt);
    FOR(i,0,2) DEBUG(ttt[i]);
    exit(0);*/
    fac[0] = 1;FOR(i,1,MAXN-1) fac[i] = 1ll*fac[i-1]*i%ha;
    inv[MAXN-1] = qpow(fac[MAXN-1]);ROF(i,MAXN-2,0) inv[i] = 1ll*inv[i+1]*(i+1)%ha;
    pw[0] = 1;FOR(i,1,MAXN-1) pw[i] = 2ll*pw[i-1]%ha;
    FOR(i,0,MAXM) FOR(j,0,(1<<(i+1))-1) W[i][j] = Exp(j*(2*pi)/(1<<(i+1)));
    scanf("%lld%d",&n,&k);init(2*k);
    if(n > k){
        puts("0");
        return 0;
    }
    // G = res
    int lenG = 1,lenF = 1;
    FOR(i,1,k) G[i] = F[i] = 1;--n;
    while(n){
        if(n&1) mul(lenF,F,lenG,G,lenG,G);
        mul(lenF,F,lenF,F,lenF,F);
        n >>= 1;
    }
    int ans = 0;
    FOR(i,0,k) add(ans,1ll*G[i]*fac[k]%ha*inv[i]%ha*inv[k-i]%ha);
    printf("%d\n",ans);
    return 0;
}