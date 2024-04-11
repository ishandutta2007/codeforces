
// Problem : C. LRU
// Contest : Codeforces - Codeforces Round #363 (Div. 1)
// URL : https://codeforces.com/problemset/problem/698/C
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
int n,m,k,c[501],pos[100001],t,t1,i,j;
double dp[1500000];
double pb[21],res[21],all=0;
vector<int> onb;
int main()
{
//  ofile;
    fio;
    cin>>n>>k;
    for (i=0;i<n;i++) cin>>pb[i];
    dp[0]=1;
    for (i=1;i<(1<<n);i++)
    {
    	int kk=i;
    	double sum=0;
    	onb.clear();
    	for (j=0;j<n;j++)
    	{
    		if (kk%2)
    		{ 
    		onb.push_back(j);
    		sum+=pb[j];
    		}
    		kk/=2;
    	}
    	for (int g:onb)
    	if (pb[g]) dp[i]+=dp[i^(1<<g)]*pb[g]/(1-sum+pb[g]);
    	if (onb.size()==k)
    	for (int g:onb)
    	res[g]+=dp[i];
    	all+=dp[i];
   // 	cout<<dp[i]<<' ';
    }
    for (i=0;i<n;i++)
    {
    	if (pb[i]) t++;
    }
    if (t<=k)
    for (i=0;i<n;i++)
    {
    	if (pb[i]) cout<<1<<' '; else cout<<0<<' ';
    }
    else
    
    for (i=0;i<n;i++) cout<<fixed<<setprecision(9)<<res[i]<<' ';
}