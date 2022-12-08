#include <cstdio>
#include <cstdlib>

const int MAXN=200111;
const long long LONF=4567891012345678910LL;

int N;

long long B[MAXN];

long long A[MAXN];

bool Test(int p){
	return A[p]<=A[p+1];
}

void Split(int l, int r, long long s){
	A[l]=A[l-1];A[r]=s-A[l];
	if(Test(l-1) && Test(r))	return;
	A[r]=A[r+1];A[l]=s-A[r];
	if(Test(l-1) && Test(r))	return;
	exit(0);
}

int main(){
	
	scanf("%d", &N);
	
	for(int i=1;i<=(N>>1);++i)	scanf("%I64d", &B[i]);
	
	A[0]=0LL;A[N+1]=LONF;
	for(int i=1;i<=(N>>1);++i)	Split(i, N-i+1, B[i]);
	
	for(int i=1;i<=N;++i)	printf("%I64d ", A[i]);
	puts("");
	
	return 0;
}