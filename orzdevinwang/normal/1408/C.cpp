#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j; i <= k; i++) 
#define R(i, j, k) for(int i = j; i >= k; i--)
#define ll long long
#define db double
using namespace std;
const int N = 1e5 + 7;
const db eps = 1e-6;
int T, n, l, a[N];
bool cheak(db x) { // meet or not 
	db sj = x, len = l;
	int v;
	v = 1;
	L(i, 1, n + 1) {
		double le = (a[i] - a[i - 1]);
		if(sj * v > le) sj -= le / v, len -= le, ++v;
		else {
			len -= sj * v;
			break;
		} 
	} 
	sj = x;
	v = 1;
	R(i, n, 0) {
		double le = (a[i + 1] - a[i]);
		if(sj * v > le) sj -= le / v, len -= le, ++v;
		else {
			len -= sj * v;
			break;
		} 
	}
	return len <= 0;
}
int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &n, &l);
		L(i, 1, n) scanf("%d", &a[i]);
		a[n + 1] = l;
		db u = 0.0, v = l;
		while(v - u > eps) {
			db mid = (u + v) * 0.5;
			if(cheak(mid)) v = mid;
			else u = mid;
		}
		printf("%.10lf\n", u);
	}
	return 0;
}