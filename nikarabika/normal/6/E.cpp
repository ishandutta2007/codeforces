#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pie;

#define PB push_back
#define MP make_pair
#define L first
#define R second

const int maxn = 1000 * 100 + 85 - 69;
int h[maxn];
pie seg[maxn * 4];
int n, k;
vector<pie> ans;

pie kos(pie x, pie y){
	return MP(max(x.L, y.L), min(x.R, y.R));
}

void make(int L = 0, int R = n, int id = 1){
	if(R - L == 1){
		seg[id] = MP(h[L], h[L]);
		return;
	}
	int mid = (L + R) >> 1;
	make(L, mid, id * 2 + 0);
	make(mid, R, id * 2 + 1);
	seg[id] = kos(seg[id * 2 + 0], seg[id * 2 + 1]);
}

pie get(int l, int r, int L = 0, int R = n, int id = 1){
	if(l == L and r == R)
		return seg[id];
	pie ret = MP(-1000 * 1000 * 10, +1000 * 1000 * 10);
	int mid = (L + R) >> 1;
	if(l < mid)
		ret = kos(ret, get(l, min(mid, r), L, mid, id * 2 + 0));
	if(r > mid)
		ret = kos(ret, get(max(l, mid), r, mid, R, id * 2 + 1));
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ans.reserve(maxn);
	cin >> n >> k;
	for(int i = 0; i < n; i++)
		cin >> h[i];
	make();
	int p = 0, maxl = -1;
	for(int i = 0; i < n; i++){
		while(p < i){
			pie x = get(p, i + 1);
			if(x.L - x.R <= k)
				break;
			p++;
		}
		if(i - p + 1 > maxl){
			maxl = i - p + 1;
			ans.clear();
		}
		if(i - p + 1 == maxl)
			ans.PB(MP(p + 1, i + 1));
	}
	cout << maxl << ' ' << ans.size() << '\n';
	for(int i = 0; i < ans.size(); i++)
		cout << ans[i].L << ' ' << ans[i].R << '\n';
	return 0;
}