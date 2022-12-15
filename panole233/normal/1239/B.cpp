#include<bits/stdc++.h>
using namespace std;

int n,sum[300010],p[300010],pn,pp[300010],ppn,ans,p1,p2,mi,S[300010];
char s[300010];

int calc(int l,int r)
{
	for (int i=1; i<=n; i++) S[i]=sum[i];
	if (s[l-1]=='(') 
	{
		for (int i=l; i<r; i++) S[i]-=2;
	} else
	{
		for (int i=l; i<r; i++) S[i]+=2;
	}
	int mi=0,cnt=0;
	for (int i=1; i<=n; i++) if (S[i]<mi) mi=S[i];
	for (int i=1; i<=n; i++) if (S[i]==mi) cnt++;
	return cnt;
}

int main()
{
	scanf("%d%s",&n,s),sum[0]=0;
	for (int i=1; i<=n; i++) sum[i]=sum[i-1]+(s[i-1]=='('?1:-1);
	if (sum[n]!=0)
	{
		puts("0"),puts("1 1");
		return 0;
	}
	mi=pn=0;
	for (int i=1; i<=n; i++)
		if (sum[i]<mi) mi=sum[i];
	for (int i=1; i<=n; i++) if (sum[i]==mi) p[++pn]=i;
	ans=pn,p1=p2=1;
	if (mi<-1)
	{
		int l=0,r=0;
		for (int i=1; i<=n; i++) if (sum[i]<=mi+1)
		{
			if (!l) l=i;
			r=i;
		}
		if (calc(l,r+1)>ans) ans=calc(l,r+1),p1=l,p2=r+1;
	}
	if (mi<0)
	{
		int l=0,r=0;
		for (int i=1; i<=n; i++) if (sum[i]==mi)
		{
			if (!l) l=i;
			r=i;
		}
		if (calc(l,r+1)>ans) ans=calc(l,r+1),p1=l,p2=r+1;
	}
	for (int i=1; i<=n; i++)
	{
		if (sum[i]==mi+1) break;
		if (s[i-1]=='(') 
		{
			for (int j=i+1; j<=n; j++)
				if (sum[j]==mi+1) 
				{
					if (calc(i,j)>ans) ans=calc(i,j),p1=i,p2=j;
					break;
				}
			break;
		}
	}
	for (int i=n-1; i; i--)
	{
		if (sum[i]==mi+1) break;
		if (s[i-1]==')')
		{
			for (int j=i-1; j; j--)
				if (sum[j]==mi+1)
				{
					if (calc(j,i)>ans) ans=calc(j,i),p1=i,p2=j;
					break;
				}
			break;
		}
	}
	for (int i=1; i<=n; i++)
	{
		if (sum[i]==mi) break;
		if (s[i-1]=='(') 
		{
			for (int j=i+1; j<=n; j++)
				if (sum[j]==mi) 
				{
					if (calc(i,j)>ans) ans=calc(i,j),p1=i,p2=j;
					break;
				}
			break;
		}
	}
	for (int i=n-1; i; i--)
	{
		if (sum[i]==mi) break;
		if (s[i-1]==')')
		{
			for (int j=i-1; j; j--)
				if (sum[j]==mi)
				{
					if (calc(j,i)>ans) ans=calc(j,i),p1=i,p2=j;
					break;
				}
			break;
		}
	}
	ppn=0;
	for (int i=1; i<p[1]; i++)
		if (sum[i]==mi+1) pp[++ppn]=i;
	for (int j=1; j<ppn; j++)
		{
			int cnt=0;
			for (int k=pp[j]+1; k<pp[j+1]; k++)
				if (sum[k]==mi+2) cnt++;
			if (pn+cnt>ans) ans=pn+cnt,p1=pp[j]+1,p2=pp[j+1];
		}
	ppn=0;
	for (int i=p[pn]+1; i<=n; i++)
		if (sum[i]==mi+1) pp[++ppn]=i;
	for (int j=1; j<ppn; j++)
		{
			int cnt=0;
			for (int k=pp[j]+1; k<pp[j+1]; k++)
				if (sum[k]==mi+2) cnt++;
			if (pn+cnt>ans) ans=pn+cnt,p1=pp[j]+1,p2=pp[j+1];
		}
	
	for (int i=1; i<pn; i++)
	{
		ppn=0;
		for (int j=p[i]+1; j<p[i+1]; j++)
			if (sum[j]==mi+1) pp[++ppn]=j;
		if (ppn>ans) ans=ppn,p1=p[i]+1,p2=p[i+1];
		for (int j=1; j<ppn; j++)
		{
			int cnt=0;
			for (int k=pp[j]+1; k<pp[j+1]; k++)
				if (sum[k]==mi+2) cnt++;
			if (pn+cnt>ans) ans=pn+cnt,p1=pp[j]+1,p2=pp[j+1];
		}
	}
	printf("%d\n%d %d\n",ans,p1,p2);
	return 0;
}