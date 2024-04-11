
// Problem: G. Running Competition
// Contest: Codeforces - Educational Codeforces Round 93 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1398/problem/G
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

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
const int ha = 998244353;
const int G = 3;
const int Gn = 332748118;

inline int qpow(int a,int n=ha-2){
	int res = 1;
	while(n){
		if(n&1) res = 1ll*res*a%ha;
		a = 1ll*a*a%ha;
		n >>= 1;
	}
	return res;
}

struct Poly{
	std::vector<int> x;
	inline void ext(int n){x.resize(n+1);}
	inline int deg(){return x.size();}
	inline int& operator [] (const int &n){return x[n];}
};

int r[MAXN<<2],N;

inline void init(int n){
	N = 1;int len = 0;
	while(N <= n) N <<= 1,len++;
	FOR(i,0,N-1) r[i] = (r[i>>1]>>1)|((i&1)<<(len-1));
}

inline void NTT(Poly &A,int opt){
	A.ext(N);
	FOR(i,0,N-1) if(i < r[i]) std::swap(A[i],A[r[i]]);
	for(int mid = 1;mid < N;mid <<= 1){
		int W = qpow(opt==1?G:Gn,(ha-1)/(mid<<1));
		for(int i = 0;i < N;i += (mid<<1)){
			for(int j = 0,w = 1;j < mid;++j,w = 1ll*w*W%ha){
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
	int len = A.deg()+B.deg();init(len);
	NTT(A,1);NTT(B,1);
	FOR(i,0,N-1) A[i] = 1ll*A[i]*B[i]%ha;
	NTT(A,-1);A.ext(len);
	return A;
}

int n,x,y;
int a[MAXN];
const int MAXM = 1e6;
bool vis[MAXM];
int f[MAXM+233];

int main(){
	scanf("%d%d%d",&n,&x,&y);
	Poly A,B,C;A.ext(x);
	FOR(i,0,n){
		int x;scanf("%d",&x);A[x]++;
	}
	B = A;std::reverse(all(B.x));C = A*B;
	FOR(i,0,x) vis[i] = C[i+x];
	CLR(f,-1);
	FOR(i,1,MAXM){
		if(i&1) continue;
		int t = i>>1;t -= y;
		if(t <= 0) continue;
		if(vis[t]) f[i] = i;
	}
	FOR(i,1,MAXM){
		for(int j = i+i;j <= MAXM;j += i){
			f[j] = std::max(f[j],f[i]);
		}
	}
	int q;scanf("%d",&q);
	while(q--){
		int x;scanf("%d",&x);
		printf("%d ",f[x]);
	}
	puts("");
	return 0;
}