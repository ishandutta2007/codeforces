#include <bits/stdc++.h>

#define fi first
#define se second
#define db double
#define U unsigned
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
		if(n & 1) res = 1ll*res*a%ha;
		a = 1ll*a*a%ha;
		n >>= 1;
	}
	return res;
}

inline void add(int &x,int y){
	(x += y);if(x >= ha) x -= ha;
}

struct Poly{
	std::vector<int> x;
	inline int& operator [] (const int &n) {return x[n];}
	inline int deg(){return (int)x.size()-1;}
	inline void ext(int n){x.resize(n+1);}
};

int r[MAXN<<2],N;

inline void init(int n){
	N = 1;int len = 0;while(N <= n) N <<= 1,len++;
	FOR(i,0,N-1) r[i] = (r[i>>1]>>1)|((i&1)<<(len-1));
}

inline void NTT(Poly &A,int opt=1){
	A.ext(N);
	FOR(i,0,N-1) if(i < r[i]) std::swap(A[i],A[r[i]]);
	for(int mid = 1;mid < N;mid <<= 1){
		int W = qpow(opt==1?G:Gn,(ha-1)/(mid<<1));
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

inline Poly operator * (Poly A,Poly B){
	int len = A.deg()+B.deg();init(len);
	NTT(A,1);NTT(B,1);FOR(i,0,N-1) A[i] = 1ll*A[i]*B[i]%ha;
	NTT(A,-1);A.ext(len);return A;
}

std::mt19937 g(time(NULL));
int P[MAXN],iP[MAXN];
char S[MAXN],T[MAXN];
int val[26];
Poly s,s2,s3,t,t2,p,p2,t2p,tp2,tp;
int t2p2[MAXN];

int main(){
	FOR(i,0,25) scanf("%d",P+i),val[i] = g()%ha,iP[P[i]] = i+1;
	scanf("%s%s",S,T);
	int n = strlen(S),m = strlen(T);--n;--m;
	s.ext(n);s2.ext(n);s3.ext(n);t.ext(m);t2.ext(m);p.ext(m);p2.ext(m);t2p.ext(m);tp2.ext(m);tp.ext(m);
	int sm = 0;
	FOR(i,0,n){
		s[i] = val[S[i]-'a'];
		s2[i] = 1ll*s[i]*s[i]%ha;
		s3[i] = 1ll*s2[i]*s[i]%ha;
		add(sm,1ll*s2[i]*s2[i]%ha);
	}
	FOR(i,0,m){
		t[i] = val[T[i]-'a'];
		t2[i] = 1ll*t[i]*t[i]%ha;
		p[i] = val[iP[T[i]-'a'+1]-1];
		p2[i] = 1ll*p[i]*p[i]%ha;
		t2p[i] = 1ll*t2[i]*p[i]%ha;
		tp2[i] = 1ll*t[i]*p2[i]%ha;
		tp[i] = 1ll*t[i]*p[i]%ha;
		t2p2[i] = 1ll*t2[i]*p2[i]%ha;
		p[i] = 2ll*p[i]%ha;
		t2p[i] = 2ll*t2p[i]%ha;
		t[i] = 2ll*t[i]%ha;
		tp2[i] = 2ll*tp2[i]%ha;
		tp[i] = 4ll*tp[i]%ha;
	}
	FOR(i,1,m) add(t2p2[i],t2p2[i-1]);
	// int rr = 0;
	// FOR(i,0,n){
		// rr += s2[i]*p2[i];
		// rr += -s3[i]*p[i];
		// rr += s2[i]*t2[i];
		// rr += -s[i]*t2p[i];
		// rr += -s3[i]*t[i];
		// rr += -s[i]*tp2[i];
		// rr += s2[i]*tp[i];
	// }
	// (rr += ha) %= ha;
	// DEBUG(rr);
	// rr += sm;
	// rr += (t2p2[n]-0);
	// DEBUG(rr);
	init(m);
	std::reverse(all(s.x));std::reverse(all(s2.x));std::reverse(all(s3.x));
	NTT(s);NTT(s2);NTT(s3);NTT(t);NTT(t2);NTT(p);NTT(p2);NTT(t2p);NTT(tp2);NTT(tp);
	Poly ans;ans.ext(N);
	FOR(i,0,N-1){
		add(ans[i],1ll*p2[i]*s2[i]%ha);
		add(ans[i],ha-1ll*p[i]*s3[i]%ha);
		add(ans[i],1ll*t2[i]*s2[i]%ha);
		add(ans[i],ha-1ll*t2p[i]*s[i]%ha);
		add(ans[i],ha-1ll*t[i]*s3[i]%ha);
		add(ans[i],ha-1ll*tp2[i]*s[i]%ha);
		add(ans[i],1ll*tp[i]*s2[i]%ha);

		// add(ans[i],ha-1ll*s[i]*t[i]%ha);
	}
	NTT(ans,-1);
	// DEBUG(ans[n]);
	FOR(i,0,m-n){
		int res = ans[i+n];
		add(res,sm);
		add(res,(t2p2[i+n]+ha-(i==0?0:t2p2[i-1]))%ha);
		// DEBUG(res);
		putchar(res?'0':'1');
	}
	return 0;
}