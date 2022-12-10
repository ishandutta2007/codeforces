//sobskdrbhvk
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define sz(x) ((int)(x).size())
#define smax(x, y) ((x) = max((x), (y)))
#define smin(x, y) ((x) = min((x), (y)))
#define all(x) x.begin(),x.end()

const int maxn = 200 * 1000 + 85 - 69;
LL seg1[maxn * 4], seg2[maxn * 4];
LL cnt[maxn];
LL n, k, a, b, q;

void modify(LL *seg, int idx, LL val, int l = 0, int r = n, int id = 1){
	if(idx >= r or idx < l)
		return;
	if(r - l == 1){
		seg[id] = val;
		return;
	}
	int mid = (l + r) >> 1;
	modify(seg, idx, val, l, mid, id * 2 + 0);
	modify(seg, idx, val, mid, r, id * 2 + 1);
	seg[id] = seg[id * 2 + 0] + seg[id * 2 + 1];
	return;
}

LL get(LL *seg, int st, int en, int l = 0, int r = n, int id = 1){
	if(st >= r or en <= l)
		return 0;
	if(st <= l and r <= en)
		return seg[id];
	int mid = (l + r) >> 1;
	return get(seg, st, en, l, mid, id * 2 + 0)
		+ get(seg, st, en, mid, r, id * 2 + 1);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k >> a >> b >> q;
	while(q--){
		int ty, fi, se;
		cin >> ty >> fi;
		fi--;
		if(ty == 1){
			cin >> se;
			cnt[fi] += se;
			modify(seg1, fi, min(b, cnt[fi]));
			modify(seg2, fi, min(a, cnt[fi]));
		}
		else
			cout << get(seg1, 0, fi) + get(seg2, fi + k, n) << '\n';
	}
	return 0;
}