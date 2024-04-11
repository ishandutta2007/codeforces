
// Problem : D. Bear and Company
// Contest : Codeforces - VK Cup 2017 - Round 1
// URL : https://codeforces.com/problemset/problem/771/D
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
int n,m,k,c[501],pos[100001],t,t1,i,j,cntv,cntk,cntx,res=1e9;
int dp[75][75][75][3],lv,lk,lx;
string s;
int main()
{
//  ofile;
    fio;
    cin>>n>>s;
    for (i=0;i<n;i++) if ((s[i]!='V')and(s[i]!='K')) s[i]='X';
    for (i=0;i<n;i++)
    {
    	switch (s[i])
    	{
    	case 'V':
    		cntv++;
    		break;
    	case 'K':
    		cntk++;
    		break;
    	case 'X':
    		cntx++;
    		break;
    		}
    }
    for (i=0;i<=cntv;i++)
    for (j=0;j<=cntk;j++)
    for (k=0;k<=cntx;k++) if (i+j+k)
    for (t=0;t<3;t++)
    {
 //   	cout<<i<<' '<<j<<' '<<k<<' '<<t<<endl;
    	dp[i][j][k][t]=1e9;
    	if (t==0)
    	{
    		if (!i) continue;
    		lv=lk=lx=0;
    		for (int ii=0;ii<n;ii++)
    		{
   // 			cout<<lv<<' '<<lk<<' '<<lx<<endl;
    			if (s[ii]=='V') lv++; if (lv==i) break;
    			if (s[ii]=='K') lk++; 
    			if (s[ii]=='X') lx++;
    		}
    		dp[i][j][k][t]=min(dp[i][j][k][t],dp[i-1][j][k][0]);
    		dp[i][j][k][t]=min(dp[i][j][k][t],dp[i-1][j][k][1]);
    		dp[i][j][k][t]=min(dp[i][j][k][t],dp[i-1][j][k][2]);
    		dp[i][j][k][t]+=max(lk-j,0)+max(lx-k,0);
    	}
    	else
    	if (t==1)
    	{
    		if (!j) continue;
    		lv=lk=lx=0;
    		for (int ii=0;ii<n;ii++)
    		{
 //   			cout<<lv<<' '<<lk<<' '<<lx<<endl;
    			if (s[ii]=='V') lv++; 
    			if (s[ii]=='K') lk++; if (lk==j) break;
    			if (s[ii]=='X') lx++;
    		}
    		dp[i][j][k][t]=min(dp[i][j][k][t],dp[i][j-1][k][1]);
    		dp[i][j][k][t]=min(dp[i][j][k][t],dp[i][j-1][k][2]);
    		dp[i][j][k][t]+=max(lv-i,0)+max(lx-k,0);
    	}
    	else
    	if (t==2)
    	{
    		if (!k) continue;
    		lv=lk=lx=0;
    		for (int ii=0;ii<n;ii++)
    		{
   // 			cout<<lv<<' '<<lk<<' '<<lx<<endl;
    			if (s[ii]=='V') lv++; 
    			if (s[ii]=='K') lk++; 
    			if (s[ii]=='X') lx++; if (lx==k) break;
    		}
    		dp[i][j][k][t]=min(dp[i][j][k][t],dp[i][j][k-1][0]);
    		dp[i][j][k][t]=min(dp[i][j][k][t],dp[i][j][k-1][1]);
    		dp[i][j][k][t]=min(dp[i][j][k][t],dp[i][j][k-1][2]);
    		dp[i][j][k][t]+=max(lv-i,0)+max(lk-j,0);
    	}
    	
    }
    res=1e9;
    res=min(res,dp[cntv][cntk][cntx][0]);
    res=min(res,dp[cntv][cntk][cntx][1]);
    res=min(res,dp[cntv][cntk][cntx][2]);
    cout<<res;
}