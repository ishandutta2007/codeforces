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
int lo2[1100000];
vector<int> base,buc[100001];
int n,m,i,j,k,t,t1,u,v,a,b;
int qx[100001],ql[100001],qr[100001];
int arr[100001];
int main()
{
	fio;
	cin>>n>>m;
	for (i=0;i<(1<<20);i++) lo2[i]=lo2[i/2]+1;
	for (i=1;i<=n;i++) cin>>arr[i];
	for (i=1;i<=m;i++)
	{
		cin>>ql[i]>>qx[i];
		buc[ql[i]].push_back(i);
	}
	v=1;
	for (i=1;i<=n;i++)
	{
		u=arr[i];
		for (j=base.size()-1;j>=0;j--)
		{
			if (lo2[u]==lo2[base[j]])
			{
				u^=base[j];
			}
		}
		if (u)
		{
			base.push_back(u);
			sort(base.begin(),base.end());
		}
		else
		{
			v*=2;
			v%=MOD;
		}
		for (int g : buc[i])
		{
	//		cout<<"proc"<<' '<<g<<endl;
			u=qx[g];
		for (j=base.size()-1;j>=0;j--)
		{
			if (lo2[u]==lo2[base[j]])
			{
				u^=base[j];
			}
		}
		if (u)
		{
			qr[g]=0;
		}
		else
		{
			qr[g]=v;
		}
		}
	}
	for (i=1;i<=m;i++)
	{
		cout<<qr[i]<<endl;
	}
}