
// Problem : F. Make It One
// Contest : Codeforces - Codeforces Round #519 by Botan Investments
// URL : https://codeforces.com/problemset/problem/1043/F
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
const int N = 3e5 + 7;

int n;
int cnt[N];
int roz[N];
int dist[N];
queue <int> Q;
vector <int> dv[N];

int base(int a){
	int ret = 1;
	while(a > 1){
		if(ret%roz[a] != 0)
			ret *= roz[a];
		a /= roz[a];
	}
	
	return ret;
}

void getEdges(int u, int d){
	vector <int> cur;
	vector <int> val;
	
	while(u > 1){
		cur.push_back(roz[u]);
		u /= roz[u];
	}
	
	for(int v: cur)
		u *= v;
	
	int T = 1 << (int)cur.size();
	val.resize(T);
	
	for(int i = 0; i < T; ++i){
		val[i] = u;
		for(int j = 0; j < (int)cur.size(); ++j)
			if(i & (1 << j))
				val[i] /= cur[j];
	}
	
	for(int i = 0; i < T; ++i){
		int s = 0;
		for(int j = i; true; j = (j - 1) & i){
			if(__builtin_popcount(i ^ j) & 1)
				s -= cnt[val[j]];
			else
				s += cnt[val[j]];
			
			if(j == 0)
				break;
		}
		
		assert(s >= 0);
		if(s && dist[val[i]] == -1){
			dist[val[i]] = d;
			Q.push(val[i]);
		}
	}
}

int main(){
	cin>>n;
	for(int i = 2; i < N; ++i){
		if(roz[i] != 0)
			continue;

		for(int j = i; j < N; j += i)
			roz[j] = i;
	}
	
	for(int i = 1; i < N; ++i)
		for(int j = i; j < N; j += i)
			dv[j].push_back(i);
	
	for(int i = 1; i < N; ++i)
		dist[i] = -1;
	
	for(int i = 1; i <= n; ++i){
		int a;
		cin>>a;
		a = base(a);
		
		if(dist[a] != -1)
			continue;

		dist[a] = 1;
		Q.push(a);
		
		for(int v: dv[a])
			cnt[v]++;
	}
	
	while(!Q.empty()){
		int u = Q.front();
		Q.pop();
		getEdges(u, dist[u] + 1);
	}
	
	cout<<dist[1];
}