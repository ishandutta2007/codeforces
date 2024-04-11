#include <iostream>

using namespace std;

const int MAXN=1000111;
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

int N, K;
int A[MAXN], L[MAXN], R[MAXN];
int St[MAXN], Top;
int C[MAXN];

int Calc(int p, int l, int r){
	l-=(p-1);r-=(p-1);
	return C[r]-C[l-1];
}

int main(){
	ios_base::sync_with_stdio(false);
	
	cin >> N >> K;--K;
	
	for(int i=K+1;i<=N;i+=K)	C[i]=1;
	for(int i=1;i<=N;++i)	C[i]+=C[i-1];
	
	for(int i=1;i<=N;++i)
		cin >> A[i];
	
	Top=0;St[0]=0;
	for(int i=1;i<=N;++i){
		while(Top>0 && A[St[Top]]<A[i])	--Top;
		L[i]=St[Top]+1;
		St[++Top]=i;
	}
	
	Top=0;St[0]=N+1;
	for(int i=N;i>=1;--i){
		while(Top>0 && A[St[Top]]<=A[i])	--Top;
		R[i]=St[Top]-1;
		St[++Top]=i;
	}
	
	int Ans=0;
	for(int i=1;i<=N;++i){
		if(R[i]-i>i-L[i]){
			for(int j=L[i];j<=i;++j){
				Ans=sum(Ans, mul(Calc(j, i, R[i]), A[i]));
			}
		}
		else{
			for(int j=i;j<=R[i];++j){
				Ans=sum(Ans, mul(Calc(N+1-j, N+1-i, N+1-L[i]), A[i]));
			}
		}
	}
	
	cout << Ans << endl;
	
	return 0;
}