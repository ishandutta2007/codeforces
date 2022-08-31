#include<bits/stdc++.h>
#define ll long long
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define vi vector < int > 
#define sz(a) ((int) a.size()) 
#define uint unsigned int 
using namespace std;
const int N = 1 << 20;
const double pi = acos (-1);
int n, x[N], y[N], tp;
ll ns;
struct vec {
	ll x, y;
	vec (ll X = 0, ll Y = 0) {
		x = X, y = Y;
	}
} p[N];
vec operator + (const vec &a, const vec &b) {
	return vec (a.x + b.x, a.y + b.y);
}
vec operator - (const vec &a, const vec &b) {
	return vec (a.x - b.x, a.y - b.y);
}
ll operator * (const vec &a, const vec &b) {
	return a.x * b.y - a.y * b.x;
}
vec ang[N];
int main() { 
	ios :: sync_with_stdio (false);
	cin.tie (0); cout.tie (0);
	cin >> n;
	L(i, 1, n) 
		cin >> p[i].x >> p[i].y;
	L(o, 1, n) {
		ll ret = (ll) (n - 1) * (n - 2) * (n - 3) * (n - 4) / 24;
		tp = 0;
		L(j, 1, n) if(o != j) ang[++tp] = p[j] - p[o];
		sort(ang + 1, ang + tp + 1, [&] (vec a, vec b) {
			int ac = a.y < 0 || (a.y == 0 && a.x > 0);
			int bc = b.y < 0 || (b.y == 0 && b.x > 0); 
			return ac == bc ? a * b < 0 : ac < bc;
		});
		L(i, 1, tp) ang[i + tp] = ang[i];
		int p = 0;
		L(j, 1, tp) {
			while (p < j + tp - 1 && ang[p + 1] * ang[j] >= 0) ++ p;
			int len = p - j;
			ret -= (ll) len * (len - 1) * (len - 2) / 6; 
		}
		ns += ret;
	}
	cout << ns << '\n';
	return 0;
}