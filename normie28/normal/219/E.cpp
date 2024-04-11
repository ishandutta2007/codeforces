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
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define FILE_IN "text.out"
#define FILE_OUT "result.out"
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
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define For(i,__,___) for(int i=__;i<=___;i++)
#define Rep(i,__,___) for(int i=__;i>=___;i--)
#define ordered_set tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update>
#define bi BigInt
#define vec plv.se
#define pi 3.1415926535897
typedef long long ll;
//------------xc xch normie tm muoi tm phan tram no----------//
ll n,m,k,b,c[1001],t,t1,i,j,minn,maxx,cur=0,lu,lv,sum=0,mul=1;
int pos[1000005];
int who[200005];
set<pair<int, int>> parking, diff;
 
int add(int id) {
	if (parking.empty()) {
		pos[id] = 1;
		parking.insert({1, id});
		return pos[id];
	}
	if (diff.empty()) {
		assert(parking.size() == 1);
		int position = parking.begin()->first;
		if (position - 1 >= n - position) {
			pos[id] = 1;
			diff.insert({(position - 1) / 2 * -4, pos[id]});
		} else {
			pos[id] = n;
			diff.insert({(n - position) / 2 * -4, position});
		}
		parking.insert({pos[id], id});
		return pos[id];
	}
	int first_pos = parking.begin()->first;
	int last_pos = parking.rbegin()->first;
	int dst_pref = 4 * (first_pos - 1);
	int dst_suf = 4 * (n - last_pos);
	auto best_seg = diff.begin();
	int dst_mid = -best_seg->first;
	if (dst_pref >= max(dst_mid, dst_suf)) {
		pos[id] = 1;
		diff.insert({(first_pos - 1) / 2 * -4, pos[id]});
	} else if (dst_mid >= dst_suf) {
		int start = best_seg->second;
		pos[id] = start + dst_mid / 4;
		diff.erase(best_seg);
		auto it = parking.find({start, who[start]});
		++it;
		assert(it != parking.end());
		int nxt = it->first;
		diff.insert({(pos[id] - start) / 2 * -4, start});
		diff.insert({(nxt - pos[id]) / 2 * -4, pos[id]});
	} else {
		pos[id] = n;
		diff.insert({(n - last_pos) / 2 * -4, last_pos});
	}
	parking.insert({pos[id], id});
	return pos[id];
}
 
void remove(int id) {
	auto it = parking.find({pos[id], id});
	int prv = -1;
	int nxt = -1;
	if (it != parking.begin()) prv = prev(it)->first;
	if (next(it) != parking.end()) nxt = next(it)->first;
	if (prv != -1) {
		diff.erase({(pos[id] - prv) / 2 * -4, prv});
	}
	if (nxt != -1) {
		diff.erase({(nxt - pos[id]) / 2 * -4, pos[id]});
	}
	if (nxt != -1 && prv != -1) {
		diff.insert({(nxt - prv) / 2 * -4, prv});
	}
	parking.erase(it);
}
 
int main() {
	fio;
	cin >> n >> m;
	for (int tc = 1; tc <= m; ++tc) {
		int t, id;
		cin >> t >> id;
		if (t == 1) {
			int res = add(id);
			who[res] = id;
			cout << res << endl;
		}	else remove(id);
	}
}