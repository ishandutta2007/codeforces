#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN=211111;
const int MAXB=555;

struct Pos{
	int x, y;
} P[MAXN];

struct Block{
	int Num[MAXB];
	int Sorted[MAXB];
	int Size;
	void Update(){
		for(int j=1;j<=Size;++j)
			Sorted[j]=Num[j];
		sort(Sorted+1, Sorted+Size+1);
		Sorted[0]=0;Sorted[Size+1]=MAXN;
	}
} B[MAXB];

int N, Q;
int Bsize, Bcnt;
int L, R;
long long ANS=0LL;
int NumL, NumR;

int getNum(int at){
	return B[P[at].x].Num[P[at].y];
}

int Find(int at){
	//cout << "Find " << at << " ";
	int CntR, CntL;
	int Left=0, Right=B[at].Size+1, Mid;
	while(Left<Right){
		Mid=(Left+Right)>>1;
		if(B[at].Sorted[Mid+1]<NumR)	Left=Mid+1;
		else	Right=Mid;
	}
	Mid=(Left+Right)>>1;
	CntR=Mid;
	Left=0;Right=B[at].Size+1;
	while(Left<Right){
		Mid=(Left+Right)>>1;
		if(B[at].Sorted[Mid]>NumL)	Right=Mid;
		else	Left=Mid+1;
	}
	Mid=(Left+Right)>>1;
	CntL=Mid;
	//cout << (CntR-CntL+1) << endl;
	if(CntR<CntL)	return 0;
	return CntR-CntL+1;
}

int Calc(int Left, int Right){
	//if(Left>Right)	return 0;
	int ret=0;
	int Bl=P[Left].x, Br=P[Right].x;
	for(int i=Bl+1;i<Br;++i)
		ret+=Find(i);
	if(Bl==Br){
		for(int i=P[Left].y;i<=P[Right].y;++i){
			if(B[Bl].Num[i]>NumL && B[Bl].Num[i]<NumR)
				++ret;
		}
	}
	else{
		for(int i=P[Left].y;i<=B[Bl].Size;++i){
			if(B[Bl].Num[i]>NumL && B[Bl].Num[i]<NumR)
				++ret;
		}
		for(int i=1;i<=P[Right].y;++i){
			if(B[Br].Num[i]>NumL && B[Br].Num[i]<NumR)
				++ret;
		}
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	
	cin >> N >> Q;
	
	//for(Bsize=0;(Bsize+1)*(Bsize+1)<N;++Bsize);
	for(Bsize=0;Bsize*Bsize<N;++Bsize);
	Bcnt=N/Bsize;
	if(N%Bsize!=0)	++Bcnt;
	for(int i=1;i<=Bcnt;++i)
		B[i].Size=min(Bsize, N-(i-1)*Bsize);
	
	P[1].x=1;P[1].y=1;
	for(int i=2;i<=N;++i){
		P[i].x=P[i-1].x;
		P[i].y=P[i-1].y+1;
		if(P[i].y>Bsize){
			++P[i].x;
			P[i].y-=Bsize;
		}
	}
	
	for(int i=1;i<=N;++i)
		B[P[i].x].Num[P[i].y]=i;
	
	for(int i=1;i<=Bcnt;++i)
		B[i].Update();
	
	while(Q--){
		cin >> L >> R;
		if(L==R){
			cout << ANS << endl;
			continue;
		}
		if(L>R)	swap(L, R);
		if(getNum(L)<getNum(R)){
			NumL=getNum(L);
			NumR=getNum(R);
			ANS+=1LL;
			ANS+=(long long)(Calc(L, R)<<1);
		}
		if(getNum(L)>getNum(R)){
			NumR=getNum(L);
			NumL=getNum(R);
			ANS-=1LL;
			ANS-=(long long)(Calc(L, R)<<1);
		}
		swap(B[P[L].x].Num[P[L].y], B[P[R].x].Num[P[R].y]);
		B[P[L].x].Update();B[P[R].x].Update();
		cout << ANS << endl;
	}
	
	return 0;
}