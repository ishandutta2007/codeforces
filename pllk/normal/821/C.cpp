#include <iostream>
#include <vector>
#include <set>

using namespace std;

int n;
vector<int> v;
set<int> z;
int c;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	int r = 1;
	for (int i = 0; i < 2*n; i++) {
		string s;
		cin >> s;
		if (s == "add") {
			int x;
			cin >> x;
			v.push_back(x);
		} else {
			if (v.size() == 0) {
				z.erase(z.begin());
				r++;
			} else {
				if (v.back() == r) {
					v.pop_back();
					r++;
				} else {
					for (auto u : v) z.insert(u);
					v.clear();
					r++;
					c++;
				}
			}
		}
	}
	cout << c << "\n";
}