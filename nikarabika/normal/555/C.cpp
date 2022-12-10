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

const int maxn = 4e5 + 85 - 69;
int seg[2][maxn * 4];
int q1[maxn],
	q2[maxn],
	n, q;
bool mark[maxn];
char q3[maxn];
vector<int> all;

int idof(int x){
	return lower_bound(all(all), x) - all.begin();
}

void modify(int sid, int val, int idx, int l = 0, int r = sz(all), int id = 1){
	if(idx < l or idx >= r)
		return;
	if(r - l == 1){
		seg[sid][id] = val;
		return;
	}
	int mid = (l + r) >> 1;
	modify(sid, val, idx, l, mid, id<<1|0);
	modify(sid, val, idx, mid, r, id<<1|1);
	seg[sid][id] = min(seg[sid][id<<1|0], seg[sid][id<<1|1]);
	return;
}

int seget(int sid, int st, int en, int l = 0, int r = sz(all), int id = 1){
	if(st >= r or en <= l)
		return sz(all);
	if(st <= l and r <= en)
		return seg[sid][id];
	int mid = (l + r) >> 1;
	return min(seget(sid, st, en, l, mid, id<<1|0),
			seget(sid, st, en, mid, r, id<<1|1));
}

int get(int sid, int val, int hi){
	int lo = 0;
	while(hi - lo > 1){
		int mid = (lo + hi) >> 1;
		if(seget(sid, mid, hi) <= val)
			lo = mid;
		else
			hi = mid;
	}
	return lo;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	memset(seg, 63, sizeof seg);
	cin >> n >> q;
	for(int i = 0; i < q; i++){
		cin >> q1[i] >> q2[i] >> q3[i];
		q1[i]--, q2[i]--;
		all.PB(q1[i]);
		all.PB(q2[i]);
	}
	all.PB(-1);
	sort(all(all));
	all.resize(unique(all(all)) - all.begin());
	for(int i = 0; i < q; i++){
		q1[i] = idof(q1[i]);
		q2[i] = idof(q2[i]);
		if(mark[q1[i]]){
			cout << 0 << '\n';
			continue;
		}
		if(q3[i] == 'L'){
			int id = get(0, q2[i], q1[i] + 1);
			cout << all[q1[i]] - all[id] << '\n';
			modify(1, id, q2[i]);
		}
		else{
			int id = get(1, q1[i], q2[i] + 1);
			cout << all[q2[i]] - all[id] << '\n';
			modify(0, id, q1[i]);
		}
		mark[q1[i]] = true;
	}
	return 0;
}