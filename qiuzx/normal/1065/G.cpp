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
#define N 210
using namespace std;
string suf[N],pre[N];
ll n,m,k,f[N];
string ans="";
ll dfs(ll x)
{
	ll i;
	if(f[x]!=-1)
	{
		return f[x];
	}
	if(suf[x].size()<ans.size())
	{
		return f[x]=0;
	}
	if(x==0)
	{
		return f[x]=(ans=="0");
	}
	if(x==1)
	{
		return f[x]=(ans=="1");
	}
	f[x]=min(dfs(x-2)+dfs(x-1),k+5);
	string alls=suf[x-2]+pre[x-1],cur;
	if(alls.size()<ans.size())
	{
		return f[x];
	}
	cur=alls.substr(0,ans.size());
	for(i=ans.size();i<alls.size();i++)
	{
		if(i-ans.size()<suf[x-2].size()&&i>suf[x-2].size())
		{
			f[x]+=(cur==ans);
		}
		cur.erase(cur.begin());
		cur+=alls[i];
	}
	if(alls.size()-ans.size()<suf[x-2].size()&&alls.size()>suf[x-2].size())
	{
		f[x]+=(cur==ans);
	}
	return f[x]=min(f[x],k+5);
}
void calc()
{
	ll i,res;
	for(i=0;i<=n;i++)
	{
		f[i]=-1;
	}
	res=dfs(n);
	if(res>=k)
	{
		return;
	}
	k-=res;
	ans[ans.size()-1]='1';
	if(suf[n].substr(suf[n].size()-ans.size())==ans)
	{
		k--;
	}
	if(k==0)
	{
		cout<<ans<<endl;
		exit(0);
	}
	return;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll i;
	cin>>n>>k>>m;
	suf[0]=pre[0]="0";
	suf[1]=pre[1]="1";
	for(i=2;;i++)
	{
		pre[i]=suf[i]=suf[i-2]+suf[i-1];
		if(suf[i-1].size()>m)
		{
			break;
		}
	}
	pre[i-1]=pre[i-1].substr(0,m);
	suf[i-1]=suf[i-1].substr(suf[i-1].size()-m);
	pre[i]=pre[i].substr(0,m);
	suf[i]=suf[i].substr(suf[i].size()-m);
	for(i++;i<=n;i++)
	{
		pre[i]=pre[i-2];
		suf[i]=suf[i-1];
	}
	for(i=0;i<m;i++)
	{
		ans+="0";
		calc();
	}
	cout<<ans<<endl;
	return 0;
}