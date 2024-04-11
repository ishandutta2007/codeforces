//sobskdrbhvk
//remember...
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define smin(x, y) (x) = min((x), (y))
#define smax(x, y) (x) = max((x), (y))
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];
		sort(a, a + n);
		LL num = 1LL * (*min_element(a, a + n)) * (*max_element(a, a + n));
		vector<int> vec;
		for (LL i = 2; i * i <= num; i++)
			if (num % i == 0)
				vec.PB(i), vec.PB(num / i);
		sort(all(vec));
		vec.resize(unique(all(vec)) - vec.begin());
		if (n == vec.size()) {
			for (int i = 0; i < n; i++)
				if (vec[i] != a[i]) {
					cout << -1 << endl;
					goto hell;
				}
			cout << num << endl;
		}
		else
			cout << -1 << endl;
hell:;
	}
	return 0;
}