//------------NMFF0B0H--------//
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define rep(i,n) for(int64_t i=0;i < (int64_t)(n);i++)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define FILE_IN "evadingin.txt"
#define FILE_OUT "evadingout.txt"
#define ofile freopen(FILE_IN,"r",stdin);freopen(FILE_OUT,"w",stdout)
#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define nfio cin.tie(0);cout.tie(0)
#define max(x,y) (((x)>(y))?(x):(y))
#define min(x,y) (((x)<(y))?(x):(y))
#define ord(a,b,c) ((a>=b)and(b>=c))
#define MOD (ll(111539768))
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
typedef long long ll;
//-----------RND------------//
int n,num,m,i,j,k,dp[2000000][4];
string s,t;
int main()
{
    fio;
    cin>>t;
	
    s="00";
	for(i=0;i<t.length();i++) s.push_back(t[i]);
    n=s.length();
    for (i=1;i<=n;i++) for (j=0;j<4;j++)
    {
        if (i==1)
        {
            if ((s[i-1]=='0')and(j==0)) dp[i][j]=1;
            if ((s[i-1]=='0')and(j==1)) dp[i][j]=0;
            if ((s[i-1]=='0')and(j==2)) dp[i][j]=1;
            if ((s[i-1]=='0')and(j==3)) dp[i][j]=1e9;
        }
        else
        {
            if ((j==0)) dp[i][j]=min(dp[i-1][1+s[i-2]-48]+1,dp[i-1][1+s[i-2]-48-1]+1);
            if ((j==1)) dp[i][j]=min(dp[i-1][1+s[i-2]-48],dp[i-1][1+s[i-2]-48]);
            if ((j==2)) dp[i][j]=min(dp[i-1][1+s[i-2]-48]+1,dp[i-1][1+s[i-2]-48+1]+1);
            if ((j==3)) dp[i][j]=min(dp[i-1][1+s[i-2]-48+1],dp[i-1][1+s[i-2]-48+1]);
        }
//cout<<"dp["<<i<<"]["<<j<<"]="<<dp[i][j]<<endl;
    }
    cout<<dp[n][1+s[n-1]-48];
}