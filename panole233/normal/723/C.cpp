#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>

using namespace std;

int n,m,sum,ff[2001][2001],ss,fs[2001],ans;
long long a[2001];

struct node
{
	int ans,num;
}f[2001];

bool cmp(node a,node b) {return a.ans<b.ans;}

int main()
{
	scanf("%d%d",&n,&m);
	memset(f,0,sizeof(f)); ss=0;
	for (int i=1; i<=m; i++) f[i].num=i;
	for (int i=1; i<=n; i++)
	{
		cin>>a[i];
		if (a[i]<=m) f[a[i]].ans++;
		else ss++;
	}
	sort(f+1,f+1+m,cmp);
	sum=n/m;
	memset(fs,0,sizeof(fs));
	int i=1,j=m; ans=0;
	for (; i<=m&&f[i].ans<sum&&ss>0;)
	{
		if (ss>sum-f[i].ans) ss-=sum-f[i].ans,fs[f[i].num]+=sum-f[i].ans,ans+=sum-f[i].ans,f[i].ans=sum,i++; else
		if (ss==sum-f[i].ans) ss=0,fs[f[i].num]+=sum-f[i].ans,ans+=sum-f[i].ans,f[i].ans=sum,i++; else
		if (ss<sum-f[i].ans) fs[f[i].num]+=ss,ans+=ss,f[i].ans+=ss,ss=0;
	}
	memset(ff,0,sizeof(ff));
	while (i<=m&&j>=1&&f[i].ans<sum&&f[j].ans>sum) 
	{
		if (f[j].ans-sum>sum-f[i].ans) f[j].ans-=sum-f[i].ans,ff[f[i].num][f[j].num]+=sum-f[i].ans,ans+=sum-f[i].ans,f[i].ans=sum,i++; else
		if (f[j].ans-sum==sum-f[i].ans) f[j].ans=sum,ff[f[i].num][f[j].num]+=sum-f[i].ans,ans+=sum-f[i].ans,f[i].ans=sum,i++,j--;
		if (f[j].ans-sum<sum-f[i].ans) f[i].ans+=f[j].ans-sum,ff[f[i].num][f[j].num]+=f[j].ans-sum,ans+=f[j].ans-sum,f[j].ans=sum,j--;
	}
	printf("%d %d\n",n/m,ans);
	for (int i=1; i<=n; i++) 
	{
		bool bo=0;
		if (a[i]>m) 
		{
			for (int j=1; j<=m; j++)
				if (fs[j]>0) {printf("%d ",j),fs[j]--,bo=1; break;}
			if (!bo) cout<<a[i]<<" ";
		}
		else
		{
			for (int j=1; j<=m; j++)
				if (ff[j][a[i]]>0) {printf("%d ",j); ff[j][a[i]]--; bo=1; break;}
			if (!bo) printf("%d ",a[i]);
		}
	}
	return 0;
}