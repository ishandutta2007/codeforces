
// Problem : C. Mastermind
// Contest : Codeforces - Codeforces Round #658 (Div. 1)
// URL : https://codeforces.com/contest/1381/problem/C
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
#define free freed
typedef long long ll;
//---------END-------//
struct cmp
{
	int operator()(pair<int,int> a, pair<int,int> b) const
	{
		if (a.se==b.se) return (a.fi<b.fi);
		return (a.se>b.se);
	}
};
int n,m,k,c[501],col[100002],res[100002],t,t1,i,j,x,y,diff,bail,fail;
vector<int> buc[100002];
set<pair<int,int>,cmp> sett;
void remove (int prev, int next)
{
    		sett.erase({prev,buc[prev].size()});
    		sett.insert({prev,buc[prev].size()-1});
    		res[buc[prev][buc[prev].size()-1]]=next;
    		buc[prev].pop_back();
}
int main()
{
//  ofile;
    fio;
    cin>>t;
    for (t1=0;t1<t;t1++)
    {
    	fail=0;
    	cin>>n>>x>>y;
    	for (i=1;i<=n+1;i++)
    	{
    		buc[i].clear();
    	}
    	sett.clear();
    	for (i=1;i<=n;i++)
    	{
    		cin>>col[i];
    		buc[col[i]].push_back(i);
    	}
    	for (i=1;i<=n+1;i++)
    	{
    		sett.insert({i,buc[i].size()});
    	}
    	bail=(--sett.end())->fi;
    	for (i=0;i<x;i++)
    	{
    		remove(sett.begin()->fi,sett.begin()->fi);
    	}
    	vector<int> bruh;
    	for (i=1;i<=n+1;i++) for (auto g : buc[i]) bruh.push_back(g);
    	diff=n-y;
    	//for (auto g : bruh) cout<<g<<' '; cout<<endl;
    	for (i=0;i<n-x;i++)
    	{
    		res[bruh[(i+(n-x)/2)%(n-x)]]=col[bruh[i]];
    		if (res[bruh[(i+(n-x)/2)%(n-x)]]==col[bruh[(i+(n-x)/2)%(n-x)]])
    		{
    			if (diff)
    			{
    				res[bruh[(i+(n-x)/2)%(n-x)]]=bail;
    				diff--;
    			}
    			else fail=1;
    		}
    	}
    	for (i=1;i<=n;i++) if ((res[i]!=bail)and(res[i]!=col[i])and(diff))
    	{
    		res[i]=bail;
    		diff--;
    	}
    	if (fail) cout<<"NO\n";
    	else 
    	{
    		cout<<"YES\n";
    		for (i=1;i<=n;i++) cout<<res[i]<<' ';
    		cout<<endl;
    	}
    }
}