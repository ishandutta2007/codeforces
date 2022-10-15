#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

typedef long long ll;

ll a, b;
vector<ll> v;

void haku(ll x) {
	if (x > b) return;
	v.push_back(x);
	if (x == b) {
		cout << "YES\n";
		cout << v.size() << "\n";
		for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
		cout << "\n";
		exit(0);
	}
	haku(2*x);
	haku(10*x+1);
	v.pop_back();
}

int main() {
	cin >> a >> b;
	haku(a);
	cout << "NO\n";
}