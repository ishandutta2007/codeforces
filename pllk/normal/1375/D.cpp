#include <iostream>
#include <vector>

using namespace std;

int n;
int a[1111];
int hh[1111];
int h;

int mex() {
	h++;
	for (int i = 1; i <= n; i++) hh[a[i]] = h;
	for (int i = 0; ; i++) if (hh[i] != h) return i;
}

int pos() {
	for (int i = 1; i <= n; i++) {
		if (a[i] != i-1) return i;
	}
}

bool ready() {
	for (int i = 2; i <= n; i++) if (a[i] < a[i-1]) return false;
	return true;
}

void print() {
	for (int i = 1; i <= n; i++) cout << a[i] << " ";
	cout << "\n";
}

vector<int> r;
void set(int k, int u) {
	a[k] = u;
	r.push_back(k);
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> a[i];
		r.clear();
		while (!ready()) {
			int m = mex();
			if (m != n) {
				set(m+1,m);
			} else {
				int p = pos();
				set(p,m);
			}
			//print();
		}
		cout << r.size() << "\n";
		for (auto x : r) cout << x << " ";
		cout << "\n";
	}
}