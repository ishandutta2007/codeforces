
// Problem : E. Change-free
// Contest : Codeforces - Codeforces Round #398 (Div. 2)
// URL : https://codeforces.com/problemset/problem/767/E
// Memory Limit : 256 MB
// Time Limit : 1000 ms
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
//---------END-------//
ll n,m,k,tar[100001],cost[100001],force[100001],t,t1,i,j,res=0;
struct cmp {
	int operator() (int a, int b)
	{
		if (cost[a]-cost[b]) return (cost[a]<cost[b]);
		return (a<b);
	}
};
set<ll,cmp> lis;
int main()
{
//  ofile;
    fio;
    cin>>n>>m;
    for (i=1;i<=n;i++) cin>>tar[i];
    for (i=1;i<=n;i++) cin>>cost[i];
    for (i=1;i<=n;i++) if (tar[i]%100==0) cost[i]=1e18; else cost[i]*=(100-tar[i]%100);
 //   for (i=1;i<=n;i++) cout<<cost[i]<<endl;
    for (i=1;i<=n;i++)
    {
    	m-=(tar[i]%100);
    	if (tar[i]%100) lis.insert(i);
    	if (m<0)
    	{
    		m+=100;
  //  		cout<<(*lis.begin())<<endl;
    		res+=cost[(*lis.begin())];
    		force[(*lis.begin())]=1;
    		lis.erase(lis.begin());
    	}
    }
    cout<<res<<endl;
    for (i=1;i<=n;i++)
    if (force[i]==0) cout<<tar[i]/100<<' '<<tar[i]%100<<endl;
    else cout<<tar[i]/100+1<<' '<<0<<endl;
}