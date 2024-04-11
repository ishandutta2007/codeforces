#include<bits/stdc++.h>
using namespace std;

int n,cnt;
pair<int,int> valp[150010];
struct node{int p,t,pp;}a[150010];
long long T,tl[150010],tr[150010];
double l,r,mid,t[150010];
const double inf=(1e18);

void add(int x,double v) {for (; x; x-=(x&-x)) t[x]=min(t[x],v);}
double query(int x) {double ans=inf; for (; x<=cnt; x+=(x&-x)) ans=min(ans,t[x]); return ans;}
bool cmp(node a,node b) {return 1ll*a.p*b.t>1ll*a.t*b.p||1ll*a.p*b.t==1ll*a.t*b.p&&a.p<b.p;}

bool check(double c)
{
	for (int i=1; i<=cnt; i++) t[i]=inf;
	for (int i=n; i; i--)
	{
		if (query(a[i].pp+1)<=a[i].p*(1-(c*tl[i])/T)) return 1;
		add(a[i].pp,a[i].p*(1-(c*tr[i])/T));
	}
	return 0;
}

int main()
{
	scanf("%d",&n);
	for (int i=1; i<=n; i++) scanf("%d",&a[i].p);
	for (int i=1; i<=n; i++) scanf("%d",&a[i].t);
	sort(a+1,a+1+n,cmp),T=0;
	for (int i=1; i<=n; i++) valp[i]=make_pair(a[i].p,i);
	sort(valp+1,valp+1+n);
	for (int i=1; i<=n; i++)
	{
		if (i==1||valp[i].first!=valp[i-1].first) cnt++;
		a[valp[i].second].pp=cnt;
	}
	for (int l=1,r; l<=n; l++)
	{
		for (r=l; r<n&&1ll*a[l].p*a[r+1].t==1ll*a[l].t*a[r+1].p; r++);
		for (int i=l; i<=r; i++) tl[i]=T+a[i].t;
		for (int i=l; i<=r; i++) T+=a[i].t;
		for (int i=l; i<=r; i++) tr[i]=T;
		l=r;
	}
	l=0,r=1;
	for (int i=1; i<=50; i++)
	{
		mid=(l+r)/2.0;
		if (check(mid)) r=mid; else l=mid;
	}
	printf("%.10lf\n",l);
	return 0;
}