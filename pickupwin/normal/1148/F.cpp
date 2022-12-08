#include <cstdio>

const int MAXN=300011;

int N;

struct Pair{
	int Val;
	long long Mask;
} P[MAXN];

long long Sum;

int main(){
	
	scanf("%d", &N);
	for(int i=1;i<=N;++i){
		scanf("%d%I64d", &P[i].Val, &P[i].Mask);
		Sum+=P[i].Val;
	}
	
	if(Sum<0LL){
		for(int i=1;i<=N;++i)	P[i].Val=-P[i].Val;
	}
	
	long long Ans=0LL, Tmp;
	/*
	for(int i=0;i<62;++i){
		Tmp=0LL;
		for(int j=1;j<=N;++j)	if((P[j].Mask>>i)&1 && ((P[j].Mask>>(i+1))==0LL))	Tmp+=P[j].Val;
		if(Tmp>0LL){
			Ans^=(1LL<<i);
			for(int j=1;j<=N;++j)	if((P[j].Mask>>i)&1)	P[j].Val=-P[j].Val;
		}
	}
	*/
	for(int i=61;i>=0;--i){
		Tmp=0LL;
		for(int j=1;j<=N;++j)	if((P[j].Mask>>i)&1 && ((P[j].Mask&((1LL<<i)-1))==0))	Tmp+=P[j].Val;
		if(Tmp>0LL){
			Ans^=(1LL<<i);
			for(int j=1;j<=N;++j)	if((P[j].Mask>>i)&1)	P[j].Val=-P[j].Val;
		}
	}
	
	printf("%I64d\n", Ans);
	
	return 0;
}