//sobskdrbhvk
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
typedef long double LD;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define sz(x) ((int)(x).size())
#define smax(x, y) ((x) = max((x), (y)))
#define smin(x, y) ((x) = min((x), (y)))
#define all(x) x.begin(),x.end()

const int maxn = 100 * 1000 + 85 - 69;
vector<int> vec[maxn * 4], stc[maxn * 4];
vector<LD> poi[maxn * 4];
LL a[maxn], b[maxn];
int n, q;

bool cmp(int i, int j){return (b[i] == b[j]) ? a[i] < a[j] : b[i] < b[j];}

LD Intersect(int id1, int id2){
	return LD(a[id1] - a[id2]) / LD(b[id2] - b[id1]);
}

void build(int l = 0, int r = n, int id = 1){
	vec[id].reserve(r - l);
	stc[id].reserve(r - l);
	poi[id].reserve(r - l);
	if(r - l == 1){
		vec[id].PB(l);
		stc[id].PB(l);
		return;
	}
	int mid = (l + r) >> 1;
	build(l, mid, id * 2 + 0);
	build(mid, r, id * 2 + 1);
	merge(all(vec[id * 2 + 0]), all(vec[id * 2 + 1]), back_inserter(vec[id]), cmp);
	for(auto idx : vec[id]){
		while(sz(stc[id]) > 1){
			int id2 = stc[id][sz(stc[id]) - 1],
				id1 = stc[id][sz(stc[id]) - 2];
			if(b[id2] == b[idx] or (b[id2] != b[idx] and Intersect(id2, idx) <= Intersect(id1, id2)))
				stc[id].pop_back();
			else break;
		}
		stc[id].PB(idx);
	}
	for(int i = 0; i + 1 < sz(stc[id]); i++)
		poi[id].PB(Intersect(stc[id][i], stc[id][i + 1]));
	return;
}

pll get(LL pos, int st, int en, int l = 0, int r = n, int id = 1){
	if(st <= l and r <= en){
		int idx = *(lower_bound(all(poi[id]), LD(pos)) - poi[id].begin() + stc[id].begin());
		return MP(a[idx] + b[idx] * pos, idx + 1);
	}
	int mid = (l + r) >> 1;
	if(en <= mid)
		return get(pos, st, en, l, mid, id * 2 + 0);
	if(st >= mid)
		return get(pos, st, en, mid, r, id * 2 + 1);
	return max(get(pos, st, en, l, mid, id * 2 + 0),
			get(pos, st, en, mid, r, id * 2 + 1));
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> q;
	for(int i = 0; i < n; i++)
		cin >> a[i] >> b[i];
	build();
	while(q--){
		LL l, r, t;
		cin >> l >> r >> t;
		cout << get(t, l - 1, r).R << endl;
	}
	return 0;
}