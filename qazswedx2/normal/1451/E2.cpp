#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,a[100005],b[100005],vis[100005];
int queryxor(int x,int y)
{
	printf("XOR %d %d\n",x,y);
	fflush(stdout);
	int ans;
	scanf("%d",&ans);
	return ans;
}
int queryor(int x,int y)
{
	printf("OR %d %d\n",x,y);
	fflush(stdout);
	int ans;
	scanf("%d",&ans);
	return ans;
}
int main()
{
	scanf("%d",&n);
	for(int i=2;i<=n;i++)
		a[i]=queryxor(i-1,i);
	int u=-1,v=-1;
	for(int i=1;i<=n;i++)
		b[i]=b[i-1]^a[i];
	for(int i=1;i<=n;i++)
	{
		if(vis[b[i]])
		{
			u=i,v=vis[b[i]];
			break;
		}
		vis[b[i]]=i;
	//	printf("i=%d,a=%d,b=%d\n",i,a[i],b[i]);
	}
	if(u!=-1)
	{
		int q=queryor(u,v)^b[u];
		printf("! ");
		for(int i=1;i<=n;i++)
			printf("%d ",b[i]^q);
		return 0;
	}
	int q,q1=queryor(vis[0],vis[1]),q2=queryor(vis[0],vis[2]);
	q=((q1>>1)<<1)+(q2&1);
	printf("! ");
	for(int i=1;i<=n;i++)
		printf("%d ",b[i]^q);
	return 0;
}