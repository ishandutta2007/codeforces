#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<LL, int> pie;

#define PB push_back
#define MP make_pair
#define L first
#define R second

const int maxn = 1e5 + 85 - 69;
LL a[maxn], d;
pie seg[maxn * 4];
int n, par[maxn];
vector<pie> all;

pie get(int l, int r, int L = 0, int R = n, int id = 1){
	if(l == L and r == R)
		return seg[id];
	int mid = (L + R) >> 1;
	pie ret1 = MP(-1, -1), ret2 = ret1;
	if(l < mid)
		ret1 = get(l, min(mid, r), L, mid, id * 2 + 0);
	if(r > mid)
		ret2 = get(max(l, mid), r, mid, R, id * 2 + 1);
	return max(ret1, ret2);
}

void sett(LL val, int idx, int L = 0, int R = n, int id = 1){
	if(R - L == 1){
		seg[id] = MP(val, idx);
		return;
	}
	int mid = (L + R) >> 1;
	if(idx < mid)
		sett(val, idx, L, mid, id * 2 + 0);
	else
		sett(val, idx, mid, R, id * 2 + 1);
	seg[id] = max(seg[id * 2 + 0], seg[id * 2 + 1]);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	/*int ty;
	cin >> n;
	while(cin >> ty >> par[0] >> d){
		if(ty == 1)
			sett(d, par[0]);
		else
			cout << get(par[0], d).L << endl;
	}*/
	cin >> n >> d;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		all.PB(MP(a[i], i));
	}
	sort(all.begin(), all.end());
	for(int i = n; i > 0; i--){
		int id = lower_bound(all.begin(), all.end(), MP(a[i], i)) - all.begin(),
			id1 = lower_bound(all.begin(), all.end(), MP(a[i] - d, 1000 * 1000 * 1000)) - all.begin(),
			id2 = lower_bound(all.begin(), all.end(), MP(a[i] + d, 0)) - all.begin();
		pie fid1 = MP(0, 0);
		pie fid2 = fid1;
		if(id1 > 0 and id1 <= n)
			fid1 = get(0, id1);
		if(id2 >= 0 and id2 < n)
			fid2 = get(id2, n);
		if(fid1.L > fid2.L and fid1.L != 0)
			par[i] = all[fid1.R].R;
		else if(fid2.L != 0)
			par[i] = all[fid2.R].R;
		sett(max(fid1.L, fid2.L) + 1, id);
	}
	vector<int> ans;
	int x = all[seg[1].R].R;
	while(x != 0){
		ans.PB(x);
		x = par[x];
	}
	cout << ans.size() << '\n';
	for(int i = 0; i < ans.size(); i++)
		cout << ans[i] << ' ';
	cout << endl;
	
	return 0;
}