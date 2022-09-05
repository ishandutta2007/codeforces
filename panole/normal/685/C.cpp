#include<bits/stdc++.h>
using namespace std;

const long long inf=6000000000000000000ll;
long long a[100010][3],l[5],r[5],L,R,Mid,Ans,ans[3],nwl[5],nwr[5];
int T,n;

bool check(long long mid)
{
	for (int i=0; i<4; i++) l[i]=-inf,r[i]=inf;
	for (int i=1; i<=n; i++)
		l[0]=max(l[0],a[i][0]+a[i][1]+a[i][2]-mid),
		r[0]=min(r[0],a[i][0]+a[i][1]+a[i][2]+mid),
		l[1]=max(l[1],-a[i][0]+a[i][1]+a[i][2]-mid),
		r[1]=min(r[1],-a[i][0]+a[i][1]+a[i][2]+mid),
		l[2]=max(l[2],a[i][0]-a[i][1]+a[i][2]-mid),
		r[2]=min(r[2],a[i][0]-a[i][1]+a[i][2]+mid),
		l[3]=max(l[3],a[i][0]+a[i][1]-a[i][2]-mid),
		r[3]=min(r[3],a[i][0]+a[i][1]-a[i][2]+mid);
	for (int o=0; o<2; o++)
	{
		bool bo=1;
		for (int i=0; i<4; i++) nwl[i]=l[i]+((l[i]&1)!=o),nwr[i]=r[i]-((r[i]&1)!=o);
		for (int i=0; i<4; i++) 
		{
			if (nwl[i]>nwr[i]) {bo=0; break;}
			if (nwl[i]<-(inf/2)||nwr[i]>(inf/2)) return 1;
		}
		if (!bo) continue;
		if (nwl[1]+nwl[2]+nwl[3]>nwr[0]) continue;
		if (nwr[1]+nwr[2]+nwr[3]<nwl[0]) continue;
		for (int j=0; j<4; j++)
		{
			long long nw=0;
			for (int k=1; k<=j; k++) nw+=nwr[k];
			for (int k=j+1; k<4; k++) nw+=nwl[k];
			if (nw>=nwl[0])
			{
				if (j==0) ans[0]=nwl[1],ans[1]=nwl[2],ans[2]=nwl[3]; else
				{
					for (int k=1; k<j; k++) ans[k-1]=nwr[k];
					for (int k=j+1; k<4; k++) ans[k-1]=nwl[k];
					ans[j-1]=nwr[j]-(nw-nwl[0]);
				}
				return 1;
			}
		}
	}
	return 0;
}

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		for (int i=1; i<=n; i++)
			for (int j=0; j<3; j++) scanf("%I64d",&a[i][j]);
		L=0,R=(3e18);
		while (L<=R)
		{
			Mid=(L+R)>>1;
			if (check(Mid)) Ans=Mid,R=Mid-1; else L=Mid+1;
		}
		check(Ans);
		printf("%I64d %I64d %I64d\n",ans[1]+ans[2]>>1,ans[0]+ans[2]>>1,ans[0]+ans[1]>>1);
	}
	return 0;
}