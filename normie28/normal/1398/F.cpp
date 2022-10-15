
// Problem : F. Controversial Rounds
// Contest : Codeforces - Educational Codeforces Round 93 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1398/problem/F
// Memory Limit : 256 MB
// Time Limit : 2000 ms
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
vector<ll> blstart[1000011];
ll maxx[1000011][2];
string s;
ll n,m,i,j,k,t,t1,u,v,a,b;
int main()
{
	fio;
	cin>>n;
	cin>>s;
	for (i=n;i>=1;i--)
	{
		if (s[i-1]!='1') maxx[i][0]=maxx[i+1][0]+1;
		if (s[i-1]!='0') maxx[i][1]=maxx[i+1][1]+1;
	}
	for (i=1;i<=n;i++)
	{
		a=0;
		if (i==1) a=max(maxx[i][0],maxx[i][1]);
		else if (s[i-2]=='0') a=maxx[i][1];
		else if (s[i-2]=='1') a=maxx[i][0];
		for (j=1;j<=a;j++) blstart[j].push_back(i);
	//	cout<<maxx[i][0]<<' '<<maxx[i][1]<<endl;
	}
	for (i=1;i<=n;i++)
	{
	//	cout<<i<<' ';
	//	for (auto g : blstart[i]) cout<<g<<' ';
	//	cout<<endl;
	}
	for (i=1;i<=n;i++)
	{
		u=0;
		j=0;
		a=0;
		while(true)
		{
			while ((j<blstart[i].size())and(u>=blstart[i][j])) j++;
			if ((maxx[u+1][0]>=i)or(maxx[u+1][1]>=i)) 
			{
				u+=i;
				a++;
			}
			else if (j<blstart[i].size())
			{
				a++;
				u=blstart[i][j]+i-1;
			}
			else break;
		}
		cout<<a<<' ';
	}
}