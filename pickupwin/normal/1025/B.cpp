#include <iostream>

using namespace std;

const int MAXN=150011;

int N;
long long A[MAXN], B[MAXN], Num[MAXN];

long long gcd(long long a, long long b){
	return (b==0LL)?a:gcd(b, a%b);
}

int main(){
	ios_base::sync_with_stdio(false);
	
	cin >> N;
	for(int i=1;i<=N;++i){
		cin >> A[i] >> B[i];
		Num[i]=A[i]*B[i];
	}
	
	long long Ans=Num[1];
	for(int i=2;i<=N;++i)	Ans=gcd(Ans, Num[i]);
	
	
	if(Ans<=1LL)	cout << "-1" << endl;
	else{
		long long Temp;
		Temp=gcd(Ans, A[1]);
		if(Temp>1LL)	Ans=Temp;
		Temp=gcd(Ans, B[1]);
		if(Temp>1LL)	Ans=Temp;
		for(long long i=2LL;i<=Ans/i;i+=1LL){
			if(Ans%i==0LL){
				Ans=i;
				break;
			}
		}
		cout << Ans << endl;
	}
	
	return 0;
}