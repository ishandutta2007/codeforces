#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <list>
#include <bitset>
#include <set>
#include <queue>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int sz = 2e3 + 1, offset = 1e3;
int n, k;
bitset<sz> bs;
int dist[sz];

int main() {
	fast;
	cin >> n >> k;
	while (k--) {
		int tmp;
		cin >> tmp;
		bs[offset + tmp - n] = 1;
	}
	vector<int> a;
	for (int i = -1e3; i <= 1e3; i++) {
		dist[offset+i] = 1e9;
		if (bs[offset + i])a.pb(i);
	}
	queue<int> q;
	for (int x : a) {
		dist[offset + x] = 1;
		q.push(x);
	}
	while (!q.empty()) {
		int x = q.front(); q.pop();
		for (int y : a) {
			if (x + y <= 1e3&&x + y >= -1e3) {
				if (dist[x + y + offset] >= 1e8) {
					dist[x + y + offset] = dist[x + offset] + 1;
					q.push(x + y);
				}
			}
		}
	}
	if (dist[offset] < 1e8)cout << dist[offset] << '\n';
	else cout << -1 << '\n';
	return 0;
}