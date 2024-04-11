#include <cstdio>
#include <algorithm>

using std::sort;

const int MAXM=1000011;

int N, M;
int A[MAXM];

int T;
int L[MAXM];
int C[MAXM];
int Aim[MAXM];

struct Pair{
	int *p, v;
	Pair(){}
	Pair(int *_p, int _v){p=_p;v=_v;}
} P[MAXM];

inline bool operator < (const Pair &A, const Pair &B){
	return A.v<B.v;
}

void Set(int p){
	if(Aim[1])	return;
	/*
	for(int i=1;i<=M;++i){
		if(Aim[i])	break;
		Aim[i]=p;
	}
	*/
	Aim[1]=p;
}

void Lanch(){
	Aim[0]=1;
	for(int i=1;i<=M;++i)	if(!Aim[i])	Aim[i]=Aim[i-1];
	for(int i=1;i<=M;++i)	printf("%d ", Aim[i]);
	puts("");
	for(int i=1;i<=M;++i)
		Aim[i]=0;
}

void Leave(int p){
	if(p<=1)	return;
	/*
	for(int i=1;i<p;++i)
		Aim[i]=0;
	*/
	Aim[p]=Aim[1];
	Aim[1]=0;
}

int main(){
	
	scanf("%d%d", &N, &M);
	for(int i=1;i<=M;++i)	scanf("%d", &A[i]);
	
	for(int i=1, v=N;i<=M;++i){
		L[i]=A[i];
		L[i]-=v;
		while(L[i]>0)	L[i]-=N;
		L[i]=-L[i];
		v=L[i];
	}
	L[M]=0;
	
	for(int i=1;i<=M;++i)	P[i]=Pair(&L[i], L[i]);
	sort(P+1, P+M+1);
	for(int i=1;i<=M;++i)	*P[i].p=i;
	
	for(int i=1;i<M;++i)	C[i]=P[i+1].v-P[i].v;
	C[M]=N-P[M].v;
	
	int Sum=0;
	for(int i=1;i<=M;++i)	Sum+=A[i];
	T=Sum/N;
	if(Sum%N!=0)	++T;
	printf("%d\n", T);
	for(int i=1;i<=M;++i)	printf("%d ", C[i]);
	puts("");
	
	for(int i=1, v=N;i<=M;++i){
		Set(i);
		A[i]-=v;
		while(A[i]>0){
			Lanch();
			Set(i);
			A[i]-=N;
		}
		Leave(L[i]);
		v=-A[i];
	}
	Lanch();
	
	
	return 0;
}