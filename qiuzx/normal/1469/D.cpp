#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define INF63 1061109567
#define INF127 9187201950435737471
#define UINF 18446744073709551615
#define F first
#define S second
#define ll long long
using namespace std;
ll n,pre;
vector<pair<ll,ll> > ans;
int main(){
	ll t,i;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		ans.clear();
		pre=n;
		for(i=n-2;i>=1;i--)
		{
			if(i==1)
			{
				ans.push_back(make_pair(n-1,i));
			}
			if((pre+i)/(i+1)>=i+1)
			{
				//cout<<i+1<<" "<<pre<<endl;
				ans.push_back(make_pair(n-1,i));
				ans.push_back(make_pair(i,n-1));
				pre=i+1;
			}
			else
			{
				ans.push_back(make_pair(i,n-1));
			}
		}
		printf("%lld\n",(ll)ans.size());
		for(i=0;i<ans.size();i++)
		{
			printf("%lld %lld\n",ans[i].F+1,ans[i].S+1);
		}
	}
	return 0;
}