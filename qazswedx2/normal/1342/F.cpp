#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int t,n,a[105],f[17][100005][17][3],sum[100005],cnt[100005],nxt[100005][17];
int b[105][2],bt,vis[105];
int query(int x)
{
	int ans=0;
	for(int i=1;i<=x;i++)
		ans+=vis[i];
	return ans;
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(int i=0;i<(1<<n);i++)
		{
			sum[i]=0;
			cnt[i]=0;
			for(int j=1;j<=n;j++)
				if(i&(1<<(j-1)))
					sum[i]+=a[j],cnt[i]++;
			for(int j=0;j<=n;j++)
			{
				nxt[i][j]=-1;
				for(int k=j+1;k<=n;k++)
					if(i&(1<<(k-1)))
					{
						nxt[i][j]=k;
						break;
					}
			}
		}
		for(int k=0;k<(1<<n);k++)
			for(int l=0;l<=n;l++)
				f[0][k][l][0]=1e9;
		f[0][0][0][0]=0;
		for(int j=0;j<n;j++)
		{
			for(int k=0;k<(1<<n);k++)
				for(int l=0;l<=n;l++)
					f[j+1][k][l][0]=1e9;
			for(int k=0;k<(1<<n);k++)
				for(int l=0;l<=n;l++)
				{
					if(f[j][k][l][0]>=1e9) continue;
				//	printf("i=%d,j=%d,k=%d,f=%d\n",j,k,l,f[j][k][l][0]);
					int mx=((1<<n)-1)^k;
				//while(k&(1<<(nxt-1))) nxt++;
				//	if(nxt>n) continue;
					for(int nw=mx;nw;nw=(nw-1)&mx)
					{
						int v=sum[nw];
						if(v<=f[j][k][l][0]||nxt[nw][l]==-1) continue;
						int (&u)[3]=f[j+1][nw+k][nxt[nw][l]];
						if(v<u[0])
						{
							u[0]=v;
							u[1]=k;
							u[2]=l;
						}
					}
				}
		}
		int id[3]={0},fl=1;
		for(int i=n;i>0&&fl;i--)
			for(int l=1;l<=n&&fl;l++)
				if(f[i][(1<<n)-1][l][0]!=1e9)
				{
					id[0]=i,id[1]=(1<<n)-1,id[2]=l;
					fl=0;
					break;
				}
		printf("%d\n",n-id[0]);
		bt=0;
		while(id[0])
		{
			int (&u)[3]=f[id[0]][id[1]][id[2]];
			b[++bt][0]=u[1]^id[1];
			b[bt][1]=id[2];
			id[0]--;
			id[1]=u[1];
			id[2]=u[2];
		}
		for(int i=1;i<=n;i++)
			vis[i]=1;
		for(int i=1;i<=bt;i++)
		{
			for(int j=1;j<=n;j++)
				if((b[i][0]&(1<<(j-1)))&&j!=b[i][1])
				{
				//	printf("i=%d,b=%d,%d,j=%d\n",i,b[i][0],b[i][1],j);
					printf("%d %d\n",query(j),query(b[i][1]));
					vis[j]=0;
				}
		}
	}
	return 0;
}