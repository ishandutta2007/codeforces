#include <iostream>
using namespace std;
#define ll long long


long long mod,l,r,k;
long long high;

void check(long long q)
{
	if(((r/q)-((l-1)/q))>=k)
		high = max(high,q);
}

void getFib(long long n,ll &a,ll &b,ll &c,ll &d)
{
	if(n==0)
	{
		a = d = 1;
		b = c = 0;
		return;
	}
	ll m1,m2,m3,m4;
	getFib(n/2,a,b,c,d);
	m1 = (a*a+b*c)%mod;
	m2 = (a*b+b*d)%mod;
	m3 = (c*a+d*c)%mod;
	m4 = (c*b+d*d)%mod;
	if(n%2)
		a = m3, b = m4, c = (m1+m3)%mod, d = (m2+m4)%mod;
	else
		a = m1, b = m2, c = m3, d = m4;
}

int main()
{
	cin >> mod >> l >> r >> k;
	high = 0;
	for(long long q=1;q*q<=max(l,r);q++)
		check(q);
	for(long long a=1;a*a<=r;a++)
		if(r/a) check(r/a);
	for(long long a=1;a*a<=l;a++)
		if((l-1)/a) check((l-1)/a);
	ll a,b,c,d;
	getFib(high,a,b,c,d);
	cout << b << endl;
}