// Problem: D. GCD of an Array
// Contest: Codeforces - Codeforces Round #705 (Div. 2)
// URL: https://codeforces.com/contest/1493/problem/D
// Memory Limit: 256 MB
// Time Limit: 2500 ms
// 
// Powered by CP Editor (https://cpeditor.org)

/*
	Normie's Template v2.1
	Changes:
	Added vectorization optimizations.
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
#pragma GCC optimize("Ofast,unroll-loops,tree-vectorize")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
 
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

// Fast min/max assigns to use with AVX.
// Requires g++ 9.2.0.
template<typename T>
__attribute__((always_inline)) void chkmin(T& a, const T& b) {
    a=(a<b)?a:b;
}

template<typename T>
__attribute__((always_inline)) void chkmax(T& a, const T& b) {
    a=(a>b)?a:b;
}
 
//Constants.
#define MOD (ll(1000000007))
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
vector<int> vec;
int n,m,i,j,k,t,t1,u,v,a,b;
struct cmp{
	int operator()(pii(int) a, pii(int) b) const
{
	if (a.se-b.se) return(a.se<b.se);
	else return (a.fi<b.fi);
}
};
map<int,set<pii(int),cmp>> mp;
map<int,map<int,int>> mpo;
ll res=1;
int pr[200001];
void procind(int num, int pos, int amt)
{
//	cout<<"procind "<<num<<' '<<pos<<' '<<amt<<endl;
	int a,b;
	if (mp[num].size()<n) a=0;
	else a=mp[num].begin()->se;
	if (mpo[num][pos]) mp[num].erase({pos,mpo[num][pos]});
	mpo[num][pos]+=amt;
	mp[num].insert({pos,mpo[num][pos]});
	if (mp[num].size()<n) b=0;
	else b=mp[num].begin()->se;
	for (int i=a;i<b;i++)
	{
		res*=num;
		res%=MOD;
	}
//	for (auto g : mpo[num]) cout<<g.fi<<' '<<g.se<<endl;
}
int main()
{
	fio;
	
	for (i=2;i<=200000;i++)
	for (j=i;j<=200000;j+=i) if (!pr[j]) pr[j]=i;
	cin>>n>>m;
	
	for (i=1;i<=n;i++)
	{
		cin>>u;
		vector<int> bruh;
		while(u>1)
		{
			bruh.push_back(pr[u]);
			u/=pr[u];
		}
		if (bruh.size())
		{
		sort(bruh.begin(),bruh.end());
		u=0;
		for (j=0;j<bruh.size();j++)
		{
			if ((j)and(bruh[j]-bruh[j-1]))
			{
				mp[bruh[j-1]].insert({i,u});
				mpo[bruh[j-1]][i]=u;
				u=1;
			}
			else u++;
		}
				mp[bruh[j-1]].insert({i,u});
				mpo[bruh[j-1]][i]=u;
				u=1;
				}
	}
	
	for (auto g : mp) if (g.se.size()==n)
	{
		u=g.se.begin()->se;
		for (i=0;i<u;i++)
		{
			res=(res*g.fi)%MOD;
		}
	}
	for (i=1;i<=m;i++)
	{
		cin>>t>>u;
		vector<int> bruh;
		while(u>1)
		{
			bruh.push_back(pr[u]);
			u/=pr[u];
		}
		if (bruh.size())
		{
		sort(bruh.begin(),bruh.end());
		u=0;
		for (j=0;j<bruh.size();j++)
		{
			if ((j)and(bruh[j]-bruh[j-1]))
			{
				procind(bruh[j-1],t,u);
				u=1;
			}
			else u++;
		}
				procind(bruh[j-1],t,u);
				u=1;
		}
		cout<<res<<endl;
	}
	/*
	*/
}