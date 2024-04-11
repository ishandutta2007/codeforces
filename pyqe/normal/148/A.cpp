#include <iostream>
#include <algorithm>

using namespace std;

long long lcm(long long k,long long l, long long m,long long n)
{
	long long z;
	
	z=k*l/__gcd(k,l);
	z=z*m/__gcd(z,m);
	z=z*n/__gcd(z,n);
	return z;
}

int main()
{
	long long k,l,m,n,d,z;
	
	cin>>k>>l>>m>>n>>d;
	z=d;
	z-=d/k;
	z-=d/l;
	z-=d/m;
	z-=d/n;
	z+=d/lcm(k,l,1,1);
	z+=d/lcm(k,1,m,1);
	z+=d/lcm(k,1,1,n);
	z+=d/lcm(1,l,m,1);
	z+=d/lcm(1,l,1,n);
	z+=d/lcm(1,1,m,n);
	z-=d/lcm(k,l,m,1);
	z-=d/lcm(k,l,1,n);
	z-=d/lcm(k,1,m,n);
	z-=d/lcm(1,l,m,n);
	z+=d/lcm(k,l,m,n);
	cout<<d-z<<endl;
}