#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <iomanip>
#include <string>
#include <cmath>
#include <set>
using namespace std;
struct part {
	int left, right, elem;
};
struct cmp {
	bool operator() (const part &a, const part &b) const{
		int sizea = a.right - a.left, sizeb = b.right - b.left;
		if (sizea != sizeb) return sizea > sizeb;
		else return a.left < b.left;
	}
};
void solve() {
	int n, current;
	cin >> n;
	set <part, cmp> partset;
	vector <int> a(n, 0);
	part x; x.left = 0; x.right = n - 1; x.elem = (x.right + x.left) / 2;
	partset.insert(x);
	for (int i = 0; i < n; ++i) {
		current = (*partset.begin()).elem;
		a[current] = i + 1;
		if (current > 0 and a[current - 1] == 0) {
			part x; x.left = (*partset.begin()).left; x.right = current - 1; x.elem = (x.right + x.left) / 2;
			partset.insert(x);
		}
		if (current < n - 1 and a[current + 1] == 0) {
			part x; x.left = current + 1; x.right = (*partset.begin()).right; x.elem = (x.right + x.left) / 2;
			partset.insert(x);
		}
		partset.erase(partset.begin());
		
	}
	for (auto i : a) cout << i << " ";
	cout << endl;


}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(15);
	int t; cin >> t;
	while (t--) {
		solve();
	}

}