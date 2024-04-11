#include<bits/stdc++.h>
#define N 400010
using namespace std;
int n,k,i,rank[N],sa[N],A[N],V[N],tsa[N],cnt,l1,r1,l2,r2,f[N];
int m,tot,j,en[N],num[N],trank[N],hei[N],g[N],gs[N],st1[N],st2[N];
long long an[N];
char s[N];
int main()
{
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++)
	{
		scanf("%s",s+1);
		m=strlen(s+1);
		rank[++tot]=27;
		A[tot]=rank[tot];
		for(j=1;j<=m;j++)
		{
			rank[++tot]=s[j]-'a'+1;
			A[tot]=rank[tot];
			V[tot]=i;
		}
		en[i]=tot;
	}
	for(i=1;i<=tot;i<<=1)
	{
		memset(num,0,sizeof(num));
		for(j=1;j<=tot;j++)num[rank[j+i]]++;
		for(j=1;j<=max(tot,27);j++)num[j]+=num[j-1];
		for(j=tot;j>=1;j--)tsa[num[rank[j+i]]--]=j;
		memset(num,0,sizeof(num));
		for(j=1;j<=tot;j++)num[rank[tsa[j]]]++;
		for(j=1;j<=max(tot,27);j++)num[j]+=num[j-1];
		for(j=tot;j>=1;j--)sa[num[rank[tsa[j]]]--]=tsa[j];
		for(j=1;j<=tot;j++)trank[j]=rank[j];
		for(j=1;j<=tot;j++)
			if(trank[sa[j]]!=trank[sa[j-1]]||trank[sa[j]+i]!=trank[sa[j-1]+i])
				rank[sa[j]]=rank[sa[j-1]]+1;else rank[sa[j]]=rank[sa[j-1]];
	}
	for(i=1;i<=tot;i++)
	{
		hei[i]=max(hei[i-1]-1,0);
		for(;A[i+hei[i]]==A[sa[rank[i]-1]+hei[i]];hei[i]++);
	}
	cnt=0;j=1;l1=1;
	for(i=1;i<=tot;i++)
	{
		gs[V[sa[i-1]]]--;
		if(V[sa[i-1]]!=0&&!gs[V[sa[i-1]]])cnt--;
		for(;cnt<k&&j<=tot;j++)
		{
			if(V[sa[j]]!=0&&!gs[V[sa[j]]])cnt++;
			gs[V[sa[j]]]++;
			for(;hei[sa[j]]<=hei[sa[st1[r1]]]&&r1>=l1;r1--);
			st1[++r1]=j;
		}
		if(st1[l1]==i)l1++;
		if(cnt>=k)
		{
			g[j-1]=l1<=r1?hei[sa[st1[l1]]]:tot;
			for(;g[j-1]>=g[st2[r2]]&&r2>=l2;r2--);
			st2[++r2]=j-1;
		}
		for(;st2[l2]<i&&l2<=r2;l2++);
		if(r2>=l2)f[sa[i]]=min(g[st2[l2]],en[V[sa[i]]]-sa[i]+1);
	}
	cnt=0;j=tot;l1=1;r1=0;l2=1;r2=0;
	for(i=tot;i>=1;i--)
	{
		gs[V[sa[i+1]]]--;
		if(V[sa[i+1]]!=0&&!gs[V[sa[i+1]]])cnt--;
		for(;cnt<k&&j>=1;j--)
		{
			if(V[sa[j]]!=0&&!gs[V[sa[j]]])cnt++;
			gs[V[sa[j]]]++;
			for(;hei[sa[j+1]]<=hei[sa[st1[r1]]]&&r1>=l1;r1--);
			st1[++r1]=j+1;
		}
		if(st1[l1]==i+1)l1++;
		//printf("%d %d %d %d %d\n",i,j,hei[sa[st1[l1]]],l1,r1);
		if(cnt>=k)
		{
			g[j+1]=l1<=r1?hei[sa[st1[l1]]]:tot;
			for(;g[j+1]>=g[st2[r2]]&&r2>=l2;r2--);
			st2[++r2]=j+1;
		}
		for(;st2[l2]>i&&l2<=r2;l2++);
		//printf("%d %d\n",st2[l2],g[st2[l2]]);
		if(r2>=l2)f[sa[i]]=max(f[sa[i]],min(g[st2[l2]],en[V[sa[i]]]-sa[i]+1));
	}
	//for(i=1;i<=tot;i++)printf("%d ",f[i]);puts("");
	for(i=1;i<=tot;i++)an[V[i]]+=f[i];
	for(i=1;i<=n;i++)printf("%I64d ",an[i]);
	puts("");
}