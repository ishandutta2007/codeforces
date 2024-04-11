#include<cstdio>
#include<iostream>
using namespace std;

const int N=105;

int n,k,a[N],res,r;

int main()
{
	cin>>n>>k;
	res=k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		r+=a[i];
		res-=min(r,8);
		r-=min(r,8);
		if(res<=0)
		{
			cout<<i;
			return 0;
		}
	}
	cout<<-1;
}