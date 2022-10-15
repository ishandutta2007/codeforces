
// Problem : Multiples of Length
// Contest : Codeforces
// URL : https://m1.codeforces.com/contest/1396/problem/A
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
#define For(i,__,___) for(int i=__;i<=___;i++)
#define Rep(i,__,___) for(int i=__;i>=___;i--)
#define ordered_set tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update>
#define endl "\n"
#define bi BigInt
typedef long long ll;
//---------END-------//
ll n,m,k,c[501],arr[100001],t,t1,i,j;
ll choose[100001];
int main()
{
//  ofile;
    fio;
    cin>>n;
    for (i=1;i<=n;i++) cin>>arr[i];
    for (i=0;i<n;i++)
    {
    	choose[i*(n-1)%n]=i;
    }
    if (n==1)
    {
    	cout<<1<<' '<<1<<endl<<-arr[1]<<endl;
    	cout<<1<<' '<<1<<endl<<0<<endl;
    	cout<<1<<' '<<1<<endl<<0<<endl;
    }
    else
    {
    	cout<<1<<' '<<n-1<<endl;
    	for (i=1;i<n;i++)
    	{
    		t=choose[(arr[i]%n+n)%n];
    		cout<<-t*(n-1)<<' ';
    		arr[i]+=-t*(n-1);
    	}
    	cout<<endl;
    	cout<<n<<' '<<n<<endl<<-arr[n]<<endl;
    	arr[n]=0;
    	cout<<1<<' '<<n<<endl;
    	for (i=1;i<=n;i++) cout<<-arr[i]<<' ';
    	cout<<endl;
    }
}