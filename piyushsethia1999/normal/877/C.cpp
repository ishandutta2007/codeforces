#include<iostream>
#include<vector>
#include<string.h>
using namespace std;
int main()
{
	int n,i;
	cin>>n;
	cout<<n+n/2<<"\n";
	for(i=0;i<(n/2);i++)
	{
		cout<<2*(i+1)<<"\t";
	}
	for(i=0;i<((n+1)/2);i++)
	{
		cout<<2*i+1<<"\t";
	}
	for(i=0;i<(n/2);i++)
	{
		cout<<2*(i+1)<<"\t";
	}
}