#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++) 
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long 
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 5e5 + 7;
const int inf = 1e9 + 7;
int n, a[N];
int seg[N << 2], fg[N << 2];
void pushdown(int id) {
	fg[id << 1] += fg[id], seg[id << 1] += fg[id];
	fg[id << 1 | 1] += fg[id], seg[id << 1 | 1] += fg[id];
	fg[id] = 0;
}
void add(int id, int L, int R, int l, int r, int val) {
	if(l <= L && R <= r) return seg[id] += val, fg[id] += val, void();
	int mid = (L + R) / 2; 
	pushdown(id);
	if(l <= mid) add(id << 1, L, mid, l, r, val);
	if(r > mid) add(id << 1 | 1, mid + 1, R, l, r, val);
	seg[id] = min(seg[id << 1], seg[id << 1 | 1]);
}
int fia[N], fib[N], mid, ans;
int cnt[N];
void Main() {
	scanf("%d", &n);
	L(i, 1, n) scanf("%d", &a[i]);
	L(i, 1, n) if(!a[i]) cnt[i] = cnt[i - 1] + 1; else cnt[i] = cnt[i - 1];
	if(cnt[n] <= 1) return puts("0"), void();
	L(i, 1, n) if(cnt[i] > cnt[n] / 2) {
		mid = i - 1;
		break;
	}
	R(i, mid, 1) if(!fia[a[i]]) fia[a[i]] = i;
	L(i, mid + 1, n) if(!fib[a[i]]) fib[a[i]] = i;
	int now = 0;
	R(i, n, mid + 1) {
		if(a[i] == 0) add(1, mid, n, i, i, now), now++;
		else add(1, mid, n, i, i, inf);
	} 
	add(1, mid, n, mid, mid, now);
	now = 0;
	L(i, 1, n) {
		if(fib[i]) {
			if(fia[i]) add(1, mid, n, mid, n, 1);
			else add(1, mid, n, fib[i], n, 1);
		} 
		else if(fia[i]) now ++;
	}
	ans = seg[1] + now;
	L(i, 1, mid) {
		if(a[i] == 0) ++now;
		else if(i == fia[a[i]]) {
			if(fib[a[i]]) add(1, mid, n, mid + 1, fib[a[i]], -1); 
			else now --; 
		} 
		ans = min(ans, now + seg[1]);
	}
	printf("%d\n", min(ans, cnt[n] / 2));
	L(i, 1, n * 4) seg[i] = fg[i] = 0;
	L(i, 1, n) fia[i] = fib[i] = 0;
}
int main() {
	int T; scanf("%d", &T);
	while(T--) Main();
	return 0;
}
/*
1
11
0 0 0 0 0 0 1 2 3 4 5
*/