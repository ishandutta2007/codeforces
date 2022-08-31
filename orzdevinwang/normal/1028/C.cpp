#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define sz(a) ((int) (a).size())
#define vi vector < int >
#define me(a, x) memset(a, x, sizeof(a))
#define ull unsigned long long 
using namespace std;
const int N = 1e6 + 7, inf = 1e9 + 7;
int n, m;
struct qwq {
	int lx, rx, ly, ry;
	qwq (int Lx = 0, int Rx = 0, int Ly = 0, int Ry = 0) {
		lx = Lx, rx = Rx, ly = Ly, ry = Ry;
	}
};
qwq operator + (qwq a, qwq b) {
	return qwq(max(a.lx, b.lx), min(a.rx, b.rx), max(a.ly, b.ly), min(a.ry, b.ry));
}
int lx[N], rx[N], ly[N], ry[N]; 
qwq c[N], pre[N], suf[N];
int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n ;
	L(i, 1, n) {
		cin >> lx[i] >> ly[i] >> rx[i] >> ry[i];
		c[i] = qwq (lx[i], rx[i], ly[i], ry[i]); 
	}
	pre[0] = suf[n + 1] = qwq(-inf, inf, -inf, inf);
	L(i, 1, n) {
		pre[i] = pre[i - 1] + c[i];
	}
	R(i, n, 1) {
		suf[i] = suf[i + 1] + c[i];
	}
	L(i, 1, n) {
		qwq mad = pre[i - 1] + suf[i + 1];
		if(mad.lx <= mad.rx && mad.ly <= mad.ry) 
			return cout << mad.lx << ' ' << mad.ly << '\n', 0;
	}
	return 0;
}