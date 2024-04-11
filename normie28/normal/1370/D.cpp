
// Problem : D. Odd-Even Subsequence
// Contest : Codeforces - Codeforces Round #651 (Div. 2)
// URL : https://codeforces.com/contest/1370/problem/D
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
//---------END-------//
int n,m,k,c[501],arr[200001],t,t1,i,j;
int check1(int x)
{
	int j=0;
	for (int i=1;i<=k;i++)
	{
		if (i%2==1)
		{
			j++;
			while(j<=n)
			{
				if (arr[j]<=x) break;
				else j++;
			}
		}
		else
		{
			j++;
		}
	}
	return (j<=n);
}
int check2(int x)
{
	int j=0;
	for (int i=1;i<=k;i++)
	{
		if (i%2==0)
		{
			j++;
			while(j<=n)
			{
				if (arr[j]<=x) break;
				else j++;
			}
		}
		else
		{
			j++;
		}
	}
	return (j<=n);
}
int bs (int l, int r)
{
	if (l==r) return l;
	int mid=(l+r)/2;
	if ((check1(mid))or(check2(mid))) return bs(l,mid); else return bs(mid+1,r);
}
int main()
{
//  ofile;
    fio;
    cin>>n>>k;
    for (i=1;i<=n;i++) cin>>arr[i];
    cout<<bs(1,1e9);
}