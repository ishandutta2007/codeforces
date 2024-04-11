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
#define N 12
using namespace std;
ll n,s,pw10[N];
vector<ll> ans;
int main(){
	ll i,j,T,cur;
	pw10[0]=1;
	for(i=1;i<N;i++)
	{
		pw10[i]=pw10[i-1]*10;
	}
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld%lld",&s,&n);
		cur=0;
		ans.clear();
		while(s>0)
		{
			while(s%10!=0)
			{
				s--;
				ans.push_back(cur);
			}
			cur++;
			s/=10;
		}
		while(ans.size()<n)
		{
			sort(ans.begin(),ans.end());
			for(i=0;i<ans.size();i++)
			{
				if(ans[i]>0)
				{
					for(j=0;j<10;j++)
					{
						ans.push_back(ans[i]-1);
					}
					ans.erase(ans.begin()+i);
					break;
				}
			}
		}
		ll fst=0;
		for(i=0;i<=ans.size()-n;i++)
		{
			fst+=pw10[ans[i]];
		}
		printf("%lld ",fst);
		for(;i<ans.size();i++)
		{
			printf("%lld ",pw10[ans[i]]);
		}
		puts("");
	}
	return 0;
}