#include<bits/stdc++.h>
#define ll long long int
using namespace std;
 
vector<ll >gt[100005];
ll n,m,k;
#define pb push_back
ll st=-1,en=-1;
ll bb[100005];
 
int dfs(vector<ll> &t,ll s,int l,bool vis[])
{
	vis[s]=1;
	for(int i=0;i<gt[s].size();i++)
	{   
	if(vis[gt[s][i]]&&bb[gt[s][i]]&&l+1-bb[gt[s][i]]>=k)
	{
		st=bb[gt[s][i]];
		en=l+1;
		t.pb(s);
		return 1;
	}
	else
	if(vis[gt[s][i]]==0)
		{   t.pb(s);
	        bb[s]=l+1;
		  if(dfs(t,gt[s][i],l+1,vis))
		  return 1;
		  else
		  {
		  	t.pop_back();
		  	bb[s]=0;
	     }	
		}
	}
	return 0;
}
ll bow (ll a, ll x)
{
	ll res=bow(a,x/2);
	res*=res;
	if (x%2) res*=a;
	return res;
}
int main()
	{
	 ios_base::sync_with_stdio(0);
    cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	bool vis[n+5];
	memset(vis,0,sizeof(vis));
	memset(bb,0,sizeof(bb));
	int i,j;
	ll a,b;
	for(i=0;i<m;i++)
	{
		cin>>a>>b;
		gt[a].pb(b);
		gt[b].pb(a);
	}
	 
	vector<ll>h;
	dfs(h,1,0,vis);
	cout<<en-st+1<<endl;
	for(i=st-1;i<h.size();i++)
	cout<<h[i]<<" ";
}