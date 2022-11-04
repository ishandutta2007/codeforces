#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lsb(x) (x & (-x))

using namespace std;

const int MAXN = (int) 1e6;

bool ciur[MAXN + 1];

int main() {
#ifdef HOME
	ifstream cin("C.in");
	ofstream cout("C.out");
#endif
	//ifstream cin(".in");
	//ofstream cout(".out");
	int i, n;
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	for(i = 2; i * i <= MAXN; i++) {
		if(ciur[i] == 0) {
			for(int j = i * i; j <= MAXN; j += i) {
				ciur[j] = 1;
			}
		}
	}
	vector <int> primes;
	for(i = 2; i <= MAXN; i++) {
		if(ciur[i] == 0) {
			primes.push_back(i);
		}
	}

	cin >> n;
	vector <ll> arr(n);
	ll ans = 0;
	for(i = 0; i < n; i++) {
		cin >> arr[i];
		ans += arr[i] % 2;
	}

	auto Check = [&](ll p) {
		ll cur = 0;
		for(int i = 0; i < n; i++) {
			if(arr[i] >= p) {
				cur += min(arr[i] % p, p - arr[i] % p);
			}
			else {
				cur += p - arr[i] % p;
			}
		}
		ans = min(ans, cur);
	};

	auto Solve = [&](ll g) {
		int i = 0;
		while(i < (int)primes.size() && 1LL * primes[i] * primes[i] <= g) {
			if(g % primes[i] == 0) {
				Check(primes[i]);
			}
			while(g % primes[i] == 0) {
				g /= primes[i];
			}
			i++;
		}
		if(g > 1) {
			Check(g);
		}
	};

	mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());
	double start = clock();
	while(1.0 * (clock() - start) / CLOCKS_PER_SEC < 2.0) {
		int a = 0, b = 0;
		while(a == b) {
			a = rng() % n;
			b = rng() % n;
		}
		for(int da = -1; da <= 1; da++) {
			for(int db = -1; db <= 1; db++) {
				ll g = __gcd(arr[a] + da, arr[b] + db);
				Solve(g);
			}
		}
	}

	cout << ans;

	return 0;
}