#include <cstdio>
#include <algorithm>
#include <functional>

using std::sort;
using std::greater;

const int MAXN=100111;

int N, M, K;

int A[MAXN];
int D[MAXN];

int main(){
	
	
	scanf("%d%d%d", &N, &M, &K);
	
	for(int i=1;i<=N;++i)	scanf("%d", &A[i]);
	
	for(int i=1;i<N;++i)	D[i]=A[i+1]-A[i];
	
	sort(D+1, D+N, greater<int>());
	
	//for(int i=1;i<N;++i)	printf("%d ", D[i]);
	//puts("");
	
	int Ans=0;
	for(int i=K;i<N;++i)	Ans+=D[i];
	Ans+=K;
	
	printf("%d\n", Ans);
	
	return 0;
}