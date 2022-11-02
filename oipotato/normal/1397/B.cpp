#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<queue>
#include<vector>
#include<map>
#include<cmath>
#include<set>
#include<iostream>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
#define pb push_back
#define mp make_pair
int a[100010];
int main()
{
	int n;
	scanf("%d",&n);
	long long ans=0;
	rep(i,n)scanf("%d",&a[i]),ans+=a[i]-1;
	sort(a+1,a+n+1);
	for(int c=2;c<=100000;c++)
	{
		long long pw=1,tans=0;
		rep(i,n)
		{
			if(i>1&&pw>a[i]/c&&pw>(ans-tans+a[i])/c){tans=ans+1;break;}
			if(i>1)pw*=c;
			tans+=abs(a[i]-pw);
		}
		ans=min(ans,tans);
	}
	printf("%lld\n",ans);
	return 0;
}