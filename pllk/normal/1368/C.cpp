#include <iostream>
#include <vector>

using namespace std;

int n;
vector<pair<int,int>> v;

void add(int y, int x) {
	v.push_back({y,x});
}

int main() {
	cin >> n;
	n++;
	add(0,0);
	int k = 0;
	while (n) {
		add(k,k+1);
		add(k,k+2);
		add(k+1,k);
		add(k+2,k);
		add(k+1,k+2);
		add(k+2,k+1);
		add(k+2,k+2);
		n--;
		k += 2;
	}
	cout << v.size() << "\n";
	for (auto u : v) cout << u.first << " " << u.second << "\n";
}