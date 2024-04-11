#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define db double
#define pii pair<int, int>
#define sz(a) ((int) (a).size())
#define x first
#define y second
using namespace std;
const int N = 1e5 + 7;
ll a, b, c, x, y, w, f[5], mx = 1, nx = 1, sx;
int main() {
	cin >> f[1] >> f[2] >> f[3];
	cout << "First" << endl;
	L(i, 1, 3) if(f[i] > f[mx]) mx = i;
	nx = (mx == 1) + 1;
	L(i, 1, 3) if(i != mx && f[i] > f[nx]) nx = i;
	sx = 6 - mx - nx;
	L(test, 1, 2) {
		x = f[nx] - f[sx], y = f[mx] - f[nx], cout << x + 2 * y << endl;
		fflush(stdout), cin >> w;
		if(w == 0) return 0;
		f[w] += x + 2 * y;
		if(w != mx) break;
	}
	mx = nx = sx = 1;
	L(i, 1, 3) if(f[i] > f[mx]) mx = i;
	nx = (mx == 1) + 1;
	L(i, 1, 3) if(i != mx && f[i] > f[nx]) nx = i;
	sx = 6 - mx - nx;
	cout << f[nx] - f[sx] << endl;
	fflush(stdout);
	cin >> w;
	if(w) assert(0);
	return 0;
}