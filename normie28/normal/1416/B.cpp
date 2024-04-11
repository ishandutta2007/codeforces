
// Problem : Make Them Equal
// Contest : Codeforces
// URL : https://m1.codeforces.com/contest/1416/problem/B
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
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define For(i,__,___) for(int i=__;i<=___;i++)
#define Rep(i,__,___) for(int i=__;i>=___;i--)
#define ordered_set tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update>
#define endl "\n"
#define bi BigInt
typedef long long ll;
//---------END-------//
ll n,m,k,c[501],arr[300001],t,t1,i,j;
ll a,b,u,v;
vector<ll> ord;
vector<plll> res; 
int main()
{
//  ofile;
    fio;
    cin>>t;
    for (t1=0;t1<t;t1++)
    {
    cin>>n;
    m=0;
    for (i=1;i<=n;i++)
    {
    	cin>>arr[i];
    	m+=arr[i];
    }
    if (m%n) {cout<<-1<<endl; continue;}
    ord.clear();
    res.clear();
    for (i=2;i<=n;i++)
    {
    	ord.push_back(i);
    }
    sort(ord.begin(),ord.end(),[](ll a, ll b)
    {
    	ll aa,bb;
    	if (arr[a]%a==0) aa=0; else aa=a-(arr[a]%a);
    	if (arr[b]%b==0) bb=0; else bb=b-(arr[b]%b);
    	return (aa<bb);
    });
    u=arr[1];
    for (i=0;i<=n-2;i++)
    {
    	a=ord[i];
    	if (arr[a]%a==0) b=0; else b=a-(arr[a]%a);
    	if (u<b) break;
    	else
    	{
    		res.push_back({1,{a,b}});
    		res.push_back({a,{1,(b+arr[a])/a}});
    		u+=arr[a];
    	}
    }
    if (res.size()<(n-1)*2) {cout<<-1<<endl; continue;}
    for (i=2;i<=n;i++)
    {
    	res.push_back({1,{i,m/n}});
    }
    cout<<res.size()<<endl;
    for (i=0;i<(n-1)*3;i++) cout<<res[i].p1<<' '<<res[i].p2<<' '<<res[i].p3<<endl;
    }
}