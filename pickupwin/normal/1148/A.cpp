#include <cstdio>
#include <algorithm>

using std::min;

int A, B, C;

int main(){
	
	scanf("%d%d%d", &A, &B, &C);
	
	int K=min(A, B);
	C+=K;A-=K;B-=K;
	long long Ans=2LL*C;
	if(A>0)	++Ans;
	if(B>0)	++Ans;
	
	printf("%I64d\n", Ans);
	
	return 0;
}