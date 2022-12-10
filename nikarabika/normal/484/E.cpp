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

const int maxn = 100 * 1000 + 85 - 69,
	  maxl = 30;
int L[maxn * maxl],
	R[maxn * maxl],
	h[maxn],
	root[maxn],
	n, sz = 1;
vector<pii> all;

struct node{
	int ans, pre, suf;
	bool fil;
	node(int x1 = 0, int x2 = 0, int x3 = 0, bool x4 = false){
		ans = x1, pre = x2, suf = x3, fil = x4;
	}
} seg[maxn * maxl];

node merge(node le, node ri){
	node ret;
	ret.fil = le.fil and ri.fil;
	ret.pre = (le.fil) ? le.pre + ri.pre : le.pre;
	ret.suf = (ri.fil) ? ri.suf + le.suf : ri.suf;
	ret.ans = max(le.suf + ri.pre, max(le.ans, ri.ans));
	return ret;
}

int add(int idx, int id, int l = 0, int r = n){
	int newid = sz++;
	if(r - l == 1){
		seg[newid].ans = seg[newid].pre = seg[newid].suf = seg[newid].fil = 1;
		return newid;
	}
	int mid = (l + r) >> 1;
	L[newid] = L[id];
	R[newid] = R[id];
	if(idx < mid)
		L[newid] = add(idx, L[newid], l, mid);
	else
		R[newid] = add(idx, R[newid], mid, r);
	seg[newid] = merge(seg[L[newid]], seg[R[newid]]);
	return newid;
}

node get(int st, int en, int id, int l = 0, int r = n){
	if(st >= r or en <= l){
		cout << ":|" << endl;
		exit(0);
	}
	if(st <= l and r <= en)
		return seg[id];
	int mid = (l + r) >> 1;
	if(en <= mid)
		return get(st, en, L[id], l, mid);
	if(st >= mid)
		return get(st, en, R[id], mid, r);
	return merge(get(st, en, L[id], l, mid),
			get(st, en, R[id], mid, r));
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> h[i];
		all.PB(MP(h[i], i));
	}
	sort(all(all), greater<pii>());
	for(int i = 0; i < sz(all); i++)
		root[i + 1] = add(all[i].R, root[i]);
	int q;
	cin >> q;
	for(int i = 0; i < q; i++){
		int fi, se, th;
		cin >> fi >> se >> th;
		fi--;
		int lo = -1, hi = sz(all) - 1;
		while(hi - lo > 1){
			int mid = (lo + hi) >> 1;
			if(get(fi, se, root[mid + 1]).ans >= th)
				hi = mid;
			else
				lo = mid;
		}
		cout << all[hi].L << '\n';
	}
	return 0;
}