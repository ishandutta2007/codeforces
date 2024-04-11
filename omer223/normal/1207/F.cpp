#define _CRT_SECURE_NO_WARNINGS
#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define mp make_pair

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <bitset>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair <ll, ll> pll;
typedef long double ld;
typedef pair <ld, ld> pld;

const int sz = 5e5, rt = 710;
ll a[sz + 1], buckets[rt][rt];

int main() {
	//fast;
	int q;
	scanf("%d", &q);
	while (q--) {
		int type, i, v;
		ll x, y;
		scanf("%d", &type);
		switch (type) {
		case 1:
			scanf("%d %d", &i, &v);
			a[i] += v;
			for (int x = 1; x < rt; x++) buckets[x][i%x] += v;
			break;
		case 2:
			scanf("%lld %lld", &x, &y);
			ll ret = 0;
			if (x*x >= sz) {
				for (int j = y; j <= sz; j+=x)ret += a[j];
				printf("%lld\n", ret);
			}
			else printf("%lld\n", buckets[x][y]);
			break;
		}
	}
	return 0;
}