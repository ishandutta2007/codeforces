#include <stdio.h>
#include <bits/stdc++.h>
#define int long long

using namespace std;

const double eps = 1e-10;
const int N = 2e5 + 10;;

int n, p[N], t[N], a[N], b[N], Ma[N], Mi[N], T;

int check(double m) {
	double M = 0.0;
	for(int i = 1, j = 1; i <= n; i++) {
		while(j <= n && p[b[j]] < p[b[i]]) M = max(M, (1.0 - m * Mi[b[j]] / T) * p[b[j]]), j++;
		if((1.0 - m * Ma[b[i]] / T) * p[b[i]] < M) return 0;
	}
	return 1;
}

signed main() {
	scanf("%lld\n", &n);
	for(int i = 1; i <= n; i++) scanf("%lld", &p[i]), a[i] = i;
	for(int i = 1; i <= n; i++) scanf("%lld", &t[i]), b[i] = i;
	sort(a + 1, a + n + 1, [&](int i, int j) {return p[i] * t[j] > p[j] * t[i];});
	sort(b + 1, b + n + 1, [&](int i, int j) {return p[i] < p[j];}); 
	for(int i = 1, j, s; i <= n; i = j) {
		for(j = i + 1, s = 0; j <= n; j++)
			if(p[a[i]] * t[a[j]] != p[a[j]] * t[a[i]]) break;
		for(int k = i; k < j; k++) s += t[a[k]];
		for(int k = i; k < j; k++) Mi[a[k]] = T + t[a[k]], Ma[a[k]] = T + s; 
		T += s;
	}
	double l = 0, r = 1;
	while(r - l > eps) {
		double mid = (l + r) / 2.0;
		if(!check(mid)) r = mid;
		else l = mid;
	}
	printf("%.10f\n", l);
	return 0;
}