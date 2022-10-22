#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

double read() {
	int x; cin >> x;
	return x;
}

ll cr(ll a, ll b, ll c, ll d) {
	return a * d - b * c;
}

int n;
ll a[1000001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	vector<int> h = {0};
	for (int i = 1; i <= n; ++i) {
		a[i] = a[i - 1] + read();
		while(h.size() >= 2) {
			int x = h.end()[-2];
			int y = h.end()[-1];
			// check if (x, y, i) is cw
			if (cr(y - x, a[y] - a[x], i - y, a[i] - a[y]) <= 0)
				h.pop_back();
			else
				break;
		}
		h.push_back(i);
	}
	cout << fixed << setprecision(9);
	for (int i = 1; i < h.size(); ++i) {
		int x = h[i - 1], y = h[i];
		// x + 1 --> y
		double cur = (double)(a[y] - a[x]) / (y - x);
		for (int j = x + 1; j <= y; ++j)
			cout << cur << "\n";
	}
	return 0;
}