#include<cstdio>
#include<iostream>
using namespace std;

int n,k,sum;

int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		sum+=x;
	}
	if(sum+n-1==k)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
}