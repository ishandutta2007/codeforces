#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN=111111;
const int MAXB=333;

int N, M;
long long Temp[MAXB];
int Bs, Bc;
int Type, X, Y;
long long C;

long long labs(long long a){
	return (a>=0LL)?a:(-a);
}

struct Block{
	long long Cn[MAXB];
	long long Co[MAXB];
	long long PaintAll, CnUp, FA;
	long long CnSum;
	long long CoQ[MAXB], CoCnt[MAXB];
	long long SumVal[MAXB], SumCnt[MAXB];
	int Top;
	int L, R, Size;
	
	Block(){
		PaintAll=0LL;
		CnSum=0LL;
		CnUp=0LL;
		Top=0;
		FA=0LL;
	}
	
	void Summer(){
		CnSum=0LL;
		for(int i=1;i<=Size;++i)
			CnSum+=Cn[i];
	}
	
	void Pdw(){
		if(PaintAll<=0LL)	return;	
		for(int i=1;i<=Size;++i){
			Cn[i]+=labs(Co[i]-FA);
			Cn[i]+=CnUp;
			Co[i]=PaintAll;
		}
		PaintAll=0LL;CnUp=0LL;FA=0LL;
	}
	
	void uQ(){
		Top=0;CoQ[0]=0LL;CoCnt[0]=0LL;
		for(int i=1;i<=Size;++i){
			Temp[i]=Co[i];
		}
		sort(Temp+1, Temp+Size+1);
		for(int i=1;i<=Size;++i){
			if(Temp[i]!=Temp[i-1]){
				++Top;
				CoQ[Top]=Temp[i];
				CoCnt[Top]=1LL;
			}
			else	++CoCnt[Top];
		}
		SumCnt[0]=CoCnt[0];SumVal[0]=CoQ[0]*CoCnt[0];
		for(int i=1;i<=Top;++i){
			SumCnt[i]=SumCnt[i-1]+CoCnt[i];
			SumVal[i]=SumVal[i-1]+CoCnt[i]*CoQ[i];
		}
	}
	
	int Find(long long k){
		int Left=0, Right=Top, Mid;
		while(Left<Right){
			Mid=(Left+Right)>>1;
			if(CoQ[Mid+1]<=k)	Left=Mid+1;
			else	Right=Mid;
		}
		Mid=(Left+Right)>>1;
		return Mid;
	}
	
	void ALLP(long long k){
		int at=Find(k);
		CnSum+=(k*SumCnt[at])-SumVal[at];
		CnSum+=(SumVal[Top]-SumVal[at])-(k*(SumCnt[Top]-SumCnt[at]));
		Top=1;
		CoQ[Top]=k;
		CoCnt[Top]=(long long)(Size);
		SumCnt[Top]=(long long)(Size);
		SumVal[Top]=CoCnt[Top]*CoQ[Top];
		if(PaintAll==0LL)	FA=k;
		if(PaintAll>0LL)
			CnUp+=labs(PaintAll-k);
		PaintAll=k;
	}
	
	void HalfP(int l, int r, long long k){
		Pdw();
		for(int i=l;i<=r;++i){
			Cn[i]+=labs(Co[i]-k);
			Co[i]=k;
		}
		Summer();
		uQ();
	}
	
	long long HalfSum(int l, int r){
		Pdw();
		long long ret=0LL;
		for(int i=l;i<=r;++i)
			ret+=Cn[i];
		return ret;
	}
} B[MAXB];

void Update(){
	int Bl=(X-1)/Bs+1, Br=(Y-1)/Bs+1;
	for(int i=Bl+1;i<Br;++i){
		B[i].ALLP(C);
	}
	if(Bl==Br)	B[Bl].HalfP(X-B[Bl].L+1, Y-B[Bl].L+1, C);
	else{
		if(X==B[Bl].L)	B[Bl].ALLP(C);
		else	B[Bl].HalfP(X-B[Bl].L+1, B[Bl].Size, C);
		if(Y==B[Br].R)	B[Br].ALLP(C);
		else	B[Br].HalfP(1, Y-B[Br].L+1, C);
	}
}

long long Query(){
	long long ret=0LL;
	int Bl=(X-1)/Bs+1, Br=(Y-1)/Bs+1;
	for(int i=Bl+1;i<Br;++i){
		ret+=B[i].CnSum;
		//cout << B[i].L << " " << B[i].R << " " << B[i].CnSum << endl;
	}
	if(Bl==Br)	ret+=B[Bl].HalfSum(X-B[Bl].L+1, Y-B[Bl].L+1);
	else{
		ret+=B[Bl].HalfSum(X-B[Bl].L+1, B[Bl].Size);
		ret+=B[Br].HalfSum(1, Y-B[Br].L+1);
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	
	Temp[0]=0;
	
	cin >> N >> M;
	
	Bs=317;
	//for(Bs=0;Bs*Bs<N;++Bs);
	Bc=N/Bs;
	if(N%Bs!=0)	++Bc;
	
	for(int i=1;i<=Bc;++i){
		B[i].R=i*Bs;
		B[i].L=B[i].R-Bs+1;
		B[i].R=min(N, B[i].R);
		B[i].Size=B[i].R-B[i].L+1;
		for(int j=B[i].L, k=1;j<=B[i].R;++j, ++k){
			B[i].Cn[k]=0LL;
			B[i].Co[k]=(long long)(j);
		}
		B[i].uQ();
	}
	
	while(M--){
		cin >> Type >> X >> Y;
		if(Type==1){
			cin >> C;
			Update();
		}
		else{
			cout << Query() << endl;
		}
	}
	
	return 0;
}

/*
91615 7
1 17153 40754 53258865
2 20000 40259
2 17153 40754
1 12126 89872 33671038
2 40755 43529
2 17153 40754
2 19820 43529

1078414181230
1256332371223
93320186400
1718644264077
1617731625075

*/