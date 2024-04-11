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
#define N 200010
using namespace std;
ll n,a[N],mex[N],cnt[N];
vector<ll> ans;
int main(){
	ll T,i,j;
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld",&n);
		set<ll> st;
		for(i=0;i<=n;i++)
		{
			st.insert(i);
		}
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
		}
		for(i=n-1;i>=0;i--)
		{
			if(st.find(a[i])!=st.end())
			{
				st.erase(a[i]);
			}
			mex[i]=(*st.begin());
		}
		ans.clear();
		for(i=0;i<n;i=j+1)
		{
			ans.push_back(mex[i]);
			ll curnum=mex[i];
			for(j=0;j<mex[i];j++)
			{
				cnt[j]=0;
			}
			for(j=i;j<n;j++)
			{
				if(curnum==0)
				{
					break;
				}
				if(a[j]<mex[i]&&cnt[a[j]]==0)
				{
					curnum--;
				}
				cnt[a[j]]++;
				if(curnum==0)
				{
					break;
				}
			}
		}
		printf("%d\n",ans.size());
		for(i=0;i<ans.size();i++)
		{
			printf("%lld ",ans[i]);
		}
		puts("");
	}
	return 0;
}