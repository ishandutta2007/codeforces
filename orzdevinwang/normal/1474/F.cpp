#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j), i##E = k; i <= i##E; i++) 
#define R(i, j, k) for(int i = (j), i##E = k; i >= i##E; i--)
#define mkp make_pair
#define pii pair<int, int>
#define ll long long
#define db double
#define sz(a) a.size()
#define x first
#define y second
#define vi vector<int>
using namespace std;
const int N = 1e4, M = 100, mod = 998244353;
int m;
struct Matrix {
	int f[M][M];
	Matrix (int x = 1) {
		L(i, 1, m) L(j, 1, m) f[i][j] = (i == j ? x : 0);
	}
} ;
Matrix operator * (Matrix aa, Matrix bb) {
	Matrix res(0);
	L(i, 1, m) L(j, 1, m) L(k, 1, m) (res.f[i][j] += (ll) aa.f[i][k] * bb.f[k][j] % mod) %= mod;
	return res;
}
Matrix operator ^ (Matrix x, ll y) {
	Matrix res(1);
	for(; y; x = x * x, y >>= 1) if(y & 1) res = res * x;
	return res;
}

int n, nousex, otp, s[N], tot, v[N], sv[N], ns;
ll a[N], p[N], mx, val, arr[N], sl[N], sr[N];
void calc(int l, int r) {
	ll mx = 0;
	p[l] = 0, tot = 0;
	L(i, l + 1, r) {
		sl[i] = (p[i - 1] + (a[i] < 0 ? -1 : 1)), p[i] = p[i - 1] + a[i], sr[i] = p[i];
		if(sl[i] > sr[i]) swap(sl[i], sr[i]);
		mx = max(mx, p[i]);	
	}
	if(val != mx) return;
	sl[l + 1] = 0;
	L(i, l + 1, r) 
		arr[++tot] = sl[i] - 1, arr[++tot] = sl[i], arr[++tot] = sl[i] + 1, 
		arr[++tot] = sr[i] - 1, arr[++tot] = sr[i], arr[++tot] = sr[i] + 1;
	sort(arr + 1, arr + tot + 1), tot = unique(arr + 1, arr + tot + 1) - arr - 1;
	m = r - l;
	memset(v, 0, sizeof(v));
	v[1] = 1, arr[0] = -1;
	L(k, 1, tot) if(arr[k] <= mx) {
		Matrix G(0);
		L(i, l + 1, r) if(sl[i] <= arr[k - 1] + 1 && arr[k] <= sr[i]) {
			L(j, l + 1, i - 1) G.f[j - l][i - l] = 1;
			if(a[i] > 0) G.f[i - l][i - l] = 1;
		}
		G = G ^ (arr[k] - arr[k - 1]);
		L(i, 1, m) L(j, 1, m) (sv[j] += (ll) v[i] * G.f[i][j] % mod) %= mod;
		L(i, 1, m) v[i] = sv[i], sv[i] = 0;
	}
	L(i, 1, m) (ns += v[i]) %= mod;
}
void Main() {
	cin >> n >> nousex;
	L(i, 1, n) {
		cin >> a[i];
		if(a[i]) a[++otp] = a[i];
	}
	n = otp, otp = 0;
	L(i, 1, n) 
		if((a[i] > 0 && a[i - 1] > 0) || (a[i] < 0 && a[i - 1] < 0)) a[otp] += a[i];
		else a[++otp] = a[i];
	n = otp;
	L(i, 1, n) mx += a[i], val = max(val, mx), mx = max(mx, 0ll);
	cout << val + 1 << " ";
	if(val == 0) {
		int sum = 1;
		L(i, 1, n) (sum += abs(a[i]) % mod) %= mod;
		return cout << sum << "\n", void();
	}
	int top = 0;
	mx = 0;
	L(i, 1, n) {
		mx += a[i];
		if(mx < 0) s[++top] = i, mx = 0;
	}
	s[++top] = n + 1;
	L(i, 1, top) calc(s[i - 1], s[i] - 1);
	cout << ns << "\n";
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	Main();
	return 0;
}