// Skyqwq
#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

template <typename T> bool chkMax(T &x, T y) { return (y > x) ? x = y, 1 : 0; }
template <typename T> bool chkMin(T &x, T y) { return (y < x) ? x = y, 1 : 0; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

typedef pair<double, double> PDD;

PDD operator + (const PDD &a, const PDD &b) {
	return mp(a.fi + b.fi, a.se + b.se);
}

PDD operator - (const PDD &a, const PDD &b) {
	return mp(a.fi - b.fi, a.se - b.se);
}

PDD operator * (const PDD &a, double b) {
	return mp(a.fi * b, a.se * b);
}

PDD operator / (const PDD &a, double b) {
	return mp(a.fi / b, a.se / b);
}

PDD p[4];

const double eps = 1e-8;

double ans = 9e18;

mt19937 rnd(114);

const unsigned int I = (1ll << 32) - 1;

double inline g() {
	return (double)rnd() / I; 
}

double inline dot(PDD a) {
	return a.fi * a.fi + a.se * a.se;
}

double inline dis(PDD A, PDD B) {
	return sqrt(dot(A - B));
}

double inline get(PDD A, PDD B, PDD C) {
	PDD now = (A + B + C) / 3;
	double ret = dis(A, now) + dis(B, now) + dis(C, now);
    for (double t = 10000; t > eps; t *= 0.99) {
    	PDD np = mp((g() * 2 - 1) * t, (g() * 2 - 1) * t);
    	np = now + np;
    	double w = dis(A, np) + dis(B, np) + dis(C, np);
    	if (chkMin(ret, w)) now = np;
    }
    return ret;
}

double inline calc(PDD u) {
	return max(get(u, p[1], p[2]), max(get(u, p[1], p[3]), get(u, p[2], p[3])));
}

int main() {
	for (int i = 1; i <= 3; i++)
    	read(p[i].fi), read(p[i].se);
    PDD now = (p[1] + p[2] + p[3]) / 3;
    ans = calc(now);
    for (double t = 10000; t > eps; t *= 0.99) {
    	PDD np = mp((g() * 2 - 1) * t, (g() * 2 - 1) * t);
    	np = now + np;
    	double w = calc(np);
    	if (chkMin(ans, w)) now = np;
    }
    printf("%.10lf\n", ans);
    return 0;
}