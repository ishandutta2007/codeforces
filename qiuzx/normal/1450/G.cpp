//ANMHLIJKTJIY!
#pragma GCC optimize(2)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline","fast-math","unroll-loops","no-stack-protector")
#pragma GCC diagnostic error "-fwhole-program"
#pragma GCC diagnostic error "-fcse-skip-blocks"
#pragma GCC diagnostic error "-funsafe-loop-optimizations"
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define F first
#define S second
#define ll long long
#define N 100010
using namespace std;
ll n,a,b,trs[30],rl[(1<<20)+10],rr[(1<<20)+10],tot[(1<<20)+10];
bool dp[(1<<20)+10];
string s,ans="";
vector<ll> apps[30],lts;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll i,j;
	cin>>n>>a>>b>>s;
	for(i=0;i<n;i++)
	{
		if(apps[s[i]-'a'].size()==0)
		{
			trs[s[i]-'a']=lts.size();
			lts.push_back(s[i]-'a');
		}
		tot[1<<trs[s[i]-'a']]++;
		apps[s[i]-'a'].push_back(i);
	}
	dp[0]=true;
	for(i=1;i<(1<<lts.size());i++)
	{
		rl[i]=INF;
		rr[i]=0;
		tot[i]=tot[i&(-i)]+tot[i^(i&(-i))];
		for(j=0;j<lts.size();j++)
		{
			if(i&(1<<j))
			{
				rl[i]=min(rl[i],apps[lts[j]][0]);
				rr[i]=max(rr[i],apps[lts[j]][apps[lts[j]].size()-1]);
			}
		}
	}
	for(i=1;i<(1<<lts.size());i++)
	{
		if((rr[i]-rl[i]+1)*a<=tot[i]*b)
		{
			for(j=0;j<lts.size();j++)
			{
				if(i&(1<<j))
				{
					dp[i]|=dp[i^(1<<j)];
				}
			}
		}
		ll curmask=0;
		for(j=0;j<lts.size();j++)
		{
			if(i&(1<<j))
			{
				curmask|=(1<<j);
				dp[i]|=(dp[curmask]&dp[i^curmask]);
			}
		}
	}
	for(i=0;i<lts.size();i++)
	{
		if(dp[(1<<lts.size())-1-(1<<i)])
		{
			ans+=(char)('a'+lts[i]);
		}
	}
	sort(ans.begin(),ans.end());
	cout<<ans.size()<<" ";
	for(i=0;i<ans.size();i++)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
}