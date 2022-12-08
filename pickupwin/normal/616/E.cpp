#include <iostream>

using namespace std;

const long long MOD=1000000007LL;

long long N, M, ANS;

long long Time[3333333];

long long norm(long long k){
	return (k%MOD+MOD)%MOD;
}

long long mul(long long a, long long b){
	return (a*b)%MOD;
}

long long del(long long a, long long b){
	long long ret=a-b;
	if(ret<0)	ret+=MOD;
	return ret;
}

long long sum(long long a, long long b){
	long long ret=a+b;
	if(ret>=MOD)	ret-=MOD;
	return ret;
}

long long Calc(long long r, long long l){
	long long a=l+r, b=r-l+1;
	if(a%2LL==0LL)
		return mul((a/2LL)%MOD, b%MOD);
	else	return mul((b/2LL)%MOD, a%MOD);
}

int main(){
	ios_base::sync_with_stdio(false);
	
	cin >> N >> M;
	
	for(int i=0;i<3333333;++i)
		Time[i]=N/(long long)(i+1)+1LL;
	
	for(int i=0;i<3333333;++i){
		if(M>=Time[i]){
			ANS=sum(ANS, del(mul(norm(M-Time[i]+1LL), norm(N)), mul(Calc(M, Time[i]), (long long)(i))));
			M=Time[i]-1LL;
		}
	}
	
	while(M>0){
		ANS=sum(ANS, N%M);
		--M;
	}
	
	cout << ANS << endl;
	
	return 0;
}