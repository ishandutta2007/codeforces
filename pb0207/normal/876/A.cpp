#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int n,a,b,c,dab,dac,dbc,ans;

int main()
{
	cin>>n>>a>>b>>c;
	int k=min(a,min(b,c));
	n--;
	if(n==0)
	{
		cout<<0;
		return 0;
	}
	if(k==a)
		ans=n*k;
	if(k==b)
		ans=n*k;
	if(k==c)
		ans=min(a,b)+c*(n-1);
	cout<<ans;
}