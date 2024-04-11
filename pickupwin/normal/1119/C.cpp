#include <cstdio>

const int MAXN=511, MAXM=511;

int N, M;

int A[MAXN][MAXM];
int B[MAXN][MAXM];

bool Test(){
	bool ret=true;
	for(int i=1;i<=N;++i)
		for(int j=1;j<=M;++j)
			ret&=(A[i][j]==B[i][j]);
	return ret;
}

void Show(bool i){
	puts(i?"Yes":"No");
}

int main(){
	
	scanf("%d%d", &N, &M);
	
	for(int i=1;i<=N;++i){
		for(int j=1;j<=M;++j){
			scanf("%d", &A[i][j]);
		}
	}
	
	for(int i=1;i<=N;++i){
		for(int j=1;j<=M;++j){
			scanf("%d", &B[i][j]);
		}
	}
	
	for(int i=1;i<N;++i){
		for(int j=1;j<M;++j){
			if(A[i][j]!=B[i][j]){
				A[i][j]=!A[i][j];
				A[i+1][j]=!A[i+1][j];
				A[i][j+1]=!A[i][j+1];
				A[i+1][j+1]=!A[i+1][j+1];
			}
		}
	}
	
	Show(Test());
	
	return 0;
}