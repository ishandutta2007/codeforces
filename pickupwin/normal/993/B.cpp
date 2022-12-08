#include <iostream>

using namespace std;

const int MAXN=13, MAXM=13;

int N, M;
int A[MAXN], B[MAXM];
int AB[MAXN][MAXM];
int SumA[MAXN], SumB[MAXM], Sum;

bool Ak=true, Bk=true, Ans;

int enCode(int k){
	return (1<<(k-1));
}

int unCode(int k){
	int ret=0;
	while(k>0){
		if(k&1)	break;
		++ret;k>>=1;
	}
	return ret+1;
}

int Bc(int k){
	int ret=0;
	while(k>0){
		if(k&1)	++ret;
		k>>=1;/**/
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	
	cin >> N >> M;
	
	for(int i=1, a, b;i<=N;++i){
		cin >> a >> b;
		A[i]=(enCode(a)|enCode(b));
	}
	
	for(int i=1, a, b;i<=M;++i){
		cin >> a >> b;
		B[i]=(enCode(a)|enCode(b));
	}
	
	for(int i=1;i<=N;++i)
		for(int j=1;j<=M;++j){
			AB[i][j]=A[i]&B[j];
			if(Bc(AB[i][j])>1)	AB[i][j]=0;
		}
	
	for(int i=1;i<=N;++i)
		for(int j=1;j<=M;++j)
			SumA[i]|=AB[i][j];
	
	for(int j=1;j<=M;++j)
		for(int i=1;i<=N;++i)
			SumB[j]|=AB[i][j];
	
	for(int i=1;i<=N;++i)	if(Bc(SumA[i])>1)	Ak=false;
	for(int i=1;i<=M;++i)	if(Bc(SumB[i])>1)	Bk=false;
	
	if((!Ak) || (!Bk))	puts("-1");
	else{
		for(int i=1;i<=N;++i)	Sum|=SumA[i];
		for(int i=1;i<=M;++i)	Sum|=SumB[i];
		if(Bc(Sum)>1)	puts("0");
		else	printf("%d\n", unCode(Sum));
	}
	
	return 0;
}

/*
2 2
1 5 3 4
1 5 6 4

4

*/