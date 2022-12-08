
#include <cstdio>
#include <algorithm>

using std::sort;

const int MAXN=100011;
const int MAXM=100011;

int N;
long long A[MAXN];
long long D[MAXN];
long long S[MAXN];
int Pos, Cnt;

int M;
long long L, R;
long long Ans[MAXM];

struct Query{
	long long d;
	int p;
} Q[MAXM];

inline bool cmpd(const Query &A, const Query &B){
	return A.d<B.d;
}

int main(){
	
	
	scanf("%d", &N);
	for(int i=1;i<=N;++i)	scanf("%I64d", &A[i]);
	sort(A+1, A+N+1);
	for(int i=1;i<N;++i)	D[i]=A[i+1]-A[i];
	sort(D+1, D+N);
	for(int i=1;i<N;++i)	S[i]=S[i-1]+D[i];
	
	scanf("%d", &M);
	for(int i=1;i<=M;++i){
		scanf("%I64d%I64d", &L, &R);
		Q[i].d=R-L;Q[i].p=i;
	}
	
	sort(Q+1, Q+M+1, cmpd);
	
	Pos=1;Cnt=N;
	for(int i=1;i<=M;++i){
		while(Pos<N && Q[i].d>=D[Pos])	{++Pos;--Cnt;}
		Ans[Q[i].p]=(Q[i].d+1LL)*(long long)(Cnt)+S[Pos-1];
	}
	
	for(int i=1;i<=M;++i)	printf("%I64d ", Ans[i]);
	puts("");
	
	return 0;
}