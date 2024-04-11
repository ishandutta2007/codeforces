#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
#define endl '\n'
#define debug cout << "ok" << endl
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7, inf = 1e9 + 7;
const ll hs = 199;
const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

int n;
vector<int> a, pos;
vector<int> b;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	a.resize(n);
	b.resize(n);
	pos.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		pos[a[i] - 1] = i;
	}
	b[n - 1] = 0;
	int p;
	for (int i = n - 2; i >= 0; i--) {
		p = pos[i];
		b[i] = 0;
		for (int j = p + i + 1; j < n; j += (i + 1))
			if (a[p] < a[j] && b[a[j] - 1] == 0)
				b[i] = 1;
		for (int j = p - i - 1; j >= 0; j -= (i + 1))
			if (a[p] < a[j] && b[a[j] - 1] == 0)
				b[i] = 1;
	}
	for (auto &i : a)
		if (b[i - 1])
			cout << "A";
		else
			cout << "B";
}