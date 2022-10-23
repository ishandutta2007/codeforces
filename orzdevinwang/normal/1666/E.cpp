#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define sz(a) ((int) (a).size())
#define vi vector < int > 
#define me(a, x) memset(a, x, sizeof(a))
#define ull unsigned long long
#define ld __float128
using namespace std;
const int N = 2e5 + 7;
// at least W. 
// at least. 
int L, n, a[N], ns;
int dl[N], dr[N];
bool solve(int l, int r) {
	dl[0] = 0, dr[0] = 0;
	L(i, 1, n) {
		dl[i] = dl[i - 1] + l;
		dr[i] = dr[i - 1] + r;
		dl[i] = max(dl[i], a[i]);
		dr[i] = min(dr[i], a[i + 1]);
		if(dl[i] > dr[i]) return false;
	}
	return dr[n] == L;
}
bool chl(int l) {
	dl[0] = 0;
	L(i, 1, n) {
		dl[i] = dl[i - 1] + l, dl[i] = max(dl[i], a[i]);
		if(dl[i] > a[i + 1]) return false;
	} 
	return true;
} 
bool chr(int r) {
	if(r < 0) return 0;
	dr[0] = 0;
	L(i, 1, n) {
		dr[i] = dr[i - 1] + r, dr[i] = min(dr[i], a[i + 1]);
		if(dr[i] < a[i]) return false;
	}
	return dr[n] == L;
} 
int f[N];

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> L >> n;
	L(i, 1, n) cin >> a[i];
	a[n + 1] = L;
	
	int l = 0, r = 1e9 + 7;
	R(i, 30, 0) if(chl(l + (1 << i))) l += 1 << i;
	R(i, 30, 0) if(chr(r - (1 << i))) r -= 1 << i;
	r = max(r, l);
	if(!solve(l, r)) assert(false);
	f[n] = L;
	R(i, n, 1) {
		f[i - 1] = min(f[i] - l, dr[i - 1]);
		assert(f[i - 1] >= dl[i - 1]);
	}
	L(i, 1, n) cout << f[i - 1] << ' ' << f[i] << '\n';
	return 0;
}