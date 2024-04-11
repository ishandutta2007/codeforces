
// Problem : D. Binary String To Subsequences
// Contest : Codeforces - Codeforces Round #661 (Div. 3)
// URL : https://codeforces.com/contest/1399/problem/D
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
#define fef(i,a,b) for(ll i=a;i<=b;i++)
#define rer(i,a,b) for(ll i=b;i>=a;i--)
#define wew while(true)
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
typedef long long LL;
//---------END-------//

int N,M,Q;
LL DP[13][1<<13];//root,s
set<int>ET[13];
struct Lca
{
	int a,b;
	Lca(){}
	Lca(const int _a,const int _b):a(_a),b(_b){}
};
vector<Lca>LCA[13];
int Lowbit(const int a){return a&(-a);}
bool FitLca(const int fa,const int root,const int s)
{
	for(int i=0;i<LCA[root].size();i++)if(!(s&(1<<LCA[root][i].a))||!(s&(1<<LCA[root][i].b)))return false;
	for(const int &nxt:ET[root])if(nxt!=fa&&!(s&(1<<nxt)))return false;
	return true;
}
LL GetDP(const int root,const int s)
{
	assert(s&(1<<root));
	LL &dp=DP[root][s];
	if(dp!=-1LL)return dp;
	if(s==(1<<root))return dp=1LL;
	dp=0LL;
	for(int sch=s-(1<<root);sch;sch=(sch-1)&(s-(1<<root)))if(sch&Lowbit(s-(1<<root)))
	{
		vector<int>must;
		for(int i=0;i<N;i++)if((sch&(1<<i))&&ET[root].find(i)!=ET[root].end())must.push_back(i);
		if(must.size()>=2)continue;
		bool valid=true;
		for(int i=0;i<LCA[root].size();i++)if((sch&(1<<LCA[root][i].a))&&(sch&(1<<LCA[root][i].b))){valid=false;break;}
		if(!valid)continue;
		if(must.size()==1)
		{
			dp+=(FitLca(root,must[0],sch)?GetDP(must[0],sch):0LL)*GetDP(root,s^sch);
		}
		else
		{
			assert(must.empty());
			LL ta=0LL;
			for(int i=0;i<N;i++)if(sch&(1<<i))ta+=(FitLca(root,i,sch)?GetDP(i,sch):0LL);
			dp+=ta*GetDP(root,s^sch);
		}
	}
	return dp;
}
int main()
{
//	freopen("in.txt","r",stdin);
	while(scanf("%d%d%d",&N,&M,&Q)==3)
	{
		for(int i=0;i<N;i++)ET[i].clear();
		for(int i=0,a,b;i<M;i++)
		{
			scanf("%d%d",&a,&b);
			a--,b--;
			ET[a].insert(b),ET[b].insert(a);
		}
		for(int i=0;i<N;i++)LCA[i].clear();
		for(int i=0,a,b,c;i<Q;i++)
		{
			scanf("%d%d%d",&a,&b,&c);
			a--,b--,c--;
			LCA[c].push_back(Lca(a,b));
		}
		for(int i=0;i<N;i++)for(int j=0;j<(1<<N);j++)DP[i][j]=-1LL;
		printf("%I64d\n",FitLca(-1,0,(1<<N)-1)?GetDP(0,(1<<N)-1):0LL);
	}
	return 0;
}