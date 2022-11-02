#define _CRT_SECURE_NO_WARNINGS
#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define ff first
#define ss second

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <bitset>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int sz = 2e5 + 1, MAX_A = 5e5;
int n, q, treesz = 0, a[sz], psize;
bitset<sz> toggle;
vector<int> p[MAX_A + 1], primes;
int tree[MAX_A + 5];


void init() {
	for (int i = 2; i <= MAX_A; i++) {
		if (p[i].empty()) {
			p[i].pb(i);
			primes.pb(i);
			for (int j = i + i; j <= MAX_A; j += i)
				p[j].pb(i);
		}
	}
	psize = primes.size();
}

void change(int val, int idx, ll crmul, int delta) {
	if (idx == p[val].size())
		tree[crmul] += delta;
	else {
		change(val, idx + 1, crmul*p[val][idx], delta);
		change(val, idx + 1, crmul, delta);
	}
}

int howmany(int val, int idx, ll crmul, int mycnt) {
	if (idx == p[val].size()) {
		if (crmul == 1)return 0;
		else if (mycnt & 1)return tree[crmul];
		else return -tree[crmul];
	}
	else
		return howmany(val, idx + 1, crmul, mycnt) + howmany(val, idx + 1, crmul*p[val][idx], mycnt + 1);
}

int main() {
	//fast;
	init();
	scanf("%d %d", &n, &q);
	foru(i, 0, n)scanf("%d", &a[i]);
	ll cur = 0, N = 0;
	while (q--) {
		int x;
		scanf("%d", &x);
		--x;
		if (toggle[x]) {
			if (a[x] != 1) {
				change(a[x], 0, 1, -1);
				cur -= howmany(a[x], 0, 1, 0);
			}
			N--;
		}
		else {
			if (a[x] != 1) {
				cur += howmany(a[x], 0, 1, 0);
				change(a[x], 0, 1, 1);
			}
			N++;
		}
		toggle[x] = !toggle[x];
		printf("%lld\n", (N*(N - 1)) / 2 - cur);
	}
	return 0;
}