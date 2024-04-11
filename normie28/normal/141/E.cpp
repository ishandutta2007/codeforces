
// Problem : E. Clearing Up
// Contest : Codeforces - Codeforces Round #101 (Div. 2)
// URL : https://codeforces.com/problemset/problem/141/E
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

/*
 A Submission by $%U%$
 at time: $%Y%$-$%M%$-$%D%$ $%h%$:$%m%$:$%s%$
*/
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define rep(i,n) for(int64_t i=0;i < (int64_t)(n);i++)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define FILE_IN "cseq.inp"
#define FILE_OUT "cseq.out"
#define ofile freopen(FILE_IN,"r",stdin);freopen(FILE_OUT,"w",stdout)
#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define nfio cin.tie(0);cout.tie(0)
#define max(x,y) (((x)>(y))?(x):(y))
#define min(x,y) (((x)<(y))?(x):(y))
#define ord(a,b,c) ((a>=b)and(b>=c))
#define MOD (ll(1000000007))
#define MAX 300001
#define mag 320
#define p1 first
#define p2 second.first
#define p3 second.second
#define fi first
#define se second
#define pow2(x) (ll(1)<<x)
#define pii pair<int,int>
#define piii pair<int,pii>
#define For(i,__,___) for(int i=__;i<=___;i++)
#define Rep(i,__,___) for(int i=__;i>=___;i--)
#define ordered_set tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update>
#define endl "\n"
#define bi BigInt
typedef long long ll;
//---------END-------//
int n,m,fa[3010],S[100010],E[100010],typ[100010];
bool use[100010];
inline int getf(int x)
{
	return x==fa[x]?x:fa[x]=getf(fa[x]);
}
char s[5];
vector<pair<int,int> > v[2];
int check(vector<pair<int,int> > &v)
{
	int ret=0;
	for(int i=1;i<=n;i++)fa[i]=i;
	for(auto &x:v)
	{
		int ti=getf(x.first),tj=getf(x.second);
		if(ti!=tj)
		{
			fa[ti]=tj;
			ret++;
		}
	}
	return ret;
}
vector<int> res;
int main()
{
	fio;
	cin>>n>>m;
	if(!(n&1))
	{
		cout<<-1;
		return 0;
	}
	for(int i=1,ti,tj;i<=m;i++)
	{
		cin>>ti>>tj>>s;
		S[i]=ti;E[i]=tj;
		if(s[0]=='S')v[0].push_back(make_pair(ti,tj)),typ[i]=0;
		else v[1].push_back(make_pair(ti,tj)),typ[i]=1;
	}
	if(check(v[0])<(n-1)/2||check(v[1])<(n-1)/2)
	{
		cout<<-1;
		return 0;
	}
	for(int i=1;i<=n;i++)fa[i]=i;
	int cnt1=0;
	for(int i=1;i<=m;i++)
	{
		int ti=getf(S[i]),tj=getf(E[i]);
		if(ti==tj)continue;
		if(typ[i]==0)
		{
			fa[ti]=tj;
		}
	}
	for(int i=1;i<=m;i++)
	{
		int ti=getf(S[i]),tj=getf(E[i]);
		if(ti==tj)continue;
		if(typ[i]==1)
		{
			use[i]=1;
			fa[ti]=tj;
		}
	}
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		int ti=getf(S[i]),tj=getf(E[i]);
		if(ti==tj)continue;
		if(use[i])fa[ti]=tj,res.push_back(i),cnt1++;
	}
	for(int i=1;i<=m;i++)
	{
		int ti=getf(S[i]),tj=getf(E[i]);
		if(ti==tj)continue;
		if(typ[i]==1)
		{
			if(cnt1<(n-1)/2)
			{
				cnt1++;
				res.push_back(i);
				fa[ti]=tj;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		int ti=getf(S[i]),tj=getf(E[i]);
		if(ti==tj)continue;
		if(typ[i]==0)
		{
			res.push_back(i);
			fa[ti]=tj;
		}
	}
	if(res.size()==n-1)
	{
		cout<<n-1<<endl;
		for(auto &x:res) cout<<x<<' ';
	}
	else cout<<-1;
}