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
string s;
vector<ll> pos[3];
ll cost[100001][2];
ll n,m,i,j,k,t,t1,u,v,a,b,x,y,base,res=1e18;
int main()
{
	fio;
	cin>>s;
	n=s.length();
	cin>>x>>y;
	for (i=0;i<n;i++) 
	{
		if (s[i]=='?') pos[2].push_back(i);
		else pos[int(s[i]-48)].push_back(i);
	}
	a=0;
	b=0;
	for (i=0;i<n;i++)
	{
		if (s[i]=='0') 
		{
			base+=b*y;
			a++;
		}
		else if (s[i]=='1')
		{
			base+=a*x;
			b++;
		}
		else if (s[i]=='?')
		{
			cost[i][0]=b*y+(pos[1].size()-b)*x;
			
			cost[i][1]=a*x+(pos[0].size()-a)*y;			
		}
	}
	a=0;
	for (i=0;i<pos[2].size();i++)
	{
		a+=cost[pos[2][i]][0];
	}
	res=min(res,base+a);
	for (i=0;i<pos[2].size();i++)
	{
		a-=cost[pos[2][i]][0];
		a+=cost[pos[2][i]][1];
		res=min(res,base+a+(i+1)*(pos[2].size()-i-1)*y);
	}
	for (i=0;i<pos[2].size();i++)
	{
		a-=cost[pos[2][i]][1];
		a+=cost[pos[2][i]][0];
		res=min(res,base+a+(i+1)*(pos[2].size()-i-1)*x);
	}
	cout<<res;
}