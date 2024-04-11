#include <cstdio>
#include <algorithm>

using std::max;
using std::swap;

const int MAXN=1011;

int N;
long long Lim, H;
int A[MAXN];

int main(){
	
	scanf("%d%I64d", &N, &Lim);
	for(int i=1;i<=N;++i)	scanf("%d", &A[i]);
	
	int Ans=1;
	
	for(int i=1;i<=N;++i){
		for(int j=i-1;j>=1;--j)	if(A[j]<A[j+1])	swap(A[j], A[j+1]);
		H=0LL;
		for(int j=1;j<=i;++j)	if(j&1)	H+=(long long)(A[j]);
		if(H<=Lim)	Ans=max(Ans, i);
		else	break;
	}
	
	printf("%d\n", Ans);
	
	return 0;
}