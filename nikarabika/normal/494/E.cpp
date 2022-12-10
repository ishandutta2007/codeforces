//sobskdrbhvk
//remember the flying, the bird dies ):(
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
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

const int maxn = 1e5 + 85 - 69;
int r1[maxn],
	r2[maxn],
	c1[maxn],
	c2[maxn],
	segs[maxn * 4],
	segm[maxn * 4],
	laz[maxn * 4];
int n, m, k;
vector<int> xall, yall;
vector<pair<pii, int> > quer[maxn];

void pull(int id){
	int le = id<<1|0,
		ri = id<<1|1;
	segm[id] = min(segm[le], segm[ri]) + laz[id];
	segs[id] = 0;
	if(segm[le] <= segm[ri]) segs[id] += segs[le];
	if(segm[ri] <= segm[le]) segs[id] += segs[ri];
	return;
}

void build(int l = 0, int r = sz(yall) - 1, int id = 1){
	if(r - l < 1) return;
	segs[id] = yall[r] - yall[l];
	segm[id] = 0;
	laz[id] = 0;
	if(r - l == 1) return;
	int mid = (l + r) >> 1;
	build(l, mid, id<<1|0);
	build(mid, r, id<<1|1);
	return;
}

void add(int val, int st, int en, int l = 0, int r = sz(yall) - 1, int id = 1){
	if(st >= r or en <= l)
		return;
	if(st <= l and r <= en){
		laz[id] += val;
		segm[id] += val;
		return;
	}
	int mid = (l + r) >> 1;
	add(val, st, en, l, mid, id<<1|0);
	add(val, st, en, mid, r, id<<1|1);
	pull(id);
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	for(int i = 0; i < m; i++)
		cin >> r1[i] >> c1[i] >> r2[i] >> c2[i];
	int high = 31 - __builtin_clz(k);
	for(int _ = 0; _ <= high; _++){
		xall.clear();
		yall.clear();
		for(int i = 0; i < maxn; i++)
			quer[i].clear();
		for(int i = 0; i < m; i++){
			xall.PB(r1[i]);
			xall.PB(r2[i] + 1);
			yall.PB(c1[i]);
			yall.PB(c2[i] + 1);
		}
		sort(all(xall));
		sort(all(yall));
		xall.resize(unique(all(xall)) - xall.begin());
		yall.resize(unique(all(yall)) - yall.begin());
		build();
		bool has = false;
		for(int i = 0; i < m; i++) if(c1[i] <= c2[i] and r1[i] <= r2[i]){
			has = true;
			int xid = lower_bound(all(xall), r1[i]) - xall.begin();
			int lid = lower_bound(all(yall), c1[i]) - yall.begin(),
				rid = lower_bound(all(yall), c2[i] + 1) - yall.begin();
			quer[xid].PB(MP(MP(lid, rid), +1));
			xid = lower_bound(all(xall), r2[i] + 1) - xall.begin();
			quer[xid].PB(MP(MP(lid, rid), -1));
		}
		if(!has)
			break;
		/*cout << "X@ ";
		for(auto val : xall)
			cout << val << ' ';
		cout << '\n';
		cout << "Y@ ";
		for(auto val : yall)
			cout << val << ' ';
		cout << '\n';
		for(int i = 0; i < sz(xall); i++)
			for(auto Q : quer[i])
				cout << "# " << Q.L.L << ' ' << Q.L.R << ' ' << Q.R << endl;
		*/
		int sum = 0;
		for(int i = 0; i < sz(xall); i++){
			for(auto Q : quer[i])
				add(Q.R, Q.L.L, Q.L.R);
			if(i + 1 < sz(xall)){
				int len = (xall[i + 1] - xall[i]) & 1;
				if(segm[1] == 0)
					sum += (len * (yall.back() - yall[0] - segs[1])) & 1;
				else
					sum += (len * (yall.back() - yall[0])) & 1;
			}
		}
		for(int i = 0; i < m; i++){
			r1[i] = (r1[i] + 1) >> 1;
			c1[i] = (c1[i] + 1) >> 1;
			r2[i] >>= 1, c2[i] >>= 1;
		}
		//cout << sum << endl;
		sum &= 1;
		if(sum){
			cout << "Hamed\n";
			return 0;
		}
	}
	cout << "Malek\n";
	return 0;
}