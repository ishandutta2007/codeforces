#include <cstdio>

const int MAXN=311111;
const int MAXM=311111;
const long long MOD=1000000009LL;

int N, M;
int Bs, Bc;
long long Num[MAXN];
long long F[MAXN], Fsum[MAXN];
long long Add[655];
int Qcnt[655];

long long sum(long long a, long long b){
	long long ret=a+b;
	if(ret>=MOD)	ret-=MOD;
	return ret;
}

long long dif(long long a, long long b){
	long long ret=a-b;
	if(ret<0LL)	ret+=MOD;
	return ret;
}

struct Point{
	int x, y;
} P[MAXN];

struct Block{
	int L, R;
	long long Sum, Add1, Add2;
	void getSum(){
		Sum=0LL;
		for(int i=L;i<=R;++i)
			Sum=sum(Num[i], Sum);
	}
	void Pdw(){
		if(Add1==0LL && Add2==0LL)	return;
		Add[0]=Add1;Add[1]=Add2;
		for(int i=2;i<=R-L;++i)
			Add[i]=sum(Add[i-1], Add[i-2]);
		for(int i=L;i<=R;++i)
			Num[i]=sum(Add[i-L], Num[i]);
		Add1=0LL;Add2=0LL;
	}
} B[655];

struct Query{
	int Type, L, R;
} Qu[MAXM], Q;

void Update(){
	int Bl=P[Q.L].x, Br=P[Q.R].x;
	for(int i=Bl+1;i<Br;++i){
		B[i].Sum=sum(B[i].Sum, dif(Fsum[B[i].R-Q.L+1], Fsum[B[i].L-Q.L]));
		if(Qcnt[i]>0){
			B[i].Add1=sum(B[i].Add1, F[B[i].L-Q.L+1]);
			B[i].Add2=sum(B[i].Add2, F[B[i].L-Q.L+2]);
		}
	}
	if(Bl==Br){
		B[Bl].Sum=sum(B[Bl].Sum, Fsum[Q.R-Q.L+1]);
		if(Qcnt[Bl]>0){
			B[Bl].Pdw();
			for(int i=Q.L;i<=Q.R;++i)
				Num[i]=sum(Num[i], F[i-Q.L+1]);
		}
	}
	else{
		B[Bl].Sum=sum(B[Bl].Sum, Fsum[B[Bl].R-Q.L+1]);
		if(Qcnt[Bl]>0){
			B[Bl].Pdw();
			for(int i=Q.L;i<=B[Bl].R;++i)
				Num[i]=sum(Num[i], F[i-Q.L+1]);
		}
		B[Br].Sum=sum(B[Br].Sum, dif(Fsum[Q.R-Q.L+1], Fsum[B[Br].L-Q.L]));
		if(Qcnt[Br]>0){
			B[Br].Pdw();
			for(int i=B[Br].L;i<=Q.R;++i)
				Num[i]=sum(Num[i], F[i-Q.L+1]);
		}
	}
}

long long Ask(){
	long long ret=0LL;
	int Bl=P[Q.L].x, Br=P[Q.R].x;
	for(int i=Bl+1;i<Br;++i)
		ret=sum(ret, B[i].Sum);
	if(Bl==Br){
		B[Bl].Pdw();
		for(int i=Q.L;i<=Q.R;++i)
			ret=sum(ret, Num[i]);
	}
	else{
		B[Bl].Pdw();
		for(int i=Q.L;i<=B[Bl].R;++i)
			ret=sum(ret, Num[i]);
		B[Br].Pdw();
		for(int i=B[Br].L;i<=Q.R;++i)
			ret=sum(ret, Num[i]);
	}
	return ret;
}

int min(int a, int b){
	return (a>b)?b:a;
}

int main(){
	
	scanf("%d%d", &N, &M);
	for(int i=1;i<=N;++i)	scanf("%I64d", &Num[i]);
	
	for(Bs=0;Bs*Bs<N;++Bs);
	Bc=N/Bs;
	if(N%Bs!=0)	++Bc;
	
	for(int i=1;i<=Bc;++i){
		B[i].R=i*Bs;
		B[i].L=B[i].R-Bs+1;
		B[i].R=min(B[i].R, N);
		B[i].getSum();
	}
	
	P[1].x=1;P[1].y=1;
	for(int i=2;i<=N;++i){
		P[i].x=P[i-1].x;
		P[i].y=P[i-1].y+1;
		if(P[i].y>Bs){
			P[i].y-=Bs;
			++P[i].x;
		}
	}
	
	F[1]=1LL;F[2]=1LL;
	for(int i=3;i<=N;++i)	F[i]=sum(F[i-1], F[i-2]);
	Fsum[0]=0LL;
	for(int i=1;i<=N;++i)	Fsum[i]=sum(Fsum[i-1], F[i]);
	
	for(int i=1;i<=M;++i){
		scanf("%d%d%d", &Qu[i].Type, &Qu[i].L, &Qu[i].R);
		if(Qu[i].Type==2){
			++Qcnt[P[Qu[i].L].x];
			++Qcnt[P[Qu[i].R].x];
		}
	}
	
	for(int i=1;i<=M;++i){
		Q=Qu[i];
		if(Q.Type==1)
			Update();
		else{
			printf("%I64d\n", Ask());
			--Qcnt[P[Qu[i].L].x];
			--Qcnt[P[Qu[i].R].x];
		}
	}
	
	return 0;
}