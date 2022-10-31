#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

using namespace std;

void append(string& ret, long long n) {
	if (n >= 10) {
		append(ret, n / 10);
	}
	ret += (char)('0' + n % 10);
}

int main()
{
#ifdef _MSC_VER
	freopen("f.in", "r", stdin);
#endif
	std::ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<long long> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	vector<pair<long long, long long>> c;
	c.emplace_back(a[n - 1], a[n - 1]);
	for (int i = n - 2; i >= 0; i--) {
		long long val = a[i];
		while (1) {
			auto& s = c.back();
			if (val == s.first) {
				c.emplace_back(val, val);
				break;
			}
			if (val + 1 == s.first) {
				s.first = val;
				break;
			}
			long long len = s.second - s.first + 1;
			if (val + len - 1 >= s.first - 1) {
				long long d = s.first - 1 - val;
				assert(d >= 0 && d < len);
				long long t = s.first;
				if (c.size() == 1) {
					s.first = s.second - d;
					--s.second;
				}
				else {
					long long w = s.second - d;
					c.pop_back();
					c.back().first = w;
				}
				c.emplace_back(t - 1, c.back().first);
				break;
			}
			if (val + len == s.first - 1) {
				long long t = s.first - 1;
				if (c.size() == 1) {
					--s.first;
					--s.second;
				}
				else {
					c.pop_back();
					c.back().first = t;
				}
				c.emplace_back(t, t);
				break;
			}
			if (c.size() > 1) {
				long long t = s.first;
				c.pop_back();
				c.back().first = t - 1;
				val += len;
				continue;
			}
			long long round = (s.first - 1 - val) / (len + 1);
			assert(round > 0);
			val += round * len;
			s.first -= round;
			s.second -= round;
			assert(val < s.first);
		}
	}

	string ret;
	ret.reserve(30 << 20);
	reverse(c.begin(), c.end());
	for (const auto& p : c) {
		for (long long x = p.first; x <= p.second; ++x) {
			append(ret, x);
			ret += ' ';
		}
	}
	ret += '\n';
	printf("%s\n", ret.c_str());
	return 0;
}