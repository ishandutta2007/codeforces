#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<int, int> pie;

#define PB push_back
#define MP make_pair
#define L first
#define R second

const int maxn = 2e5 + 85 - 69;
int seg[maxn * 4];
vector<int> a, all;
vector<pie> sw;
LL ans = 0;
int n;

void add(int idx, int L = 0, int R = all.size(), int id = 1){
	seg[id]++;
	if(R - L == 1)
		return;
	int mid = (L + R) >> 1;
	if(idx < mid)
		add(idx, L, mid, id * 2 + 0);
	else
		add(idx, mid, R, id * 2 + 1);
}

LL get(int l, int r, int L = 0, int R = all.size(), int id = 1){
	if(l == L and r == R)
		return seg[id];
	int mid = (L + R) >> 1;
	LL sum = 0;
	if(l < mid)
		sum += get(l, min(mid, r), L, mid, id * 2 + 0);
	if(r > mid)
		sum += get(max(l, mid), r, mid, R, id * 2 + 1);
	return sum;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++){
		int fi, se;
		cin >> fi >> se;
		all.PB(fi);
		all.PB(se);
		sw.PB(MP(fi, se));
	}
	sort(all.begin(), all.end());
	all.resize(unique(all.begin(), all.end()) - all.begin());
	a = all;
	for(int i = 0; i < sw.size(); i++){
		int x = sw[i].L, y = sw[i].R;
		int id1 = lower_bound(all.begin(), all.end(), x) - all.begin(),
			id2 = lower_bound(all.begin(), all.end(), y) - all.begin();
		swap(a[id1], a[id2]);
	}
	for(int i = 0; i < a.size(); i++){
		int id = lower_bound(all.begin(), all.end(), a[i]) - all.begin();
		LL cnt = get(id, all.size());
		ans += cnt;
		if(i > id)
			ans += (all[i] - all[id] - (i - id)) * 1LL;
		else if(i < id)
			ans += (all[id] - all[i] - (id - i)) * 1LL;
		add(id);
	}
	cout << ans << endl;
	return 0;
}