#include <cstdio>
#include <algorithm>

using std::sort;

const int MAXN=1011, MAXA=100011, MOD=998244353;

inline int sum(const int &a, const int &b){
	return (a+b>=MOD)?(a+b-MOD):(a+b);
}

inline void add(int &f, const int &v){
	f+=v;f-=(f>=MOD)?MOD:0;
}

int N, K, V[MAXN], ANS=0;
int A[MAXN][MAXN], B[MAXN][MAXN];

int main(){
	
	scanf("%d%d", &N, &K);
	
	for(int i=1;i<=N;++i)	scanf("%d", &V[i]);
	
	sort(V+1, V+N+1);
	
	for(int i=1, k;i*(K-1)<MAXA;i++){
		k=0;
		B[0][0]=A[0][0]=1;
		for(int j=1;j<=N;++j){
			while(k+1<j && V[k+1]+i<=V[j])	++k;
			for(int l=1;l<=K;++l)	add(A[j][l], B[k][l-1]);
			for(int l=0;l<=K;++l)	B[j][l]=sum(B[j-1][l], A[j][l]); 
		}
		add(ANS, B[N][K]);
		for(int j=0;j<=N;++j)
			for(int k=0;k<=K;++k)
				A[j][k]=B[j][k]=0;
	}
	
	printf("%d\n", ANS);
	
	return 0;
}