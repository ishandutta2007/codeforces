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
#define B 200000
using namespace std;
string s;
ll prelen=0,masks[B+50],ans=LINF;
map<ll,ll> mp;
int main(){
	ll i,j;
	cin>>s;
	if(s.find('1')==-1)
	{
		puts("-1");
		return 0;
	}
	while(s[0]=='0')
	{
		s.erase(s.begin());
		prelen++;
	}
	ll smask=0;
	for(i=0;i<s.size();i++)
	{
		if(s[i]=='1')
		{
			smask|=(1ll<<i);
		}
	}
	masks[0]=(1ll<<(s.size()-1));
	mp[masks[0]]=0;
	for(i=1;i<B;i++)
	{
		masks[i]=(masks[i-1]>>1)^((masks[i-1]&2)?smask:0);
		mp[masks[i]]=i;
	}
	for(i=B;i<=B+s.size();i++)
	{
		masks[i]=(masks[i-1]>>1)^((masks[i-1]&2)?smask:0);
	}
	ll curmasks=(1ll<<(s.size()-1));
	for(i=1;i<=B;i++)
	{
		ll nxt=0;
		for(j=0;j<s.size();j++)
		{
			if(curmasks&(1ll<<j))
			{
				nxt^=masks[B+s.size()-j-1];
			}
		}
		curmasks=nxt;
		if(mp.count(curmasks))
		{
			ans=min(ans,i*B-mp[curmasks]);
		}
	}
	cout<<prelen+1<<" "<<prelen+1+ans<<endl;
	return 0;
}