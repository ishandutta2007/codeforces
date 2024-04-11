#include <bits/stdc++.h>
using namespace std;
using ll=long long;
vector<ll> rows, cols;
const int MAX = 1000 + 5;
ll r[MAX], c[MAX];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m, C;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			cin >> C;
			r[i] += C;
			c[j] += C;
		}
 
	ll total, x, y;
	for (int i = 0; i < n + 1; i++) {
		total = 0;
		for (int j = 0; j < n; j++) {
			x = i * 4;
			y = j * 4 + 2;
			total += (x - y) * (x - y) * r[j];
		}
		rows.push_back(total);
	}
	for (int i = 0; i < m + 1; i++) {
		total = 0;
		for (int j = 0; j < m; j++) {
			x = i * 4;
			y = j * 4 + 2;
			total += (x - y) * (x - y) * c[j];
		}
		cols.push_back(total);
	}
	int szr = rows.size(), szc = cols.size();
	pair<ll, pair<int, int>> mn { 1 + 1e18, pair<int,int>(-1,-1)};
	for (int i = 0; i < szr; i++)
		for (int j = 0; j < szc; j++) {
			mn = min(mn, make_pair( rows[i] + cols[j], pair<int,int>( i, j ) ));
			}
	cout << mn.first << "\n" << mn.second.first << " " << mn.second.second;
}