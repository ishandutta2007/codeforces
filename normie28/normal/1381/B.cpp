
// Problem : B. Unmerge
// Contest : Codeforces - Codeforces Round #658 (Div. 1)
// URL : https://codeforces.com/contest/1381/problem/B
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
int n,m,k,c[501],pos[4001],t,t1,i,j;
int dp[4001][4001];
vector<int> block; vector<int> presum;
int main()
{
//  ofile;
    fio;
    cin>>t;
    for (t1=0;t1<t;t1++)
    {
    	cin>>n; block.clear(); presum.clear(); presum={0};
    	for (i=1;i<=2*n;i++)
    	{
    		cin>>pos[i];
    	}
    	j=pos[1];
    	k=1;
    	
    	for (i=2;i<=2*n;i++)
    	{
    		if (pos[i]<j) k++;
    		else
    		{
    			block.push_back(k);
    			presum.push_back(presum[presum.size()-1]+k);
    			j=pos[i];
    			k=1;
    		}
    	}
    	
    			block.push_back(k);
    			presum.push_back(presum[presum.size()-1]+k);
    			j=pos[i];
    			k=1;
    		m=block.size();
    	for (i=m;i>=0;i--)
    	for (j=0;j<=n;j++)
    	{
    		dp[i][j]=0;
    		k=presum[i]-j;
    		if ((j>n)or(k>n)) dp[i][j]=0;
    		else if (i==m) dp[i][j]=1;
    		else
    		{
    			if ((j+block[i]<=n)and(dp[i+1][j+block[i]])) dp[i][j]=1;
    			if ((k+block[i]<=n)and(dp[i+1][j])) dp[i][j]=1;
    		}
    	}
    if (dp[0][0]) cout<<"YES\n"; else cout<<"NO\n";
    }
}