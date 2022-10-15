
// Problem : C. Edo and Magnets
// Contest : Codeforces - Codeforces Round #330 (Div. 1)
// URL : https://codeforces.com/problemset/problem/594/C
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
typedef long double ld;
//---------END-------//
int n;
vector<pair<int, int> > vv[4];
int k;
 
void add(int c, int x, int n) {
	vv[c].push_back(make_pair(x, n));
	int now = vv[c].size() - 1;
	while (now > 0 && vv[c][now - 1] < vv[c][now])
		swap(vv[c][now], vv[c][now - 1]), --now;
	while ((int)vv[c].size() > k + 1)
		vv[c].pop_back();
}
 
int main() {
	fio;
	cin>>n>>k;
	for (int i = 0; i < n; ++i) {
		int x1, x2, y1, y2;
		cin>>x1>>y1>>x2>>y2;
		int x, y;
		x = x1 + x2;
		y = y2 + y1;
		add(0, x, i);
		add(1, y, i);
		add(2, -x, i);
		add(3, -y, i);
	}
	for (int i = 0; i < (int)vv[2].size(); ++i)
		vv[2][i].first = -vv[2][i].first;
	for (int i = 0; i < (int)vv[3].size(); ++i)
		vv[3][i].first = -vv[3][i].first;
 
	ll ans = 2e18;
 
	for (int i = 0; i < (int)vv[0].size(); ++i)
		for (int j = 0; j < (int)vv[1].size(); ++j)
			for (int t = 0; t < (int)vv[2].size(); ++t)
				for (int l = 0; l < (int)vv[3].size(); ++l) {
					ll dx = max(2, vv[0][i].first - vv[2][t].first);
					ll dy = max(2, vv[1][j].first - vv[3][l].first);
					if (dx & 1)
						++dx;
					if (dy & 1)
						++dy;
					dx >>= 1;
					dy >>= 1;
					if (dx * dy >= ans)
						continue;
					vector<int> gg;
					for (int it = 0; it < i; ++it)
						gg.push_back(vv[0][it].second);
					for (int it = 0; it < j; ++it)
						gg.push_back(vv[1][it].second);
					for (int it = 0; it < t; ++it)
						gg.push_back(vv[2][it].second);
					for (int it = 0; it < l; ++it)
						gg.push_back(vv[3][it].second);
					sort(gg.begin(), gg.end());
					gg.resize(unique(gg.begin(), gg.end()) - gg.begin());
					if ((int)gg.size() <= k)
						ans = dx * dy;
				}
 
	cout << ans << "\n";
}