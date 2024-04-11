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
const int N = 1e5 + 5;
 
int n, m, k, unit, a[N << 1], cnt[N * 20];
long long sum, ans[N];
 
struct node {
	int l, r, id;
	bool operator < (const node &rhs) const {
		if (l / unit == rhs.l / unit)
			return r < rhs.r;
		return l / unit < rhs.l / unit;
	}
} q[N];
 
inline void add(int i) {
	sum += cnt[a[i] ^ k];
	cnt[a[i]]++;
}
 
inline void remove(int i) {
	cnt[a[i]]--;
	sum -= cnt[a[i] ^ k];
}
 
int main() {
	fio;
	cin>>n>>m>>k;
	for (int i = 1; i <= n; ++i) {
		cin>>a[i];
		a[i] ^= a[i - 1];
	}
	for (int i = 1; i <= m; ++i) {
		cin>>q[i].l>>q[i].r;
		q[i].id = i;
	}
	unit = sqrt(m);
	sort(q + 1, q + m + 1);
	int l = 1, r = 0; cnt[0]++;
	for (int i = 1; i <= m; ++i) {
		while (l > q[i].l) add(--l - 1);
		while (l < q[i].l) remove(l++ - 1);
		while (r > q[i].r) remove(r--);
		while (r < q[i].r) add(++r);
		ans[q[i].id] = sum;
	}
	for (int i = 1; i <= m; ++i)
	cout<<ans[i]<<endl;
}