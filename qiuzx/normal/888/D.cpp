#include <bits/stdc++.h>
using namespace std;
long long wp[11]={1,0,1,2,9,44,265,1854,14833,133496,1334961};
long long c[1010][1010];
long long n,k,ans=0;
int main(){
	int i,j;
	cin>>n>>k;
	memset(c,0,sizeof(c));
	c[0][0]=1;
	for(i=1;i<1010;i++)
	{
		c[i][0]=1;
		for(j=0;j<=i;j++)
		{
			c[i][j]=c[i-1][j]+c[i-1][j-1];
		}
	}
	for(i=0;i<=k;i++)
	{
		ans+=c[n][n-i]*wp[i];
	}
	cout<<ans<<endl;
	return 0;
}