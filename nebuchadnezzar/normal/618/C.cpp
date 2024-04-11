#include "bits/stdc++.h"
#define puba push_back
#define mapa make_pair
#define ff first
#define ss second
#define bend(_x) (_x).begin(), (_x).end()
#define szof(_x) ((int) (_x).size())
#define TASK_NAME ""

using namespace std;
typedef long long ll;
typedef pair <int, int> pii;

struct point {
  	ll x, y;

  	point() {
  	 	x = y = 0;
  	}

  	point(ll _x, ll _y) {
  	 	x = _x;
  	 	y = _y;
  	}

  	ll operator*(point p) {
  	 	return x * p.y - y * p.x;
  	}

  	ll operator/(point p) {
  	 	return x * p.x + y * p.y;
  	}

  	point operator-(point p) {
  	 	return point(x - p.x, y - p.y);
  	}
};

int n;
vector<point> inp;

int sign(ll num) {
 	if (num < 0) {
 	 	return -1;
 	}
 	if (num > 0) {
 	 	return 1;
 	}
 	return 0;
}

pair<int, int> getany(int a, int b, int c) {
	int ret = 0;
	int p = -1;
 	for (int i = 0; i < n; ++i) {
 	 	if (i != a && i != b && i != c) {
 	 	 	int tmp1 = sign((inp[a] - inp[i]) * (inp[b] - inp[i]));
 	 	 	int tmp2 = sign((inp[b] - inp[i]) * (inp[c] - inp[i]));
 	 	 	int tmp3 = sign((inp[c] - inp[i]) * (inp[a] - inp[i]));
 	 	 	if (max(max(tmp1, tmp2), tmp3) - min(min(tmp1, tmp2), tmp3) <= 1) {
 	 	 	 	++ret;
 	 	 	 	p = i;
 	 	 	}
 	 	}
 	}
 	return {ret, p};
}

int nott(int a, int b, int c) {
 	if ((inp[a] - inp[c]) * (inp[b] - inp[c])) {
   	 	return 0;
   	}
   	return 1;
}

int main() {
	//freopen(TASK_NAME ".in", "r", stdin);
	//freopen(TASK_NAME ".out", "w", stdout);

	scanf("%d", &n);

	for (int i = 0; i < n; ++i) {
	 	int x, y;
	 	scanf("%d%d", &x, &y);
	 	inp.puba(point(x, y));
	}

	//cout << nott(0, 3, 4) << endl;

	int a = 0, b = 1, c = -1;

	for (int i = 2; i < n; ++i) {
	 	if ((inp[a] - inp[i]) * (inp[b] - inp[i])) {
	 	 	c = i;
	 	 	break;
	 	}
	}

	while (true) {
	 	pii p = getany(a, b, c);
	 	if (p.ff == 0) {
	 	 	break;
	 	}
	 	int d = p.ss;
	 	pii tmp1 = getany(a, b, d);
	 	if (nott(a, b, d)) {
	 	 	tmp1.ff = 1e9 + 7;
	 	}
	 	pii tmp2 = getany(a, d, c);
	 	if (nott(a, d, c)) {
	 	 	tmp2.ff = 1e9 + 7;
	 	}
	 	pii tmp3 = getany(d, b, c);
	 	if (nott(d, b, c)) {
	 	 	tmp3.ff = 1e9 + 7;
	 	}	 	
	 	//cerr << a << " " << b << " " << c << " " << d << " " << tmp1.ff << " " << tmp2.ff << " " << tmp3.ff << endl;
	 	if (tmp1.ff <= tmp2.ff && tmp1.ff <= tmp3.ff) {
	 	 	c = d;
	 	} else if (tmp2.ff <= tmp1.ff && tmp2.ff <= tmp3.ff) {
	 	 	b = d;
	 	} else {
	 	 	a = d;
	 	}
	}

	cout << a + 1 << " " << b + 1 << " " << c + 1 << endl;

	return 0;
}