
// Problem : E. Santa Claus and Tangerines
// Contest : Codeforces - Technocup 2017 - Elimination Round 3
// URL : https://codeforces.com/problemset/problem/748/E
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
#define pll pair<ll,ll>
#define For(i,__,___) for(int i=__;i<=___;i++)
#define Rep(i,__,___) for(int i=__;i>=___;i--)
#define ordered_set tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update>
#define endl "\n"
#define bi BigInt
typedef long long ll;
#define f(i, x, n) for(int i = x; i < (int)(n); ++i)
//---------END-------//
ll an;
int x[100001];
vector<int> tr[100001];
 
vector<pair<int, int> > go(int v = 1, int p = 0){
	vector<pair<int, int> > fr(20, pair<int, int>(0, 0));
	an += x[v];
	f(i, 0, tr[v].size()){
		int u = tr[v][i];
		if (u == p)continue;
		vector<pair<int, int> > t = go(u, v);
		f(j, 0, 20){
			if (x[v] >> j & 1)an += (ll)fr[j].first * t[j].first + (ll)fr[j].second * t[j].second + t[j].first << j;
			else an += (ll)fr[j].first * t[j].second + (ll)fr[j].second * t[j].first + t[j].second << j;
			fr[j].first += t[j].first;
			fr[j].second += t[j].second;
		}
	}
	f(i, 0, 20){
		if (x[v] >> i & 1)swap(fr[i].first, fr[i].second), ++fr[i].second;
		else ++fr[i].first;
	}
	return fr;
}
 
int main(){
    fio;
	int n;
	cin>>n;
	f(i, 1, n + 1)cin>>x[i];
	f(i, 1, n){
		int a, b;
		cin>>a>>b;
		tr[a].push_back(b);
		tr[b].push_back(a);
	}
	go();
	cout<<an<<endl;
}