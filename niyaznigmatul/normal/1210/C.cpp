/**
 * Niyaz Nigmatullin
 */

#include <bits/stdc++.h>

using namespace std;


string to_string(string s) {
  return '"' + s + '"';
}

string to_string(const char* s) {
  return to_string((string) s);
}

string to_string(bool b) {
  return (b ? "true" : "false");
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}

#ifndef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif
int ans = 0;
int const MOD = 1000000007;

void add(int &a, int b) {
	a += b;
	if (a >= MOD) a -= MOD;
}

int mul(int a, int b) {
	return (int) ((long long) a * b % MOD);
}

long long gcd(long long a, long long b) {
	while (b != 0) {
		long long t = a % b;
		a = b;
		b = t;
	}
	return a;
}

int const K = 20;
int const N = 123456;

vector<int> edges[N];
int h[N];
long long x[N];
long long px[K][N];

long long get(int left, int right) {
	int k = h[right - left + 1];
	return gcd(px[k][right], px[k][left + (1 << k) - 1]);
}

void dfs(int v, int pv, int d) {
	px[0][d] = x[v];
	for (int i = 1; i < K; i++) {
		if (d >= (1 << (i - 1))) {
			px[i][d] = gcd(px[i - 1][d - (1 << (i - 1))], px[i - 1][d]);
		} else {
			px[i][d] = px[i - 1][d];
		}
	}
	int cur = 0;
	while (cur <= d) {
		int left = cur;
		int right = d + 1;
		long long z = get(cur, d);
		while (left < right - 1) {
			int mid = (left + right) >> 1;
			if (get(mid, d) == z) {
				left = mid;
			} else {
				right = mid;
			}
		}
		// debug(v, z, left - cur + 1);
		add(ans, mul((int) (z % MOD), left - cur + 1));
		cur = right;
	}
	for (int to : edges[v]) {
		if (to == pv) continue;
		dfs(to, v, d + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> x[i];
	for (int i = 2; i <= n; i++) {
		h[i] = h[i / 2] + 1;
	}
	for (int i = 0; i + 1 < n; i++) {
		int from, to;
		cin >> from >> to;
		from--;
		to--;
		edges[from].push_back(to);
		edges[to].push_back(from);
	}
	dfs(0, -1, 0);
	cout << ans << endl;
}