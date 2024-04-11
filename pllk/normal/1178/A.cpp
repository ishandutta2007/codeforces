#include <iostream>
#include <vector>

using namespace std;

int n;
int a[111];
int s;
vector<int> v;

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		s += a[i];
	}
	v.push_back(1);
	int u = a[1];
	for (int i = 2; i <= n; i++) {
		if (a[1] >= a[i]*2) {
			v.push_back(i);
			u += a[i];
		}
	}
	if (u >= s/2+1) {
		cout << v.size() << "\n";
		for (auto x : v) cout << x << " ";
		cout << "\n";
	} else {
		cout << "0\n";
	}
}