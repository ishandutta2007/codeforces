#include <cstdio>

const int MOD=1000000007;
const int MAXL=10000011;

inline int sum(const int &a, const int &b){
	return (a+b>=MOD)?(a+b-MOD):(a+b);
}

inline int mul(const int &a, const int &b){
	return (int)((1LL*a*b)%(long long)(MOD));
}

int pow(int t, int k){
	int r=1;
	while(k){
		if(k&1)	r=mul(r, t);
		t=mul(t, t);
		k>>=1;
	}
	return r;
}

int L, Fac[MAXL], Inv[MAXL];

int Ans;

int N, M;

int A(int n, int m){
	return mul(Fac[n], Inv[n-m]);
}

int C(int n, int m){
	if(n<m)	return 0;
	return mul(Fac[n], mul(Inv[m], Inv[n-m]));
}

int F(int n, int m){
	return (n==m)?1:mul(m, pow(n, n-m-1));
}

int main(){
	
	L=10000000;
	Fac[0]=1;
	for(int i=1;i<=L;++i)	Fac[i]=mul(Fac[i-1], i);
	Inv[L]=pow(Fac[L], MOD-2);
	for(int i=L;i>=1;--i)	Inv[i-1]=mul(Inv[i], i);
	
	scanf("%d%d", &N, &M);
	
	for(int i=1;i<=N-1;++i)
		Ans=sum(Ans, mul(mul(A(N-2, i-1), C(M-1, i-1)), mul(F(N, i+1), pow(M, N-i-1))));
	
	printf("%d\n", Ans);
	
	return 0;
}