#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN=200111;
const int MAXM=2000001;
const int MOD=1000000007;

int sr;
int sum(int a, int b){
	sr=a+b;
	if(sr>=MOD)	sr-=MOD;
	return sr;
}

int mul(int a, int b){
	return (int)((1LL*a*b)%(1LL*MOD));
}

int pow(int a, int k){
	int ret=1, t=a;
	while(k){
		if(k&1)	ret=mul(ret, t);
		t=mul(t, t);
		k>>=1;
	}
	return ret;
}

int M=2000000;

bool isP[MAXM];
int P[MAXM], Pc;
int Id[MAXM], MinP[MAXM];

int N;
int A[MAXN];
bool _[MAXN];
int Mt[MAXM], Mc[MAXM];

void Push(int p, int t){
	if(Mt[p]<t)	{Mt[p]=t;Mc[p]=1;}
	else if(Mt[p]==t)	++Mc[p];
}

bool Ask(int p, int t){
	return Mt[p]>t || Mc[p]>1;
}

void Push(int v){
	for(int p=MinP[v], c=0;v>1;){
		v/=p;++c;
		if(MinP[v]!=p){
			Push(Id[p], c);
			p=MinP[v];c=0;
		}
	}
}

bool Test(int v){
	bool ret=true;
	for(int p=MinP[v], c=0;v>1;){
		v/=p;++c;
		if(MinP[v]!=p){
			ret&=Ask(Id[p], c);
			p=MinP[v];c=0;
		}
	}
	return ret;
}

int Calc(){
	int ret=1;
	for(int i=Pc;i>=1;--i){
		ret=mul(ret, pow(P[i], Mt[i]));
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	
	for(int i=2;i<=M;++i)	isP[i]=true;
	for(int i=2;i<=M;++i){
		if(isP[i]){
			P[++Pc]=i;
			Id[i]=Pc;
			MinP[i]=i;
		}
		for(int j=1;j<=Pc && P[j]<=M/i;++j){
			isP[i*P[j]]=false;
			MinP[i*P[j]]=P[j];
			if(i%P[j]==0)	break;
		}
	}
	
	cin >> N;
	
	for(int i=1;i<=N;++i)
		cin >> A[i];
	
	sort(A+1, A+N+1);
	
	for(int i=N;i>=1;--i){
		_[i]=Mt[Id[A[i]]];
		Push(A[i]-_[i]);
	}
	
	int Ans=Calc();
	
	bool Add=false;
	for(int i=N;i>=1 && !Add;--i){
		Add|=Test(A[i]-_[i]);
	}
	
	Ans=sum(Ans, Add);
	
	cout << Ans << endl;
	
	return 0;
}