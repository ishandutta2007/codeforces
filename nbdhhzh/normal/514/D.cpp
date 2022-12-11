#include<bits\stdc++.h>
using namespace std;
int n,m,k;
int a[100001][6];
int q[100001][6],h[6]={1,1,1,1,1,1},t[6];
int mx=0,ans[6];
int main()
{
	int i,j,l,ii,jj;
	scanf("%d%d%d",&n,&m,&k);
	for(i=1;i<=n;i++)
	for(j=1;j<=m;j++)scanf("%d",&a[i][j]);
	for(i=1,j=1;i<=n;i++)
	{
		for(l=1;l<=m;l++)
		{
			while(h[l]<=t[l]&&q[t[l]][l]<a[i][l])t[l]--;
			q[++t[l]][l]=a[i][l];
		}
		int s=0;
		for(l=1;l<=m;l++)s+=q[h[l]][l];
		while(j<=i&&s>k)
		{
			for(l=1;l<=m;l++)if(h[l]<=t[l]&&q[h[l]][l]==a[j][l])h[l]++;
			j++;
			s=0;
			for(l=1;l<=m;l++)s+=q[h[l]][l];
		}
		if(i-j+1>mx)
		{
			mx=i-j+1;
			for(l=1;l<=m;l++)ans[l]=q[h[l]][l];
		}
	}
	for(l=1;l<=m;l++)printf("%d ",ans[l]);printf("\n");
	return 0;
}