#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair
#define int long long

using namespace std;

int bl = 400;

int col[100001], bcol[300], consistent[300], bsum[300], badd[300], su[100001];

void fillleft(int r, int x) {
	if (consistent[r / bl]) {
		consistent[r / bl] = 0;
		for (int i = (r / bl) * bl, c = bcol[r / bl]; i < (r / bl + 1) * bl; ++i)
			col[i] = c;
	}
	for (int i = (r / bl) * bl; i < r; ++i) {
		int v = abs(x - col[i]);
		su[i] += v;
		bsum[r / bl] += v;
		col[i] = x;
	}
}

void fillblock(int i, int x) {
	if (consistent[i]) {
		badd[i] += abs(bcol[i] - x);
		bcol[i] = x;
		return; 
	} 
	for (int j = i * bl; j < (i + 1) * bl; ++j) {
		int v = abs(col[j] - x);
		bsum[i] += v;
		su[j] += v;
	}
	bcol[i] = x;
	consistent[i] = 1;
	if (i == 100) {
	}
}

void fillright(int l, int x) {
	if (l % bl == 0) { fillblock(l / bl, x); return; }
	if (consistent[l / bl]) {
		consistent[l / bl] = 0;
		for (int i = (l / bl) * bl, c = bcol[l / bl]; i < (l / bl + 1) * bl; ++i) 
			col[i] = c;
	}
	for (int i = l; i < (l / bl + 1) * bl; ++i) {
		int v = abs(col[i] - x);
		su[i] += v;
		bsum[l / bl] += v;
		col[i] = x;
	}
}


void fillmiddle(int l, int r, int x) {
	if (consistent[l / bl]) {
		consistent[l / bl] = 0;
		for (int i = (l / bl) * bl, c = bcol[l / bl]; i < (l / bl + 1) * bl; ++i) 
			col[i] = c;
	} 
	for (int i = l; i < r; ++i) {
		int v = abs(col[i] - x);
		bsum[l / bl] += v;
		su[i] += v;
		col[i] = x;
	}
}


int queryleft(int r) {
	if (r % bl == 0) return 0;
	int y = (r - (r / bl) * bl) * badd[r / bl];
	for (int i = (r / bl) * bl; i < r; ++i)
		y += su[i];
	return y;
}

int queryblock(int i) {
	return (badd[i] * (bl) + bsum[i]);
}

int queryright(int l) {
	if (l % bl == 0) return queryblock(l / bl);
	int y = ((l / bl + 1) * bl - l) * badd[l / bl];
	for (int i = l; i < (l / bl + 1) * bl; ++i)
		y += su[i];
	return y;
}


int querymiddle(int l, int r) {
	int y = (r - l) * badd[l / bl];
	for (int i = l; i < r; ++i)
		y += su[i];
	return y;
}

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	int n; cin >> n;
	for (int i = 1; i <= n; ++i)
		col[i] = i;
	int m; cin >> m;
	for (int i = 0; i < m; ++i) {
		int type; cin >> type;
		if (type == 1) {
			int l; cin >> l;
			int r; cin >> r; r++;
			int x; cin >> x;
			//update(l to r, x)
			if (r >= ((l / bl) + 1) * bl) {
				fillmiddle(l, (l / bl + 1) * bl, x);
				for (int i = l / bl + 1; i < r / bl; ++i)
					fillblock(i, x);
				fillmiddle((r / bl) * bl, r, x);
			} else {
				fillmiddle(l, r, x);
			}
		} else {
			int l; cin >> l;
			int r; cin >> r; r++;
			//query(l to r)
			int y;
			if (r >= (l / bl + 1) * bl) {
				y = querymiddle(l, (l / bl + 1) * bl);
				for (int i = l / bl + 1; i < r / bl; ++i)
					y += queryblock(i);
				y += querymiddle((r / bl) * bl, r);
			} else {
				y = querymiddle(l, r);
			}
			cout << y << "\n";
		}
	}
}