#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
LL ans;
int n,m,a[100010];
set<pair<int,int>>s;
LL cal(int l,int r){return (LL)(l+r)*(r-l+1)/2+(LL)(n-r)*r;}
int main()
{
	scanf("%d%d",&n,&m);
	rep(i,n)scanf("%d",&a[i]);
	for(int i=1;i<=n;)
	{
		int j=i;
		for(;j<=n&&a[j]==a[i];j++);
		ans+=cal(i,j-1);
		s.insert(mp(i,j-1));
		i=j;
	}
	rep(i,m)
	{
		int x,y;scanf("%d%d",&x,&y);
		auto it=s.upper_bound(mp(x,n+1));it--;
		int l=it->first,r=it->second;
		s.erase(it);
		ans-=cal(l,r);
		if(l<x)ans+=cal(l,x-1),s.insert(mp(l,x-1));
		if(r>x)ans+=cal(x+1,r),s.insert(mp(x+1,r));
		a[x]=y;
		l=r=x;
		if(x>1&&a[x-1]==a[x])
		{
			auto it=s.upper_bound(mp(x,0));it--;
			l=it->first;
			s.erase(it);
			ans-=cal(l,x-1);
		}
		if(x<n&&a[x+1]==a[x])
		{
			auto it=s.upper_bound(mp(x,0));
			r=it->second;
			s.erase(it);
			ans-=cal(x+1,r);
		}
		ans+=cal(l,r);
		s.insert(mp(l,r));
		printf("%lld\n",ans);
		// for(auto [x,y]:s)printf("%d %d\n",x,y);puts("");
	}
    return 0;
}