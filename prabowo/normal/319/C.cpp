#include <cstdio>
#include <vector>

typedef long long LL;

const int N = 100000;

struct Line {
	LL m, c;
	Line (LL _m, LL _c) { m = _m; c = _c; }
};

int n;
int a[N], b[N];

bool check (Line A, Line B, Line C) {
	return (double) (C.c - A.c) / (C.c - B.c) >= (double) (A.m - C.m) / (B.m - C.m);
}

LL evaluate (Line A, LL x) {
	return A.m * x + A.c;
}

LL dp[N];

int main () {
	scanf ("%d", &n);
	
	for (int i=0; i<n; i++) scanf ("%d", a + i);
	for (int i=0; i<n; i++) scanf ("%d", b + i);
	
	std::vector <Line> v;
	
	v.push_back(Line(b[0], dp[0] = b[0]));
	int idx = 0;
	for (int i=1; i<n; i++) {
		if (idx >= v.size()) idx = v.size() - 1;
		while (idx + 1 < v.size() && evaluate(v[idx], a[i]) >= evaluate(v[idx + 1], a[i])) idx++;
		
		dp[i] = evaluate(v[idx], a[i]) - v[idx].m + b[i];
		while (v.size() > 1 && check(v[v.size()-2], v.back(), Line(b[i], dp[i]))) v.pop_back();
		v.push_back(Line(b[i], dp[i]));
	}
	
	printf ("%I64d\n", dp[n-1]);
	
	return 0;
}