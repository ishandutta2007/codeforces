
// Problem : A Bit Similar
// Contest : Codeforces
// URL : https://m1.codeforces.com/contest/1469/problem/E
// Memory Limit : 1024 MB
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
int n,m,i,j,k,t,t1,u,v,a,b;
int cnt[1100000];
int pre1[1100000];
string s;
int main()
{
	fio;
	cin>>t;
	for (t1=0;t1<t;t1++)
	{
		cin>>n>>k;
		cin>>s;
		for (i=0;i<n;i++) s[i]=char(97-s[i]);
		for (i=1;i<=n;i++)
		{
			pre1[i]=pre1[i-1];
			if (s[i-1]=='1') pre1[i]++;
		}
		u=0;
		for (i=1;i<=n;i++)
		{
			u<<=1;
			u+=(s[i-1]-48);
			u%=(1<<(min(20,k)));
			if ((i>=k)and((k<=20)or(pre1[i-20]-pre1[i-k]==0))) cnt[u]++;
		}
		
		for (i=0;((k>20)or(i<(1<<k)));i++) if (!cnt[i]) break;
		if ((k<=20)and(i==(1<<k))) cout<<"NO\n";
		else
		{
			cout<<"YES\n";
			for (j=0;j<max(0,k-20);j++) cout<<0;
			for (j=min(k,20)-1;j>=0;j--) if (i&(1<<j)) cout<<1;else cout<<0;
			cout<<endl;
		}
		
		u=0;
		for (i=1;i<=n;i++)
		{
			u<<=1;
			u+=(s[i-1]-48);
			u%=(1<<(min(20,k)));
			if ((i>=k)and((k<=20)or(pre1[i-20]-pre1[i-k]==0))) cnt[u]--;
		}
	}
}