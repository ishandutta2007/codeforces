
// Problem : C. Permutation recovery
// Contest : Codeforces - Codeforces Round #559 (Div. 1)
// URL : https://codeforces.com/contest/1158/problem/C
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
#define next mxt
typedef long long ll;
//---------END-------//
int n,m,k,topo[500001],used[500001],t,t1,i,j;
int next[500001]; vector<int> start[500001],stop[500001],gt[500001];
ordered_set bruh;
vector<int> ans;
void dfs(int v) {
    used[v] = true;
    for (int u : gt[v]) {
        if (!used[u])
            dfs(u);
    }
    ans.push_back(v);
}

void topological_sort() {
	for (int i=1;i<=n;i++) {used[i]=0; topo[i]=0;}
    ans.clear();
    for (int i = 1; i <= n; ++i) {
        if (!used[i])
            dfs(i);
    }
    for (i=1;i<=n;i++) topo[ans[i-1]]=i;
}

int main()
{
//  ofile;
    fio;
    cin>>t;
    for (t1=0;t1<t;t1++)
    {
    	cin>>n;
    	for (i=1;i<=n;i++)
    	{
    		gt[i].clear();
    		start[i].clear();
    		stop[i].clear();
    	}
    	bruh.clear();
    	for (i=1;i<=n;i++)
    	{
    		cin>>next[i];
    		if (next[i]>=0)
    		{
    		gt[next[i]].push_back(i);
    		stop[i].push_back(i);
    		start[next[i]-1].push_back(i);
    		}
    	}
    	for (i=n;i>=1;i--)
    	{
    		for (ll g : start[i]) {bruh.insert(g); }
    		for (ll g : stop[i]) {bruh.erase(bruh.lower_bound(g)); }
    		if (bruh.size())
    		{
    			int aa=*(bruh.find_by_order(bruh.size()-1));
    		if (bruh.size()) gt[aa].push_back(i);
    		}
    	}
    	topological_sort();
    	int fail=0;
    	for (i=1;i<=n;i++)
    	{
    		for (int j : gt[i]) if (topo[j]>topo[i]) fail=1;
    	}
    	if (fail) cout<<-1;
    	else 
    	for (i=1;i<=n;i++) cout<<topo[i]<<' ';
    	cout<<endl;
    }
    
}