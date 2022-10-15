
// Problem : C. Captains Mode
// Contest : Codeforces - Codeforces Round #222 (Div. 1)
// URL : https://codeforces.com/problemset/problem/377/C
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
vector<int> st;
vector<pair<char,int>> ord;
int dp[21][1048576];
int main()
{
//  ofile;
    fio;
    cin>>n;
    for (i=0;i<n;i++)
    {
    	cin>>j;
    	st.push_back(j);
    }
    sort(st.begin(),st.end(),[](int a, int b){return (a>b);});
    cin>>m;
    for (i=0;i<m;i++)
    {
    	char c;
    	cin>>c>>j;
    	ord.push_back({c,j});
    }
    int d=min(m,n); 
    for (i=1;i<=m;i++) for (j=0;j<(1<<d);j++)
    {
  //  	cout<<i<<' '<<j<<endl;
    	if ((ord[m-i].fi=='p')and(ord[m-i].se==1))
    	{
    		dp[i][j]=-1e9;
    		for (k=0;k<d;k++) 
    		{
    //			cout<<i<<' '<<j<<' '<<k<<' '<<int(j&(1<<(d-1-k)))<<endl;
    		if (int(j&(1<<(d-1-k)))==0)
    		{
    		dp[i][j]=max(dp[i][j],dp[i-1][j|(1<<(d-1-k))]+st[k]);
    		}
    		}
    	}
    	if ((ord[m-i].fi=='p')and(ord[m-i].se==2))
    	{
    		dp[i][j]=1e9;
    		for (k=0;k<d;k++) 
    		{
    //			cout<<i<<' '<<j<<' '<<k<<' '<<int(j&(1<<(d-1-k)))<<endl;
    		if (int(j&(1<<(d-1-k)))==0)
    		{
    			
    		dp[i][j]=min(dp[i][j],dp[i-1][j|(1<<(d-1-k))]-st[k]);
    		}
    		}
    	}
    	if ((ord[m-i].fi=='b')and(ord[m-i].se==1))
    	{
    		dp[i][j]=dp[i-1][j];
    		for (k=0;k<d;k++)
    		{
   // 			cout<<i<<' '<<j<<' '<<k<<' '<<int(j&(1<<(d-1-k)))<<endl;
    		 if (int(j&(1<<(d-1-k)))==0)
    		{
    		dp[i][j]=max(dp[i][j],dp[i-1][j|(1<<(d-1-k))]);
    		}
    		}
    	}
    	if ((ord[m-i].fi=='b')and(ord[m-i].se==2))
    	{
    		dp[i][j]=dp[i-1][j];
    		for (k=0;k<d;k++) 
    		{
    			
    //			cout<<i<<' '<<j<<' '<<k<<' '<<int(j&(1<<(d-1-k)))<<endl;
    			if (int(j&(1<<(d-1-k)))==0)
    		{
    		dp[i][j]=min(dp[i][j],dp[i-1][j|(1<<(d-1-k))]);
    		}
    		}
    	}
    }
    cout<<dp[m][0];
}