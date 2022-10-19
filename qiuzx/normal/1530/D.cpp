//ANMHLIJKTJIY!
#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define F first
#define S second
#define ll long long
#define N 200010
using namespace std;
ll n,a[N],ans[N],res;
bool vis[N];
vector<ll> lft,lch;
int main(){
	ll T,i;
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld",&n);
		for(i=0;i<n;i++)
		{
			ans[i]=-1;
			vis[i]=false;
		}
		lft.clear();
		lch.clear();
		res=0;
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
			a[i]--;
			if(!vis[a[i]])
			{
				vis[a[i]]=true;
				res++;
				ans[i]=a[i];
			}
		}
		for(i=0;i<n;i++)
		{
			if(!vis[i])
			{
				lft.push_back(i);
			}
			if(ans[i]==-1)
			{
				lch.push_back(i);
			}
		}
		if(lch.size()==1&&lch[0]==lft[0])
		{
			for(i=0;i<n;i++)
			{
				if(a[i]==a[lch[0]])
				{
					ans[lch[0]]=a[lch[0]];
					ans[i]=lft[0];
					break;
				}
			}
			lch.clear();
			lft.clear();
		}
		if(!lch.empty())
		{
			i=1;
			ans[lch[0]]=lft[0];
			if(lch[0]==lft[0])
			{
				ans[lch[0]]=lft[1];
				ans[lch[1]]=lft[0];
				i=2;
			}
			for(;i<lch.size();i++)
			{
				ans[lch[i]]=lft[i];
				if(lch[i]==lft[i])
				{
					swap(ans[lch[i]],ans[lch[i-1]]);
				}
			}
		}
		printf("%lld\n",res);
		for(i=0;i<n;i++)
		{
			printf("%lld ",ans[i]+1);
		}
		puts("");
	}
	return 0;
}