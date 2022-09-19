#include <bits/stdc++.h>
using namespace std;
 
// @author: pashka

int sign(int x) {
	if (x > 0) return 1;
	else return -1;
}

void solve_test() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	vector<int> s;
	s.push_back(a[0]);
	for (int i = 1; i < n; i++) {
		if (sign(a[i]) != sign(s.back())) {
			s.push_back(a[i]);
		} else {
			if (a[i] > s.back()) {
				s.back() = a[i];
			}
		}
	}
	long long ss = 0;
	for (int x : s) {
		ss += x;
	}
	cout << ss << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        solve_test();
    }
    return 0;
}