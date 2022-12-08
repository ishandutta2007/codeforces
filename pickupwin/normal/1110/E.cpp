#include <cstdio>
#include <algorithm>

using std::sort;

const int MAXN=100111;

int N;

int A[MAXN], B[MAXN];

int main(){
	
	scanf("%d", &N);
	
	for(int i=1;i<=N;++i)	scanf("%d", &A[i]);
	
	for(int i=1;i<=N;++i)	scanf("%d", &B[i]);
	
	if(A[1]!=B[1] || A[N]!=B[N]){
		puts("No");
		return 0;
	}
	
	for(int i=1;i<N;++i)	A[i]=A[i+1]-A[i];
	
	for(int i=1;i<N;++i)	B[i]=B[i+1]-B[i];
	
	sort(A+1, A+N);
	
	sort(B+1, B+N);
	
	for(int i=1;i<N;++i){
		if(A[i]!=B[i]){
			puts("No");
			return 0;
		}
	}
	
	puts("Yes");
	
	return 0;
}