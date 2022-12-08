#include <iostream>
#include <cstdlib>

using namespace std;

const int MAXP=1111111;

long long A, B, P;
long long X;
long long L[MAXP], I[MAXP];
int PP;

long long inv, aim, need, len;
long long pow(long long a, long long k){
	long long ret=1LL, t=a;
	while(k>0LL){
		if(k%2LL==1LL){
			ret*=t;
			ret%=P;
		}
		t*=t;
		t%=P;
		k/=2LL;
	}
	return ret;
}

long long ANS=0LL;
long long POS;

int main(){
	ios_base::sync_with_stdio(false);
	
	cin >> A >> B >> P;
	cin >> X;
	PP=(int)(P);
	len=P*(P-1LL);
	L[0]=1LL;
	for(int i=1;i<=PP-1;++i)	L[i]=L[i-1]*A%P;
	I[PP-1]=pow(L[PP-1], P-2LL);
	for(int i=PP-2;i>=0;--i)	I[i]=I[i+1]*A%P;
	for(int i=1;i<=PP-1;++i){
		inv=I[i];
		aim=B*inv%P;
		need=((long long)(i)+P-aim)%P;
		POS=need*(P-1LL)+(long long)(i);
		if(X>=POS)	ANS+=((X-POS)/len)+1LL;
	}
	
	cout << ANS << endl;
	
	return 0;
}

/*
2 3 5 8

2

*/

/*
4 6 7 13

1

*/

/*
233 233 10007 1

1

*/