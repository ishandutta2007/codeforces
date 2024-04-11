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


vector<int> apply(vector<int> const &a, vector<int> const &b) {
	int n = (int) a.size();
	vector<int> res(n);
	for (int i = 0; i < n; i++) {
		res[i] = a[b[i]];
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
	int m, n;
	cin >> m >> n;
	map<vector<int>, int> ms;
	vector<vector<int>> ps;
	{
		vector<int> p(n);
		for (int i = 0; i < n; i++) p[i] = i;
		int c = 0;
		do {
			ps.push_back(p);
			ms[p] = c;
			c++;
		} while (next_permutation(p.begin(), p.end()));
	}
	int all = 1;
	for (int i = 2; i <= n; i++) all *= i;
	vector<vector<int>> d(all, vector<int>(all, -1));
	for (int i = 0; i < all; i++) {
		vector<int> p = ps[i];
		for (int j = 0; j < all; j++) {
			vector<int> q = ps[j];
			vector<int> r = apply(p, q);
			d[i][j] = ms[r];
		}
	}
	vector<int> a(m);
	for (int i = 0; i < m; i++) {
		vector<int> p(n);
		for (int j = 0; j < n; j++) {
			cin >> p[j];
			p[j]--;
		}
		a[i] = ms[p];
	}
	map<vector<int>, int> qh;
	vector<vector<int>> edges;
	vector<vector<int>> kl;
	{
		auto dor = [](vector<int> const &a, vector<int> const &b) {
			vector<int> ret(a.size());
			for (int i = 0; i < (int) a.size(); i++) {
				ret[i] = a[i] | b[i];
			}
			return ret;
		};
		auto make = [&](vector<int> a) {
			while (true) {
				bool changed = false;
				for (int i = 0; i < (int) a.size(); i++) {
					if (!a[i]) continue;
					for (int j = 0; j < (int) a.size(); j++) {
						if (!a[j]) continue;
						if (!a[d[i][j]]) {
							a[d[i][j]] = true;
							changed = true;
						}
					}
				}
				if (!changed) break;
			}
			return a;
		};
		auto add = [&](vector<int> const &a) {
			int sz = (int) qh.size();
			qh[a] = sz;
			kl.push_back(a);
			edges.push_back(vector<int>(all));
		};
		vector<int> start(all);
		start[0] = 1;
		add(start);
		for (int j = 0; j < (int) kl.size(); j++) {
			for (int i = 0; i < all; i++) {
				vector<int> cur = kl[j];
				cur[i] = 1;
				cur = make(cur);
				if (qh.find(cur) == qh.end()) {
					add(cur);
				}
				edges[j][i] = qh[cur];
			}
		}
	}
	vector<int> first(all, m);
	vector<int> z(all);
	for (int i = 0; i < all; i++) z[i] = i;
	long long ans = 0;
	for (int i = m - 1; i >= 0; i--) {
		first[a[i]] = i;
		vector<int> have(all);
		have[0] = 1;
		sort(z.begin(), z.end(), [&](int v, int u) {
			return first[v] < first[u];
		});
		int curPos = i;
		for (int it = 0; it < all; it++) {
			int pr = z[it];
			if (have[pr]) continue;
			int pos = first[pr];
			int count = 0;
			for (int i : have) count += i;
			ans += (long long) (pos - curPos) * count;
			// debug(i, pos, curPos, count, pr);
			curPos = pos;
			if (pos == m) break;
			have = kl[edges[qh[have]][pr]];
		}
		int count = 0;
		for (int i : have) count += i;
		ans += (m - curPos) * count;
		// debug(i, m, curPos, count);
	}
	cout << ans << endl;
}