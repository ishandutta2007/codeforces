#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair
#define int long long

using namespace std;

int bl = 400;

int col[100001], over[100001], cnt[100001], n;

void build() {
	for (int i = n; i >= 1; --i) {
		if (col[i] + i >= min(n + 1, ((i / bl + 1) * bl)))  {
			if (col[i] + i > n)
				over[i] = i;
			else
				over[i] = col[i] + i;
			cnt[i] = 1;
			if (over[i] == i) cnt[i] = 0;
		} else {
			over[i] = over[i + col[i]];
			cnt[i] = cnt[col[i] + i] + 1;
		}
	}
// 	for(int i = 1; i <= n; i++) cout << cnt[i] << " " << over[i] << "\n";
// 	cout << "\n";
}

void fill(int pos, int b) {
	int r = min(n, (pos / bl + 1) * bl);
	col[pos] = b;
	for (int i = pos; i >= (pos / bl) * bl; --i) {
		if (col[i] + i >= r)  {
			if (col[i] + i > n)
				over[i] = i;
			else
				over[i] = col[i] + i;
			cnt[i] = 1;
			if (over[i] == i) cnt[i] = 0;
		} else {
			over[i] = over[i + col[i]];
			cnt[i] = cnt[col[i] + i] + 1;
		}
	}
}

int query(int& i) {
	int y = cnt[i] + 1;
	while (over[i] != i) {
		i = over[i];
		y += cnt[i];
	}
	return y;
}

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	cin >> n;
	int m; cin >> m;
	for (int i = 1; i <= n; ++i) cin >> col[i];
	build();
	for (int i = 0; i < m; ++i) {
		int type; cin >> type;
		if (type == 0) {
			int a; cin >> a;
			int b; cin >> b;
			fill(a, b);
		} else {
			int a; cin >> a;
			int r = query(a);
			cout << a << " " << r << "\n";
		}
	}
}