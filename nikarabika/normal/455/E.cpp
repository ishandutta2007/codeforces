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

const int maxn = 100 * 1000 * 10 / 10 + 85 - 69;
vector<int> tmp[maxn * 4],
	vec[maxn * 4];
vector<LD> its[maxn * 4];
LL a[maxn],
   b[maxn],
   sum[maxn],
   n, q, Inf;
int qc[maxn],
	qr[maxn];

bool cmp(int i, int j){
	return MP(a[i], b[i]) > MP(a[j], b[j]);
}

LD Intersect(int i, int j){
	return LD(b[i] - b[j]) / LD(a[j] - a[i]);
}

void build(int l = 0, int r = n, int id = 1){
	vec[id].reserve(r - l);
	tmp[id].reserve(r - l);
	its[id].reserve(r - l - 1);
	if(r - l == 1){
		vec[id].PB(l);
		return;
	}
	int mid = (l + r) >> 1;
	build(l, mid, id * 2 + 0);
	build(mid, r, id * 2 + 1);
	merge(all(vec[id * 2 + 0]), all(vec[id * 2 + 1]), back_inserter(tmp[id]), cmp);
	for(int i = 0; i < sz(tmp[id]); i++){
		while(sz(vec[id]) > 0 and a[vec[id].back()] == a[tmp[id][i]])
			vec[id].pop_back();
		while(sz(vec[id]) > 1){
			int id1 = vec[id][sz(vec[id]) - 2],
				id2 = vec[id][sz(vec[id]) - 1],
				id3 = tmp[id][i];
			if(Intersect(id1, id2) >= Intersect(id2, id3))
				vec[id].pop_back();
			else
				break;
		}
		vec[id].PB(tmp[id][i]);
	}
	for(int i = 0; i + 1 < sz(vec[id]); i++)
		its[id].PB(Intersect(vec[id][i], vec[id][i + 1]));
	return;
}

LL get(LL idx, int st, int en, int l = 0, int r = n, int id = 1){
	if(st >= r or en <= l)
		return Inf;
	if(st <= l and r <= en){
		int id2 = *(lower_bound(all(its[id]), LD(idx)) - its[id].begin() + vec[id].begin());
		return idx * a[id2] + b[id2];
	}
	int mid = (l + r) >> 1;
	return min(get(idx, st, en, l, mid, id * 2 + 0),
			get(idx, st, en, mid, r, id * 2 + 1));
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	Inf = 1000;
	Inf *= Inf;
	Inf *= Inf * Inf;
	Inf += 85 - 69;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		sum[i + 1] = sum[i] + a[i];
	}
	for(LL i = 0; i < n; i++)
		b[i] = sum[n] - sum[i] + a[i] * i;
	build();
	cin >> q;
	for(int i = 0; i < q; i++){
		cin >> qr[i] >> qc[i];
		qc[i]--;
		LL val = get(qr[i] - qc[i] - 1, max(0, qc[i] - qr[i] + 1), qc[i] + 1) - (sum[n] - sum[qc[i] + 1]);
		cout << val << '\n';
	}
	return 0;
}