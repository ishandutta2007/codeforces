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

const int ha = 998244353;
const int MAXN = 4000+5;

inline void add(int &x,int y){
	x += y;if(x >= ha) x -= ha;
}

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
	std::vector<int> v;
	inline void ext(int n){v.resize(n+1);}
	inline int deg(){return (int)v.size()-1;}
	inline int& operator [] (const int &n){return v[n];}
};

Poly operator + (Poly A,Poly B){
	if(A.deg() < B.deg()) A.ext(B.deg());
	FOR(i,0,B.deg()) add(A[i],B[i]);
	return A;
}

Poly operator - (Poly A,Poly B){
	if(A.deg() < B.deg()) A.ext(B.deg());
	FOR(i,0,B.deg()) add(A[i],ha-B[i]);
	return A;
}

int n1,n2,k;// mod k

inline Poly Inv(Poly A){
	Poly B;A.ext(k);B.ext(k);
	B[0] = qpow(A[0]);
	FOR(i,1,k){
		FOR(j,1,i) add(B[i],1ll*A[j]*B[i-j]%ha);
		B[i] = ha-B[i];
		B[i] = 1ll*B[i]*B[0]%ha;
	}
	return B;
}

inline Poly operator << (Poly A,int n){
	Poly B;B.ext(A.deg()+n);
	FOR(i,0,A.deg()) B[i+n] = A[i];
	B.ext(k);return B;
}

std::vector<int> T[MAXN];
Poly F[MAXN],G[MAXN],one;

inline void dfs1(int v,int fa=0){
	for(auto x:T[v]){
		if(x == fa) continue;
		dfs1(x,v);
		G[v] = G[v]+(Inv(one-G[x])<<2);
	}
}

inline void dfs2(int v,int fa=0){
	F[v] = Inv(one-G[v]);
	for(auto x:T[v]){
		if(x == fa) continue;
		G[v] = G[v]-(Inv(one-G[x])<<2);
		G[x] = G[x]+(Inv(one-G[v])<<2);
		dfs2(x,v);
		G[x] = G[x]-(Inv(one-G[v])<<2);
		G[v] = G[v]+(Inv(one-G[x])<<2);
	}
}

int f1[MAXN],f2[MAXN];
int fac[MAXN],inv[MAXN];

inline void prework(){
	fac[0] = 1;FOR(i,1,MAXN-1) fac[i] = 1ll*fac[i-1]*i%ha;
	inv[MAXN-1] = qpow(fac[MAXN-1]);ROF(i,MAXN-2,0) inv[i] = 1ll*inv[i+1]*(i+1)%ha;
}

inline int C(int n,int m){
	if(n < m || n < 0 || m < 0) return 0;
	return 1ll*fac[n]*inv[m]%ha*inv[n-m]%ha;
}

int main(){
	prework();
	scanf("%d%d%d",&n1,&n2,&k);one.ext(k);one[0] = 1;
	FOR(i,2,n1){
		int u,v;scanf("%d%d",&u,&v);
		T[u].pb(v);T[v].pb(u);
	}
	dfs1(1);dfs2(1);
	FOR(i,1,n1){
		assert(F[i].deg()==k);
		FOR(j,1,k) add(f1[j],F[i][j]);
		F[i].ext(-1),G[i].ext(-1),T[i].clear();
	}
	FOR(i,2,n2){
		int u,v;scanf("%d%d",&u,&v);
		T[u].pb(v);T[v].pb(u);
	}
	dfs1(1);dfs2(1);
	FOR(i,1,n2){
		assert(F[i].deg()==k);
		FOR(j,1,k) add(f2[j],F[i][j]);
	}
	f1[0] = n1;f2[0] = n2;
	int res = 0;
	FOR(i,0,k) add(res,1ll*C(k,i)*f1[i]%ha*f2[k-i]%ha);
	printf("%d\n",res);
	return 0;
}