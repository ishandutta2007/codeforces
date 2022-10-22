#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
void solve() {
	int n, t; cin >> n;
	if (n < 4) cout << -1 << endl;
	else if (n == 4) cout << "3 1 4 2\n";
	else {
		for (int i = 2 - n % 2; i <= n; i += 2) {
			cout << i << " ";
			t = i;
		}
		t -= 3; cout << t << " "; t += 2; cout << t << " "; t -= 4;
		for (int i = t; i >= 1; i -= 2) {
			cout << i << " ";
		}

		cout << endl;
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) {
		solve();
	}

}