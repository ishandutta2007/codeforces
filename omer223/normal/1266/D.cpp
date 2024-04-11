#define MOD 998244353
#define fast ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define mp make_pair
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <queue>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int sz = 3e5;
int n, m;
ll in[sz], out[sz];

int main() {
	cin >> n >> m;
	int a, b, v;
	foru(i, 0, m) {
		cin >> a >> b >> v; a--; b--;
		in[b] += v;
		out[a] += v;
	}
	priority_queue<pll> pos, neg;
	foru(i, 0, n) {
		if (in[i] > out[i])pos.push(mp(in[i] - out[i], i));
		else if (in[i] < out[i])neg.push(mp(out[i] - in[i], i));
	}
	vector<pair<pii, ll>> vec;
	while (!pos.empty() && !neg.empty()) {
		auto ps = pos.top(); pos.pop();
		auto ng = neg.top(); neg.pop();
		if (ps.first > ng.first) {
			vec.pb(mp(mp(ng.second, ps.second), ng.first));
			pos.push(mp(ps.first - ng.first, ps.second));
		}
		else if (ps.first < ng.first){
			vec.pb(mp(mp(ng.second, ps.second), ps.first));
			neg.push(mp(ng.first - ps.first, ng.second));
		}
		else {
			vec.pb(mp(mp(ng.second, ps.second), ps.first));
		}
	}
	cout << vec.size() << endl;
	for (auto x : vec)cout << x.first.first + 1 << " " << x.first.second + 1 << " " << x.second << endl;
	return 0;
}