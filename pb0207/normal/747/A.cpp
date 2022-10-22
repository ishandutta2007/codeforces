#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int n,a,b;

int main()
{
	cin>>n;
	for(int i=1;i*i<=n;i++)
		if(n%i==0)
			a=i,b=n/i;
	cout<<a<<" "<<b;
}