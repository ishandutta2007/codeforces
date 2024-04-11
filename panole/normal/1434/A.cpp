#include<bits/stdc++.h>
using namespace std;

const int inf=2000000000;
int n,a[7],b[100010],nw[100010],ans;
pair<int,int> p[600010];
set<pair<int,int> > s;

int main()
{
	for (int i=1; i<=6; i++) scanf("%d",&a[i]);
	sort(a+1,a+7);
	scanf("%d",&n);
	for (int i=1; i<=n; i++) nw[i]=inf,scanf("%d",&b[i]);
	int cnt=0;
	for (int i=1; i<=n; i++) 
		for (int j=1; j<=6; j++) p[++cnt]=make_pair(b[i]-a[j],i);
	sort(p+1,p+1+cnt);
	s.clear(),ans=inf;
	for (int i=1; i<=n; i++) s.insert(make_pair(inf,i));
	for (int i=cnt; i; i--)
	{
		int x=p[i].second;
		s.erase(make_pair(nw[x],x));
		nw[x]=p[i].first;
		s.insert(make_pair(nw[x],x));
		ans=min(ans,(*(--s.end())).first-nw[x]);
	}
	printf("%d\n",ans);
	return 0;
}