#include <cstdio>

const int MAXN=111;

int N;
int A[MAXN];
long long F[MAXN];

int main(){
	
	scanf("%d", &N);
	
	for(int i=1;i<=N;++i)	scanf("%d", &A[i]);
	
	for(int i=1;i<=N;++i){
		F[i]=F[i-1]+1LL+1LL*(A[i]-1)*i;
	}
	
	printf("%I64d\n", F[N]);
	
	return 0;
}