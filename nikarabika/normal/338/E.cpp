#include <bits/stdc++.h>

using namespace std;

//Manam A _____ & an O_o waiting 230u :)

const int maxn = 1.5e5 + 10;
int seg[maxn * 4], Min[maxn * 4];
int a[maxn], b[maxn];
int n, len, h;

void add(int val, int st, int en, int l = 0, int r = len, int id = 1){
	if(st == l and en == r){
		seg[id] += val;
		Min[id] += val;
		return;
	}
	int mid = (l + r) >> 1;
	if(st < mid)
		add(val, st, min(mid, en), l, mid, id * 2 + 0);
	if(en > mid)
		add(val, max(st, mid), en, mid, r, id * 2 + 1);
	Min[id] = min(Min[id * 2 + 0], Min[id * 2 + 1]) + seg[id];
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> len >> h;
	for(int i = 0; i < len; i++)
		cin >> b[i];
	for(int i = 0; i < n; i++)
		cin >> a[i];
	sort(b, b + len);
	for(int i = 0; i < len; i++)
		add(-(i + 1), i, i + 1);
	for(int i = 0; i < len; i++){
		int id = lower_bound(b, b + len, h - a[i]) - b;
		if(id != len)
			add(+1, id, len);
	}
	int ans = (Min[1] >= 0);
	for(int i = len; i < n; i++){
		int id = lower_bound(b, b + len, h - a[i]) - b;
		if(id != len)
			add(+1, id, len);
		id = lower_bound(b, b + len, h - a[i - len]) - b;
		if(id != len)
			add(-1, id, len);
		ans += (Min[1] >= 0);
	}
	cout << ans << endl;
	return 0;
}