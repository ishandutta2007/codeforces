// Problem : A. String Transformation 1
// Contest : Codeforces - Codeforces Round #659 (Div. 1)
// URL : https://codeforces.com/contest/1383/problem/0
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
 
//---------END-------//
int n,m,k,c[501],pos[100001],t,t1,i,j;
string a, b;
vector<pii> req;
vector<int> gt[21];
int used[21];
void dfs (int x)
{
	used[x]=1;
	for (int g : gt[x]) if (!used[g]) dfs(g);
}
int main()
{
//  ofile;
    fio;
    cin>>t;
    for (t1=0;t1<t;t1++)
    {
    	k=0;
    	req.clear();
    	cin>>n>>a>>b;
    	for (i=0;i<=20;i++) gt[i].clear(); 
    	for (i=0;i<=20;i++) used[i]=0;
    	for (i=0;i<=20;i++) c[i]=i;
    	int fail=0;
    	for (i=1;i<=n;i++)
    	{
    		if (a[i-1]>b[i-1]) 
    		{
    			fail=1;
    			break;
    		}
    		else if (a[i-1]<b[i-1])
    		{
    			req.push_back({a[i-1]-97,b[i-1]-97});
    		}
    	}
    	if (fail)
    	{
    		cout<<-1<<endl;
    		continue;
    	}
    	sort(req.begin(),req.end(),[](pii a, pii b){if (a.fi-b.fi) return (a.fi>b.fi); return (a.se<b.se);});
    	for (pii g : req)
    	{
    	for (i=0;i<=20;i++) used[i]=0;
    	dfs(g.se);
    	if (!used[g.fi])
    	{
    		k++;
    		for (j=g.fi; (!used[j]); j++) {}
    		gt[j].push_back(g.fi);
    	}
    	}
    	cout<<k<<endl;
    }
}