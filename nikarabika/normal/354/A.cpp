//sobskdrbhvk
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define sz(x) ((int)(x).size())
#define smax(x, y) ((x) = max((x), (y)))
#define smin(x, y) ((x) = min((x), (y)))
#define all(x) x.begin(),x.end()

const int maxn = 1e5 + 85 - 69;
LL ps[maxn],
   w[maxn],
   sum, n, l, r, ql, qr,
   ans = 1000LL * 1000 * 1000 * 1000000 * 1000;

int getl(int lc, int rc){
	return max(0, lc - rc - 1);
}

int getr(int lc, int rc){
	return max(0, rc - lc - 1);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> l >> r >> ql >> qr;
	for(int i = 0; i < n; i++)
		cin >> w[i], sum += w[i], ps[i + 1] = ps[i] + w[i];
	for(int i = -1; i < n; i++){
		LL cur = ps[i + 1] * l + (sum - ps[i + 1]) * r;
		cur += getl(i + 1, n - i - 1) * ql;
		cur += getr(i + 1, n - i - 1) * qr;
		smin(ans, cur);
	}
	cout << ans << '\n';
	return 0;
}