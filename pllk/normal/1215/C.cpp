#include <iostream>
#include <vector>

using namespace std;

int n;
string x, y;
vector<pair<int,int>> v;

int main() {
	cin >> n;
	cin >> x >> y;
	int k = -1;
	for (int i = 0; i < n; i++) {
		if (x[i] == 'a' && y[i] == 'b') {
			if (k == -1) {
				k = i;
			} else {
				v.push_back({k,i});
				y[k] = 'a';
				x[i] = 'b';
				k = -1;
			}
		}
	}
	k = -1;
	for (int i = 0; i < n; i++) {
		if (x[i] == 'b' && y[i] == 'a') {
			if (k == -1) {
				k = i;
			} else {
				v.push_back({k,i});
				y[k] = 'b';
				x[i] = 'a';
				k = -1;
			}
		}
	}
	int k1 = -1, k2 = -1;
	for (int i = 0; i < n; i++) {
		if (x[i] == 'a' && y[i] == 'b') k1 = i;
		if (x[i] == 'b' && y[i] == 'a') k2 = i;
	}
	if (k1 == -1 && k2 == -1) {
	} else if (k1 == -1 || k2 == -1) {
		cout << "-1\n";
		return 0;
	} else {
		v.push_back({k1,k1});
		v.push_back({k1,k2});
	}
	cout << v.size() << "\n";
	for (auto x : v) cout << x.first+1 << " " << x.second+1 << "\n";
}