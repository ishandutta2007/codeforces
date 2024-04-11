#include <cstdio>

const int MAXN=511;
const int MOD=1000000007;

inline int sum(const int &a, const int &b){
	return (a+b>=MOD)?(a+b-MOD):(a+b);
}

inline int mul(const int &a, const int &b){
	return (int)((1LL*a*b)%(long long)(MOD));
}

inline void add(int &f, const int &v){
	f+=v;if(f>=MOD)	f-=MOD;
}

inline int inv(const int &a);

int pow(int a, int k){
	if(k<0)	return pow(inv(a), -k);
	int r=1;
	while(k){
		if(k&1)	r=mul(r, a);
		a=mul(a, a);
		k>>=1;
	}
	return r;
}

inline int inv(const int &a){
	return pow(a, MOD-2);
}

int N, K;
int C[MAXN][MAXN];

struct Vert{
	int FE;
	int Size;
	int F[MAXN], G[MAXN];
} V[MAXN];

struct Edge{
	int y, next;
};

Edge E[MAXN<<1];

int Ecnt;

void addE(int a, int b){
	++Ecnt;
	E[Ecnt].y=b;E[Ecnt].next=V[a].FE;V[a].FE=Ecnt;
}

void DFS(int at, int f=0){
	V[at].Size=1;
	V[at].F[0]=V[at].G[0]=1;
	for(int k=V[at].FE, to;k;k=E[k].next){
		to=E[k].y;
		if(to==f)	continue;
		DFS(to, at);
		for(int i=V[at].Size-1;i>=0;--i){
			for(int j=1;j<V[to].Size;++j){
				add(V[at].F[i+j+1], mul(V[at].F[i], V[to].F[j]));
				add(V[at].G[i+j+1], mul(V[at].G[i], V[to].F[j]));
				add(V[at].F[i+j], sum(mul(V[at].F[i], V[to].G[j]), mul(V[at].G[i], V[to].F[j])));
				add(V[at].G[i+j], mul(V[at].G[i], V[to].G[j]));
			}
			add(V[at].F[i+1], mul(V[at].F[i], V[to].F[0]));
			add(V[at].G[i+1], mul(V[at].G[i], V[to].F[0]));
			V[at].F[i]=sum(mul(V[at].F[i], V[to].G[0]), mul(V[at].G[i], V[to].F[0]));
			V[at].G[i]=mul(V[at].G[i], V[to].G[0]);
		}
		V[at].Size+=V[to].Size;
	}
}

int Ans[MAXN], ANS[MAXN];

int main(){
	
	scanf("%d", &N);
	
	for(int i=0;i<=N;++i){
		C[i][0]=C[i][i]=1;
		for(int j=1;j<i;++j){
			C[i][j]=sum(C[i-1][j], C[i-1][j-1]);
		}
	}
	
	for(int i=1, a, b;i<N;++i){
		scanf("%d%d", &a, &b);
		addE(a, b);addE(b, a);
	}
	
	DFS(1);
	
	for(int i=0;i<N;++i)	Ans[i]=mul(pow(N, N-i-2), V[1].F[N-1-i]);
	
	for(int k=0;k<N;++k){
		for(int i=k, t=1;i<N;++i, t=MOD-t){
			add(ANS[k], mul(mul(t, C[i][k]), Ans[i]));
		}
	}
	
	for(int i=0;i<N;++i)	printf("%d ", ANS[i]);
	puts("");
	
	return 0;
}