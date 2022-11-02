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

const int sz = 1e6 + 5;
int n, m, k;
bitset<sz> block;
ll p[sz], amt[sz], lst[sz];

void input() {
	scanf("%d %d %d", &n, &m, &k);
	int tmp;
	foru(i, 0, m) {
		scanf("%d", &tmp);
		block[tmp] = 1;
	}
	foru(i, 0, k) scanf("%d", &p[i + 1]);
	int cur = -1;
	foru(i, 0, n) {
		if (!block[i])cur = i;
		lst[i] = cur;
	}
}

int main() {
	input();
	if (block[0]) {
		cout << -1 << '\n';
		return 0;
	}
	ll bst = 1e15;
	for (int l = 1; l <= k; l++) {
		int ind = 0, mxColored = -1;
		while (mxColored < n - 1 && ind < n) {
			mxColored = min(ind + l - 1, n - 1);
			amt[l]++;
			if (mxColored == n - 1)break;
			int nxt = lst[mxColored+1];
			if (nxt == ind)break;
			else ind = nxt;
		}
		if (mxColored < n - 1)amt[l] = 2e12;
		bst = min(bst, p[l] * amt[l]);
	}
	if(bst<=1e12)printf("%lld\n", bst);
	else printf("-1\n");
	return 0;
}