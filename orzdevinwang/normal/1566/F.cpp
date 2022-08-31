#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 4e5 + 7;
int n, m, tp; 
struct segm {
	int op;
	ll l, r; 
} seg[N];
map < ll, int > S;
ll dp[N], pos[N];
ll rec[N], recc[N]; 
void Main () {
	S.clear ();
	cin >> n >> m, tp = n;
	L(i, 1, n) cin >> seg[i].l, seg[i].op = 1, seg[i].r = seg[i].l, S[seg[i].l] = 1;
	L(i, 1, m) {
		int x, y;
		cin >> x >> y;
		if(x == y && S[x]) continue;
		++tp, seg[tp].l = x, seg[tp].r = y, seg[tp].op = 0; 
	} 
	sort(seg + 1, seg + tp + 1, [&] (segm a, segm b) {
		return a.l == b.l ? a.r > b.r : a.l < b.l; 
	});
	L(i, 1, tp) dp[i] = 1e10;
	ll mx = 2e9;
	R(i, tp, 1) {
		if(seg[i].r >= mx) seg[i].op = -1;
		else mx = seg[i].r;
	}
	int cnt = 0;
	L(i, 1, tp) cnt += seg[i].op != -1;
	int now = 0;
	L(i, 1, tp) if(seg[i].op != -1) ++now, seg[now] = seg[i]; 
	tp = now;
	n = 0;
	L(i, 1, tp) if(seg[i].op == 1) pos[++n] = i;
	pos[n + 1] = tp + 1;
	L(i, 0, tp + 1) rec[i] = recc[i] = 1e10;
	L(i, 1, n) {
		ll mna = 1e10, mnb = 1e10;
		L(j, pos[i - 1] + 1, pos[i] - 1) {
			ll a = seg[pos[i]].l - seg[j].r;
			mna = min(mna, a + dp[j - 1]);
			mnb = min(mnb, a * 2 + dp[j - 1]);
		}
		L(k, pos[i] + 1, pos[i + 1] - 1) dp[k] = min(dp[k], mna + (seg[k].l - seg[pos[i]].r) * 2);
		L(k, pos[i] + 1, pos[i + 1] - 1) dp[k] = min(dp[k], mnb + (seg[k].l - seg[pos[i]].r));
		dp[pos[i]] = dp[pos[i] - 1];
		L(j, pos[i], pos[i + 1] - 1) dp[j] = min(dp[j], dp[pos[i] - 1] + (seg[j].l - seg[pos[i]].r));
		L(j, pos[i - 1] + 1, pos[i]) dp[pos[i]] = min(dp[pos[i]], seg[pos[i]].r - seg[j].r + dp[j - 1]);
	}
	cout << dp[tp] << '\n'; 
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	while (T--) Main ();
	return 0;
}