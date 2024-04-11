// Problem: A. Going Home
// Contest: Codeforces - Codeforces Round #707 (Div. 1, based on Moscow Open Olympiad in Informatics)
// URL: https://codeforces.com/contest/1500/problem/A
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
//#include <atcoder/convolution>
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
vector<int> vec;
int n,m,i,j,k,t,t1,u,v,a,b;
vector<int> cnt[2500001];
vector<int> va,vb,vc;
vector<int> cntdiff[2500001];
void answer(ll a, ll b, ll c, ll d)
{
			cout<<"YES\n";
			cout<<cnt[a][0]<<' '<<cnt[b][0]<<' '<<cnt[c][0]<<' '<<cnt[d][0];
			exit(0);
}
int main()
{
	fio;
	cin>>n;
	for (i=1;i<=n;i++)
	{
		cin>>a;
		cnt[a].push_back(i);
	}
	for (i=1;i<=2500000;i++)
	{
		if (cnt[i].size()>=2) vec.push_back(i);
		if (cnt[i].size()>=4)
		{
			cout<<"YES\n";
			cout<<cnt[i][0]<<' '<<cnt[i][1]<<' '<<cnt[i][2]<<' '<<cnt[i][3];
			return 0;
		}
	}
	if (vec.size()>=2)
	{
		cout<<"YES\n";
		cout<<cnt[vec[0]][0]<<' '<<cnt[vec[1]][0]<<' '<<cnt[vec[0]][1]<<' '<<cnt[vec[1]][1];
		return 0;
	}
	if (vec.size())
	{
		u=vec[0];
		a=min(u-1,2500000-u);
		for (i=1;i<=a;i++)
		{
			if ((cnt[u-i].size())and(cnt[u+i].size())) 
			{
	//			cout<<"what\n";
		cout<<"YES\n";
		cout<<cnt[u][0]<<' '<<cnt[u][1]<<' '<<cnt[u-i][0]<<' '<<cnt[u+i][0];
		return 0;
			}
		}
	}
	vec.clear();
	for (i=1;i<=2500000;i++) if (cnt[i].size()) vec.push_back(i);
	if (vec.size()>6000)
	{
		for (i=1;i<vec.size();i+=2)
		{
			cntdiff[vec[i]-vec[i-1]].push_back(i);
			if (cntdiff[vec[i]-vec[i-1]].size()>=2) 
			{
				answer(vec[i],vec[cntdiff[vec[i]-vec[i-1]][0]-1],vec[i-1],vec[cntdiff[vec[i]-vec[i-1]][0]]);
			}
		}
	}
	else
	{
		for (i=1;i<vec.size();i++) for (j=0;j<i;j++)
		{
			cntdiff[vec[i]-vec[j]].push_back(i*20000+j);
			for (k=0;k<cntdiff[vec[i]-vec[j]].size()-1;k++) if ((j!=cntdiff[vec[i]-vec[j]][k]/20000)and(i!=cntdiff[vec[i]-vec[j]][k]%20000))
			{
				answer(vec[i],vec[cntdiff[vec[i]-vec[j]][k]%20000],vec[j],vec[cntdiff[vec[i]-vec[j]][k]/20000]);
			}
		}
	}
	cout<<"NO";
}