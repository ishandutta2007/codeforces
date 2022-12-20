#include <iostream>
using namespace std;
#define MOD 1000000007

long long pw(int a,long long e)
{
	if(e==0) return 1;
	int tmp = pw(a,e/2);
	tmp = (tmp*((long long)tmp))%MOD;
	if(e%2) tmp = (tmp*((long long)a))%MOD;
	return tmp;
}
long long inv(int a)
{
	return pw(a,MOD-2);
}

int main()
{
	long long A,B,N,X;
	cin >> A >> B >> N >> X;
	long long an = pw(A,N);
	an = (an*((long long)X))%MOD;
	if(A==1) an = (an + B*(N%MOD))%MOD;
	else
	{
		long long p = ((pw(A,N) - 1)*((long long)inv(A-1)))%MOD;
		an = (an+(B*((long long)p)))%MOD;
	}
	cout << an << '\n';
}