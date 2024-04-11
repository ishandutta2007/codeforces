#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,t,tans[5000005][2],a[1000005],b[1000005];
void mswap(int x,int y)
{
	tans[++t][0]=x;
	tans[t][1]=y;
	swap(b[a[x]],b[a[y]]);
	swap(a[x],a[y]);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		b[a[i]]=i; 
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=i)
		{
			int nw=b[i];
			if(nw<=n/2&&i<=n/2)
			{
				//tans[++t][0]=b[i];
				//tans[t][1]=n;
				//tans[++t][0]=n;
				//tans[t][1]=i;
				mswap(b[i],n);
				mswap(n,i);
				//int nww=a[b[i]];
				///b[nww]=b[i];
				//b[a[n]]=n;
				//b[]
			}
			if(nw>n/2&&i<=n/2)
			{
				/*tans[++t][0]=b[i];
				tans[t][1]=n;
				tans[++t][0]=n;
				tans[t][1]=i;
				swap(a[b[i]],a[n]);
				swap(a[n],a[i]);*/
				mswap(nw,1);
				mswap(1,n);
				mswap(n,i);
				if(i!=1)
				{
					mswap(1,n);
					mswap(nw,1);
				}
			}
			if(nw>n/2&&i>n/2)
			{
				//tans[++t][0]=b[i];
				//tans[t][1]=1;
				//tans[++t][0]=1;
				//tans[t][1]=i;
				//tans[++t][0]=b[i];
				//tans[t][1]=1;
				int nww=b[i];
				mswap(nww,1);
				mswap(1,i);
				mswap(nww,1);
			}
		}
	}
	printf("%d\n",t);
	for(int i=1;i<=t;i++)
	{
		printf("%d %d\n",tans[i][0],tans[i][1]); 
	}
	return 0;
}