#include <iostream>

using namespace std;

const int MAXN=511;
const int MOD=1000000007;

int sr;
int sum(int a, int b){
	sr=a+b;
	if(sr>=MOD)	sr-=MOD;
	return sr;
}

int N;
int Cnt[MAXN];
int Pow[MAXN], Ans;

int main(){
	ios_base::sync_with_stdio(false);
	
	cin >> N;
	
	Pow[0]=1;
	for(int i=1;i<=N;++i)	Pow[i]=sum(Pow[i-1], Pow[i-1]);
	
	for(int i=1, f;i<=N;++i){
		cin >> f;
		if(f>0)	++Cnt[f];
	}
	
	Ans=sum(Pow[N-1], MOD-1);
	for(int i=1;i<=N;++i)	Ans=sum(Ans, MOD+1-Pow[Cnt[i]]);
	
	printf("%d\n", Ans);
	
	return 0;
}