#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define PB push_back

const int maxn = 3e5 + 85 - 69;
const LL Mod = 1000000009;
LL f[maxn];
LL a[maxn];
LL seg[maxn * 4], laz1[maxn * 4], laz2[maxn * 4];
int n, m;

void propagate(int, int, int);

LL fib(int id, LL val1, LL val2){
	return (((f[id] * val1) % Mod) + ((f[id - 1] * ((val2 - val1) % Mod)) % Mod)) % Mod;
}

void build(int l = 0, int r = n, int id = 1){
	if(r - l == 1){
		seg[id] = a[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(l, mid, id * 2 + 0);
	build(mid, r, id * 2 + 1);
	seg[id] = (seg[id * 2 + 0] + seg[id * 2 + 1]) % Mod;
	return;
}

void add(int val1, int val2, int st, int en, int l = 0, int r = n, int id = 1){
	if(en <= l or r <= st)
		return;
	if(st <= l and r <= en){
		laz1[id] = (laz1[id] + fib(l - st + 1, val1, val2)) % Mod;
		laz2[id] = (laz2[id] + fib(l - st + 2, val1, val2)) % Mod;
		seg[id] = (((seg[id] + fib(r - st + 2, val1, val2) - fib(l - st + 2, val1, val2)) % Mod) + Mod) % Mod;
		return;
	}
	int mid = (l + r) >> 1;
	propagate(l, r, id);
	add(val1, val2, st, en, l, mid, id * 2 + 0);
	add(val1, val2, st, en, mid, r, id * 2 + 1);
	seg[id] = (seg[id * 2 + 0] + seg[id * 2 + 1]) % Mod;
	return;
}

LL get(int st, int en, int l = 0, int r = n, int id = 1){
	if(en <= l or r <= st)
		return 0;
	if(st <= l and r <= en)
		return seg[id];
	int mid = (l + r) >> 1;
	propagate(l, r, id);
	return (get(st, en, l, mid, id * 2 + 0)
		+ get(st, en, mid, r, id * 2 + 1)) % Mod;
}

void propagate(int l, int r, int id){
	if(laz1[id] != 0 or laz2[id] != 0){
		int mid = (l + r) >> 1;
		add(laz1[id], laz2[id], l, r, l, mid, id * 2 + 0);
		add(laz1[id], laz2[id], l, r, mid, r, id * 2 + 1);
		laz1[id] = laz2[id] = 0;
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	f[0] = 0;
	f[1] = 1;
	for(int i = 2; i < maxn; i++)
		f[i] = (f[i - 1] + f[i - 2]) % Mod;
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	build();
	while(m--){
		int ty, fi, se;
		cin >> ty >> fi >> se;
		if(ty == 1)
			add(1, 1, fi - 1, se);
		else
			cout << get(fi - 1, se) << '\n';
	}
	return 0;
}