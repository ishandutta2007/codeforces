#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,mx=-1e9,id,a[100005],b[100005],c[100005],ct;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int v=n-i-n/(i+1)-(n%(i+1)!=0);
		//printf("n=%d,i=%d,v=%d\n",n,i,v);
		if(v>mx)
		{
			mx=v;
			id=i;
		}
	}
	for(int i=1;i<=n;i+=id+1)
	{
		for(int j=0;j<id;j++)
			if(i+j<n) a[i+j]=1;
	}
	while(1)
	{
		/*for(int i=1;i<=n;i++)
			printf("%d ",b[i]);
		printf("\n");*/
		ct=0;
		for(int i=1;i<=n;i++)
			if(a[i]!=b[i])
			{
				c[++ct]=i;
			}
		if(ct<=id)
		{
			printf("0\n");
			return 0;
		}
		printf("%d\n",id+1);
		for(int i=1;i<=id+1;i++)
			printf("%d ",c[i]),b[c[i]]=1;
		printf("\n");
		fflush(stdout);
		int x;
		scanf("%d",&x);
		for(int i=x,j=1;j<=id+1;i=i%n+1,j++)
			b[i]=0;
	}
	return 0;
}