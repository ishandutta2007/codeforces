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
#define FILE_IN "ming.inp"
#define FILE_OUT "ming.out"
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
const int mxN=5e5;
int n, bs, q, a[mxN], ans[mxN], cnt[mxN+1];
vector<int> v;
bool inv[mxN+1];
 
struct query {
	int l, r, i;
	inline bool operator<(const query &o) const {
		if(l/bs!=o.l/bs)
			return l<o.l;
		return l/bs%2?r<o.r:r>o.r;
	}
} qs[mxN];
 
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	bs=sqrt(n);
	for(int i=0; i<n; ++i)
		cin >> a[i];
	cin >> q;
	for(int i=0; i<q; ++i)
		cin >> qs[i].l >> qs[i].r, --qs[i].l, --qs[i].r, qs[i].i=i;
	sort(qs, qs+q);
	int l=0, r=-1;
	for(int i=0; i<q; ++i) {
//		out(qs[i].i);
		while(l>qs[i].l) {
			--l;
			++cnt[a[l]];
			if(cnt[a[l]]==1&&!inv[a[l]]) {
				v.push_back(a[l]);
				inv[a[l]]=1;
			}
		}
		while(r<qs[i].r) {
			++r;
			++cnt[a[r]];
			if(cnt[a[r]]==1&&!inv[a[r]]) {
				v.push_back(a[r]);
				inv[a[r]]=1;
			}
		}
		while(l<qs[i].l) {
			--cnt[a[l]];
			if(cnt[a[l]]==1&&!inv[a[l]]) {
				v.push_back(a[l]);
				inv[a[l]]=1;
			}
			++l;
		}
		while(r>qs[i].r) {
			--cnt[a[r]];
			if(cnt[a[r]]==1&&!inv[a[r]]) {
				v.push_back(a[r]);
				inv[a[r]]=1;
			}
			--r;
		}
		while(!v.empty()&&cnt[v.back()]!=1) {
			inv[v.back()]=0;
			v.pop_back();
		}
		ans[qs[i].i]=v.empty()?0:v.back();
	}
	for(int i=0; i<q; ++i)
		cout << ans[i] << "\n";
}