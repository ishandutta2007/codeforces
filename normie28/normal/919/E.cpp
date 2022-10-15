
// Problem : D. Restore Permutation
// Contest : Codeforces - Manthan, Codefest 19 (open for everyone, rated, Div. 1 + Div. 2)
// URL : https://codeforces.com/problemset/problem/1208/D
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
#define fef(i,a,b) for(ll i=a;i<=b;i++)
#define rer(i,a,b) for(ll i=b;i>=a;i--)
#define wew while(true)
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
//-------------------//
ll bow (ll a , ll x , ll m)
{
	if (x==0) return 1;
	ll res= bow(a,x/2,m);
	res*=res;
	res%=m;
	if (x%2) res*=a;
	return res%m;
}
//---------END-------//
ll n,a,b,p,m,k,c[501],pos[100001],t,t1,i,j,res=0;
set<int> bruh;
int main()
{
//  ofile;
    fio;
    cin>>a>>b>>p>>n;
    ll c=1;
    for (i=0;i<p-1;i++)
    {
    	ll inv=b*bow(c,p-2,p);
    	inv%=p;
    	ll act=c;
    	ll tries;
    	if (i<inv) tries=i+(p-inv);
    	else tries=i-inv;
    	act=i+tries*(p-1);
    //	cout<<i<<' '<<c<<' '<<inv<<' '<<act<<endl;
    	if (act==0) res+=n/((p*(p-1)));
    	else if (act<=n%(p*(p-1))) res+=n/((p*(p-1)))+1;
    	else res+=n/((p*(p-1)));
    	c*=a;
    	c%=p;
    }
    cout<< res;
}