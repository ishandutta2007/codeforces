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
struct seg
{
	int val[2000001];
	void reset(int l, int r, int cur)
	{
		val[cur]=-1e9;
		if (l<r)
		{
			int mid=(l+r)/2;
			reset(l,mid,(cur<<1));
			reset(mid+1,r,(cur<<1)+1);
		}
	}
	void update(int l, int r, int cur, int x, int d)
	{
		if ((l<=x)and(x<=r))
		{
			val[cur]=max(val[cur],d);
			if (l<r) 
			{
				int mid=(l+r)/2;
				update(l,mid,(cur<<1),x,d);
				update(mid+1,r,(cur<<1)+1,x,d);
			}
		}
	}
	int get (int l, int r, int cur, int tl, int tr)
	{
		if ((l>tr)or(tl>r)) return -1e9;
		if ((tl<=l)and(tr>=r)) return val[cur];
		else
		{
			int mid=(l+r)/2;
			int a=get(l,mid,(cur<<1),tl,tr);
			int b=get(mid+1,r,(cur<<1)+1,tl,tr);
			return max(a,b);
		}
	}
};
seg st,stp;
int n,m,i,j,k,t,t1,u,v,a,b,res=0;
int arr[500001];
int ord[500001];
int dp[500001];
vector<int> lis;
vector<int> trg[500001];
vector<int> stacc;
int main()
{
	fio;
	cin>>t;
	for (t1=0;t1<t;t1++)
	{
		res=0;
		lis.clear();
		cin>>n;
		for (i=1;i<=n;i++)
		{
			cin>>arr[i];
			lis.push_back(i);
			trg[i].clear();
		}
		sort(lis.begin(),lis.end(),[](int a, int b){
			if (arr[a]-arr[b]) return (arr[a]<arr[b]);
			return (a<b);
		});
		for (i=1;i<=n;i++) ord[lis[i-1]]=i;
		stacc.clear();
		for (i=n;i>=1;i--)
		{
			while ((stacc.size())and(arr[stacc[stacc.size()-1]]<arr[i])) stacc.pop_back();
			if ((stacc.size())and(stacc[stacc.size()-1]<n)) trg[stacc[stacc.size()-1]+1].push_back(i);
			stacc.push_back(i);
		}
		st.reset(1,n,1);
		stp.reset(1,n,1);
		for (i=1;i<=n;i++)
		{
			for (int g : trg[i]) stp.update(1,n,1,ord[g],dp[g]);
			if (i==1) dp[i]=1;
			else dp[i]=2;
			a=st.get(1,n,1,1,ord[i]);
			dp[i]=max(dp[i],a+1);
			a=stp.get(1,n,1,1,ord[i]);
			dp[i]=max(dp[i],a+2);
			res=max(res,dp[i]);
			st.update(1,n,1,ord[i],dp[i]);
		}
		cout<<res<<endl;
	}
}