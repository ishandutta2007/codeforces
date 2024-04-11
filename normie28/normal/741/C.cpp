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
#define MOD (ll(100003))
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
const int N = 2e5+77;
bool o[N];
int kolor[N];
vector<int> G[N];
 
void dfs(int v, int kol) {
	o[v] = 1;
	kolor[v] = kol;
 
	for(int w: G[v]) {
		if(o[w]) continue;
		dfs(w, kol^1);
	}
}
 
int main () {
    fio;
 
	int n;
	cin >> n;
 
	vector< pair<int,int> > pairs;
 
	int a,b;
	for(int i=1;i<=n;i++) {
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
		pairs.push_back({a,b});
	}
 
	for(int i=1;i<=n;i++) {
		int pie = 2 * i;
		int dru = 2 * i + 1;
		if(dru > 2*n) dru = 1;
		G[pie].push_back(dru);
		G[dru].push_back(pie);
	}
 
	for(int i=1;i<=2*n;i++) if(!o[i])
		dfs(i, 0);
 
	for(auto p: pairs) {
		cout << kolor[p.first]+1 << " " << kolor[p.second]+1 << endl;
	}
 
}