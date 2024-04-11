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
	LL cnt[2] = {0LL};
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		cnt[i & 1] += x / 2;
		cnt[i & 1 ^ 1] += x - x / 2;
	}
	cout << min(cnt[0], cnt[1]) << endl;
	return 0;
}