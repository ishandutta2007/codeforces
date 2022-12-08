#include <cstdio>
#include <algorithm>

using std::min;

const int MAXN=300011;

int N;
long long A[MAXN];
long long Cnt, Pa, Tmp;
long long Ans;

int main(){
	
	scanf("%d", &N);
	for(int i=1;i<=N;++i)	scanf("%I64d", &A[i]);
	
	for(int i=1;i<=N;++i){
		Tmp=min(A[i]>>1, Cnt);
		Ans+=Tmp;
		Cnt-=Tmp;A[i]-=(Tmp<<1);
		Ans+=A[i]/3LL;A[i]%=3LL;
		Cnt+=A[i];
	}
	
	printf("%I64d\n", Ans);
	
	return 0;
}