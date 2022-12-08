#include <iostream>
#include <string>
#include <cassert>

using namespace std;

const int MAXL=400011;
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

string input;
int L;
int A[MAXL], Al;
int B[MAXL], Bl;
int C[4];

int Fac[MAXL], Inv[MAXL];

inline int val(int a, int b){
	return (a<<1)+b;
}

int Com(int n, int m){
	return mul(Fac[n], mul(Inv[m], Inv[n-m]));
}

int D(int a, int b){
	if(b==0)	return a==0;
	return Com(a+b-1, b-1);
}

int Cnt(int p, int i, int c[]){
	int Sc[2];
	Sc[!i]=c[val(i, !i)];
	Sc[i]=c[val(!i, i)]+1;
	assert(Sc[i]>=Sc[!i] && Sc[i]<=Sc[!i]+1);
	assert(c[0]+Sc[0]+c[3]+Sc[1]==p);
	return mul(D(c[0], Sc[0]), D(c[3], Sc[1]));
}

int Calc(int X[], int Xl){
	if(Xl<L)	return 0;
	if(Xl>L)	return Cnt(L, 1, C);
	int ret=0;
	int c[4];
	for(int i=0;i<4;++i)	c[i]=C[i];
	for(int i=L, v;i>=1;--i){
		if(i<L){
			v=val(X[i+1], X[i]);
			if(c[v]==0)	break;
			--c[v];
		}
		if(i>1 && X[i-1]){
			v=val(X[i], 0);
			--c[v];
			ret=sum(ret, Cnt(i-1, 0, c));
			++c[v];
		}
		if(i==1)	ret=sum(ret, 1);
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	
	cin >> input;Al=input.length();
	for(int i=Al;i>=1;--i){
		A[i]=input[Al-i]-'0';
	}
	
	--A[1];
	for(int i=1;A[i]<0;++i){
		--A[i+1];
		A[i]+=2;
	}
	
	while(Al>0 && A[Al]==0)	--Al;
	
	cin >> input;Bl=input.length();
	for(int i=Bl;i>=1;--i){
		B[i]=input[Bl-i]-'0';
	}
	
	cin >> C[0] >> C[1] >> C[2] >> C[3];
	
	if(C[2]-1!=C[1] && C[1]!=C[2]){
		cout << "0" << endl;
		return 0;
	}
	
	L=C[0]+C[1]+C[2]+C[3]+1;
	
	Fac[0]=1;
	for(int i=1;i<=L;++i)	Fac[i]=mul(Fac[i-1], i);
	Inv[L]=pow(Fac[L], MOD-2);
	for(int i=L;i>=1;--i)	Inv[i-1]=mul(Inv[i], i);
	
	/*
	cout << L << endl;
	for(int i=L;i>=1;--i)	cout << A[i];
	cout << endl;
	for(int i=L;i>=1;--i)	cout << B[i];
	cout << endl;
	*/
	
	int Ans=sum(Calc(B, Bl), MOD-Calc(A, Al));
	
	cout << Ans << endl;
	
	return 0;
}