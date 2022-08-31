#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct pt
{
	int val,id;
	bool operator<(const pt x) const
	{
		return val>x.val;
	}
}a[100005];
int t,n,m,f[1000005],ft,tans[1005][1005];
int tmp[1000005];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&m,&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i].val),a[i].id=i;
		sort(a+1,a+n+1);
		int k;
		for(int i=1;i<=m;i++)
		{
			if(i*((i+1)/2)>=a[1].val&&i*i-(i/2)*(i/2)>=m)
			{
				k=i;
				break;
			}
		}
		for(int i=1;i<=k*k;i++)
			f[i]=0;
		ft=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=a[i].val;j++)
				f[++ft]=a[i].id;
		for(int i=1;i<=k;i++)
			for(int j=1;j<=k;j++)
				tans[i][j]=0;
		int A=k/2,B=(k+1)/2;
		int nw0=1,nw1=A*B+1,nw2=2*A*B+1,nw3=k*k-(k/2)*(k/2)+1;
		if(f[nw1-1]==f[nw1])
		{
			int len=A*B;
		//	printf("len=%d,nw1=%d,%d\n",len,nw1,k*k-len+1);
			memcpy(tmp,f+nw1,sizeof(int)*len);
			memcpy(f+nw1,f+nw3-len,sizeof(int)*len);
			memcpy(f+nw3-len,tmp,sizeof(int)*len);
		}
	/*	for(int i=1;i<=k*k;i++)
			printf("%d ",f[i]);
		printf("\n");*/
		for(int i=nw0;i<nw1;i++)
			tans[(i-nw0)/A*2+1][(i-nw0)%A*2+2]=f[i];
		for(int i=nw1;i<nw2;i++)
			tans[(i-nw1)/B*2+2][(i-nw1)%B*2+1]=f[i];
		for(int i=nw2;i<nw3;i++)
			tans[(i-nw2)/B*2+1][(i-nw2)%B*2+1]=f[i];
		printf("%d\n",k);
		for(int i=1;i<=k;i++)
		{
			for(int j=1;j<=k;j++)
				printf("%d ",tans[i][j]);
			printf("\n");
		}
	}
	return 0;
}