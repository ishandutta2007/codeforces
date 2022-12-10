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
	int n;
	cin >> n;
	int a[n];
	multiset<int> s;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		s.insert(x);
	}
	for (int i = 0; i < n; i++) {
		int best = (n - a[i]) % n;
		auto it = s.lower_bound(best);
		if (it == s.end())
			it = s.begin();
		cout << (a[i] + *it) % n << ' ';
		s.erase(it);
	}
	cout << endl;
	return 0;
}