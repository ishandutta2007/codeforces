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
#include <intrin.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int sz = 1e6;
int a[sz], n;
int cnt[2];

int main() {
	fast;
	int q;
	cin >> n >> q;
	foru(i, 0, n) {
		cin >> a[i];
		cnt[a[i]]++;
	}
	while (q--) {
		int yp;
		cin >> yp;
		switch (yp) {
		case 1:
			int i;
			cin >> i;
			i--;
			cnt[a[i]]--;
			a[i] = 1 - a[i];
			cnt[a[i]]++;
			break;
		case 2:
			int k;
			cin >> k;
			if (cnt[1] >= k)cout << 1 << '\n';
			else cout << 0 << '\n';
			break;
		}
	}
	return 0;
}