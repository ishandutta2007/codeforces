#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define F first
#define S second
#define ll long long
using namespace std;
ll n,ed[110][110],plc[110][12];
char sgm[52];
map<char,ll> mp;
map<vector<ll>,pair<ll,string> > dp;
string s[12];
pair<ll,string> dfs(vector<ll> v)
{
	ll i,j,k;
	if(dp.count(v))
	{
		return dp[v];
	}
	for(i=0;i<n;i++)
	{
		if(v[i]>=s[i].size())
		{
			return make_pair(0,"");
		}
	}
	pair<ll,string> ret=make_pair(0,"");
	vector<ll> nv;
	for(i=0;i<52;i++)
	{
		nv.clear();
		for(j=0;j<n;j++)
		{
			ll vv=-1;
			for(k=v[j];k<s[j].size();k++)
			{
				if(sgm[i]==s[j][k])
				{
					vv=k+1;
					break;
				}
			}
			if(vv==-1)
			{
				break;
			}
			nv.push_back(vv);
		}
		if(nv.size()==n)
		{
			pair<ll,string> vvv=dfs(nv);
			vvv.F++;
			vvv.S=sgm[i]+vvv.S;
			ret=max(ret,vvv);
		}
	}
	return dp[v]=ret;
}
void solve()
{
	ll i,j,k;
	vector<ll> v;
	cin>>n;
	for(i=0;i<n;i++)
	{
		v.push_back(0);
		cin>>s[i];
	}
	dp.clear();
	pair<ll,string> pr=dfs(v);
	cout<<pr.F<<endl<<pr.S<<endl;
	return;
}
int main(){
	ll T,i;
	for(i=0;i<26;i++)
	{
		mp['a'+i]=i;
		sgm[i]='a'+i;
	}
	for(i=26;i<52;i++)
	{
		mp['A'+i-26]=i;
		sgm[i]='A'+i-26;
	}
	cin>>T;
	while(T--)
	{
		solve();
	}
	return 0;
}