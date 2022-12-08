#include <iostream>

using namespace std;

const long long MOD=1000000007LL;

long long p, k, m;

long long pow(long long a, long long k){
	long long ret=1LL, t=a;
	while(k>0LL){
		if(k%2LL==1LL){
			ret*=t;
			ret%=MOD;
		}
		t*=t;
		t%=MOD;
		k>>=1;
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	
	cin >> p >> k;
	
	if(k==0LL){
		cout << pow(p, p-1) << endl;
	}
	else if(k==1LL)
		cout << pow(p, p) << endl;
	else{
		m=1;
		long long x=k;
		while(x!=1LL){
			++m;
			x=(x*k)%p;
		}
		cout << pow(p, (p-1)/m) << endl;
	}
	
	return 0;
}