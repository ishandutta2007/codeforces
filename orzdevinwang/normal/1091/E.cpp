#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 1e6 + 7;
int n, FIND = -1, op, sav[N], deg[N], gs;
bool check(int x) { int dd;
	L(i, 1, n) deg[i] = sav[i];
	R(i, n, 0) if(x <= deg[i]) {
		deg[i + 1] = x, dd = i + 1;
		break;
	} 
	else swap(deg[i], deg[i + 1]);
	int pn = n + 1;
	ll suma = 0, Sum = 0, sumb; int zz = pn + 1;
	L(i, 1, pn) {
		if(zz == i) Sum -= deg[i], zz = i + 1;
		while(zz > i + 1 && deg[zz - 1] <= i) --zz, Sum += deg[zz];
		suma += deg[i];
		sumb = Sum + 1ll * (zz - i - 1) * i + 1ll * i * (i - 1);
		if(suma > sumb) {
			if(dd <= i) gs = 0;
			else gs = 1;
			return 0;
		}
	}
	return 1;
}
int findmx(int l, int r) {
	int ans = l;
	while(l <= r) {
		int mid = (l + r) / 2;
		if(check(2 * mid + op)) ans = mid, l = mid + 1;
		else r = mid - 1;
	}
	return ans;
}
int findmn(int l, int r) {
	int ans = r;
	while(l <= r) {
		int mid = (l + r) / 2;
		if(check(2 * mid + op)) ans = mid, r = mid - 1;
		else l = mid + 1;
	}
	return ans;
}
int main() {
	scanf("%d", &n);
	L(i, 1, n) scanf("%d", &sav[i]), op ^= (sav[i] & 1);
	sort(sav + 1, sav + n + 1), reverse(sav + 1, sav + n + 1);
	int l = 0, r = (n - op) / 2;
	while(l <= r) {
		int mid = (l + r) / 2;
		if(check(2 * mid + op)) {
			FIND = mid;
			break;
		}
		if(gs == 1) l = mid + 1;
		else r = mid - 1;
	}
	if(FIND == -1) return puts("-1"), 0;
	L(i, findmn(0, FIND), findmx(FIND, (n - op) / 2)) printf("%d ", i * 2 + op);
	puts("");
	// check(1);
	return 0;
}