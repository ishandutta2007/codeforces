#include<bits/stdc++.h>
using namespace std;

#define pn putchar('\n')
#define ps putchar(' ')

const int B=256,inf=114514;
int n,q,a[10010],len,p[10010],f[17][257][257],Ans[100010],ansn,ans[2200010][2],bel[10010],pa[10010],P[257],o[21],oN,l,r,A[17][257];
struct node{int f[257][257];};

void print(int x)
{
	if (!x) putchar('0'); else
	{
		oN=0;
		while (x) o[++oN]=x%10,x/=10;
		for (int i=oN; i; i--) putchar(o[i]+48);
	}
}

node solve(int l,int r)
{
	node A;
	if (l==r)
	{
		A.f[P[l]][P[l]]=pa[P[l]];
		return A;
	}
	int mid=(l+r)>>1;
	node F=solve(l,mid),G=solve(mid+1,r);
	for (int J=l; J<=r; J++)
		for (int K=l; K<=r; K++)
		{
			int j=P[J],k=P[K];
			if (j>k) continue;
			int l1=inf,r1=0,l2=inf,r2=0;
			for (int o=l; o<=mid; o++)
				if (P[o]>=j&&P[o]<=k) l1=min(l1,P[o]),r1=max(r1,P[o]);
			for (int o=mid+1; o<=r; o++)
				if (P[o]>=j&&P[o]<=k) l2=min(l2,P[o]),r2=max(r2,P[o]);
			if (!r1) A.f[j][k]=G.f[j][k]; else
			if (!r2) A.f[j][k]=F.f[j][k]; else 
			ans[++ansn][0]=F.f[l1][r1],ans[ansn][1]=G.f[l2][r2],A.f[j][k]=ansn+n;
		}
	return A;
}

int lowb(int b,int x)
{
	int l=1,r=(b==bel[n]?((n-1)%B+1):B),mid,ans=r+1;
	while (l<=r)
	{
		mid=(l+r)>>1;
		if (A[b][mid]>=x) r=mid-1,ans=mid; else l=mid+1;
	}
	return ans;
}

int main()
{
	scanf("%d%d",&n,&q),ansn=0;
	for (int i=1; i<=n; i++) scanf("%d",&a[i]),p[a[i]]=i,bel[i]=(i-1)/B+1;
	for (int i=1,b=1; i<=n; i+=B,b++)
	{
		len=0;
		for (int j=i; j<i+B&&j<=n; j++) pa[++len]=p[j];
		sort(pa+1,pa+1+len);
		for (int j=1; j<=len; j++) P[a[pa[j]]-i+1]=j,A[b][j]=pa[j];
		for (int j=1; j<=len; j++) f[b][j][j]=pa[j];
		if (len!=1) 
		{
			int mid=(len+1)>>1;
			node F=solve(1,mid),G=solve(mid+1,len);
			for (int j=1; j<=len; j++)
				for (int k=j+1; k<=len; k++)
				{
					int l1=inf,r1=0,l2=inf,r2=0;
					for (int o=1; o<=mid; o++)
						if (P[o]>=j&&P[o]<=k) l1=min(l1,P[o]),r1=max(r1,P[o]);
					for (int o=mid+1; o<=len; o++)
						if (P[o]>=j&&P[o]<=k) l2=min(l2,P[o]),r2=max(r2,P[o]);
					if (!r1) f[b][j][k]=G.f[j][k]; else
					if (!r2) f[b][j][k]=F.f[j][k]; else 
					ans[++ansn][0]=F.f[l1][r1],ans[ansn][1]=G.f[l2][r2],f[b][j][k]=ansn+n;
				}
		}
	}
	for (int i=1; i<=q; i++)
	{
		int la=0;
		scanf("%d%d",&l,&r);
		for (int j=1; j<=bel[n]; j++)
		{
			int L=lowb(j,l),R=lowb(j,r+1)-1;
			if (L<=R) 
			{
				if (!la) la=f[j][L][R];
				else ans[++ansn][0]=la,ans[ansn][1]=f[j][L][R],la=ansn+n;
			}
		}
		Ans[i]=la;
	}
	print(ansn+n),pn;
	for (int i=1; i<=ansn; i++) print(ans[i][0]),ps,print(ans[i][1]),pn;
	for (int i=1; i<=q; i++) print(Ans[i]),ps;
	return pn,0;
}