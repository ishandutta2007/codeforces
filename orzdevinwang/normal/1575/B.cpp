//#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 8e5 + 7;
const double pi = acos (-1);
int n, k;
double x[N], y[N], ds[N];

int tot;
pair < double, int > ac[N];
void make (double l, double r) {
//	if(l > r) cout << l << ' ' << r << '\n';
	ac[++tot] = {l, 1}, ac[++tot] = {r, -1};
}
bool check (double r) {
	tot = 0;
	L(i, 1, n) if(x[i] != 0 || y[i] != 0) {
		double orz = atan2 (x[i], y[i]), Len = ds[i] / 2;
		if(Len > r) continue ;
		double dt = acos(Len / r), cl = orz - dt, cr = orz + dt;
		if(cl < -pi && cr > pi) assert (0);
		if(-pi <= cl && cr <= pi) make (cl, cr); 
		if(cl < -pi) make (-pi, cr), make (cl + 2 * pi, pi);
		if(cr > pi) make (cl, pi), make (-pi, cr - 2 * pi);
	}
	sort (ac + 1, ac + tot + 1);
	int now = 0;
	L(i, 1, tot) {
		now += ac[i].second; 
		if(now >= k) return true;
	}
	return false;
}
int main () {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cout.precision(12), cout << fixed;
	cin >> n >> k;
	L(i, 1, n) {
		int X, Y;
		cin >> X >> Y;
		if(X == 0 && Y == 0) 
			k -= 1;
		x[i] = X, y[i] = Y;
		ds[i] = sqrt (x[i] * x[i] + y[i] * y[i]);
	}
	if(k <= 0) 
		return cout << 0 << '\n', 0;
//	check(2);
	double l = 0, r = 3e5;
	while (r - l > 1e-8) {
		double mid = (l + r) / 2;
		if(check(mid)) r = mid;
		else l = mid;
	}
	cout << r << '\n';
	return 0;
}