
// Problem : A. Berland Poker
// Contest : Codeforces - Educational Codeforces Round 88 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1359/problem/0
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

/*
 A Submission by $%U%$
 at time: $%Y%$-$%M%$-$%D%$ $%h%$:$%m%$:$%s%$
*/
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define rep(i,n) for(int64_t i=0;i < (int64_t)(n);i++)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define FILE_IN "cseq.inp"
#define FILE_OUT "cseq.out"
#define ofile freopen(FILE_IN,"r",stdin);freopen(FILE_OUT,"w",stdout)
#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define nfio cin.tie(0);cout.tie(0)
#define max(x,y) (((x)>(y))?(x):(y))
#define min(x,y) (((x)<(y))?(x):(y))
#define ord(a,b,c) ((a>=b)and(b>=c))
#define MOD (ll(1000000007))
#define MAX 300001
#define mag 320
#define p1 first
#define p2 second.first
#define p3 second.second
#define fi first
#define se second
#define pow2(x) (ll(1)<<x)
#define pii pair<int,int>
#define piii pair<int,pii>
#define For(i,__,___) for(int i=__;i<=___;i++)
#define Rep(i,__,___) for(int i=__;i>=___;i--)
#define ordered_set tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update>
#define endl "\n"
#define bi BigInt
typedef long long ll;
typedef long double ld;
//---------END-------//
ll n,m,k,pos[100001],t,t1,i,j,x,y;
ld h,c,tar;
ld calc (ll x)
{
	return double((x/2)*c+(x-x/2)*h)/x;
}
int main()
{
//  ofile;
    fio;
    cin>>t;
    for (t1=0;t1<t;t1++)
    {
    	cin>>h>>c>>tar;
    	if (h-tar==0) cout<<1;
    	else
    	if (h-tar==tar-c) cout<<2;
    	else
    	{
    		ll res=2;
    		ll cycles=(h-tar)/(tar-c-(h-tar));
    //		cout<<2<<' '<<calc(2)<<endl;
   //		cout<<cycles*2+1<<' '<<calc(cycles*2+1)<<endl;
   //		cout<<cycles*2+3<<' '<<calc(cycles*2+3)<<endl; 
    		if ((abs(calc(cycles*2+1)-tar)<abs(calc(res)-tar))or
    		(
    		(abs(calc(cycles*2+1)-tar)<abs(calc(res)-tar))
    		and
    		(cycles*2+1<res)
    		))
    		res=cycles*2+1;
    		if ((abs(calc(cycles*2+3)-tar)<abs(calc(res)-tar))or
    		(
    		(abs(calc(cycles*2+3)-tar)<abs(calc(res)-tar))
    		and
    		(cycles*2+3<res)
    		))
    		res=cycles*2+3;
    		cout<<res;
    	}
    	cout<<endl;
    }
}