//sobskdrbhvk
#include <bits/stdc++.h>

using namespace std;

//man am A _____ & a pair of Izzz wayTn' 230u :)

typedef long long int LL;

const int maxn = 1e5 + 85 - 69;
const LL base = 313, Mod = 1000LL * 1000 * 1000 + 7;
LL P[maxn], S[maxn];
LL seg[maxn * 4], laz[maxn * 4];
int a[maxn], n, q;

void push(int l, int r, int id);
void pull(int l, int r, int id);

void build(int l = 0, int r = n, int id = 1){
	if(r - l == 1){
		seg[id] = a[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(l, mid, id * 2 + 0);
	build(mid, r, id * 2 + 1);
	pull(l, r, id);
	return;
}

void modify(LL val, int st, int en, int l = 0, int r = n, int id = 1){
	if(st >= r or en <= l)
		return;
	if(st <= l and r <= en){
		seg[id] = (S[r - l] * val) % Mod;
		laz[id] = val;
		return;
	}
	push(l, r, id);
	int mid = (l + r) >> 1;
	modify(val, st, en, l, mid, id * 2 + 0);
	modify(val, st, en, mid, r, id * 2 + 1);
	pull(l, r, id);
	return;
}

LL get(int st, int en, int l = 0, int r = n, int id = 1){
	if(st >= r or en <= l)
		return 0;
	if(st <= l and r <= en)
		return (seg[id] * P[en - r]) % Mod;
	push(l, r, id);
	int mid = (l + r) >> 1;
	return (get(st, en, l, mid, id * 2 + 0)
		+ get(st, en, mid, r, id * 2 + 1)) % Mod;
}

void push(int l, int r, int id){
	if(laz[id] != -1){
		int mid = (l + r) >> 1;
		modify(laz[id], l, mid, l, mid, id * 2 + 0);
		modify(laz[id], mid, r, mid, r, id * 2 + 1);
		laz[id] = -1;
	}
	return;
}

void pull(int l, int r, int id){
	int mid = (l + r) >> 1;
	seg[id] = (seg[id * 2 + 1] + ((seg[id * 2 + 0] * P[r - mid]) % Mod)) % Mod;
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	memset(laz, -1, sizeof laz);
	P[0] = 1;
	for(int i = 1; i < maxn; i++){
		P[i] = (P[i - 1] * base) % Mod;
		S[i] = (S[i - 1] + P[i - 1]) % Mod;
	}
	cin >> n;
	{
		int fi, se;
		cin >> fi >> se;
		q = fi + se;
	}
	for(int i = 0; i < n; i++){
		char c;
		cin >> c;
		a[i] = c - '0';
	}
	build();
	for(int i = 0; i < q; i++){
		int ty, fi, se, th;
		cin >> ty >> fi >> se >> th;
		fi--;
		if(ty == 1)
			modify(th, fi, se);
		else if(get(fi, se - th) == get(fi + th, se))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}