//sobskdrbhvk
#include <bits/stdc++.h>

using namespace std;

//man am A _____ & a pair of Iz wayTn' 230u :)

const int maxn = 1e6 + 10;
int a[maxn];
int n, m;
bool laz[maxn * 4];

struct node{
	int increa, decrea, four, seven;
	node(){
		increa = decrea = four = seven = 0;
	}
} seg[maxn * 4];

void propagate(int, int, int);

node merge(node &left, node &right){
	node ret;
	ret.seven = left.seven + right.seven;
	ret.four = left.four + right.four;
	ret.increa = max(max(ret.seven, ret.four), max(left.increa + right.seven, left.four + right.increa));
	ret.decrea = max(max(ret.seven, ret.four), max(left.decrea + right.four, left.seven + right.decrea));
	return ret;
}

void build(int l = 0, int r = n, int id = 1){
	if(r - l == 1){
		seg[id].increa = 1;
		seg[id].decrea = 1;
		seg[id].seven = a[l];
		seg[id].four = !a[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(l, mid, id * 2 + 0);
	build(mid, r, id * 2 + 1);
	seg[id] = merge(seg[id * 2 + 0], seg[id * 2 + 1]);
	return;
}

void flip(int st, int en, int l = 0, int r = n, int id = 1){
	if(en <= l or st >= r)
		return;
	if(st <= l and r <= en){
		swap(seg[id].increa, seg[id].decrea);
		swap(seg[id].four, seg[id].seven);
		laz[id] = !laz[id];
		return;
	}
	int mid = (l + r) >> 1;
	propagate(l, r, id);
	flip(st, en, l, mid, id * 2 + 0);
	flip(st, en, mid, r, id * 2 + 1);
	seg[id] = merge(seg[id * 2 + 0], seg[id * 2 + 1]);
	return;
}

void propagate(int l, int r, int id){
	if(laz[id]){
		int mid = (l + r) >> 1;
		flip(l, mid, l, mid, id * 2 + 0);
		flip(mid, r, mid, r, id * 2 + 1);
		laz[id] = 0;
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		char c;
		cin >> c;
		a[i] = c != '4';
	}
	build();
	while(m--){
		string command;
		cin >> command;
		if(command == "count")
			cout << seg[1].increa << '\n';
		else{
			int fi, se;
			cin >> fi >> se;
			flip(fi - 1, se);
		}
	}
	return 0;
}