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

const int maxm = 200 * 1000 + 85 - 69;
pll seg[maxm * 4];
LL ans, Inf;
vector<pll> pla;
LL d, n, m;

void build(int l = 0, int r = sz(pla), int id = 1){
	if(r - l == 1){
		seg[id] = MP(pla[l].R, l);
		return;
	}
	int mid = (l + r) >> 1;
	build(l, mid, id * 2 + 0);
	build(mid, r, id * 2 + 1);
	seg[id] = min(seg[id * 2 + 0],
			seg[id * 2 + 1]);
	return;
}

pll get(LL st, LL en, int l = 0, int r = sz(pla), int id = 1){
	if(st >= r or en <= l)
		return MP(Inf, -1);
	if(st <= l and r <= en)
		return seg[id];
	int mid = (l + r) >> 1;
	return min(get(st, en, l, mid, id * 2 + 0),
			get(st, en, mid, r, id * 2 + 1));
}

int getless(int idx, int lo, int hi){
	while(hi - lo > 1){
		LL mid = (lo + hi) >> 1;
		if(get(idx + 1, mid).L <= pla[idx].R)
			hi = mid;
		else
			lo = mid;
	}
	return lo;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	Inf = 1000;
	Inf *= Inf;
	Inf *= Inf * Inf;
	cin >> d >> n >> m;
	for(int i = 0; i < m; i++){
		int fi, se;
		cin >> fi >> se;
		pla.PB(MP(fi, se));
	}
	pla.PB(MP(0, 0));
	pla.PB(MP(d, 0));
	sort(all(pla));
	build();
	LL pos = 0, fuel = n;
	for(int i = 1; i + 1 < sz(pla); i++){
		fuel -= pla[i].L - pla[i - 1].L;
		pos = pla[i].L;
		int id1 = lower_bound(all(pla), MP(pos + 1, -1LL)) - pla.begin(),
			id2 = lower_bound(all(pla), MP(pos + 1 + n, -1LL)) - pla.begin();
		pll Min = get(id1, id2);
		if(Min.L == Inf){
			cout << -1 << endl;
			return 0;
		}
		if(Min.L >= pla[i].R){
			ans += pla[i].R * (n - fuel), fuel = n;
			continue;
		}
		LL Less = getless(i, id1, id2);
		if(pla[Less].L - pos <= fuel)
			continue;
		ans += ((pla[Less].L - pos) - fuel) * pla[i].R;
		fuel = pla[Less].L - pos;
	}
	cout << ans << endl;
	return 0;
}