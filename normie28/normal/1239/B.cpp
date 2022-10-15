
// Problem : B. The World Is Just a Programming Task (Hard Version)
// Contest : Codeforces - Codeforces Round #594 (Div. 1)
// URL : https://codeforces.com/contest/1239/problem/B
// Memory Limit : 512 MB
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
int n,m,k,c[501],t,t1,i,j,minn=1e9,maxx,maxx2,resl,resr,res2l,res2r;
string s;
int dp[300001];
vector<int> pos;
int main()
{
//  ofile;
    fio;
    cin>>n;
    cin>>s;
    for (i=0;i<n;i++)
    {
    	if (s[i]=='(') dp[i+1]=dp[i]+1;
    	else dp[i+1]=dp[i]-1; 
    }
    if (dp[n]!=0) return cout<<0<<endl<<1<<' '<<1,0;
    for (i=1;i<=n;i++) 
    {
    	if (minn>dp[i]) minn=dp[i];
    }
    for (i=1;i<=n;i++) 
    {
    	if (minn==dp[i]) t++;
    }
    
    for (i=0;i<2*n;i++)
    {
 //   	cout<<i%n+1<<' '<<dp[i%n+1]<<endl;
    	if (dp[i%n+1]==minn)
    	{
    		if (maxx<pos.size()) 
    		{
    			maxx=pos.size();
    			resl=pos[0];
    			resr=pos[maxx-1];
    		}
    		pos.clear();
    	}
    	else if (dp[i%n+1]==minn+1)
    	{
    		pos.push_back(i%n+1);
    	}
    }
    pos.clear();
    for (i=0;i<2*n;i++)
    {
    	if (dp[i%n+1]==minn+1)
    	{
    		if (maxx2<pos.size()) 
    		{
    			maxx2=pos.size();
    			res2l=pos[0];
    			res2r=pos[maxx2-1];
    		}
    		pos.clear();
    	}
    	else if (dp[i%n+1]==minn+2)
    	{
    		pos.push_back(i%n+1);
    	}
    }
    if ((maxx>t)and(maxx>maxx2+t))
    {
    cout<<maxx<<endl<<resl<<' '<<resr%n+1;
    }
    else
    if ((maxx2+t>t)and(maxx2+t>=maxx))
    {
    cout<<maxx2+t<<endl<<res2l<<' '<<res2r%n+1;
    }
    else cout<<t<<endl<<1<<' '<<1;
}