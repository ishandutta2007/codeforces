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

const int sz = 1e3;
int a[sz];
int n;

int main() {
	fast;
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		int prv = -1, tot = 0;
		foru(i, 0, n) {
			cin >> a[i];
			if (a[i] == 1) {
				if (prv != -1)tot += (i - prv - 1);
				prv = i;
			}
		}
		cout << tot << '\n';
	}
	return 0;
}