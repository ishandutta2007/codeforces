#include<bits\stdc++.h>
using namespace std;
int n,x[1001],y[1001];
int ok[1001];
int cnt=0;
int main()
{
	int i,j,k;
	scanf("%d%d%d",&n,&x[0],&y[0]);
	for(i=1;i<=n;i++)scanf("%d%d",&x[i],&y[i]);
	for(i=1;i<=n;i++)if(!ok[i])
	{
		cnt++;
		for(j=i+1;j<=n;j++)if((x[i]-x[0])*(y[j]-y[0])==(x[j]-x[0])*(y[i]-y[0]))ok[j]=1;
	}
	printf("%d\n",cnt);
	return 0;
}