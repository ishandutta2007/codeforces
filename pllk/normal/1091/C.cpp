#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int n;
vector<int> v;
vector<int> w;

void lol(int k, int t, int e) {
	if (k == v.size()) {
		w.push_back(t);
		return;
	}
	lol(k+1,t,0);
	if (k > 0 && v[k-1] == v[k] && !e) return;
	lol(k+1,t*v[k],1);
}

int main() {
	cin >> n;
	int u = n;
	for (int k = 2; k*k <= u; k++) {
		while (u%k == 0) {
			v.push_back(k);
			u /= k;
		}
	}
	if (u != 1) v.push_back(u);
	lol(0,1,1);
	vector<ll> r;
	for (auto x : w) {
		ll s = x;
		s = s*(s-1)/2;
		s = (n/x)*s;
		s += x;
		r.push_back(s);
	}
	sort(r.begin(),r.end());
	for (auto x : r) cout << x << " ";
	cout << "\n";
}