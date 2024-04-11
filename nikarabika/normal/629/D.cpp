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

const int maxn = 100 * 1000 + 85 - 69;
LL seg[maxn * 4];
LL a[maxn];
vector<LL> all;
int n;

void modify(int idx, LL val, int l = 0, int r = sz(all), int id = 1){
	if(idx < l or idx >= r)
		return;
	if(r - l == 1){
		seg[id] = val;
		return;
	}
	int mid = (l + r) >> 1;
	modify(idx, val, l, mid, id * 2 + 0);
	modify(idx, val, mid, r, id * 2 + 1);
	seg[id] = max(seg[id * 2 + 0], seg[id * 2 + 1]);
	return;
}

LL get(int st, int en, int l = 0, int r = sz(all), int id = 1){
	if(st >= r or en <= l)
		return 0;
	if(st <= l and r <= en)
		return seg[id];
	int mid = (l + r) >> 1;
	return max(get(st, en, l, mid, id * 2 + 0),
			get(st, en, mid, r, id * 2 + 1));
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	LD PI = atan(1) * 4;
	cin >> n;
	for(int i = 0; i < n; i++){
		LL r, h;
		cin >> r >> h;
		a[i] = r * r * h;
		all.PB(a[i]);
	}
	sort(all(all));
	all.resize(unique(all(all)) - all.begin());
	for(int i = 0; i < n; i++)
		a[i] = lower_bound(all(all), a[i]) - all.begin();
	for(int i = 0; i < n; i++)
		modify(a[i], get(0, a[i]) + all[a[i]]);
	cout.precision(15);
	cout << fixed << seg[1] * PI << endl;
	return 0;
}