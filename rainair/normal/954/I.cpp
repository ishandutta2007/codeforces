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

const int MAXN = 2e5 + 5;
const int ha = 998244353;
const int G = 3;
const int Gn = 332748118;
char S[MAXN],T[MAXN];
int n,m;

inline int qpow(int a,int n=ha-2){
	int res = 1;
	while(n){
		if(n & 1) res = 1ll*res*a%ha;
		a = 1ll*a*a%ha;
		n >>= 1;
	}
	return res;
}

struct Poly{
    std::vector<int> x;
    inline void ext(int n){x.resize(n+1);}
    inline int deg(){return (int)x.size()-1;}
    inline int& operator [](const int &n){return x[n];}
};

int r[MAXN<<2],N;

inline void init(int n){
    N = 1;int len = 0;
    while(N <= n) N <<= 1,len++;
    FOR(i,0,N-1) r[i] = r[i>>1]>>1|((i&1)<<(len-1));
}

inline void NTT(Poly &A,int opt){
    A.ext(N);
    FOR(i,0,N-1) if(i < r[i]) std::swap(A[i],A[r[i]]);
    for(int mid = 1;mid < N;mid <<= 1){
        int W = qpow(opt==-1?Gn:G,(ha-1)/(mid<<1));
        for(int i = 0;i < N;i += (mid<<1)){
            for(int w=1,j = 0;j < mid;++j,w = 1ll*w*W%ha){
                int x = A[i+j],y = 1ll*w*A[i+mid+j]%ha;
                A[i+j] = (x+y)%ha;A[i+mid+j] = (x+ha-y)%ha;
            }
        }
    }
    if(opt == -1){
        int inv = qpow(N);
        FOR(i,0,N-1) A[i] = 1ll*A[i]*inv%ha;
    }
}

Poly operator * (Poly A,Poly B){
    int len = A.deg()+B.deg();
    init(len);
    NTT(A,1);NTT(B,1);
    FOR(i,0,N-1) A[i] = 1ll*A[i]*B[i]%ha;
    NTT(A,-1);A.ext(len);return A;
}

std::vector<P> opt[MAXN];
int f[MAXN];

inline int find(int x){
    return x == f[x] ? x : f[x] = find(f[x]);
}

int main(){
    scanf("%s%s",S,T);n = strlen(S);m = strlen(T);
    FOR(a,1,6){
        FOR(b,1,6){
            if(a == b) continue;
//            DEBUG(a);DEBUG(b);
            Poly A,B;A.ext(n-1);B.ext(m-1);
            FOR(i,0,n-1) A[i] = S[i]-'a'+1 == a;
            FOR(i,0,m-1) B[i] = T[i]-'a'+1 == b;std::reverse(all(B.x));
            A = A*B;
            FOR(i,1,n-m+1){
                if(A[i-1+m-1]) opt[i].pb(MP(a,b));
            }
        }
    }
    FOR(i,1,n-m+1){
        std::iota(f+1,f+6+1,1);int ans = 0;
        for(auto x:opt[i]){
            x.fi = find(x.fi);x.se = find(x.se);
            if(x.fi == x.se) continue;
            ans++;f[x.se] = x.fi;
        }
        printf("%d%c",ans," \n"[i==n-m+1]);
    }
    return 0;
}