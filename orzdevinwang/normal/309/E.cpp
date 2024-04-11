#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
#define uint unsigned int 
using namespace std;
const int N = 2333;
int n, tl[N], tr[N], cnt[N], ans[N], pos[N];
struct xt {
	int l, r, id, ns;
} f[N];
bool vis[N];
bool check(int x) {
	L(i, 1, n) pos[i] = n, vis[i] = true;
	L(i, 1, n) {
		L(j, 1, n) cnt[j] = 0;
		L(j, 1, n) if(vis[j]) cnt[pos[j]] += 1;
		L(j, 1, n) cnt[j] += cnt[j - 1];
		int p = -1;
		L(j, i - 1, n) if(cnt[j] > j - i + 1) return false;
		L(j, i, n) if(cnt[j] == j - i + 1) {
			p = j;
			break ; 
		} 
		L(j, 1, n) if(vis[j] && pos[j] <= p) {
			p = j, f[j].ns = i;
			break ;
		}
//		cout << "p = " << p << endl;
		assert(p > 0);
		pos[p] = i, vis[p] = false;
//		cout << "p = " << p << '\n';
		L(j, 1, p - 1) if(f[j].r >= f[p].l) pos[j] = min(pos[j], i + x);
		L(j, p + 1, n) if(f[j].l <= f[p].r) pos[j] = min(pos[j], i + x);
//		L(j, 1, n) cout << pos[j] << ' ';
//		cout << '\n';
	}
	return true;
}
int main () { 
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	L(i, 1, n) cin >> f[i].l >> f[i].r, f[i].id = i;
	sort(f + 1, f + n + 1, [&] (xt x, xt y) {
		return x.r < y.r;
	});
	int l = 0, r = n - 1, ns = -1;
	while(l <= r) {
		int mid = (l + r) >> 1;
		if(check(mid)) ns = mid, r = mid - 1;
		else l = mid + 1;
	}
	check(ns);
	L(i, 1, n) ans[f[i].ns] = f[i].id;
	L(i, 1, n) cout << ans[i] << ' ';
	return 0;
}