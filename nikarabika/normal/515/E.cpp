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

const int maxn = 100 * 1000 + 85 - 69;

struct node{
	LL ans, preans, sufans;
	LL len;
} seg[maxn * 4];

int n, q;
LL d[maxn], h[maxn];

node merge(node left, node right, LL dis){
	node ret;
	ret.ans = max(max(left.ans, right.ans), left.sufans + dis + right.preans);
	ret.preans = max(left.preans, left.len + dis + right.preans);
	ret.sufans = max(right.sufans, right.len + dis + left.sufans);
	ret.len = left.len + right.len + dis;
	return ret;
}

void build(int l = 0, int r = n, int id = 1){
	if(r - l == 1){
		seg[id].ans = h[l];
		seg[id].preans = seg[id].sufans = h[l];
		seg[id].len = 0;
		return;
	}
	int mid = (l + r) >> 1;
	build(l, mid, id * 2 + 0);
	build(mid, r, id * 2 + 1);
	seg[id] = merge(seg[id * 2 + 0], seg[id * 2 + 1], d[mid - 1]);
	return;
}

node get(int st, int en, int l = 0, int r = n, int id = 1){
	if(st <= l and r <= en)
		return seg[id];
	int mid = (l + r) >> 1;
	if(en <= mid)
		return get(st, en, l, mid, id * 2 + 0);
	if(st >= mid)
		return get(st, en, mid, r, id * 2 + 1);
	return merge(get(st, en, l, mid, id * 2 + 0),
			get(st, en, mid, r, id * 2 + 1),
			d[mid - 1]);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> q;
	for(int i = 0; i < n; i++)
		cin >> d[i];
	for(int i = 0; i < n; i++)
		cin >> h[i], h[i] <<= 1;
	build(0, n);
	while(q--){
		int fi, se;
		cin >> fi >> se;
		fi--, se--;
		if(fi > se)
			cout << get(se + 1, fi).ans << '\n';
		else if(fi == 0)
			cout << get(se + 1, n).ans << '\n';
		else if(se == n - 1)
			cout << get(0, fi).ans << '\n';
		else{
			auto left = get(0, fi),
				 right = get(se + 1, n);
			cout << max(max(left.ans, right.ans), left.preans + right.sufans + d[n - 1]) << '\n';
		}
	}
	return 0;
}