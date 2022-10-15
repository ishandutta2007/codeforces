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
ll n,m,i,j,k,t,t1,u,v,a,b,res;
ll arr[300011];
ll dp[300011],jmp[300011];
ll las[300011];
struct cmp
{
	int operator()(ll a, ll b) const
	{
		if (arr[a+1]-arr[b+1]) return (arr[a+1]<arr[b+1]);
		return (a<b);
	 } 
};
set<ll,cmp> chain[300011];
int main()
{
	fio;
	cin>>t;
	for (t1=0;t1<t;t1++)
	{
		res=0;
	cin>>n;
	for (i=1;i<=n;i++)
	{
		cin>>arr[i];
	}
	for (i=0;i<=n;i++)
	{
		jmp[i]=0;
		las[i]=0;
		chain[i].clear();
	}
	arr[n+1]=1e9;
	for (i=n;i>=0;i--)
	{
		if (i==n)
		{
			las[i]=i;
			jmp[i]=-1;
			chain[las[i]].insert(i);
		}
		else
		{
			arr[0]=arr[i+1];
			auto it=chain[las[i+1]].lower_bound(-1);
	//		cout<<"chain[las[i+1]]'s content: ";
		//	for (ll g : chain[las[i+1]]) cout<<g<<' ';
	//		cout<<endl;
		//	cout<<"arr[0]="<<arr[0]<<endl;
			if (((it)!=chain[las[i+1]].end()) and (arr[(*it)+1]==arr[i+1])) 
			{
				jmp[i]=(*it)+1;
				las[i]=las[jmp[i]];
				chain[las[i]].insert(i);
			}
			else
			{
			las[i]=i;
			jmp[i]=-1;
			chain[las[i]].insert(i);
			}
		}
	//	cout<<jmp[i]<<' '<<las[i]<<endl;
	}
	for (i=0;i<=n;i++) res+=(chain[i].size())*(chain[i].size()-1)/2;
	cout<<res<<endl;
	}
}