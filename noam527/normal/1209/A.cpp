#include <bits/stdc++.h>
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 4e18;
const int OO = 1;
const int OOO = 1;
using namespace std;

int n;
vector<int> a;

void work() {
	vector<int> b;
	for (int i = 0; i < a.size(); i++)
		if (a[i] % a[0] != 0) b.push_back(a[i]);
	a = b;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	a.resize(n);
	for (auto &i : a) cin >> i;
	sort(a.begin(), a.end());
	int ans = 0;
	while (a.size()) work(), ans++;
	cout << ans;
}