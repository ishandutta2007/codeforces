
// Problem : D. Help Monks
// Contest : Codeforces - Codeforces Beta Round #78 (Div. 1 Only)
// URL : https://codeforces.com/problemset/problem/98/D
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
int n,m,k,c[501],pos[100001],t,t1,i,j;
vector<int> bruh; 
vector<pii> sol;
void solve (int x, int a, int b, int c, int flipped)
{
	if (x==m-1)
	{
		if (bruh[x]==1) sol.push_back({a,b});
		else if (flipped) 
		{
			for (int i=0;i<bruh[x];i++) sol.push_back({a,b});
		}
		else
		{
			
			for (int i=1;i<bruh[x];i++) sol.push_back({a,c});
			sol.push_back({a,b});
			for (int i=1;i<bruh[x];i++) sol.push_back({c,b});
		}
	}
	else
	{
		if (bruh[x]==1)
		{
			solve(x+1,a,c,b,1);
			sol.push_back({a,b});
			solve(x+1,c,b,a,1);
		}
		else if (flipped) 
		{
			solve(x+1,a,c,b,1);
			for (int i=0;i<bruh[x];i++) sol.push_back({a,b});
			solve(x+1,c,b,a,1);
		}
		else
		{
			solve(x+1,a,b,c,1);
			for (int i=0;i<bruh[x];i++) sol.push_back({a,c});
			solve(x+1,b,a,c,1);
			for (int i=0;i<bruh[x];i++) sol.push_back({c,b});
			solve(x+1,a,b,c,0);
		}
	}
}
int main()
{
//  ofile;
    fio;
    cin>>n;
    j=0;
    for (i=1;i<=n;i++)
    {
    	cin>>c[i];
    	if ((i==1)or(c[i]==c[i-1])) j++;
    	else 
    	{
    		bruh.push_back(j);
    		j=1;
    	}
    }
    		bruh.push_back(j);
   	m=bruh.size();
   	solve(0,1,3,2,0);
   	cout<<sol.size()<<endl;
   	for (pii pp : sol) cout<<pp.fi<<' '<<pp.se<<endl;
}