#include <bits/stdc++.h>
#define ll int
#define INF 1000000000
#define LINF 1000000000000000000
#define F first
#define S second
#define N 110
using namespace std;
ll n,k;
vector<ll> q,s,p;
map<pair<vector<ll>,ll>,bool> dp;
vector<ll> getnxt(vector<ll> st)
{
	vector<ll> ret;
	ll i;
	for(i=0;i<st.size();i++)
	{
		ret.push_back(st[q[i]-1]);
	}
	return ret;
}
vector<ll> getlst(vector<ll> st)
{
	vector<ll> ret;
	ll i;
	for(i=0;i<n;i++)
	{
		ret.push_back(i);
	}
	for(i=0;i<st.size();i++)
	{
		ret[q[i]-1]=st[i];
	}
	return ret;
}
bool dfs(vector<ll> t,ll lft)
{
	if(lft!=k&&t==s)
	{
		return false;
	}
	if(lft==0)
	{
		if(t==p)
		{
			return true;
		}
		return false;
	}
	if(dp.count(make_pair(t,lft)))
	{
		return dp[make_pair(t,lft)];
	}
	return dp[make_pair(t,lft)]=dfs(getnxt(t),lft-1)|dfs(getlst(t),lft-1);
}
int main(){
	ll i,x;
	scanf("%d%d",&n,&k);
	for(i=0;i<n;i++)
	{
		scanf("%d",&x);
		q.push_back(x);
		p.push_back(i+1);
	}
	for(i=0;i<n;i++)
	{
		scanf("%d",&x);
		s.push_back(x);
	}
	if(dfs(s,k))
	{
		puts("YES");
	}
	else
	{
		puts("NO");
	}
	return 0;
}