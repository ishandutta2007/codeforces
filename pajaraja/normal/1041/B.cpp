#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a,long long b)
{
	if(b==0) return a;
	return gcd(b,a%b);
}
int main()
{
	long long a,b,x,y;
	cin>>a>>b>>x>>y;
	long long d=gcd(x,y);
	x=x/d; y=y/d;
	cout<<min(a/x,b/y);
}