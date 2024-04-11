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
#include <list>
#include <bitset>
#include <queue>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int sz = 2e5 + 5, mxNum = 1e6;
const ll mod = 1e9 + 7;
int n;
ll a[sz];
ll divSum[mxNum + 1], divAmount[mxNum + 1], p2[mxNum + 1];

vector<int> divisors(int x) {
	vector<int> res;
	for (int i = 2; i * i <= x; i++) {
		if (x%i == 0) {
			res.pb(i);
			if (i*i != x)res.pb(x / i);
		}
	}
	return res;
}

void prec() {
	for (int i = 2; i <= mxNum; i++) {
		vector<int> v = divisors(i);
		for (int x : v)divSum[i] += (x - divSum[x]);
	}
	p2[0] = 1;
	for (int i = 1; i <= mxNum; i++) p2[i] = (p2[i - 1] * 2) % mod;
}

void addToArr(int tmp) {
	for (int i = 1; i * i <= tmp; i++) {
		if (tmp%i == 0) {
			divAmount[i]++;
			if (i*i != tmp)divAmount[tmp / i]++;
		}
	}
}

int main() {
	fast;
	prec();
	int tmp;
	scanf("%d", &n);
	foru(i, 0, n) {
		scanf("%d", &tmp);
		addToArr(tmp);
	}
	ll ret = 0;
	for (ll i = 2; i <= mxNum; i++) {
		if (!divAmount[i])continue;
		ll toAdd = (i - divSum[i]) % mod;
		if (toAdd < 0)toAdd += mod;
		ll cur = (toAdd * divAmount[i]);
		cur %= mod;
		cur *= p2[divAmount[i] - 1];
		cur %= mod;
		ret += cur;
		ret %= mod;
	}
	printf("%lld\n", ret);
	return 0;
}