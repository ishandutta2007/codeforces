#include <bits/stdc++.h>
#define MAXN 200007
using namespace std;
pair<int,int> a[MAXN];
int d[MAXN],s[MAXN];
set<int> p;
int main()
{
	int n,m,di,mx=0;
	scanf("%d%d%d",&n,&m,&di);
	for(int i=1;i<=n;i++) {a[i].second=i; scanf("%d",&a[i].first);}
	sort(a+1,a+n+1);
	a[0].first=-di;
	for(int i=1;i<=n;i++) p.insert(i);
	int t1=0,t2=1;
	d[0]=n+1;
	while(t2<=n)
	{
		while(a[t2].first-a[t1].first>di) 
		{
			p.insert(d[t1]);
			t1++;
		}
		d[t2]=*p.lower_bound(0);
		p.erase(d[t2]);
		t2++;
	}
	for(int i=1;i<=n;i++)
	{
		mx=max(mx,d[i]);
		s[a[i].second]=d[i];
	}
	printf("%d\n",mx);
	for(int i=1;i<=n;i++) printf("%d ",s[i]);
}