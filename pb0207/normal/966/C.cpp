#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;

typedef long long ll;

const int N=1e5+1e3+7;

multiset<ll>s[71];

int n;

ll ans[N];

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		ll x;
		scanf("%lld",&x);
		for(int j=60;j>=0;j--)
			if(x&(1ll<<j))
			{
				s[j].insert(x);
				break;
			}
	}
	ll now=0;
	bool ok=1;
	for(int i=1;i<=n;i++)
	{
		bool flag=false;
		for(int j=0;j<=60;j++)
			if((now&(1ll<<j))==0&&(s[j].size()))
			{
				ans[i]=*s[j].begin();
				s[j].erase(s[j].find(ans[i]));
				now^=ans[i];
				flag=true;
				break;
			}
		if(!flag)
		{
			ok=false;
			break;
		}
	}
	if(!ok)
	{
		puts("No");
		return 0;
	}
	puts("Yes");
	for(int i=1;i<=n;i++)
		printf("%lld ",ans[i]);
}