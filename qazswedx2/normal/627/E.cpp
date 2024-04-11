#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
int n,m,q,k,a[3005][3005],b[3005],c[3005],L[3005],R[3005];
vector<int> val[3005];
int main()
{
	scanf("%d%d%d%d",&n,&m,&q,&k);
	for(int i=1;i<=q;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		a[x][y]++;
		val[x].push_back(y);
	}
	ll ans=0;
	for(int i=n;i>=1;i--)
	{
		for(int j=1;j<=m;j++)
			b[j]+=a[i][j];
		int las=0;
		for(int j=1;j<=m;j++)
		{
			c[j]=b[j];
			if(c[j])
			{
				L[j]=las;
				R[las]=j;
				las=j;
			}
		}
		R[las]=m+1;
		L[m+1]=las;
		c[0]=c[m+1]=1e9;
		for(int j=n;j>=i;j--)
		{
			int sz=val[j].size();
			for(int l=0;l<sz;l++)
			{
				int v=val[j][l];
				int nw=v,ct=c[v];
				while(nw&&ct<k)
				{
					nw=L[nw];
					ct+=c[nw];
				}
			/*	printf("i=%d,j=%d,v=%d,c=",i,j,v);
				for(int r=1;r<=m;r++)
					printf("%d ",c[r]);
				printf("\n");*/
				for(int r=v;r<=m;ct+=c[R[r]],r=R[r])
				{
					while(nw<=v&&ct>k)
					{
						ct-=c[nw];
						nw=R[nw];
					}
				//	printf("i=%d,j=%d,l=%d,r=%d,v=%d,nw=%d,ct=%d\n",i,j,l,r,v,nw,ct);
					if(nw>v) break;
					if(ct==k) ans+=1ll*(nw-L[nw])*(R[r]-r)*(n-j+1);
				}
				c[v]--;
				if(!c[v])
				{
					L[R[v]]=L[v];
					R[L[v]]=R[v];
				}
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}