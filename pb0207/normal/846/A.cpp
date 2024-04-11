#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=1e3+1e2+7;

int n,s[N],ans,tot;

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>s[i];
	s[n+1]=1;
	for(int i=1;i<=n+1;i++)
		if(s[i]==1)	
		{
			tot=0;
			for(int j=1;j<i;j++)
				tot+=(s[j]==0);
			for(int j=i;j<=n;j++)
				tot+=(s[j]==1);
			ans=max(ans,tot);
		}	
	cout<<ans;
}