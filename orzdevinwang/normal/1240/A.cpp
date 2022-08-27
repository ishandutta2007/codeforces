#include<bits/stdc++.h>
#define ll long long
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define vi vector < int > 
#define sz(a) ((int) a.size()) 
using namespace std;
const int N = 2e5 + 7; 
int n, w[N], cw[N], p[N];
ll k;
bool check(int t) {
	ll ret = 0;
	L(i, 1, t) cw[i] = w[i];
	sort(cw + 1, cw + t + 1), reverse(cw + 1, cw + t + 1);
	L(i, 1, t) ret += p[i] * cw[i];
	return ret >= k;
}
void Main () {
	cin >> n;
	L(i, 1, n) w[i] = 0;
	L(i, 1, n) cin >> p[i], p[i] /= 100;
	sort (p + 1, p + n + 1), reverse(p + 1, p + n + 1);
	int a, x, b, y;
	cin >> x >> a >> y >> b ;
	for (int i = a; i <= n; i += a) 
		w[i] += x;
	for(int i = b; i <= n; i += b) 
		w[i] += y;
	cin >> k;
	int l = 1, r = n, ns =- 1;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if(check(mid)) ns = mid, r = mid - 1;
		else l = mid + 1;
	}
	cout << ns << '\n';
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	while(T--) Main ();
	return 0;
}