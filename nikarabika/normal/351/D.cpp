//azin segmentaye shabih-e DQUERY mizanam ghorbatan elallah :-??
#include <bits/stdc++.h>

using namespace std;

//man am A _____ & a pair of Izzz wayTn' 230u :)

typedef pair<int, int> pii;
typedef pair<pii, int> piii;

#define PB push_back
#define MP make_pair
#define L first
#define R second

const int maxn = 1e5 + 85 - 69;
int min_seg[maxn * 4], cnt_seg[maxn * 4];
int a[maxn], adss[maxn], lasteq[maxn], mineq[maxn], ans[maxn];
vector<int> all;
vector<piii> quer;
int n, q;

bool cmp(piii x, piii y){
	return x.L.R < y.L.R;
}

void pull(int id){
	min_seg[id] = min(min_seg[id * 2 + 0], min_seg[id * 2 + 1]);
	cnt_seg[id] = cnt_seg[id * 2 + 0] + cnt_seg[id * 2 + 1];
	return;
}

void add(int idx, int l = 0, int r = n, int id = 1){
	if(idx < l or idx >= r)
		return;
	if(r - l == 1){
		min_seg[id] = (mineq[idx] == -1 ? -1 : lasteq[mineq[idx]]);
		cnt_seg[id] = 1;
		return;
	}
	int mid = (l + r) >> 1;
	add(idx, l, mid, id * 2 + 0);
	add(idx, mid, r, id * 2 + 1);
	pull(id);
	return;
}

void rem(int idx, int l = 0, int r = n, int id = 1){
	if(idx < l or idx >= r)
		return;
	if(r - l == 1){
		min_seg[id] = 1000000;
		cnt_seg[id] = 0;
		return;
	}
	int mid = (l + r) >> 1;
	rem(idx, l, mid, id * 2 + 0);
	rem(idx, mid, r, id * 2 + 1);
	pull(id);
	return;
}

pii get(int st, int en, int l = 0, int r = n, int id = 1){
	if(st >= r or en <= l)
		return MP(1000000, 0);
	if(st <= l and r <= en)
		return MP(min_seg[id], cnt_seg[id]);
	int mid = (l + r) >> 1;
	pii vall = get(st, en, l, mid, id * 2 + 0),
		valr = get(st, en, mid, r, id * 2 + 1);
	return MP(min(vall.L, valr.L), vall.R + valr.R);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		all.PB(a[i]);
	}
	cin >> q;
	for(int i = 0; i < q; i++){
		int fi, se;
		cin >> fi >> se;
		fi--, se--;	//make 0-base
		quer.PB(MP(MP(fi, se), i));
	}
	sort(quer.begin(), quer.end(), cmp);
	sort(all.begin(), all.end());
	all.resize(unique(all.begin(), all.end()) - all.begin());
	memset(adss, -1, sizeof adss);
	for(int i = 0; i < n; i++){
		int id = lower_bound(all.begin(), all.end(), a[i]) - all.begin();
		lasteq[i] = adss[id];
		//inja dorost beshe :/
		if(lasteq[i] == -1 or lasteq[lasteq[i]] == -1)
			mineq[i] = -1;
		else if(i - lasteq[i] != lasteq[i] - lasteq[lasteq[i]])
			mineq[i] = lasteq[i];
		else
			mineq[i] = mineq[lasteq[i]];
		adss[id] = i;
	}
	int p = 0;
	for(int i = 0; i < n; i++){
		if(lasteq[i] != -1)
			rem(lasteq[i]);
		add(i);
		while(p < q and quer[p].L.R <= i){
			pii x = get(quer[p].L.L, quer[p].L.R + 1);
			ans[quer[p].R] = x.R + (x.L >= quer[p].L.L);
			p++;
		}
	}
	for(int i = 0; i < q; i++)
		cout << ans[i] << '\n';
	return 0;
}