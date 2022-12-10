#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

#define MP make_pair
#define L first
#define R second

const int maxn = 3e5 + 85 - 69;
int segvec[25][maxn], pnt[maxn], b[maxn];
int n, m, ans;
pii a[maxn];

void make(int l = 0, int r = n, int id = 0){
	if(r - l == 1){
		segvec[id][l] = a[l].R;
		return;
	}
	int mid = (l + r) >> 1;
	make(l, mid, id + 1);
	make(mid, r, id + 1);
	merge(segvec[id + 1] + l, segvec[id + 1] + mid, segvec[id + 1] + mid, segvec[id + 1] + r, segvec[id] + l);
	return;
}

int get(int val, int st, int en, int l = 0, int r = n, int id = 0){
	if(st == l and en == r)
		return lower_bound(segvec[id] + l, segvec[id] + r, val) - segvec[id] - l;
	int mid = (l + r) >> 1,
		ret = 0;
	if(st < mid)
		ret += get(val, st, min(mid, en), l, mid, id + 1);
	if(en > mid)
		ret += get(val, max(st, mid), en, mid, r, id + 1);
	return ret;
}

int get(int x, int y){
	int id = upper_bound(b, b + n, x) - b;
	return (id < n) ? get(y, id, n) : 0;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		cin >> a[i].L >> a[i].R;
	sort(a, a + n);
	for(int i = 0; i < n; i++)
		b[i] = a[i].L;
	make();
	for(int i = 0; i < m; i++){
		int cnt;
		cin >> cnt;
		for(int j = 0; j < cnt; j++)
			cin >> pnt[j];
		ans = get(0, pnt[0]);
		for(int j = 1; j < cnt; j++)
			ans += get(pnt[j - 1], pnt[j]);
		ans += get(pnt[cnt - 1], 1e6 + 10);
		cout << n - ans << '\n';
	}
	return 0;
}