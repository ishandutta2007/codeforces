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
const int N = 1 << 20;
int x[5], y[5], A[N], B[N], tp;
vector < array < int, 4 > > vc;
ll s = 0;
void link(int ax, int ay, int bx, int by) {
	while(ax != bx || ay != by) {
		if(ax != bx) vc.push_back({ax, ay, bx, ay}), ax = bx;
		else vc.push_back({ax, ay, ax, by}), ay = by;
	}
}
int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	L(i, 1, 3) 
		cin >> x[i] >> y[i];
	L(i, 1, 3) A[i] = x[i], B[i] = y[i];
	sort(A + 1, A + 4);
	sort(B + 1, B + 4);
	int X = A[2], Y = B[2]; 
	L(i, 1, 3) 
		link(x[i], y[i], X, Y);
	cout << sz(vc) << '\n';
	for(auto u : vc) 
		cout << u[0] << ' ' << u[1] << ' ' << u[2] << ' ' << u[3] << '\n';
	return 0;
}