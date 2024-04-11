#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,a[500005],t=2e7,val=24;
char sum[40000005];
inline int lowbit(int x)
{
	return x&-x;
}
void modify(int x)
{
	x++;
	for(int i=x;i<=t;i+=lowbit(i))
		sum[i]^=1;
}
int query(int x)
{
	int ans=0;
	x++;
	for(int i=x;i;i-=lowbit(i))
		ans^=sum[i];
	return ans;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	/*	for(int j=0;j<=val+1;j++)
		{
			c[(1<<j)+(a[i]&((1<<j)-1))]^=1;
			if(j<=3) printf("i=%d,j=%d,%d\n",i,j,(1<<j)+(a[i]&((1<<j)-1)));
		}*/
	}
	//for(int i=1;i<=val+1;i++)
	//	for(int j=(1<<i)+1;j<(1<<(i+1));j++)
	//		c[j]^=c[j-1];
	//for(int i=0;i<=15;i++)
	//	printf("%d",c[i]);
	//printf("\n");
	int ans=0;
	for(int i=0;i<=val;i++)
	{
		int nw=(1<<i),ct=0;
		for(int j=1;j<=n;j++)
		{
			int x=(a[j]&(nw-1)),y=(a[j]>>i)&1;
			//if(i<=2) printf("i=%d,j=%d,x=%d,y=%d,nw=%d\n",i,j,x,y,nw);
			if(!y)
			{
				ct^=(query(nw-1)^query((nw-x)-1));
			//	if(i&&x>=nw/2) ct^=1;
				ct^=(query(nw+nw-x-1)^query(nw-1));
			}
			else
			{
				ct^=(query(nw*2-1)^query(nw+(nw-x)-1));
			//	if(i&&x>=nw/2) ct^=1;
				ct^=(query((nw-x-1)));
			}
		//	if(i<=2) printf("ct=%d\n",ct); 
			modify(a[j]&((1<<(i+1))-1));
		}
		for(int j=1;j<=n;j++)
			modify(a[j]&((1<<(i+1))-1));
		if(ct) ans|=nw;
	}
	printf("%d",ans);
	return 0;
}