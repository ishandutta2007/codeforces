#include <iostream>
#include <string>
#include <cassert>

using namespace std;

const long long MOD=1000000009LL;

string input;
long long N, A, B, K;
long long iA, iB;
long long AkBk, iAB1;

long long lsum(long long a, long long b){
	long long r=a+b;
	if(r>=MOD)	r-=MOD;
	return r;
}

long long lmul(long long a, long long b){
	return (a*b)%MOD;
}

long long pow(long long a, long long k){
	long long ret=1LL, t=a;
	while(k>0LL){
		if(k%2LL==1LL)	ret=lmul(ret, t);
		t=lmul(t, t);
		k/=2LL;
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	
	cin >> N >> A >> B >> K;
	cin >> input;
	
	long long ANS=0LL, Now;
	
	/*
	if(A==B){
		
		for(long long i=0LL, d;i<K;i+=1LL){
			d=(N-i)/K;
			if(input[i]=='-')	{ANS=lsum(ANS, MOD-lmul(pow(A, N), d+1LL));continue;}
			if(input[i]=='+')	{ANS=lsum(ANS, lmul(pow(A, N), d+1LL));continue;}
			assert(false);
		}
			
	}
	*/
	
	//else{
		swap(A, B);
		iA=pow(A, MOD-2LL);iB=pow(B, MOD-2LL);
		AkBk=lmul(pow(A, K), pow(iB, K));
		iAB1=pow(lsum(AkBk, MOD-1LL), MOD-2LL);
		
		for(long long i=0LL, d;i<K;i+=1LL){
			if(input[i]=='-'){
				Now=lmul(pow(A, i), pow(B, N-i));
				d=(N-i)/K;
				if(iAB1!=0LL)	Now=lmul(Now, lmul(lsum(pow(AkBk, d+1LL), MOD-1LL), iAB1));
				else	Now=lmul(Now, d+1LL);
				ANS=lsum(ANS, MOD-Now);
				continue;
			}
			if(input[i]=='+'){
				Now=lmul(pow(A, i), pow(B, N-i));
				d=(N-i)/K;
				if(iAB1!=0LL)	Now=lmul(Now, lmul(lsum(pow(AkBk, d+1LL), MOD-1LL), iAB1));
				else	Now=lmul(Now, d+1LL);
				ANS=lsum(Now, ANS);
				continue;
			}
			assert(false);
		}
	//}
	
	assert(ANS>=0LL && ANS<MOD);
	
	cout << ANS << endl;
	
	return 0;
}

/*
2 1 1 3
+-+

1

*/