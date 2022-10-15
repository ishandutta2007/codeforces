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
int n,m,k,c[501],pos[100001],t,t1,i,j;
int arr[1001],l[1001],r[1001];
int main()
{
//  ofile;
    fio;
    cin>>t;
    for (t1=0;t1<t;t1++)
    {
    	cin>>n;
    	for (i=1;i<=n;i++) cin>>arr[i];
    	for (i=1;i<=n;i++)
    	{
    		if (i==1) l[i]=1;
    		else if (arr[i]<arr[l[i-1]]) l[i]=i;
    		else l[i]=l[i-1];
    	}
    	for (i=n;i>=1;i--)
    	{
    		if (i==n) r[i]=n;
    		else if (arr[i]<arr[r[i+1]]) r[i]=i;
    		else r[i]=r[i+1];
    	}
    	int fail=1;
    	for (i=2;i<n;i++)
    	{
    		if ((arr[i]>arr[l[i-1]])and(arr[i]>arr[r[i+1]])) 
    		{
    			cout<<"YES"<<endl<<l[i-1]<<' '<<i<<' '<<r[i+1]<<endl;
    			fail=0;
    			break;
    		}
    	}
    	if (fail) cout<<"NO\n";
    }
}