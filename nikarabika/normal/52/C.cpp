#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

const int maxn = 2e5 + 85 - 69;
LL seg[maxn * 4], laz[maxn * 4];
LL a[maxn];
int n, m;

void make(int L = 0, int R = n, int id = 1){
	if(R - L == 1){
		seg[id] = a[L];
		return;
	}
	int mid = (L + R) >> 1;
	make(L, mid, id * 2 + 0);
	make(mid, R, id * 2 + 1);
	seg[id] = min(seg[id * 2 + 0], seg[id * 2 + 1]);
}

void add(LL val, int l, int r, int L = 0, int R = n, int id = 1){
	if(l == L and r == R){
		seg[id] += val;
		laz[id] += val;
		return;
	}
	int mid = (L + R) >> 1;
	if(laz[id]){
		add(laz[id], L, mid, L, mid, id * 2 + 0);
		add(laz[id], mid, R, mid, R, id * 2 + 1);
		laz[id] = 0;
	}
	if(l < mid)
		add(val, l, min(mid, r), L, mid, id * 2 + 0);
	if(r > mid)
		add(val, max(l, mid), r, mid, R, id * 2 + 1);
	seg[id] = min(seg[id * 2 + 0], seg[id * 2 + 1]);
}

LL get(int l, int r, int L = 0, int R = n, int id = 1){
	if(l == L and r == R)
		return seg[id];
	int mid = (L + R) >> 1;
	LL Min = 2e18;
	if(laz[id]){
		add(laz[id], L, mid, L, mid, id * 2 + 0);
		add(laz[id], mid, R, mid, R, id * 2 + 1);
		laz[id] = 0;
	}
	if(l < mid)
		Min = min(Min, get(l, min(mid, r), L, mid, id * 2 + 0));
	if(r > mid)
		Min = min(Min, get(max(l, mid), r, mid, R, id * 2 + 1));
	return Min;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	LL ghoorghoori = 0;
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	make();
	cin >> m;
	string s;
	getline(cin, s);
	///*
	while(m--){
		getline(cin, s);
		LL x[3] = {0, 0, 0};
		int c = 0, sign = +1;
		for(int i = 0; i < s.size(); i++){
			if(s[i] == ' '){
				sign = +1;
				c++;
				continue;
			}
			if(s[i] == '-'){
				sign = -1;
				continue;
			}
			x[c] = (x[c] * 10) + (s[i] - '0') * sign;
		}
		int fi = x[0], se = x[1];
		if(c == 1){
			if(fi <= se)
				cout << get(fi, se + 1) + ghoorghoori << '\n';
			else
				cout << min(get(0, se + 1), get(fi, n)) + ghoorghoori << '\n';
		}
		else{
			LL val = x[2];
			if(fi > se){
				add(val, 0, se + 1);
				add(val, fi, n);
			}
			else
				add(val, fi, se + 1);
		}
	}
	/*
	int ty, fi, se, val;
	while(m-- and cin >> ty >> fi >> se){
		if(ty == 1){
			if(fi <= se)
				cout << get(fi, se + 1) << endl;
			else
				cout << min(get(0, se + 1), get(fi, n)) << endl;
		}
		else{
			cin >> val;
			if(fi > se){
				add(val, 0, se + 1);
				add(val, fi, n);
			}
			else
				add(val, fi, se + 1);
		}
	}
	*/

	return 0;
}