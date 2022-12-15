#include<bits/stdc++.h>
using namespace std;

long long ans;
int n,m,x,y,ch,cl;
bool boh[100001],bol[100001];

int main()
{
	scanf("%d%d",&n,&m); 
	ans=1ll*n*n,ch=cl=0;
	memset(boh,0,sizeof(boh));
	memset(bol,0,sizeof(bol));
	for (int i=1; i<=m; i++)
	{
		scanf("%d%d",&x,&y);
		if (!boh[x]) boh[x]=1,ans-=(n-cl),ch++;
		if (!bol[y]) bol[y]=1,ans-=(n-ch),cl++;
		printf("%I64d ",ans);
	}
	return 0;
}