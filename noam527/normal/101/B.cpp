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

int n, m;
vector<pair<int, int>> a;
int dp[200005] = {}, Sdp[200005] = {};

bool cmp(pair<int, int> aa, pair<int, int> bb) {
	return aa.second < bb.second;
}

int main() {
	fast;
	cin >> n >> m;
	a.resize(m);

	map<int, int> comp;
	for (auto &i : a) cin >> i.first >> i.second, comp[i.first] = comp[i.second] = 0;
	comp[n] = comp[0] = 0;

	int nxt = 1;
	for (auto &i : comp) i.second = nxt++;
	for (auto &i : a) i.first = comp[i.first], i.second = comp[i.second];
	sort(a.begin(), a.end(), cmp);

	dp[1] = Sdp[1] = 1;
	nxt = 2;
	for (auto &i : a) {
		while (nxt < i.second) {
			Sdp[nxt] = (Sdp[nxt - 1] + dp[nxt]) % md;
			nxt++;
		}
		dp[i.second] = ((dp[i.second] + Sdp[i.second - 1] - Sdp[i.first - 1]) % md + md) % md;
		Sdp[i.second] = (Sdp[i.second - 1] + dp[i.second]) % md;
	}
	finish(dp[comp[n]]);
}