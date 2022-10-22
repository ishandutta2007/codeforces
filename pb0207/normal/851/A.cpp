#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int n,k,t;

int main()
{
	cin>>n>>k>>t;
	if(t<=k)
		cout<<t;
	else
		if(t>=n)
			cout<<n+k-t;
	else
		cout<<k;
}