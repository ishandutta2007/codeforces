#pragma warning(disable:4996)

#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <string>
#define mp make_pair
#define mul(a,b) ((long long)(a)*(b)%mod)

using namespace std;
typedef pair<int, int> pii;

int axpby(int a, int b) {
	//a,b must be less than 2^30
	int xx = 1; int yy = 0; int dd = a;
	int x = 0; int y = 1; int d = b;
	while (d) {
		int q = dd / d;

		int tmp = d;
		d = dd - d*q;
		dd = tmp;

		tmp = x;
		x = xx - x*q;
		xx = tmp;

		tmp = y;
		y = yy - y*q;
		yy = tmp;
	}
	if (xx < 0) xx += b;
	return xx;
}

const int mod = 1000000007;
int fact[200001];
int inv[200001];
int dyn[2001];

pii pts[2001];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	fact[0] = inv[0] = 1;
	for (int i = 1; i <= 200000; i++) {
		fact[i] = mul(fact[i - 1], i);
		inv[i] = axpby(fact[i], mod);
	}
	int h, w, n;
	scanf("%d %d %d", &h, &w, &n);
	for (int i = 0; i < n; i++) {
		int r, c;
		scanf("%d %d", &r, &c);
		r--; c--;
		pts[i] = mp(r, c);
	}
	pts[n] = mp(h - 1, w - 1);
	n++;
	sort(pts, pts + n, [](const pii& a, const pii& b)->bool {return a.first + a.second < b.first + b.second; });
	for (int i = 0; i < n; i++) {
		dyn[i] = fact[pts[i].first + pts[i].second];
		dyn[i] = mul(dyn[i], inv[pts[i].first]);
		dyn[i] = mul(dyn[i], inv[pts[i].second]);
		for (int j = 0; j < i; j++) {
			if (pts[j].first <= pts[i].first && pts[j].second <= pts[i].second) {
				int dx = pts[i].first - pts[j].first;
				int dy = pts[i].second - pts[j].second;
				int tmp = dyn[j];
				tmp = mul(tmp, fact[dx + dy]);
				tmp = mul(tmp, inv[dx]);
				tmp = mul(tmp, inv[dy]);
				dyn[i] -= tmp;
				if (dyn[i] < 0)dyn[i] += mod;
			}
		}
	}
	printf("%d\n", dyn[n - 1]);
	return 0;
}