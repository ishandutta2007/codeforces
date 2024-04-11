
// Problem : E. Neko and Flashback
// Contest : Codeforces - Codeforces Round #554 (Div. 2)
// URL : https://codeforces.com/problemset/problem/1152/E
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
#define MAX 100010
 
map<int, int> mp;
multiset<int> adj[MAX];
int ori[MAX];
int b[MAX], c[MAX];
int st = -1, en = -1;
 
list<int> cyc;
 
bool check(int cnt){
	for (int i = 1; i <= cnt; i++)
	{
		if (adj[i].size() & 1){
			if(st == -1) st = i;
			else if (en == -1) en = i;
			else return false;
		}
	}
	return true;
}
 
void EulerPath(list<int>::iterator i, int u){
	while(!adj[u].empty()){
		int v = *adj[u].begin();
		adj[v].erase(adj[v].find(u));
		adj[u].erase(adj[u].find(v));
		EulerPath(cyc.insert(i, u), v);
	}
}
 
int main()
{
	fio;
	int N;
	cin >> N;
	int cnt = 0;
 
	for (int i = 1; i < N; i++) cin >> b[i];
	for (int i = 1; i < N; i++) cin >> c[i];
 
	for (int i = 1; i < N; i++)
	{
		if (b[i] > c[i])
		{
			cout << "-1\n";
			return 0;
		}
 
		if (mp[b[i]] == 0)
		{
			cnt++;
			mp[b[i]] = cnt;
			ori[cnt] = b[i];
		}
		if (mp[c[i]] == 0)
		{
			cnt++;
			mp[c[i]] = cnt;
			ori[cnt] = c[i];
		}
 
		if (cnt >= MAX)
		{
			cout << "-1\n";
			return 0;
		}
 
		adj[mp[b[i]]].insert(mp[c[i]]);
		adj[mp[c[i]]].insert(mp[b[i]]);
	}
 
 
	if (!check(cnt))
	{
		cout << "-1\n";
		return 0;
	}
	if (st == -1) st = 1, en = 1;
 
	EulerPath(cyc.begin(), st);
	cyc.insert(cyc.begin(), en);
	if (cyc.size() < N)
	{
		cout << "-1\n";
		return 0;
	}
 
	for(auto k : cyc) cout << ori[k] << " ";
	cout << endl;
}