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
#define int long long
//---------END-------//
int n,m,i,j,k,t,u,t1,v,a,b;
vector<int> gt[300001],stacc;
int used[300001];
int ql[300001],qr[300001]; ll qres[300001];
vector<int> lis;
ll maxx[300001],pre[300001],prer[300001],smaller;
void dfs(int x, int p)
{
//	cout<<"dfs "<<x<<' '<<p<<endl;
	stacc.push_back(x);
	used[x]=1;
	for (int g : gt[x]) if (g!=p)
	{
		if (used[g]==0) dfs(g,x);
		else if (used[g]==1)
		{
			int mi=1e9,ma=0;
			for (int i=stacc.size()-1;i>=0;i--)
			{
				mi=min(mi,stacc[i]);
				ma=max(ma,stacc[i]);
				if (stacc[i]==g) break;
			}
	//		cout<<"add "<<g<<' '<<mi<<' '<<ma<<endl;
			maxx[ma]=max(maxx[ma],mi);
		}
	}
	stacc.pop_back();
	used[x]=2;
}
signed main()
{
	fio;
	cin>>n>>m;
	for (i=1;i<=m;i++)
	{
		cin>>u>>v;
		gt[u].push_back(v);
		gt[v].push_back(u);
	}
	for (i=1;i<=n;i++)
	if (!used[i]) dfs(i,0);
//	for (i=1;i<=n;i++) cout<<i<<' '<<maxx[i]<<endl;
	for (i=1;i<=n;i++) maxx[i]=max(maxx[i-1],maxx[i]);
	smaller=0;
	for (i=1;i<=n;i++)
	{
		prer[i]=prer[i-1]+i;
		pre[i]=pre[i-1]+i-maxx[i];
	}
//	for (i=1;i<=n;i++) cout<<i<<' '<<maxx[i]<<endl;
	cin>>t;
	for (i=1;i<=t;i++)
	{
		cin>>ql[i]>>qr[i];
		lis.push_back(i);
	}
	sort(lis.begin(),lis.end(),[](int a, int b){
		return (ql[a]<ql[b]);
	});
	for (int g : lis)
	{
		while ((smaller<n)and(maxx[smaller+1]<ql[g]-1)) smaller++;
		qres[g]=(prer[min(smaller,qr[g])]-prer[ql[g]-1])-(ql[g]-1)*(min(smaller,qr[g])-(ql[g]-1))+pre[qr[g]]-pre[min(qr[g],smaller)];
	//	cout<<g<<' '<<"components:\n";
//		cout<<(prer[min(smaller,qr[g])]-prer[ql[g]-1])<<' ';
	//	cout<<(ql[g]-1)*(min(smaller,qr[g])-(ql[g]-1))<<' ';
	//	cout<<pre[qr[g]]-pre[min(qr[g],smaller)]<<endl;
	}
	for (i=1;i<=t;i++) cout<<qres[i]<<endl;
}