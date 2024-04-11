#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,a[100005],vis[100005],tans[1000005][2],t;
void ins(int x,int y)
{
	++t;
	tans[t][0]=x,tans[t][1]=y;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	int nw=1,nw2=1,l=1;
	for(int i=1;i<=n;i++)
	{
		if(!a[i]||vis[i]==1) continue;
		if(a[i]==1)
		{
			ins(i,l);
			l++;
		}
		else if(a[i]==2)
		{
			while(nw2<=n&&(nw2<=i||a[nw2]!=1||vis[nw2])) nw2++;
			if(nw2==n+1)
			{
				printf("-1\n");
				return 0;
			}
			ins(i,l),ins(nw2,l);
			l++;
			vis[nw2]=1;
		}
		else
		{
			while(nw<=n&&(nw<=i||a[nw]==0||vis[nw])) nw++;
			if(nw==n+1)
			{
				printf("-1\n");
				return 0;
			}
			ins(i,l),ins(nw,l);
			vis[nw]=2;
			l++;
		}
	}
	printf("%d\n",t);
	for(int i=1;i<=t;i++)
		printf("%d %d\n",tans[i][1],tans[i][0]);
	return 0;
}