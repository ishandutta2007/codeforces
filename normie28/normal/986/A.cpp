
// Problem : A. Fair
// Contest : Codeforces - Codeforces Round #485 (Div. 1)
// URL : https://codeforces.com/contest/986/problem/A
// Memory Limit : 512 MB
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
int n,m,k,tar,col[100001],res[100001],dis[100001][101],t,t1,i,j;
vector<int> gt[100001],buc[101],ord;
deque<int> bruh;
void proc (int x)
{
	for (int g : gt[x]) if (dis[g][i]==1e9)
	{
		dis[g][i]=dis[x][i]+1;
		bruh.push_back(g);
	}
}
int main()
{
//  ofile;
    fio;
    cin>>n>>m>>k>>tar;
    for (i=1;i<=n;i++) {cin>>col[i]; buc[col[i]].push_back(i);}
    for (i=1;i<=m;i++)
    {
    	cin>>t>>t1;
    	gt[t].push_back(t1);
    	gt[t1].push_back(t);
    }
    for (i=1;i<=k;i++)
    {
    	for (j=1;j<=n;j++)
    	{
    		dis[j][i]=1e9;
    	}
    	for (int g : buc[i])
    	{
    		bruh.push_back(g);
    		dis[g][i]=0;
    	}
    	while(bruh.size())
    	{
    		proc(bruh.front());
    		bruh.pop_front();
    	}
    }
    for (i=1;i<=n;i++)
    {
    	ord.clear();
    	for (j=1;j<=k;j++) ord.push_back(dis[i][j]);
    	sort(ord.begin(),ord.end());
    	for (j=0;j<tar;j++) res[i]+=ord[j];
    	cout<<res[i]<<' ';
    }
}