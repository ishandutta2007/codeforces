#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define mp make_pair

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <list>
#include <queue>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


int main() {
	fast;
	int t;
	cin >> t;
	while (t--) {
		int x, tot = 0;
		cin >> x;
		foru(i, 1, 10) {
			int tmp = i, cur = 1;
			while (tmp <= 10000) {
				tot += cur;
				if (tmp == x)break;
				tmp *= 10;
				tmp += i;
				cur++;
			}
			if (tmp == x)break;
		}
		cout << tot << '\n';
	}
	return 0;
}