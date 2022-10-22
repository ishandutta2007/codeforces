#include<cstdio>
#include<iostream>
using namespace std;

int n;

int main()
{
	cin>>n;
	cout<<n/2<<endl;
	if(n&1)
	{
		for(int i=1;i<=n/2-1;i++)
			cout<<2<<" ";
		cout<<3;
	}
	else
		for(int i=1;i<=n/2;i++)
			cout<<2<<" ";
}