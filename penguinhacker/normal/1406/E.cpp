#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

vector<int> generatePrimes(const int MXPRIME) { //nloglogn where n is MXPRIME
	vector<bool> isPrime(MXPRIME+1, 1);
	vector<int> primes;
	for (int i=2; i<=MXPRIME; ++i) {
		if (!isPrime[i]) {
			continue;
		}
		primes.push_back(i);
		for (ll j=(ll)i*i; j<=MXPRIME; j+=i) {
			isPrime[j]=0;
		}
	}
	return primes;
}

int ask(char c, int x) {
	cout << c << " " << x << endl;
	int res;
	cin >> res;
	return res;
}

const int B = 95;
int n, ans = 1;
vector<int> p, other, cur;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	p = generatePrimes(n);
	for (int i : p) {
		if ((ll)i * i <= n) {
			ask('B', i);
			for (int j = i; j <= n; j *= i) {
				int x = ask('A', j);
				if (x == 0) {
					break;
				}
				ans *= i;
			}
		}
		else {
			other.push_back(i);
		}
	}
	int last = ask('A', 1);
	auto reset = [&]() {
		int nxt = ask('A', 1);
		if (nxt + cur.size() != last) {
			assert(nxt + cur.size() - 1 == last);
			for (int j : cur) {
				int x = ask('A', j);
				if (x > 0) {
					assert(x == 1);
					ans *= j;
					break;
				}
			}
		}
		last = nxt;
		cur.clear();
	};
	for (int i : other) {
		if ((ll)i * ans > n) {
			break;
		}
		cur.push_back(i);
		int x = ask('B', i);
		assert(x == 1 || x == 2);
		if (x == 2) {
			ans *= i;
			cout << "C " << ans << endl;
			return 0;
		}
		if (cur.size() == B) {
			reset();
		}
	}
	if (!cur.empty()) {
		reset();
	}
	cout << "C " << ans << endl;
	return 0;
}