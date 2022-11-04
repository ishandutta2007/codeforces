#pragma comment(linker, "/STACK:9759095000")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,abm,mmx,tune=native")
#include<vector>
#include<iostream>
#include<stack>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<string>
#include<tuple>
#include<bitset>
#include<queue>
#include<unordered_map>
#include<random>
#include<ctime>
//#define double long double
typedef long long ll;
typedef double ld;
typedef unsigned long long ull;
using namespace std;
ll gcd(ll i, ll j) {
	if (j == 0)return i;
	else return gcd(j, i % j);
}
#ifdef _DEBUG
ll __builtin_popcount(ll x) { return x ? (__builtin_popcount(x >> 1) + (x & 1)) : 0; }
#endif
template<typename T> inline T getint() {
	T val = 0;
	char c;

	bool neg = false;
	while ((c = getchar()) && !(c >= '0' && c <= '9')) {
		neg |= c == '-';
	}

	do {
		val = (val * 10) + c - '0';
	} while ((c = getchar()) && (c >= '0' && c <= '9'));

	return val * (neg ? -1 : 1);
}
//#define int long long
const ll INF = 1e18;
const int mod = 1000000007, mod1 = 1000000009;
const ld eps = 1e-9, pi = acos(-1);
const int maxN = 1000100, maxT = 1601;
vector<ll>p;
int pr[maxN];
void build_prime() {
	for (int i = 2; i < maxN; ++i) {
		if (pr[i] == 0) {
			p.push_back(i);
			for (int j = 2 * i; j < maxN; j += i)pr[j] = 1;
		}
	}
}
bool is_it_prime(ll v) {
	for (auto x : p) {
		if (x * x > v)break;
		if (v % x == 0 && v != x)return false;
	}
	return true;
}
vector<ll>build_to_k(ll k, map<ll, vector<ll>>mp, map<ll, vector<ll>>inf) {
	vector<ll>ans;
	if (k % 2 == 0) {
		for (auto &x : mp) {
			if (k == 0)break;
			k -= 2;
			ans.push_back(x.second.back());
			x.second.pop_back();
			ans.push_back(x.second.back());
			x.second.pop_back();
		}
		for (auto& x : mp) {
			while (k != 0 && !x.second.empty()) {
				--k;
				ans.push_back(x.second.back());
				x.second.pop_back();
			}
		}
		for (auto x : inf) {
			if (k) {
				--k;
				ans.push_back(x.first);
			}
		}
		return ans;
	}
	ll mn = INF;
	for (auto x : mp)if (x.second.size() != 2)mn = 1;
	for (auto x : inf)mn = min(mn, (ll)x.second.size());
	if (mn * 2 > k)return ans;
	if (mn == 1) {
		for (auto& x : mp) {
			if (x.second.size() != 2) {
				k -= 3;
				for (int j = 0; j < 3; ++j) {
					ans.push_back(x.second.back());
					x.second.pop_back();
				}
				break;
			}
		}
	}
	else {
		ll to_del = -1;
		for (auto x : inf) {
			if (x.second.size() == mn) {
				to_del = x.first;
				k -= 2 * mn + 1;
				ans.push_back(x.first);
				for (auto prime : x.second) {
					for (int j = 0; j < 2; ++j) {
						ans.push_back(mp[prime].back());
						mp[prime].pop_back();
					}
				}
				break;
			}
		}
		inf.erase(to_del);
	}
	for (auto &x : mp) {
		if (k == 0)break;
		if (x.second.size() >= 2) {
			k -= 2;
			ans.push_back(x.second.back());
			x.second.pop_back();
			ans.push_back(x.second.back());
			x.second.pop_back();
		}
	}
	for (auto& x : mp) {
		while (!x.second.empty() && k != 0) {
			--k;
			ans.push_back(x.second.back());
			x.second.pop_back();
		}
	}
	for (auto& x : inf) {
		if (k) {
			--k;
			ans.push_back(x.first);
		}
	}
	return ans;
}
void solve() {
	int n, k;
	cin >> n >> k;
	map<ll, vector<ll>>mp;
	vector<ll>a(n);
	for (auto& x : a)cin >> x;
	for (auto x : a) {
		ll remember = x;
		if (x <= 2e9 && is_it_prime(x)) {
			mp[x].push_back(x);
			continue;
		}
		int ct = 0;
		for (auto d : p) {
			if (x % d == 0) {
				ct = 1;
				while (x % d == 0)x /= d;
				if (x == 1) {
					mp[d].push_back(remember);
				}
				break;
			}
		}
		if (ct)continue;
		ll b = 1, e = 2e9;
		while (b + 1 != e) {
			ll m = (b + e) / 2;
			if (m * m <= remember) {
				b = m;
			}
			else e = m;
		}
		if (b * b == x && is_it_prime(b))mp[b].push_back(remember);
	}
	map<ll, vector<ll>>inf_about_dig;
	vector<ll>to_erase;
	for (auto x : mp)if (x.second.size() == 1)to_erase.push_back(x.first);
	for (auto x : to_erase)mp.erase(x);
	for (auto c : a) {
		ll rm = c;
		vector<ll>zaebic;
		for (auto x : mp) {
			if (c % x.first == 0) {
				zaebic.push_back(x.first);
				while (c % x.first == 0)c /= x.first;
			}
		}
		if (c > 1 || zaebic.size() == 1)continue;
		inf_about_dig[rm] = zaebic;
	}
	vector<ll>ans = build_to_k(k, mp, inf_about_dig);
	if (ans.size() != k) {
		cout << "0\n";
		return;
	}
	sort(ans.begin(), ans.end());
	for (auto x : ans)cout << x << " "; cout << "\n";
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout.precision(10);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
	//freopen("epic.in", "r", stdin); freopen("epic.out", "w", stdout);
#endif
	int t = 1;
	build_prime();
	//cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}