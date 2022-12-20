#include <iostream>
using namespace std;
#define MOD 1000000007

int k;
long long a[100000];

long long pw(long long b, long long e)
{
	if(e==0) return 1;
	long long tmp = pw(b,e/2);
	tmp = (tmp*tmp)%MOD;
	if(e%2) tmp = (tmp*b)%MOD;
	return tmp;
}

int main()
{
	cin >> k;
	for(int i=0;i<k;i++) cin >> a[i];
	bool even = 0;
	for(int i=0;i<k;i++) if(a[i]%2 == 0) even = 1;
	long long den = 2;
	for(int i=0;i<k;i++) den = pw(den,a[i]);
	long long num = den;
	if(even) num = (num+2)%MOD;
	else num = (num+MOD-2)%MOD;
	num = (num*pw(3,MOD-2))%MOD;
	num = (num*pw(2,MOD-2))%MOD;
	den = (den*pw(2,MOD-2))%MOD;
	cout << num << "/" << den << '\n';
}