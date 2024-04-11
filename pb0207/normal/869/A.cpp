#include<cstdio>
#include<iostream>
using namespace std;

int n,a[4000001],b[4000001],v[4000001];

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i],v[a[i]]=1;
	for(int i=1;i<=n;i++)
		cin>>b[i],v[b[i]]=1;
	int ans=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(v[a[i]^b[j]])
				ans++;
	cout<<(ans&1?"Koyomi":"Karen");
}