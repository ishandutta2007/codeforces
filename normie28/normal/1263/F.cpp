
// Problem : F. Economic Difficulties
// Contest : Codeforces - Codeforces Round #603 (Div. 2)
// URL : https://codeforces.com/contest/1263/problem/F
// Memory Limit : 256 MB
// Time Limit : 3000 ms
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
int n,n1,n2,m,k,c[501],pos[100001],t,t1,i,j;
vector<int> gt1[2001],gt2[2001];
int l1[2001],r1[2001],c1[2001];
int l2[2001],r2[2001],c2[2001];
int dp[2001];
void dfs1(int x)
{
//	cout<<"dfs1 "<<x<<endl;
	if (l1[x]) return;
	l1[x]=1e9;
	r1[x]=-1e9;
	for (int g : gt1[x])
	{
		if (g<0)
		{
			l1[x]=min(l1[x],-g);
			r1[x]=max(r1[x],-g);
		}
		else
		{
			dfs1(g);
			l1[x]=min(l1[x],l1[g]);
			r1[x]=max(r1[x],r1[g]);
			c1[x]+=c1[g];
		}
	}
	if (x>1) c1[x]++;
}

void dfs2(int x)
{
//	cout<<"dfs2 "<<x<<endl;
	if (l2[x]) return;
	l2[x]=1e9;
	r2[x]=-1e9;
	for (int g : gt2[x])
	{
		if (g<0)
		{
			l2[x]=min(l2[x],-g);
			r2[x]=max(r2[x],-g);
		}
		else
		{
			dfs2(g);
			l2[x]=min(l2[x],l2[g]);
			r2[x]=max(r2[x],r2[g]);
			c2[x]+=c2[g];
		}
	}
	if (x>1) c2[x]++;
}

int main()
{
//  ofile;
    fio;
    cin>>n;
    cin>>n1;
    for (i=2;i<=n1;i++)
    {
    	cin>>k;
    	gt1[k].push_back(i);
    }
    for (i=1;i<=n;i++)
    {
    	cin>>k;
    	gt1[k].push_back(-i);
    }
    cin>>n2;
    for (i=2;i<=n2;i++)
    {
    	cin>>k;
    	gt2[k].push_back(i);
    }
    for (i=1;i<=n;i++)
    {
    	cin>>k;
    	gt2[k].push_back(-i);
    }
    dfs1(1);
    dfs2(1);
    dp[0]=0;
    	for (j=1;j<=n1;j++)
    	{
  //  		cout<<"n1 "<<j<<' '<<l1[j]<<' '<<r1[j]<<' '<<c1[j]<<endl;
    	}
    	for (j=1;j<=n2;j++)
    	{
  //  		cout<<"n2 "<<j<<' '<<l2[j]<<' '<<r2[j]<<' '<<c2[j]<<endl;
    	}
    for (i=1;i<=n;i++)
    {
    	for (j=1;j<=n1;j++)
    	{
    		if (r1[j]==i)
    		{
    			dp[i]=max(dp[i],dp[l1[j]-1]+c1[j]);
    		}
    	}
    	for (j=1;j<=n2;j++)
    	{
    		if (r2[j]==i)
    		{
    			dp[i]=max(dp[i],dp[l2[j]-1]+c2[j]);
    		}
    	}
    }
    cout<<dp[n];
}