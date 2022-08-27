#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j; i <= k; i++)
using namespace std;
int n, ns, mx[2]; long long all;
struct piii { int x, y, c; } a[200007];
int main() {
	scanf("%d", &n);
	L(i, 1, n) scanf("%d", &a[i].x);
	L(i, 1, n) scanf("%d", &a[i].y), 
	((a[i].c = a[i].x > a[i].y) && (swap(a[i].x, a[i].y), 0)), all += a[i].y - a[i].x;
	sort(a + 1, a + n + 1, [&] (piii a, piii b) { return a.x < b.x; });
	L(i, 1, n) ns = max(ns, min(mx[a[i].c ^ 1], a[i].y) - a[i].x), mx[a[i].c] = max(mx[a[i].c], a[i].y);
	return printf("%lld\n", all - ns * 2), 0;
}