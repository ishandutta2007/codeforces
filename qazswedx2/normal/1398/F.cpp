#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct pt
{
	int val,id;
	bool operator<(const pt x) const
	{
		return val<x.val;
	}
}a[1000005];
int n,dp[1000005][2],tans[1000005],f[1000005];
char s[1000005];
int find(int x)
{
	if(x==f[x]) return x;
	return f[x]=find(f[x]);
}
void link(int x,int y)
{
	x=find(x),y=find(y);
	if(x==y) return;
	if(x>y) swap(x,y);
	f[x]=y;
}
int main()
{
	scanf("%d%s",&n,s+1);
	for(int i=1;i<=n;i++)
	{
		if(s[i]!='1') dp[i][0]=dp[i-1][0]+1;
		if(s[i]!='0') dp[i][1]=dp[i-1][1]+1;
		a[i].val=max(dp[i][0],dp[i][1]);
		a[i].id=i;
		f[i]=i;
	}
	f[n+1]=n+1;
	sort(a+1,a+n+1);
	int nw=1;
	for(int i=1;i<=n;i++)
	{
		int ct=0;
		for(int l=1,r;l<=n;l=r+1)
		{
			if(i+l-1>n) break;
			r=find(i+l-1);
			if(r>n) break;
		//	printf("l=%d,r=%d\n",l,r);
			ct++;
		}
		printf("%d ",ct);
		while(nw<=n&&a[nw].val==i)
		{
			link(a[nw].id,a[nw].id+1);
			nw++;
		}
	}
	return 0;
}