#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define upd(a, b) (a = max(a, b))

using namespace std;
const int N = 505;
typedef long long ll;
int n; ll f[N];
struct node {
	int a, b, k;
	bool operator <(const node& o)const { return b > o.b; }
} c[N];
int main() {
	cin >> n;
	rep(i, 1, n) scanf("%d%d%d", &c[i].a, &c[i].b, &c[i].k);
	sort(c + 1, c + n + 1);
	rep(i, 1, n) per(j, i, 0) {
		f[j] += max(c[i].a - 1ll * c[i].k * c[i].b, 0ll);
		if(j) upd(f[j], f[j - 1] + c[i].a - 1ll * min(c[i].k, j - 1) * c[i].b);
	}
	ll ans = 0;
	rep(i, 1, n) upd(ans, f[i]);
	cout << ans;
	return 0;
}