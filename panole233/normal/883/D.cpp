#include<bits/stdc++.h>
using namespace std;

#define pb push_back
vector<int> vp,va;
int f[1000001][2],g[1000001][2],n,l,r,mid,ans;
char s[1000010];
//0:P 1:* f:*..P g:.*P.
bool check(int x)
{
	f[0][0]=g[0][0]=-10000000;
	f[0][1]=g[0][1]=10000000;
	for (int i=1; i<=n; i++)
		if (s[i]=='.') f[i][0]=f[i-1][0],g[i][0]=g[i-1][0],f[i][1]=f[i-1][1],g[i][1]=g[i-1][1];
		else if (s[i]=='P') 
		{
			if (f[i-1][1]+x>=i) g[i][0]=f[i-1][0],g[i][1]=10000000;
			else if (g[i-1][1]+x<i) return 0;
			else g[i][0]=g[i-1][0],g[i][1]=10000000;
			f[i][0]=i,f[i][1]=g[i-1][1];
		} else
		{
			if (f[i-1][1]==10000000)
			{
				if (f[i-1][0]+x>=i) f[i][0]=f[i-1][0],f[i][1]=f[i-1][1];
				else f[i][0]=f[i-1][0],f[i][1]=i;
			}
			else f[i][0]=f[i-1][0],f[i][1]=f[i-1][1];
			if (g[i-1][1]==10000000)
			{
				if (g[i-1][0]+x>=i) g[i][0]=g[i-1][0],g[i][1]=g[i-1][1];
				else g[i][0]=g[i-1][0],g[i][1]=i;
			}
			else g[i][0]=g[i-1][0],g[i][1]=g[i-1][1];
			if (g[i][1]<f[i][1]) swap(g[i][0],f[i][0]),swap(g[i][1],f[i][1]);
		}
	return (f[n][1]==10000000||g[n][1]==10000000);
}

int main()
{
	scanf("%d",&n); scanf("%s",s+1);
	for (int i=1; i<=n; i++)
		if (s[i]=='*') va.pb(i); else 
		if (s[i]=='P') vp.pb(i);
	if (vp.size()==0||va.size()==0) return puts("0 0"),0;
	if (vp.size()==1) 
	{
		if (va[0]>vp[0]) return printf("%d %d\n",va.size(),va[va.size()-1]-vp[0]),0;
		if (va[va.size()-1]<vp[0]) return printf("%d %d\n",va.size(),vp[0]-va[0]),0;
		l=0; r=va.size()-1;
		while (l<=r)
		{
			mid=(l+r)>>1;
			if (va[mid]<vp[0]) ans=mid,l=mid+1; else r=mid-1;
		}
		mid=ans;
		if (mid+1<va.size()-mid-1) return printf("%d %d\n",va.size()-mid-1,va[va.size()-1]-vp[0]),0;
		if (mid+1>va.size()-mid-1) return printf("%d %d\n",mid+1,vp[0]-va[0]),0;
		return printf("%d %d\n",mid+1,min(va[va.size()-1]-vp[0],vp[0]-va[0])),0;
	}
	printf("%d ",va.size());
	l=1; r=n;
	while (l<=r)
	{
		mid=(l+r)>>1;
		if (check(mid)) ans=mid,r=mid-1; else l=mid+1;
	}
	printf("%d\n",ans);
	return 0;
}