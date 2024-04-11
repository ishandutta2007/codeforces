#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ar array
 
const int BLOCK=555;
int n, m, a[200000], cnt[1000001];
ll res=0, ans[200000];
struct QRY {
	int l, r, ind;
	bool operator< (const QRY &o) {return l/BLOCK==o.l/BLOCK?r<o.r:l/BLOCK<o.l/BLOCK;}
} q[200000];
 
inline void add(int ind) {res+=1ll*a[ind]*(2*cnt[a[ind]]+1); ++cnt[a[ind]];}
inline void remove(int ind) {--cnt[a[ind]]; res-=1ll*a[ind]*(2*cnt[a[ind]]+1);}
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
 
	cin >> n >> m;
	for (int i=0; i<n; ++i) cin >> a[i];
	for (int i=0; i<m; ++i) cin >> q[i].l >> q[i].r, --q[i].l, --q[i].r, q[i].ind=i;
	sort(q, q+m);
	int lb=0, rb=0;
	for (int i=0; i<m; ++i) {
		int l=q[i].l, r=q[i].r;
		while(lb<l) remove(lb++);
		while(lb>l) add(--lb);
		while(rb<=r) add(rb++);
		while(rb>r+1) remove(--rb);
		ans[q[i].ind]=res;
	}
	for (int i=0; i<m; ++i) cout << ans[i] << '\n';
	return 0;
}
 
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/