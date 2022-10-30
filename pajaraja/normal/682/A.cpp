#include <iostream>
#include <stdio.h>
using namespace std;
int main(int argc, char** argv) 
{
	long long n,m;
	cin>>n>>m;
	long long a[5],b[5];
	long long s=0;
	for(int i=1;i<5;i++)
	{
		a[i]=(n+5-i)/5;
		b[i]=(m+5-i)/5;
	}
	a[0]=n/5;
	b[0]=m/5;
	s+=a[0]*b[0];
	for(int i=1;i<5;i++) 
	{
		s+=a[i]*b[5-i];
	}
	cout<<s;
	return 0;
}