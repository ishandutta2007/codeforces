#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
long long ans,l,r,mid;
int n,x,y,mar[100002],mir[100002],mal[100002],mil[100002],R,ma,mi;
pair<int,int> a[100001];

long long sq(long long x) {return x*x;}

bool check(long long nw)
{
	long long ans=sq(mar[1]-mir[1]); R=1;
	while (R<n&&sq(a[R+1].fi-a[1].fi)<=nw) R++;
	ans=min(ans,max(sq(mar[R+1]-mir[R+1]),max(sq(a[1].fi),sq(a[R].fi))+max(sq(mar[R+1]),sq(mir[R+1]))));
	for (int i=2; i<=n; i++)
	{
		while (R<n&&sq(a[R+1].fi-a[i].fi)<=nw) R++;
		ma=max(mal[i-1],mar[R+1]),mi=min(mil[i-1],mir[R+1]);
		ans=min(ans,max(sq(ma-mi),max(sq(a[i].fi),sq(a[R].fi))+max(sq(ma),sq(mi))));
	}
	R=n;
	while (R>1&&sq(a[n].fi-a[R-1].fi)<=nw) R--;
	ans=min(ans,max(sq(mal[R-1]-mil[R-1]),max(sq(a[n].fi),sq(a[R].fi))+max(sq(mal[R-1]),sq(mil[R-1]))));
	for (int i=n-1; i; i--)
	{
		while (R>1&&sq(a[i].fi-a[R-1].fi)<=nw) R--;
		ma=max(mar[i+1],mal[R-1]),mi=min(mil[R-1],mir[i+1]);
		ans=min(ans,max(sq(ma-mi),max(sq(a[i].fi),sq(a[R].fi))+max(sq(ma),sq(mi))));
	}
	R=n+1;
	for (int i=1; i<=n; i++)
		if (a[i].fi<0)
		{
			while (a[R-1].fi>-a[i].fi) R--;
			if (R==n+1&&i==1) continue;
			ma=max(mal[i-1],mar[R]);
			mi=min(mil[i-1],mir[R]);
			ans=min(ans,max(max(sq(a[R-1].fi-a[i].fi),sq(ma-mi)),sq(a[i].fi)+max(sq(ma),sq(mi))));
		}
	R=0;
	for (int i=n; i; i--)
		if (a[i].fi>0)
		{
			while (a[R+1].fi<-a[i].fi) R++;
			if (R==0&&i==n) continue;
			ma=max(mar[i+1],mal[R]);
			mi=min(mir[i+1],mil[R]);
			ans=min(ans,max(max(sq(a[i].fi-a[R+1].fi),sq(ma-mi)),sq(a[i].fi)+max(sq(ma),sq(mi))));
		}
	return ans<=nw;
}

int main()
{
	scanf("%d",&n);
	mal[0]=mar[n+1]=-100000000,mil[0]=mir[n+1]=100000000;
	for (int i=1; i<=n; i++) scanf("%d%d",&a[i].fi,&a[i].se);
	sort(a+1,a+1+n),l=0,r=sq(a[n].fi-a[1].fi)-1,ans=r+1;
	for (int i=n; i; i--) mar[i]=max(mar[i+1],a[i].se),mir[i]=min(mir[i+1],a[i].se);
	for (int i=1; i<=n; i++) mal[i]=max(mal[i-1],a[i].se),mil[i]=min(mil[i-1],a[i].se);
	while (l<=r)
	{
		mid=(l+r)>>1;
		if (check(mid)) r=mid-1,ans=mid; else l=mid+1;
	}
	printf("%I64d\n",ans);
	return 0;
}