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
const long double PI=3.14159265358979;
 
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
int n,m,i,j,k,t,t1,u,v,a,b,fin;
int fa,fb,fc;
int pw2[500001];
int arr[500001];
vector<int> facs[500001];
int pr[10000001];
int cnt[10000001],res; 
int main()
{
	fio;
	cin>>n;
	pw2[0]=1;
	for (i=1;i<=n;i++)
	{
		pw2[i]=(pw2[i-1]*2)%MOD;
	}
	for (i=2;i*i<=10000000;i++) if (!pr[i])
	{
		pr[i]=i;
		for (j=i*i;j<=10000000;j+=i) if (!pr[j]) pr[j]=i;
	}
	for (i=2;i<=10000000;i++) if (!pr[i]) pr[i]=i;
	for (i=1;i<=n;i++)
	{
		cin>>arr[i];
		u=arr[i];
		while(u>1)
		{
			facs[i].push_back(pr[u]);
			u/=pr[u];
		}
		auto it=unique(facs[i].begin(),facs[i].end());
		facs[i].erase(it,facs[i].end());
		u=1;
		for (auto g : facs[i]) u*=g;
		arr[i]=u;
	}
 
	for (i=1;i<=n;i++)
	{
		for (j=0;j<(1<<facs[i].size());j++)
		{
			u=1;
			for (k=0;k<facs[i].size();k++) if (j&(1<<k)) u*=facs[i][k];
			if (__builtin_popcount(j)%2==0) 
			{
				res+=(pw2[cnt[u]]);
				res%=MOD;
				res+=MOD;
				res%=MOD;
				cnt[u]++;
			}
			else 
			{
				res-=(pw2[cnt[u]]);
				res%=MOD;
				res+=MOD;
				res%=MOD;
				cnt[u]++;
			}
		}
	}
	//cout<<res<<endl;
	for (i=1;i<=n;i++)
	{
		for (j=0;j<(1<<facs[i].size());j++)
		{
			u=1;
			for (k=0;k<facs[i].size();k++) if (j&(1<<k)) u*=facs[i][k];
			if (__builtin_popcount(j)%2==0) 
			{
				cnt[u]--;
				res-=(pw2[cnt[u]]);
				res%=MOD;
				res+=MOD;
				res%=MOD;
			}
			else 
			{
				cnt[u]--;
				res+=(pw2[cnt[u]]);
				res%=MOD;
				res+=MOD;
				res%=MOD;
			}
		}
		b=pw2[n-1]-1-res;
	//	cout<<b<<endl;
		b%=MOD;
		b+=MOD;
		b%=MOD;
		for (j=1;j<(1<<facs[i].size());j++)
		{
			u=1;
			for (k=0;k<facs[i].size();k++) if (j&(1<<k)) u*=facs[i][k];
			if (__builtin_popcount(j)%2==0) b+=(pw2[cnt[u]]-1); else b-=(pw2[cnt[u]]-1);
			b%=MOD;
			b+=MOD;
			b%=MOD;
		}
		fin+=b;
		fin%=MOD;
		for (j=0;j<(1<<facs[i].size());j++)
		{
			u=1;
			for (k=0;k<facs[i].size();k++) if (j&(1<<k)) u*=facs[i][k];
			if (__builtin_popcount(j)%2==0) 
			{
				res+=(pw2[cnt[u]]);
				res%=MOD;
				res+=MOD;
				res%=MOD;
				cnt[u]++;
			}
			else 
			{
				res-=(pw2[cnt[u]]);
				res%=MOD;
				res+=MOD;
				res%=MOD;
				cnt[u]++;
			}
		}
 
	//	cout<<fin<<endl;
	}
	cout<<fin;
}