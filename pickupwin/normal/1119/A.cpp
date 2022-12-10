#include <cstdio>
#include <algorithm>

using std::min;
using std::max;

const int MAXN=300011;

int N;
int A[MAXN];
int P[2];
int Ans=0;

int main(){
	
	scanf("%d", &N);
	for(int i=1;i<=N;++i)	scanf("%d", &A[i]);
	
	for(int i=0;i<20;++i){
		P[0]=P[1]=N;
		for(int j=1;j<=N;++j){
			if((A[j]>>i)&1){
				Ans=max(Ans, j-P[0]);
				P[1]=min(P[1], j);
			}
			else{
				Ans=max(Ans, j-P[1]);
				P[0]=min(P[0], j);
			}
		}
	}
	
	printf("%d\n", Ans);
	
	return 0;
}