
// Problem : DeadLee
// Contest : Codeforces
// URL : https://m1.codeforces.com/contest/1369/problem/E
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
#define For(i,__,___) for(int i=__;i<=___;i++)
#define Rep(i,__,___) for(int i=__;i>=___;i--)
#define ordered_set tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update>
#define endl "\n"
#define bi BigInt
typedef long long ll;
//---------END-------//
const int N = 200100;
 
int w[N];
int x[N], y[N];
 
int used[N];
int used_c[N];
int qtd[N], qtd2[N];
 
priority_queue <int> pq;
vector <int> E[N];
 
 
int main() {
	fio;
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> w[i];
	}
	for (int i = 1; i <= m; ++i) {
		cin >> x[i] >> y[i];
		qtd[x[i]]++;
		E[x[i]].push_back(i);
		qtd[y[i]]++;
		E[y[i]].push_back(i);
	}
	for (int i = 1; i <= n; ++i) {
		qtd2[i] = qtd[i];
		if(w[i] >= qtd[i]) {
			pq.push(i);
			used_c[i]=1;
		} 
	}
	vector <int> ans;
	while(!pq.empty()) {
		int at = pq.top();
		pq.pop();
		for (int p: E[at]) {
			if(used[p] == 0) {
				qtd[x[p]]--;
				qtd[y[p]]--;
				if(used_c[x[p]] == 0 && w[x[p]] >= qtd[x[p]]) {
					pq.push(x[p]);
					used_c[x[p]]=1;
				}
				if(used_c[y[p]] == 0 && w[y[p]] >= qtd[y[p]]) {
					pq.push(y[p]);
					used_c[y[p]]=1;
				}
				used[p] = 1;
				ans.push_back(p);
			}
		}
	}
	int ok = 1;
	ok = ans.size() == m;
	if(ok) {
		cout<<"ALIVE\n";
		reverse(ans.begin(), ans.end());
		for (int p: ans) {
			cout<<p<<' ';
		}
		cout<<endl;
	} else {
		cout<<"DEAD\n";
	}
}