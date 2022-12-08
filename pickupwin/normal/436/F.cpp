#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN=111111;
const int MAXB=411;

int N, w;
long long ANS;
int POS;
int Bs, Bc;

struct Peo{
	int a, b;
} P[MAXN];

bool cmpb(Peo A, Peo B){
	return A.b<B.b;
}

struct Block{
	long long Num[MAXB];
	int Stack[MAXB], Head, Tail;
	long long TT[MAXB];
	int Time;
	int L, R;
	Block(){
		for(int i=0;i<MAXB;++i)	Num[i]=0LL;
		Time=0;
	}
	void Calc(){
		Head=1;Tail=1;
		for(int i=L, j=1;i<=R;++i, ++j){
			//cout << i << endl;
			while(Tail>Head){
				if(Num[Stack[Tail-1]]<Num[j]+TT[Tail-1]*(long long)(j-Stack[Tail-1])){
					--Tail;
				}
				else	break;
			}
			if(Tail==Head){
				Stack[Tail]=j;
				TT[Tail++]=0LL;
			}
			else{
				Stack[Tail]=j;
				TT[Tail]=(Num[Stack[Tail-1]]-Num[j])/(long long)(j-Stack[Tail-1]);
				if((Num[Stack[Tail-1]]-Num[j])%(long long)(j-Stack[Tail-1])!=0LL)	TT[Tail]+=1LL;
				++Tail;
			}
		}
	}
	void Pdw(){
		if(Time==0)	return;
		for(int i=L, j=1;i<=R;++i, ++j){
			Num[j]+=(long long)(Time)*(long long)(i);
		}
		Time=0;
	}
	
	long long Ask(int &p){
		while(Head+1<Tail && TT[Head+1]<=Time)	++Head;
		p=Stack[Head];
		return Num[p]+Time*(long long)(p+L-1);
	}
} B[MAXB];

void Update(int k){
	//cout << "U " << k << endl;
	int Bat=k/Bs+1;
	for(int i=1;i<Bat;++i){
		++B[i].Time;
	}
	B[Bat].Pdw();
	for(int i=B[Bat].L, j=1;i<=k;++i, ++j){
		B[Bat].Num[j]+=i;
	}
	B[Bat].Calc();
}

long long Query(int &p){
	//cout << "Q" << endl;
	long long ret=0LL, rr;
	int pp;
	for(int i=1;i<=Bc;++i){
		rr=B[i].Ask(pp);pp=pp+B[i].L-1;
		if(ret<rr){
			ret=rr;p=pp;
		}
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	
	cin >> N >> w;
	
	Bs=317;
	Bc=316;
	
	for(int i=1;i<=Bc;++i){
		B[i].L=(i-1)*Bs;
		B[i].R=B[i].L+Bs-1;
	}
	B[Bc].R=100000;
	
	for(int i=1;i<=Bc;++i)	B[i].Calc();
	
	for(int i=1;i<=N;++i)	cin >> P[i].a >> P[i].b;
	
	sort(P+1, P+N+1, cmpb);
	
	for(int c=0, j=1;c<=P[N].b+1;++c){
		while(j<=N && P[j].b<c){
			Update(P[j].a);
			++j;
		}
		ANS=(long long)(c)*(long long)(w)*(long long)(N-j+1)+Query(POS);
		cout << ANS << " " << POS << endl;
	}
	
	return 0;
}