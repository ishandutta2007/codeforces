#include<bits/stdc++.h>
using namespace std;

int n,f[10010][1010],m,a[10010],G,R,l,r,x,t;
pair<int,int> q[10000010];
vector<int> v;

int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1; i<=m; i++) scanf("%d",&a[i]);
	sort(a+1,a+1+m);
	scanf("%d%d",&G,&R),f[1][0]=1,q[l=r=1]=make_pair(1,0);
	int nw=0;
	while (r)
	{
		nw++,v.clear();
		while (l<=r)
		{
			x=q[l].first,t=q[l++].second;
			if (x>1&&t+a[x]-a[x-1]<=G&&!f[x-1][t+a[x]-a[x-1]]) 
			{
				f[x-1][t+a[x]-a[x-1]]=nw,q[++r]=make_pair(x-1,t+a[x]-a[x-1]);
				if (t+a[x]-a[x-1]==G) v.push_back(x-1);
			}
			if (x<m&&t+a[x+1]-a[x]<=G&&!f[x+1][t+a[x+1]-a[x]])
			{
				f[x+1][t+a[x+1]-a[x]]=nw,q[++r]=make_pair(x+1,t+a[x+1]-a[x]);
				if (t+a[x+1]-a[x]==G) v.push_back(x+1);
			}
		}
		l=1,r=0;
		for (int i=0,sz=v.size(); i<sz; i++) q[++r]=make_pair(v[i],0),f[v[i]][0]=nw+1;
	}
	long long ans=1000000000000000000ll;
	for (int i=0; i<=G; i++) if (f[m][i]&&1ll*(f[m][i]-1)*(G+R)+i<=ans) ans=1ll*(f[m][i]-1)*(G+R)+i;
	if (ans==1000000000000000000ll) puts("-1"); else printf("%I64d\n",ans);
	return 0;
}