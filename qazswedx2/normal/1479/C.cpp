#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int L,R,n=22,m,tans[1000005][3];
void add(int u,int v,int w)
{
	tans[++m][0]=u;
	tans[m][1]=v;
	tans[m][2]=w;
}
int main()
{
	for(int i=1;i<n;i++)
	{
		int nw;
		if(i==1) nw=1;
		else nw=(1<<(i-2));
		for(int j=i+1;j<n;j++)
			add(i,j,nw);
	}
	scanf("%d%d",&L,&R);
	for(int i=n-2;i>=0;i--)
		if(R-L+1>(1<<i))
		{
			add(i+2,n,R-(1<<i));
			R-=(1<<i);
		}
	add(1,n,L);
	printf("YES\n%d %d\n",n,m);
	for(int i=1;i<=m;i++)
		printf("%d %d %d\n",tans[i][0],tans[i][1],tans[i][2]);
	return 0;
}