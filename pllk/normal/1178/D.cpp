#include <iostream>
#include <vector>

using namespace std;

bool prime(int x) {
	if (x < 2) return false;
	for (int i = 2; i < x; i++) {
		if (x%i == 0) return false;
	}
	return true;
}

int n;
vector<pair<int,int>> e;

int main() {
	cin >> n;
	for (int i = 2; i <= n; i++) {
		e.push_back({i-1,i});
	}
	e.push_back({1,n});
	int x = n;
	int a = 1;
	int b = n/2+1;
	while (!prime(x)) {
		x++;
		e.push_back({a,b});
		a++; b++;
	}
	cout << e.size() << "\n";
	for (auto u : e) {
		cout << u.first << " " << u.second << "\n";
	}
}