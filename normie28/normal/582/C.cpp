// Problem : F. Economic Difficulties
// Contest : Codeforces - Codeforces Round #603 (Div. 2)
// URL : https://codeforces.com/contest/1263/problem/F
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
 
int n, m, a[200000], gg[200000];
set<int> divs;
 
int gcd(int a, int b) {
	return b ? gcd(b, a%b) : a;
}
 
void find_divs(int k) {
	divs.clear();
	divs.insert(1);
	for (int d=2; d*d<=k; ++d) {
		if (k%d) continue;
		divs.insert(d);
		divs.insert(k/d);
	}
	if (k == 1)
		divs.clear();
}
 
int main() {
    cin>>n;
	for (int i=0; i<n; ++i)
		cin>>a[i];
	find_divs(n);
	for (int i=0; i<n; ++i)
		gg[i] = gcd(i, n);
	ll res = 0;
	for (int g : divs) {
		vector<int> section(g), c(n/g);
		for (int i=0; i<n; ++i)
			section[i%g] = max(section[i%g], a[i]);
		int start = 0;
		for (; start<n; ++start)
			if (section[start%g] != a[start])
				break;
		if (start == n) {
			for (int i=1; i<n/g; ++i)
				c[i] += n;
		} else {
			int cnt = 0;
			for (int i=start+1; i<n+start+1; ++i) {
				if (a[i%n] == section[i%g])
					++cnt;
				else {
					for (int i=1; i<=cnt/g; ++i) {
						c[i] += cnt - i*g + 1;
					}
					cnt = 0;
				}
			}
		}
		for (int i=0; i<n; ++i)
			if (gg[i] == g)
				res += c[i/g];
	}
	cout<<res;
}