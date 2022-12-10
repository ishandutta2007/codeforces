//sobskdrbhvk
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

const int maxn = 2e5 + 85 - 69;
const int Inf = 1.5e9;
const LL Linf = 1e18;
LL seg[maxn * 4],
	arr[maxn],
	le[maxn],
	ri[maxn],
	q[maxn],
	qord[maxn];
LL ans[maxn],
   tim[maxn];
LL n, m;
vector<LL> all, tall;
vector<pll> add;

bool qcmp(int i, int j){
	return q[i] < q[j];
}

void modify(int idx, int l = 0, int r = sz(all) - 1, int id = 1){
	if(le[idx] >= r or ri[idx] <= l) return;
	if(le[idx] <= l and r <= ri[idx]){
		smin(seg[id], tim[idx]);
		return;
	}
	int mid = (l + r) >> 1;
	modify(idx, l, mid, id<<1);
	modify(idx, mid, r, id<<1|1);
	return;
}

void get(LL val = Linf, int l = 0, int r = sz(all) - 1, int id = 1){
	smin(val, seg[id]);
	if(r - l == 1){
		arr[r] = val - all[r];
		return;
	}
	int mid = (l + r) >> 1;
	get(val, l, mid, id<<1);
	get(val, mid, r, id<<1|1);
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	memset(seg, 63, sizeof seg);
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		cin >> le[i] >> ri[i] >> tim[i];
		all.PB(le[i]);
		all.PB(ri[i]);
	}
	sort(all(all));
	all.resize(unique(all(all)) - all.begin());
	for(int i = 0; i < m; i++){
		le[i] = lower_bound(all(all), le[i]) - all.begin();
		ri[i] = lower_bound(all(all), ri[i]) - all.begin();
		modify(i);
	}
	get();
	for(int i = sz(all)-1; i; i--){
		add.PB(MP(arr[i], +1));
		tall.PB(add.back().L);
		add.PB(MP(arr[i] + (all[i] - all[i - 1]), -1));
		tall.PB(add.back().L);
	}
	sort(all(add));
	sort(all(tall));
	tall.resize(unique(all(tall)) - tall.begin());
	for(int i = 0; i < n; i++)
		cin >> q[i];
	iota(qord, qord + n, 0);
	sort(qord, qord + n, qcmp);
	LL act = 0,
	   sum = 0,
	   tim = Inf;
	int ptr = 0,
		qptr = 0;
	for(int i = 0; i < sz(tall); i++){
		while(qptr < n and q[qord[qptr]] <= tall[i])
			ans[qord[qptr]] = sum + act * (q[qord[qptr]] - tim), qptr++;
		sum += act * (tall[i] - tim);
		tim = tall[i];
		while(ptr < sz(add) and add[ptr].L <= tim)
			act += add[ptr++].R;
	}
	while(qptr < n)
		ans[qord[qptr]] = sum + act * (q[qord[qptr]] - tim), qptr++;
	for(int i = 0; i < n; i++)
		cout << ans[i] << '\n';
	return 0;
}