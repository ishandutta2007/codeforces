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
#include <numeric>
#include <queue>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int sz = 1e6 + 5, mx = 1e6;
ll ans[sz];
bitset<sz> vs, isPrime;

void sieve() {
	for (int i = 2; i <= mx; i++) {
		if (!vs[i]) {
			isPrime[i] = 1;
			vs[i] = 1;
			for (int j = i + i; j <= mx; j += i)vs[j] = 1;
		}
	}
}

void prec() {
	sieve();
	ans[1] = 1;
	queue<int> pq;
	for (int i = 2; i <= mx; i++) {
		ans[i] = ans[i - 1];
		if (isPrime[i]) {
			pq.push(i);
			ans[i]++;
		}
		else if (pq.front()*pq.front() == i) {
			pq.pop();
			ans[i]--;
		}
	}
}

int main() {
	prec();
	int n, t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		printf("%d\n", ans[n]);
	}
	return 0;
}