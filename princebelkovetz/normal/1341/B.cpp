#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;
const unsigned long long nmax = 205000;
unsigned long long a[nmax];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(15);
	long long t, n, k, ans, f, cur, l, r;
	cin >> t;
	while (t--) {
		vector <long long> b;
		cin >> n >> k;
		cin >> a[0];
		cin >> a[1];
		cur = 0;
		f = 0;
		for (long long i = 2; i < n; ++i) {
			cin >> a[i];
			if (a[i - 2] < a[i - 1] and a[i - 1] > a[i]) {
				b.push_back(i-1);
			}
		}
		l = 0;
		ans = 0;
		if (b.size() > 1) {
			for (long long i = 0; i < b.size(); ++i) {
				if (b[i] - b[l] > k - 3) {
					l++;
				}
				if (i - l + 1 > f) {
					f = i - l + 1;
					ans = b[i];
				}
			}

			cout << f + 1 << " " << max(cur + 1, ans - k + 3) << endl;
		}
		else if (b.size() == 1){
			cout << 2 << " " << max(cur + 1, b[0] - k + 3) << endl;
		}
		else {
			cout << 1 << " " << 1 << endl;
		}


	}

}