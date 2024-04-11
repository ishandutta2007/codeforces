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
ll n;
string s[N];
map<string,ll> mp,mp2;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll T,i;
	cin>>T;
	while(T--)
	{
		cin>>n;
		bool ok=false;
		mp.clear();
		for(i=0;i<n;i++)
		{
			cin>>s[i];
			mp[s[i]]=1;
			if(s[i].size()==1)
			{
				ok=true;
			}
		}
		mp2.clear();
		for(i=0;i<n;i++)
		{
			if(s[i].size()==2)
			{
				string cur="";
				cur+=s[i][1],cur+=s[i][0];
				if(mp.count(cur))
				{
					ok=true;
				}
			}
			else
			{
				string cur="";
				cur+=s[i][2],cur+=s[i][1],cur+=s[i][0];
				if(mp.count(cur))
				{
					ok=true;
				}
				cur="";
				cur+=s[i][2],cur+=s[i][1];
				if(mp2.count(cur))
				{
					ok=true;
				}
			}
			mp2[s[i]]=1;
		}
		mp2.clear();
		for(i=n-1;i>=0;i--)
		{
			if(s[i].size()==3)
			{
				string cur="";
				cur+=s[i][1],cur+=s[i][0];
				if(mp2.count(cur))
				{
					ok=true;
				}
			}
			mp2[s[i]]=1;
		}
		cout<<(ok?"YES":"NO")<<endl;
	}
	return 0;
}