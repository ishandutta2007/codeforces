#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
void Min(int &x, int y) { if(x > y) x = y; }
void Max(int &x, int y) { if(x < y) x = y; }
const int N = 1e6 + 7; 
const int mod = 1e9 + 7;
int n, m, k, tot, a[N], A[N], B[N], op[N], ans;
int qpow(int x, int y) {
	int res = 1;
	for(; y; x = (ll) x * x % mod, y >>= 1) if(y & 1) res = (ll) res * x % mod;
	return res;
}
int Maxb[N];
struct node {
	ll x, y; // [x / y]
	db xl;
	int id;
} f[N];
vector< pii > ve[N];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
	L(i, 1, n) cin >> a[i];
	L(i, 1, m) {
		cin >> op[i] >> A[i] >> B[i];
		if(op[i] == 1) {
			if(B[i] > B[Maxb[A[i]]]) Maxb[A[i]] = i;
		}
		if(op[i] == 2) ve[A[i]].push_back(mkp(B[i], i));
		if(op[i] == 3) ++tot, f[tot].x = B[i], f[tot].y = 1, f[tot].id = i;
	}
	L(i, 1, n) {
		ll t = a[i];
		if(B[Maxb[i]] > a[i]) ve[i].push_back(mkp(B[Maxb[i]] - a[i], Maxb[i]));
		sort(ve[i].begin(), ve[i].end()), reverse(ve[i].begin(), ve[i].end());
		for(pii x : ve[i]) ++tot, f[tot].x = t + x.first, f[tot].y = t, t += x.first, f[tot].id = x.second;
	}
	L(i, 1, tot) f[i].xl = (db) f[i].x / f[i].y;
	sort(f + 1, f + tot + 1, [&](node aa, node bb) { return aa.xl > bb.xl; });
	int Len = min(tot, k);
	cout << Len << endl;
	L(i, 1, Len) if(op[f[i].id] == 1) cout << f[i].id << " ";
	L(i, 1, Len) if(op[f[i].id] == 2) cout << f[i].id << " ";
	L(i, 1, Len) if(op[f[i].id] == 3) cout << f[i].id << " ";
	cout << endl;
	return 0;
}