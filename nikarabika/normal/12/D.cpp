#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define smax(x, y) (x) = max((x), (y))
#define sz(x) ((int)(x).size())

const int maxn = 5e5 + 85 - 69;
vector<int> alll, allrr;
int seg[maxn * 4];
piii a[maxn];
vector<pii> vec[maxn];
int n, ans;

template <class T>
void compre(vector <T> &v){
	sort(v.begin(), v.end());
	v.resize(unique(v.begin(), v.end()) - v.begin());
	return;
}

int get(int st, int en, int l = 0, int r = sz(alll), int id = 1){
	if(en <= l or r <= st)
		return -1;
	if(st <= l and r <= en)
		return seg[id];
	int mid = (l + r) >> 1;
	return max(get(st, en, l, mid, id * 2 + 0),
			get(st, en, mid, r, id * 2 + 1));
}

void modify(int idx, int val, int l = 0, int r = sz(alll), int id = 1){
	if(idx < l or r <= idx)
		return;
	if(r - l == 1){
		smax(seg[id], val);
		return;
	}
	int mid = (l + r) >> 1;
	modify(idx, val, l, mid, id * 2 + 0);
	modify(idx, val, mid, r, id * 2 + 1);
	seg[id] = max(seg[id * 2 + 0],
			seg[id * 2 + 1]);
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i].L;
		alll.PB(a[i].L);
	}
	for(int i = 0; i < n; i++)
		cin >> a[i].R.L;
	for(int i = 0; i < n; i++){
		cin >> a[i].R.R;
		allrr.PB(a[i].R.R);
	}
	compre(alll);
	compre(allrr);
	for(int i = 0; i < n; i++){
		int id = lower_bound(allrr.begin(), allrr.end(), a[i].R.R) - allrr.begin();
		vec[id].PB(MP(a[i].L, a[i].R.L));
	}
	memset(seg, -1, sizeof seg);
	for(int i = sz(allrr) - 1; i >= 0; i--){
		for(int j = 0; j < sz(vec[i]); j++){
			int id = lower_bound(alll.begin(), alll.end(), vec[i][j].L) - alll.begin();
			ans += (get(id + 1, sz(alll)) > vec[i][j].R);
		}
		for(int j = 0; j < sz(vec[i]); j++){
			int id = lower_bound(alll.begin(), alll.end(), vec[i][j].L) - alll.begin();
			modify(id, vec[i][j].R);
		}
	}
	cout << ans << endl;
	return 0;
}