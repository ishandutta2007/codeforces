#include<bits/stdc++.h>
using namespace std;

bool p[5010];
int n,a[1000010],f[5010],pr[5010],pn,cnt[5010],L,R,po[5010],sum[5010],l[5010],r[5010];
vector<pair<int,int> > v[5010];
long long ans;

int main()
{
	memset(p,1,sizeof(p)),pn=0;
	for (int i=2; i<=5000; i++) if (p[i])
	{
		pr[++pn]=i;
		for (int j=(i<<1); j<=5000; j+=i) p[j]=0;
	}
	for (int i=1; i<=5000; i++)
	{
		v[i].clear();
		for (int j=pn; j; j--) if (pr[j]<=i)
		{
			int x=i;
			x/=pr[j],f[i]+=x;
			while (x>=pr[j]) x/=pr[j],f[i]+=x;
			v[i].push_back(make_pair(j,f[i]));
		}
	}
	scanf("%d",&n);
	for (int i=1; i<=n; i++) scanf("%d",&a[i]),ans+=f[a[i]],cnt[a[i]]++;
	L=1,R=5000,memset(po,0,sizeof(po));
	for (int i=0; ; i++)
	{
		for (int j=1; j<=pn; j++) sum[j]=l[j]=r[j]=0;
		for (int j=L; j<=R; j++) 
			if (i<f[j])
			{
				if (v[j][po[j]].second==i) po[j]++;
				sum[v[j][po[j]].first]+=cnt[j];
				if (!l[v[j][po[j]].first]) l[v[j][po[j]].first]=j;
				r[v[j][po[j]].first]=j;
			}
		int p=0;
		for (int j=1; j<=pn; j++) if (sum[j]*2>n) {p=j; break;}
		if  (!p) return printf("%I64d\n",ans),0;
		ans-=(sum[p]-(n-sum[p])),L=l[p],R=r[p];
	}
	return 0;
}