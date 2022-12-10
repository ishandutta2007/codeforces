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
LL sum[maxn * 4];
int Max[maxn * 4];
LL a[maxn];
int n, q;

void modify(int idx, LL val, int l = 0, int r = n, int id = 1){
	if(idx < l or idx >= r)
		return;
	if(r - l == 1){
		a[idx] = val;
		sum[id] = val;
		Max[id] = idx;
		return;
	}
	int mid = (l + r) >> 1;
	modify(idx, val, l, mid, id * 2 + 0);
	modify(idx, val, mid, r, id * 2 + 1);
	sum[id] = sum[id * 2 + 0] + sum[id * 2 + 1];
	Max[id] = (a[Max[id * 2 + 0]] > a[Max[id * 2 + 1]]) ? Max[id * 2 + 0] : Max[id * 2 + 1];
	return;
}

LL get_sum(int st, int en, int l = 0, int r = n, int id = 1){
	if(st >= r or en <= l)
		return 0;
	if(st <= l and r <= en)
		return sum[id];
	int mid = (l + r) >> 1;
	return get_sum(st, en, l, mid, id * 2 + 0)
		+ get_sum(st, en, mid, r, id * 2 + 1);
}

int get_max(int st, int en, int l = 0, int r = n, int id = 1){
	if(st >= r or en <= l)
		return st;
	if(st <= l and r <= en)
		return Max[id];
	int mid = (l + r) >> 1;
	int left = get_max(st, en, l, mid, id * 2 + 0);
	int right = get_max(st, en, mid, r, id * 2 + 1);
	return a[left] > a[right] ? left : right;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> q;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		modify(i, x);
	}
	while(q--){
		LL ty, fi, se, th;
		cin >> ty >> fi >> se;
		if(ty == 1)
			cout << get_sum(fi - 1, se) << '\n';
		else if(ty == 2){
			cin >> th;
			int id;
			while(a[id = get_max(fi - 1, se)] >= th)
				modify(id, a[id] %= th);
		}
		else
			modify(fi - 1, se);
	}
	return 0;
}