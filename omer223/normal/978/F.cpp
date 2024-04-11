#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define mp make_pair

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <bitset>
#include <list>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int sz = 2e5;
int n;
pll a[sz];
vector<int> adj[sz];
bitset<sz> bs;


int main() {
	fast;
	int k;
	cin >> n >> k;
	foru(i, 0, n) {
		cin >> a[i].first;
		a[i].second = i;
	}
	int x, y;
	foru(i, 0, k) {
		cin >> x >> y;
		x--; y--;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	sort(a, a + n);
	vector<int> res(n, 0);
	int cnt = 0;
	foru(i, 1, n) {
		if (a[i].first != a[i - 1].first) {
			ford(j, i - 1, 0) {
				if (a[j].first != a[i - 1].first)break;
				bs[a[j].second] = 1;
				cnt++;
			}
		}
		int tcnt = 0;
		for (int k : adj[a[i].second]) tcnt += bs[k];
		res[a[i].second] = cnt - tcnt;
	}
	foru(i, 0, n)cout << res[i] << " ";
	return 0;
}