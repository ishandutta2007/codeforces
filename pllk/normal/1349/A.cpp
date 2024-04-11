#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int n;
int a[101010];
vector<int> v[202020];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) {
		for (int j = 2; j*j <= a[i]; j++) {
			if (a[i]%j != 0) continue;
			int c = 1;
			while (a[i]%j == 0) {
				a[i] /= j;
				c *= j;
			}
			v[j].push_back(c);
		}
		if (a[i] != 1) v[a[i]].push_back(a[i]);
	}
	ll u = 1;
	for (int i = 2; i <= 200000; i++) {
		sort(v[i].begin(),v[i].end());
		if (v[i].size() == n) {
			u *= v[i][1];
		} else if (v[i].size() == n-1) {
			u *= v[i][0];
		}
	}
	cout << u << "\n";
}