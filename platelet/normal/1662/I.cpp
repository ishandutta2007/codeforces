#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,m,a[N],p[N],d[N],c[N],pl[N],pr[N];
long long ps[N],ans;
multiset<int>sl,sr;
inline int ok()
{
	if(!sl.size())
		return 1;
	
	return (-(*sl.begin()))<=(*sr.begin());
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		ps[i]=ps[i-1]+a[i];
	for(int i=1;i<=m;i++)
		scanf("%d",&c[i]),c[i]<<=1;
	sort(c+1,c+m+1);
	for(int i=2;i<=n;i++)
		p[i]=p[i-1]+200;
	for(int i=1;i<=n;i++)
	{
		d[i]=INT_MAX;
		int bf=upper_bound(c+1,c+m+1,p[i])-c-1;
		if(bf>=1) d[i]=min(d[i],p[i]-c[bf]);
		int sf=lower_bound(c+1,c+m+1,p[i])-c;
		if(sf<=m) d[i]=min(d[i],c[sf]-p[i]);
		d[i]--;
		pl[i]=p[i]-d[i];
		pr[i]=p[i]+d[i];
	}
	for(int i=1,j=0;i<=n;i++)
	{
		while(j<n&&ok())
		{
			j++;
			sl.insert(-pl[j]);
			sr.insert(pr[j]);
		}
		ans=max(ans,ps[j-1]-ps[i-1]);
		if(ok()) ans=max(ans,ps[j]-ps[i-1]);
		sl.erase(sl.find(-pl[i]));
		sr.erase(sr.find(pr[i]));
	}
	printf("%lld\n",ans);
	return 0;
}