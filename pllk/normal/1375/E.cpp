#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int a[1111];

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	vector<pair<int,int>> r;
	for (int i = 1; i <= n; i++) {
		vector<pair<int,int>> v;
		for (int j = i+1; j <= n; j++) {
			if (a[i] > a[j]) {
				v.push_back({a[j],j});
			}
		}
		sort(v.rbegin(),v.rend());
		for (auto x : v) r.push_back({i,x.second});
	}
	cout << r.size() << "\n";
	for (auto x : r) cout << x.first << " " << x.second << "\n";
}