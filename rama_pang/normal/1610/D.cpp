#include <bits/stdc++.h>
using namespace std;

using lint = long long;
const lint INF = 1e18;
using ll = long long;

#define int lint

typedef unsigned long long ull;
ull modmul(ull a, ull b, ull M) {
	ll ret = a * b - M * ull(1.L / M * a * b);
	return ret + M * (ret < 0) - M * (ret >= (ll)M);
}
ull modpow(ull b, ull e, ull mod) {
	ull ans = 1;
	for (; e; b = modmul(b, b, mod), e /= 2)
		if (e & 1) ans = modmul(ans, b, mod);
	return ans;
}

bool isPrime(ull n) {
	if (n < 2 || n % 6 % 4 != 1) return (n | 1) == 3;
	ull A[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022},
	    s = __builtin_ctzll(n-1), d = n >> s;
	for (ull a : A) {   // ^ count trailing zeroes
		ull p = modpow(a%n, d, n), i = s;
		while (p != 1 && p != n - 1 && a % n && i--)
			p = modmul(p, p, n);
		if (p != n-1 && i != s) return 0;
	}
	return 1;
}

ull pollard(ull n) {
	auto f = [n](ull x) { return modmul(x, x, n) + 1; };
	ull x = 0, y = 0, t = 30, prd = 2, i = 1, q;
	while (t++ % 40 || __gcd(prd, n) == 1) {
		if (x == y) x = ++i, y = f(x);
		if ((q = modmul(prd, max(x,y) - min(x,y), n))) prd = q;
		x = f(x), y = f(f(y));
	}
	return __gcd(prd, n);
}
vector<ull> factor(ull n) {
	if (n == 1) return {};
	if (isPrime(n)) return {n};
	ull x = pollard(n);
	auto l = factor(x), r = factor(n / x);
	l.insert(l.end(), begin(r), end(r));
	return l;
}

