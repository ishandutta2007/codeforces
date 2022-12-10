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
	vector<int> vec[2];
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		vec[x & 1].PB(x);
	}
	sort(all(vec[0]), greater<int>());
	sort(all(vec[1]), greater<int>());
	if (sz(vec[0]) < sz(vec[1]))
		swap(vec[0], vec[1]);
	int sum = 0;
	for (int i = sz(vec[1]) + 1; i < sz(vec[0]); i++)
		sum += vec[0][i];
	cout << sum << endl;
	return 0;
}