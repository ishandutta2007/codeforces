#include<bits/stdc++.h>
#define L(i, j, k) for (int i = (j); i <= (k); ++i) 
#define R(i, j, k) for (int i = (j); i >= (k); --i)  
#define ll long long
#define vi vector < int > 
#define sz(a) ((int) (a).size())
using namespace std;
int xa, ya, xb, yb, xc, yc;
int ns = 1e5, xd, yd;
void prt (int a, int b, int c, int d) {
	while(a < c) ++a, cout << a << ' ' << b << '\n';
	while(a > c) --a, cout << a << ' ' << b << '\n';
	while(b > d) --b, cout << a << ' ' << b << '\n';
	while(b < d) ++b, cout << a << ' ' << b << '\n';
}
int main () {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> xa >> ya;
	cin >> xb >> yb;
	cin >> xc >> yc;
	L(i, 0, 1000) L(j, 0, 1000) {
		int a = abs (xa - i) + abs (ya - j);
		int b = abs (xb - i) + abs (yb - j);
		int c = abs (xc - i) + abs (yc - j);
		ns = min(ns, a + b + c + 1);
	}
	L(i, 0, 1000) L(j, 0, 1000) {
		int a = abs (xa - i) + abs (ya - j);
		int b = abs (xb - i) + abs (yb - j);
		int c = abs (xc - i) + abs (yc - j);
		if(a + b + c + 1 == ns) {
			cout << ns << '\n';
			cout << i << ' ' << j << '\n';
			prt (i, j, xa, ya);
			prt (i, j, xb, yb);
			prt (i, j, xc, yc);
			return 0;
		}
	}
	return 0;
}