#include<bits/stdc++.h>
using namespace std;

const int M=105;
int n,dp[M*M][M],ans,t,suma,sumb;

struct node
{
	int a,b;
}a[M];

bool cmp(node a,node b){return a.b>b.b;}

int main()
{
	cin>>n;
	for (int i=1;i<=n;i++)cin>>a[i].a,suma+=a[i].a;
	for (int i=1;i<=n;i++)cin>>a[i].b;
	sort(a+1,a+1+n,cmp);
	while(sumb<suma)t++,sumb+=a[t].b;
	cout<<t<<' ';memset(dp,128,sizeof(dp));dp[0][0]=0;
	for (int i=1;i<=n;i++)
		for (int j=sumb;j>=a[i].b;j--)
			for (int k=1;k<=t;k++)
				dp[j][k]=max(dp[j][k],dp[j-a[i].b][k-1]+a[i].a);
	for (int i=suma;i<=sumb;i++)ans=max(ans,dp[i][t]);
	ans=suma-ans;
	cout<<ans;
	return 0;
}