void Main() {
  // m
  // (lo + hi) * m/2
  // hi - lo + 1 == m
  // (lo + m + lo - 1)*m/2
  // (2lo - 1 + m)*m/2
  // lo * m - m/2 + m*m/2
  // lo * m + (m - 1)*m/2
  // so (m - 1)*m/2 + x * m for any x
  // so we take mod m
  // (m - 1)*m/2 mod m

  int n;
  cin >> n;
  vector<int> a(n);
  vector<pair<int, int>> mods;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    mods.emplace_back(1ll * (a[i] - 1) * a[i] / 2 % a[i], a[i]);
  }
  
  for (auto [x, y] : mods) {
    if (y & 1) assert(x == 0);
    else assert(x == y/2);
  }

  // only odd = good
  // only even: bad sequence = 2 * (1,2,4,16,...) or (1,3,9,27,...)
  // if odd and even: good


  const lint MOD = 1e9 + 7;
  vector<lint> pow2(n + 1);
  pow2[0] = 1;
  for (int i = 1; i <= n; i++) {
    pow2[i] = 2 * pow2[i - 1] % MOD;
  }

  lint odd = 0;
  map<lint, lint> cnt;
  for (auto [x, y] : mods) {
    if (y & 1) {
      odd++;
      continue;
    }
    lint c0 = 0;
    while (y % (2ll << c0) == 0) c0++;
    cnt[c0]++;
  }
  lint ans = 0;
  // lint mul = 1;
  lint all = 0;
  for (auto [a, b] : cnt) all += b;
  for (auto [a, b] : cnt) {
    ans += (pow2[b - 1] - 1) * pow2[all - b] % MOD;
    //  (pow2[all] - 1);
    // mul *= (b + 1);
    all -= b;
    // mul %= MOD;
  }
  // ans = pow2[n] - mul;
  ans += (pow2[odd] - 1) * pow2[n - odd] % MOD;
  ans %= MOD;
  ans += MOD;
  ans %= MOD;
  cout << ans << '\n';

  // vector<pair<lint, lint>> ls;
  // map<lint, lint> mp;
  // map<vector<pair<lint, lint>>, lint> cnt;
  // for (auto [x, y] : mods) {
  //   auto fac = factor(y);
  //   ls.clear();
  //   mp.clear();
  //   for (auto i : fac) mp[i]++;
  //   lint g = 0;
  //   for (auto [i, j] : mp) {
  //     g = g == 0 ? j : gcd(g, j);
  //   }
  //   lint m = 1;
  //   while (g % (2 * m) == 0) {
  //     m *= 2;
  //   }
  //   for (auto [i, j] : mp) {
  //     ls.emplace_back(i, j / m);
  //   }
  //   cnt[ls] += 1;
  // }

  // lint ans = pow2[n];
  // ans -= 1;
  // for (auto [x, y] : cnt) {
  //   ans -= pow2[y] - 1;
  // }
  // ans %= MOD;
  // ans += MOD;
  // ans %= MOD;
  // cout << ans << '\n';
  
  // (k + l) mod gcd(2k, 2l)
  // 

  // for (int x = 1; x <= 20; x++) {
  //   for (int y = x; y <= 20; y++) if (x != y) {
  //     lint c0 = 0, c1 = 0;
  //     while (x % (2ll << c0) == 0) c0++;
  //     while (y % (2ll << c1) == 0) c1++;
  //     // int z = y;
  //     // while (z % x == 0) z /= x;
  //     if((x + y) % gcd(2 * x, 2 * y) == 0) {
  //       // assert(z != 1);
  //       // assert(y % x == 0);
  //       // assert(y / x)
  //       assert(c0 == c1);
  //       // cout << x << ' ' <<y  << '\n';
  //     } else {
  //       assert(c0 != c1);
  //       // cout
  //       // assert(z == 1);
  //       // assert(y % x != 0);

  //     }
  //   }
  // }

  // let x = 2k, y = 2l
  // (k + l) mod 2gcd(k, l)
  // 
  // x/2 + y/2 mod gcd(x, y)
  
    // cout << x << ' ' << y << '\n';


  // map<vector<int>, vector<int>> ls;
  // int id;
  // map<lint, int> mp;
  // vector<pair<lint, int>> facs;
  // const auto Dfs = [&](const auto &self, int pos, int z) -> void {
  //   if (pos == facs.size()) {
  //     ls[z].emplace_back(id);
  //   } else {
  //     int mul = 1;
  //     for (int i = 0; i <= facs[pos].second; i++) {
  //       self(self, pos + 1, z * mul);
  //       mul *= facs[pos].first;
  //     }
  //   }
  // };
  // vector<int> pls;
  // vector<vector<pair<int, int>>> prls;
  // map<vector<pair<int, 
  // for (auto [x, y] : mods) {
  //   auto fac = factor(y);
  //   mp.clear();
  //   id = x;
  //   facs.clear();
  //   for (auto i : fac) {
  //     mp[i]++;
  //   }
  //   prls.emplace_back();
  //   for (auto [i, j] : mp) {
  //     facs.emplace_back(i, j);
  //     // pls.emplace_back(i);
  //     // prls.back().emplace_back(i, j);
  //   }

  // }

  // sort(begin(pls), end(pls));
  // pls.resize(unique(begin(pls), end(pls)) - begin(pls));

  // for (auto &a : prls) {
  //   for (auto [i, j] : a) {

  //   }
  // }

  // cout << ls.size() << '\n';
  // for (auto [a, b] : ls) {

  // }

  // sum % g == 0
  // 
  // int ans = 0;
  // for (int mask = 1; mask < (1 << n); mask++) {
  //   int sum = 0, g = 0;
  //   for (int i = 0; i < n; i++) {
  //     if ((mask >> i) & 1) {
  //       sum += mods[i].first;
  //       g = g == 0 ? mods[i].second : gcd(mods[i].second, g);
  //     }
  //   }
  //   if (sum % g == 0) {
  //     ans += 1;
  //   } else {
  //     assert(g % 2 == 0);
  //   }
  //   //  ans += 1;
  // }
  // cout << ans << '\n';

}

int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  // cin >> T;
  while (T--) {
    Main();
  }
  return 0;
}
/*
m^2/2 - m/2 mod m
m/2 mod m
if m odd
1/2 mod m = (m + 1)/2

so m/2 mod m = m*(m+1)/2

m^2/2 - m^2/2 - m/2
-m/2 mod m



8x^2 - 2x mod 4x

*/