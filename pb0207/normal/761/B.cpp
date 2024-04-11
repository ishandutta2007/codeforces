#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

int a[51],b[51],c[51],d[51],n,l;

int main()
{
	cin>>n>>l;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		cin>>b[i];
	for(int i=1;i<n;i++)
		c[i]=a[i+1]-a[i];
	c[n]=a[1]+l-a[n];
	for(int i=1;i<n;i++)
		d[i]=b[i+1]-b[i];
	d[n]=b[1]+l-b[n];
	for(int i=0;i<n;i++)
	{
		bool flag=true;
		for(int j=1;j<=n;j++)
			if(c[j]!=d[(j+i)%n+1])
				flag=false;
		if(flag)
		{
			cout<<"YES";
			return 0;
		}
	}
	cout<<"NO";
}