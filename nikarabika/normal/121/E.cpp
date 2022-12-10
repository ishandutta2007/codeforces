#include <bits/stdc++.h>

using namespace std;

#define PB push_back

#undef minus
#define minus Minus

const int maxn = 1e5 + 85 - 69, maxval = 10001;
int minused[maxn * 4];
int a[maxn], level[maxn];
vector<int> luck;
int n, q;

struct node{
	int Min, Cnt, ID;
} seg[maxn * 4], khonsa;

bool islucky(int x){
	while(x){
		if(x % 10 != 4 and x % 10 != 7)
			return false;
		x /= 10;
	}
	return true;
}

node merge(node le, node ri){
	if(le.Min < ri.Min)
		return le;
	if(le.Min > ri.Min)
		return ri;
	node ret;
	ret.Min = le.Min;
	ret.Cnt = le.Cnt + ri.Cnt;
	ret.ID = le.ID;
	return ret;
}

void build(int l = 0, int r = n, int id = 1){
	if(r - l == 1){
		seg[id].Min = a[l];
		seg[id].Cnt = 1;
		seg[id].ID = l;
		return;
	}
	int mid = (l + r) >> 1;
	build(l, mid, id * 2 + 0);
	build(mid, r, id * 2 + 1);
	seg[id] = merge(seg[id * 2 + 0], seg[id * 2 + 1]);
	return;
}

void modify(int idx, int val, int l = 0, int r = n, int id = 1){
	if(idx < l or idx >= r)
		return;
	if(r - l == 1){
		seg[id].Min = val;
		seg[id].Cnt = 1;
		seg[id].ID = l;
		return;
	}
	int mid = (l + r) >> 1;
	modify(idx, val + minused[id], l, mid, id * 2 + 0);
	modify(idx, val + minused[id], mid, r, id * 2 + 1);
	seg[id] = merge(seg[id * 2 + 0], seg[id * 2 + 1]);
	seg[id].Min -= minused[id];
	return;
}

void minus(int val, int st, int en, int l = 0, int r = n, int id = 1){
	if(st >= r or en <= l)
		return;
	if(st <= l and r <= en){
		minused[id] += val;
		seg[id].Min -= val;
		return;
	}
	int mid = (l + r) >> 1;
	minus(val, st, en, l, mid, id * 2 + 0);
	minus(val, st, en, mid, r, id * 2 + 1);
	seg[id] = merge(seg[id * 2 + 0], seg[id * 2 + 1]);
	seg[id].Min -= minused[id];
	return;
}

node get(int st, int en, int l = 0, int r = n, int id = 1){
	if(st >= r or en <= l)
		return khonsa;
	if(st <= l and r <= en)
		return seg[id];
	int mid = (l + r) >> 1;
	node ret = merge(get(st, en, l, mid, id * 2 + 0),
			get(st, en, mid, r, id * 2 + 1));
	ret.Min -= minused[id];
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	khonsa.Min = 1000 * 1000;
	for(int i = 1; i < maxval; i++)
		if(islucky(i))
			luck.PB(i);
	luck.PB(1e5);
	cin >> n >> q;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		level[i] = lower_bound(luck.begin(), luck.end(), a[i]) - luck.begin();
		a[i] = luck[level[i]] - a[i];
	}
	build();
	while(q--){
		string ty;
		int fi, se;
		cin >> ty >> fi >> se;
		fi--;
		if(ty == "count"){
			node ans = get(fi, se);
			if(ans.Min == 0)
				cout << ans.Cnt << '\n';
			else
				cout << 0 << '\n';
		}
		else{
			int val;
			cin >> val;
			minus(val, fi, se);
			while(seg[1].Min < 0){
				int id = seg[1].ID;
				int valid = seg[1].Min;
				while(valid < 0){
					valid += luck[level[id] + 1] - luck[level[id]];
					level[id]++;
				}
				modify(id, valid);
			}
		}
	}
	return 0;
}