#include<cstdio>
#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
vector<int>ans;
int n,a[500010],tans;
long long sum[500010];
int main()
{
	scanf("%d",&n);
	rep(i,n)scanf("%d",&a[i]);
	sort(a+1,a+n+1,greater<int>());
	rep(i,n)sum[i]=sum[i-1]+a[i];
	int ll=0,rr=n;
	rep(i,n)
	{
		int x=lower_bound(a+i+1,a+n+1,i,greater<int>())-a;
		long long X=sum[i],Y=sum[n]-sum[x-1]+1ll*(x-i-1)*i+1ll*i*(i-1);
		if(X>Y)
		{
			ll=max(1ll*ll,X-Y);
			if(X-Y-i>0){puts("-1");return 0;}
		}
		rr=min(x+i+Y-X,1ll*rr);
	}
	if(sum[n]&1)
	{
		if((ll&1)==0)ll++;
	}
	else
	{
		if(ll&1)ll++;
	}
	for(int i=ll;i<=rr;i+=2)ans.push_back(i);
	int cnt=ans.size();
	rep(i,cnt)printf("%d%c",ans[i-1]," \n"[i==cnt]);
	return 0;
}