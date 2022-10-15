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
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define FILE_IN "graph.inp"
#define FILE_OUT "graph.out"
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
#define pi 3.1415926535897
typedef int ll;
//------------xc xch normie tm muoi tm phan tram no----------//
ll n,m,k,c[1001],t,t1,i,j,minn,maxx,cur,used[1001],lu,lv,res=0;
vector<ll> cyc;
char mp[1001][1001];
int main()
{
	cin>>n;
	for (i=1;i<=n;i++)
	{
		cin>>k;
		c[k]=i;
		for (j=1;j<=n;j++) mp[i][j]='.';
	}
	t=n;
	for (i=1;i<=n;i++) if (!used[i])
	{
		j=i;
		cyc.clear();
		while ((!used[j]))
		{
			used[j]=1;
			cyc.push_back(j);
			j=c[j];
		}
		m=cyc.size();
		if (m==1) ;
		else
		{
			j=0;
			for (k=0;k<m;k++) if (cyc[k]<cyc[j]) j=k;
			for (k=0;k<m-1;k++) if (cyc[(j+k)%m]==1) continue; else
			if (cyc[(j+k)%m]<cyc[(j+k+1)%m])
			{
				mp[t-k][cyc[(j+k)%m]]='\\';
				mp[t-k][cyc[(j+k+1)%m]]='\\';
			}
			else
			{
				mp[t-k][cyc[(j+k)%m]]='/';
				mp[t-k][cyc[(j+k+1)%m]]='/';
			}
			if (cyc[j]==1)
			{
				mp[t-m+1][cyc[(j+m-1)%m]]='/';
				mp[t-m+1][cyc[(j)%m]]='/';
			}
			else
			{
				mp[t-m+1][cyc[(j+m-1)%m]]='/';
				mp[t-m+1][1]='/';
				mp[t][1]='\\';
			}
			t-=m;
		}
	}
	if (t==n)
	{
		cout<<n;
	}
	else cout<<n-1;
	cout<<endl;
	for (i=1;i<=n;i++) {
	for (j=1;j<=n;j++) {
	cout<<mp[i][j]; }
	cout<<endl;
}
	
}
/*
Invocation failed [COMPILATION_ERROR]
Can't compile file:
program.cpp: In function 'int main()':
program.cpp:64:59: error: invalid operands of types 'll' {aka 'int'} and 'll [101]' {aka 'int [101]'} to binary 'operator-'
   64 |    if (t>=dp[i-1][j]-dp[i][j-1]) fp[i][j][t]+=fp[i][j-1][t-fp[i-1][j]+dp[i][j-1]];
      |                                                          ~^~~~~~~~~~~
      |                                                          |          |
      |                                                          |          ll [101] {aka int [101]}
      |                                                          ll {aka int}
 
=====
Used: 0 ms, 0 KB
*/