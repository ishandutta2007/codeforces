#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
long long euklidov(long long a,long long b)
{
	if(a==0) return b;
	return euklidov(b%a,a);
}
int main(int argc, char** argv) 
{
	long long a,b,c,d,e,s=0,n,z;
	cin>>a>>b>>c>>d>>e;
	n=b*c/euklidov(max(b,c),b+c-max(b,c));
	s+=(a/b)*d;
	s+=(a/c)*e;
	s-=(a/n)*min(d,e);
	cout<<s;
	return 0;
}