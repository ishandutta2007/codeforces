#include <iostream>

using namespace std;

const int MAXN=300111;

int N;
long long A[MAXN], B[MAXN];
long long Snake[MAXN];
long long Sum[MAXN];
long long Ud[MAXN], Uu[MAXN];

int main(){
	ios_base::sync_with_stdio(false);
	
	cin >> N;
	for(int i=1;i<=N;++i)	cin >> A[i];
	for(int i=1;i<=N;++i)	cin >> B[i];
	
	Sum[N+1]=0LL;
	Sum[N]=A[N]+B[N];
	for(int i=N-1;i>=1;--i)	Sum[i]=Sum[i+1]+A[i]+B[i];
	
	Snake[0]=0LL;
	for(int i=1, a=0, b=1;i<=N;++i, a+=2, b+=2){
		if(i&1)	Snake[i]=Snake[i-1]+a*A[i]+b*B[i];
		else	Snake[i]=Snake[i-1]+a*B[i]+b*A[i];
	}
	
	Ud[N+1]=0LL;
	Ud[N]=B[N];
	for(int i=N-1, p=3;i>=1;--i, p+=2)
		Ud[i]=Ud[i+1]+Sum[i+1]+B[i]*p;
	
	Uu[N+1]=0LL;
	Uu[N]=A[N];
	for(int i=N-1, p=3;i>=1;--i, p+=2)
		Uu[i]=Uu[i+1]+Sum[i+1]+A[i]*p;
	
	long long Ans=0LL;
	
	for(int i=0, t=0;i<=N;++i, t+=2){
		if(i&1)	Ans=max(Ans, Snake[i]+Uu[i+1]+Sum[i+1]*t);
		else	Ans=max(Ans, Snake[i]+Ud[i+1]+Sum[i+1]*t);
	}
	
	cout << Ans << endl;
	
	return 0;
}