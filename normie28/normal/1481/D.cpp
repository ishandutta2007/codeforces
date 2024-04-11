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
char mp[1001][1001];
int n,m,i,j,k,t,t1,u,v,a,b;
int main()
{
	fio;
	cin>>t;
	for (t1=0;t1<t;t1++){
		cin>>n>>m;
		for (i=1;i<=n;i++) for (j=1;j<=n;j++) cin>>mp[i][j];
		if (m%2==1)
		{
					cout<<"YES\n";
			for (i=1;i<=m+1;i++) cout<<i%2+1<<' ';
			cout<<endl;
		}
		else
		{
			for (i=1;i<=n;i++)
			{
				a=0; // in
				b=0; // out
				int passed=0;
				for (j=1;j<=n;j++)
				if ((i!=j)and(mp[i][j]==mp[j][i]))
				{
					cout<<"YES\n";
					for (k=1;k<=m+1;k++) if (k%2) cout<<i<<' '; else cout<<j<<' ';
					cout<<endl;
					passed=1; break;
				}
				else if ((mp[j][i]=='a')and(i-j)) a=j;
				else if ((mp[j][i]=='b')and(i-j)) b=j;
				if (passed) break;
				if ((!a)or(!b)) continue;
           //   cout<<a<<' '<<b<<endl;
				if ((m/2)%2)
				{
					cout<<"YES\n";
					cout<<a<<' ';
					for (k=1;k<=m/2;k++) {if (k%2)  cout<<i; else cout<<a; cout<<' ';}
					for (k=1;k<=m/2;k++) {if (k%2)  cout<<b; else cout<<i; cout<<' ';}
					cout<<endl;
					break;
				}
				else
				{
					cout<<"YES\n";
					cout<<i<<' ';
					for (k=1;k<=m/2;k++) {if (k%2)  cout<<a; else cout<<i; cout<<' ';}
					for (k=1;k<=m/2;k++) {if (k%2)  cout<<b; else cout<<i; cout<<' ';}
					cout<<endl;
					break;
				}
			}
			if (i==n+1) cout<<"NO\n";
		}
	}
}