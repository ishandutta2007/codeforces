#include <cstdio>
#include <cstdlib>
#include <algorithm>

using std::max;

const int MAXN=200011, MAXM=200011;

int N, M, K;
int Ta, Tb, To;
int A[MAXN], B[MAXM];

void Fail(int d){
	//printf("%d\n", d);
	puts("-1");
	exit(0);
}

int Find(int l, int r, int v){
	int m;
	for(;l<r;){
		m=(l+r)>>1;
		if(B[m]>=v)	r=m;
		else	l=m+1;
	}
	m=(l+r)>>1;
	return m;
}

int main(){
	
	scanf("%d%d", &N, &M);
	scanf("%d%d", &Ta, &Tb);
	scanf("%d", &K);
	
	for(int i=1;i<=N;++i)	scanf("%d", &A[i]);
	for(int j=1;j<=M;++j)	scanf("%d", &B[j]);
	
	if(K>=N || K>=M)	Fail(1);
	
	int Ans=0;
	for(int i=0, p;i<=K;++i){
		To=A[i+1]+Ta;
		if(To>B[M])	Fail(2);
		p=Find(1, M, To);
		if(M-p+1<=(K-i))	Fail(3);
		Ans=max(Ans, B[p+K-i]+Tb);
	}
	
	printf("%d\n", Ans);
	
	return 0;
}