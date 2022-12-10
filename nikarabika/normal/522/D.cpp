#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pie;
typedef pair<int, pie> piie;

#define PB push_back
#define MP make_pair
#define L first
#define R second

const int maxn = 5e5 + 85 - 69;
int seg[maxn * 4];
int a[maxn], ans[maxn], address[maxn], last[maxn];
vector<int> all;
piie q[maxn];
int n, m;

bool cmp(piie x, piie y){
	return x.R.R < y.R.R;
}

void sett(int idx, int val, int L = 1, int R = n + 1, int id = 1){
	if(R - L == 1){
		seg[id] = val;
		return;
	}
	int mid = (L + R) >> 1;
	if(idx < mid)
		sett(idx, val, L, mid, id * 2 + 0);
	else
		sett(idx, val, mid, R, id * 2 + 1);
	seg[id] = min(seg[id * 2 + 0], seg[id * 2 + 1]);
}

int get(int l, int r, int L = 1, int R = n + 1, int id = 1){
	if(l == L and r == R)
		return seg[id];
	int Min = 2e9,
		mid = (L + R) >> 1;
	if(l < mid)
		Min = min(Min, get(l, min(mid, r), L, mid, id * 2 + 0));
	if(r > mid)
		Min = min(Min, get(max(l, mid), r, mid, R, id * 2 + 1));
	return Min;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		all.PB(a[i]);
	}
	sort(all.begin(), all.end());
	all.resize(unique(all.begin(), all.end()) - all.begin());
	for(int i = 1; i <= n; i++){
		int id = lower_bound(all.begin(), all.end(), a[i]) - all.begin();
		last[i] = address[id];
		address[id] = i;
	}
	for(int i = 0; i < m; i++){
		cin >> q[i].R.L >> q[i].R.R;
		q[i].L = i;
	}
	sort(q, q + m, cmp);
	memset(seg, 127, sizeof seg);
	int p = 0;
	for(int i = 1; i <= n; i++){
		if(last[i])
			sett(last[i], i - last[i]);
		while(p < m and q[p].R.R == i){
			ans[q[p].L] = get(q[p].R.L, q[p].R.R + 1);
			if(ans[q[p].L] > 5 * n)
				ans[q[p].L] = -1;
			p++;
		}
	}
	for(int i = 0; i < m; i++)
		cout << ans[i] << '\n';
	return 0;
}