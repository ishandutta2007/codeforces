#include <cstdio>
#include <cmath>

const int MAXN=200111;
const double eps=1e-9;

double Hei, A, B;

int N, M;

struct Seg{
	double l, r;
	double len, sum;
} S[MAXN];

double X, Y;

double L, R;

int pl, pr;

int Find(double v){
	if((v-S[1].l)<eps)	return 0;
	int Left=1, Right=N, Mid;
	while(Left<Right){
		Mid=(Left+Right)>>1;
		if((S[Mid+1].l-v)<eps)	Left=Mid+1;
		else	Right=Mid;
	}
	Mid=(Left+Right)>>1;
	return Mid;
}

double Calc(double &a, double &b, double &c, double &d){
	return fmax(0.0, fmin(b, d)-fmax(a, c));
}

double Sum(int a, int b){
	if(a>b)	return 0.0;
	return S[b].sum-S[a-1].sum;
}

int main(){
	
	scanf("%lf%lf%lf", &Hei, &A, &B);
	
	scanf("%d", &N);
	for(int i=1;i<=N;++i)
		scanf("%lf%lf", &S[i].l, &S[i].r);
	
	for(int i=1;i<=N;++i)
		S[i].len=S[i].r-S[i].l;
	S[0].sum=0.0;
	for(int i=1;i<=N;++i)
		S[i].sum=S[i-1].sum+S[i].len;
	
	double Ans;
	
	scanf("%d", &M);
	while(M--){
		scanf("%lf%lf", &X, &Y);
		L=X+(A-X)/(Y-Hei)*Y;
		R=X+(B-X)/(Y-Hei)*Y;
		pl=Find(L);pr=Find(R);
		if(pl==pr)
			Ans=Calc(L, R, S[pl].l, S[pr].r);
		else{
			Ans=0.0;
			Ans+=Calc(L, R, S[pl].l, S[pl].r);
			Ans+=Calc(L, R, S[pr].l, S[pr].r);
			Ans+=Sum(pl+1, pr-1);
		}
		Ans=Ans/(R-L)*(B-A);
		printf("%.7lf\n", Ans);
	}
	
	return 0;
}