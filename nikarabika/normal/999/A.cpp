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
	int n, k;
	cin >> n >> k;
	int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	bool mark[n] = {0};
	for (int i = 0; i < n; i++)
		if (!i or mark[i - 1]) {
			if (a[i] <= k)
				mark[i] = true;
		}
		else
			break;
	for (int i = n - 1; i >= 0; i--)
		if (i == n - 1 or mark[i + 1]) {
			if (a[i] <= k)
				mark[i]++;
		}else
			break;
	cout << count(mark, mark + n, true) << endl;
	return 0;
}