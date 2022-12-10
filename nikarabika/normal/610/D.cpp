#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
typedef pair<LL, pll> plll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define sz(x) ((int)(x).size())
#define smin(x, y) (x) = min((x), (y))
#define smax(x, y) (x) = max((x), (y))
#undef right
#define right roght

const int maxn = 1e5 + 85 - 69;
vector<LL> seg[maxn * 8], all;
vector<plll> right2, up2;
vector<plll> up, right;
LL n, ans;

void make(vector<plll> &vec, vector<plll> &vec2){
	int p;
	for(int i = 0; i < sz(vec); i = p){
		p = i;
		while(p < sz(vec) and vec[p].L == vec[i].L) p++;
		pll last_inter(vec[i].R);
		for(int j = i + 1; j < p; j++){
			if(vec[j].R.L >= last_inter.R){
				vec2.PB(MP(vec[j].L, last_inter));
				last_inter = vec[j].R;
			}
			else
				smax(last_inter.R, vec[j].R.R);
		}
		vec2.PB(MP(vec[p - 1].L, last_inter));
	}
	return;
}

void add(LL val, int st, int en, int l = 0, int r = sz(all) - 1, int id = 1){
	if(st >= r or en <= l)
		return;
	if(st <= l and r <= en){
		seg[id].PB(val);
		return;
	}
	int mid = (l + r) >> 1;
	add(val, st, en, l, mid, id * 2 + 0);
	add(val, st, en, mid, r, id * 2 + 1);
	return;
}

LL get(int idx, LL st, LL en, int l = 0, int r = sz(all) - 1, int id = 1){
	if(idx < l or idx >= r)
		return 0;
	LL val = lower_bound(seg[id].begin(), seg[id].end(), en) - lower_bound(seg[id].begin(), seg[id].end(), st);
	if(r - l == 1)
		return val;
	int mid = (l + r) >> 1;
	return get(idx, st, en, l, mid, id * 2 + 0)
		+ get(idx, st, en, mid, r, id * 2 + 1)
		+ val;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++){
		LL fi, se, th, fo;
		cin >> fi >> se >> th >> fo;
		if(se == fo)
			right.PB(MP(se, MP(min(fi, th), max(fi, th) + 1)));
		else if(fi == th)
			up.PB(MP(fi, MP(min(se, fo), max(se, fo) + 1)));
	}
	sort(right.begin(), right.end());
	make(right, right2);
	for(auto quer : right2)
		all.PB(quer.R.L), all.PB(quer.R.R), ans += quer.R.R - quer.R.L;
	sort(all.begin(), all.end());
	all.resize(unique(all.begin(), all.end()) - all.begin());
	for(auto quer : right2){
		int id1 = lower_bound(all.begin(), all.end(), quer.R.L) - all.begin(),
			id2 = lower_bound(all.begin(), all.end(), quer.R.R) - all.begin();
		add(quer.L, id1, id2);
	}
	sort(up.begin(), up.end());
	make(up, up2);
	for(auto quer : up2){
		int id = upper_bound(all.begin(), all.end(), quer.L) - all.begin() - 1;
		ans += quer.R.R - quer.R.L - get(id, quer.R.L, quer.R.R);
	}
	cout << ans << endl;
	return 0;
}