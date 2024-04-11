#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pi pair<int, int>
const int MOD=1e9+7;
const int mxN=1e7+10;

vector<int> primes;
int n, m, p[mxN]={0}, sum[mxN]={0};

void genPrimes() {
	for (int i=2; i<=4000; ++i) {
		bool isPrime = 1;
		for (int j=2; j*j<=i; ++j) {
			if (i%j==0) {
				isPrime = 0;
				break;
			}
		}
		if (isPrime)
			primes.push_back(i);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	genPrimes();
	cin >> n;
	for (int i=0, a; i<n; ++i) {
		cin >> a;
		unordered_set<int> s;
		while (a>1) {
			bool isPrime = 1;
			for (int i=0; i<=primes.size(); ++i) {
				if (primes[i]*primes[i]>a)
					break;
				if (a%primes[i]==0) {
					s.insert(primes[i]);
					a /= primes[i];
					isPrime = 0;
					break;
				}
			}
			if (isPrime) {
				s.insert(a);
				break;
			}
		}
		for (const int &i:s)
			p[i]++;
	}
	for (int i=1; i<=1e7; ++i)
		sum[i] = sum[i-1]+p[i];
	cin >> m;
	while (m--) {
		int l, r;
		cin >> l >> r;
		if (l>=1e7) {
			cout << 0 << '\n';
			continue;
		}
		if (r>1e7)
			r = 1e7;
		cout << sum[r]-sum[l-1] << '\n';
	}
	return 0;
}