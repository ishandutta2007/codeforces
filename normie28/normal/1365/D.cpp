
// Problem : D. Solve The Maze
// Contest : Codeforces - Codeforces Round #648 (Div. 2)
// URL : https://codeforces.com/contest/1365/problem/D
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
int n,m,k,c[501],pos[100001],used[51][51],t,t1,i,j,fail=0;
int vaild (int i, int j)
{
	return ((i>=1)and(i<=n)and(j>=1)and(j<=m));
}
char mp[51][51];
void dfs(int i, int j)
{
//	cout<<i<<' '<<j<<endl;
//	cout<<mp[i][j]<<' '<<used[i][j]<<endl;
	used[i][j]=1;
	if (mp[i][j]=='#') return;
	if (mp[i][j]=='G') k--;
	if (mp[i][j]=='B') fail=1;
    if ((vaild(i+1,j))and(!used[i+1][j])) dfs(i+1,j);
    if ((vaild(i-1,j))and(!used[i-1][j])) dfs(i-1,j);
    if ((vaild(i,j+1))and(!used[i][j+1])) dfs(i,j+1);
    if ((vaild(i,j-1))and(!used[i][j-1])) dfs(i,j-1);
}
int main()
{
//  ofile;
    fio;
    cin>>t;
    for (t1=0;t1<t;t1++)
    {
    	k=0; fail=0;
    	cin>>n>>m;
    	for (i=1;i<=n;i++) for (j=1;j<=m;j++) 
    	{
    	cin>>mp[i][j];
    	used[i][j]=0;
    	}
    	for (i=1;i<=n;i++) for (j=1;j<=m;j++) if (mp[i][j]=='B')
    	{
    		if ((vaild(i+1,j))and(mp[i+1][j]=='.')) mp[i+1][j]='#';
    		if ((vaild(i-1,j))and(mp[i-1][j]=='.')) mp[i-1][j]='#';
    		if ((vaild(i,j+1))and(mp[i][j+1]=='.')) mp[i][j+1]='#';
    		if ((vaild(i,j-1))and(mp[i][j-1]=='.')) mp[i][j-1]='#';
    	}
    	else if (mp[i][j]=='G') k++;
    	dfs(n,m);
    	if (k) cout<<"No";else if (fail) cout<<"No"; else cout<<"Yes";
    	cout<<endl;
    }
}