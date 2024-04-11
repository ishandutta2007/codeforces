#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
#define endl '\n'
#define fast ios::sync_with_stdio(0), cin.tie(0)
#define debug cout << "ok" << endl
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7, inf = 1e9 + 7;
const ll hs = 199;
const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

int n, k;
string s, t;

int main() {
	fast;
	cin >> s >> k;
	n = s.size();
	int C[256] = {}, ban[256] = {};
	for (auto &i : s) C[i]++;
	vector<pair<int, int>> A;
	for (int i = 0; i < 256; i++)
		if (C[i]) A.push_back({ C[i], i });
	sort(A.begin(), A.end());
	reverse(A.begin(), A.end());
	while (A.size() && k >= A.back().first) {
		ban[A.back().second] = 1;
		k -= A.back().first;
		A.pop_back();
	}
	for (auto &i : s)
		if (!ban[i]) t.push_back(i);
	cout << A.size() << endl << t << endl;
}