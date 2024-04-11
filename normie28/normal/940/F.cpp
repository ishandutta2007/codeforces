
// Problem : F. Machine Learning
// Contest : Codeforces - Codeforces Round #466 (Div. 2)
// URL : https://codeforces.com/contest/940/problem/F
// Memory Limit : 512 MB
// Time Limit : 4000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

/*
	Normie's Template v2.0
*/
 
// Standard library in one include.
#include <bits/stdc++.h>
using namespace std;
 
// ordered_set library.
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set(el) tree<el,null_type,less<el>,rb_tree_tag,tree_order_statistics_node_update>
 
// AtCoder library. (Comment out these two lines if you're not submitting in AtCoder.) (Or if you want to use it in other judges, run expander.py first.)
//#include <atcoder/all>
//using namespace atcoder;
 
//Pragmas (Comment out these three lines if you're submitting in szkopul.)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
 
//File I/O.
#define FILE_IN "cseq.inp"
#define FILE_OUT "cseq.out"
#define ofile freopen(FILE_IN,"r",stdin);freopen(FILE_OUT,"w",stdout)
 
//Fast I/O.
#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define nfio cin.tie(0);cout.tie(0)
#define endl "\n"
 
//Order checking.
#define ord(a,b,c) ((a>=b)and(b>=c))
 
//min/max redefines, so i dont have to resolve annoying compile errors.
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))

//Constants.
#define MOD (ll(998244353))
#define MAX 300001
#define mag 320
 
//Pairs and 3-pairs.
#define p1 first
#define p2 second.first
#define p3 second.second
#define fi first
#define se second
#define pii(element_type) pair<element_type,element_type>
#define piii(element_type) pair<element_type,pii(element_type)>
 
//Quick power of 2.
#define pow2(x) (ll(1)<<x)
 
//Short for-loops.
#define ff(i,__,___) for(int i=__;i<=___;i++)
#define rr(i,__,___) for(int i=__;i>=___;i--)
 
//Typedefs.
#define bi BigInt
typedef long long ll;
typedef long double ld;
typedef short sh;
//---------END-------//
int arr[200001];
vector<pair<pii(int),pii(int)>> queries;
int cnt[200001],szcnt[200001];
int cp[200001],cv[200001],cb[200001];
int res[200001];
map<int,int> bruh;
int n,m,i,j,k,t,t1,u,v,a,b;
int curt,curl,curr;
void opadd(int x)
{
	cnt[x]++;
	szcnt[cnt[x]-1]--;
	szcnt[cnt[x]]++;
}
void oprmv(int x)
{
	cnt[x]--;
	szcnt[cnt[x]+1]--;
	szcnt[cnt[x]]++;
}
void adapt(int t, int l, int r)
{
//	cout<<t<<' '<<l<<' '<<r<<endl;
	
	while(curt<t)
	{
		if ((curl<=cp[curt+1])and(cp[curt+1]<=curr))
		{
		oprmv(cb[curt+1]);
		opadd(cv[curt+1]);
		}
		arr[cp[curt+1]]=cv[curt+1];
		curt++;
	}
	while(curt>t)
	{
		if ((curl<=cp[curt])and(cp[curt]<=curr))
		{
		oprmv(cv[curt]);
		opadd(cb[curt]);
		}
		arr[cp[curt]]=cb[curt];
		curt--;
	}
	while(curr<r)
	{
		opadd(arr[curr+1]);
		curr++;
	}
	while(curl>l)
	{
		opadd(arr[curl-1]);
		curl--;
	}
	while(curr>r)
	{
		oprmv(arr[curr]);
		curr--;
	}
	while(curl<l)
	{
		oprmv(arr[curl]);
		curl++;
	}
	
}
int main()
{
	fio;
	cin>>n;
	
	cin>>m;
	cnt[0]++;
	szcnt[1]++;
	for (i=1;i<=n;i++)
	{
		cin>>arr[i];
		if (!bruh[arr[i]]) bruh[arr[i]]=i;
		arr[i]=bruh[arr[i]];
	}
	for (i=1;i<=m;i++)
	{
		cin>>u>>a>>v;
		if (u==2)
		{
			t++;
			if (!bruh[v]) bruh[v]=n+t;
			v=bruh[v];
			cp[t]=a;
			cb[t]=arr[a];
			cv[t]=v;
			arr[a]=v;
		}
		else
		{
			queries.push_back({{i,t},{a,v}});
		}
	}
	for (i=t;i>=1;i--) arr[cp[i]]=cb[i];
	//for (i=1;i<=n;i++) cout<<arr[i]<<' ';
	//cout<<endl;
	//for (i=1;i<=t;i++) cout<<cp[i]<<' '<<cv[i]<<' '<<cb[i]<<endl;
	//cout<<endl;
	u=ceil(cbrt(n)*cbrt(n));
	sort(queries.begin(),queries.end(),[](pair<pii(int),pii(int)> a, pair<pii(int),pii(int)> b){
		if ((a.fi.se)/u-(b.fi.se)/u) return ((a.fi.se)/u<(b.fi.se)/u); 
		if ((a.se.fi)/u-(b.se.fi)/u) return ((a.se.fi)/u<(b.se.fi)/u); 
		return (a.se.se<b.se.se);
	});
	
	for (auto g : queries) 
	{
	adapt(g.fi.se,g.se.fi,g.se.se);
	for (i=1;i<=200000;i++) if (!szcnt[i]) break;
	res[g.fi.fi]=i;
	}
	for (i=1;i<=m;i++) if (res[i]) cout<<res[i]<<endl;
	
}