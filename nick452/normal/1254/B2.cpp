#include <bits/stdc++.h>

using namespace std;

long long calc(vector<int> a, long long cnt) {
	int n = a.size();
	for (int i = 0; i < n; ++i) {
		a[i] %= cnt;
	}
	long long total = 0;
	vector<pair<int, int>> b;
	long long result = 0;
	for (int i = 0; i < n; ++i) {
		if (total + a[i] < cnt) {
			b.emplace_back(i, a[i]);
			total += a[i];
		} else {
			int a0 = (int)(cnt - total);
			b.emplace_back(i, a0);

			long long s = 0;
			int medium_id = -1;
			for (const auto& id_to_cnt : b) {
				s += id_to_cnt.second;
				if (s + s >= cnt) {
					medium_id = id_to_cnt.first;
					break;
				}
			}
			for (const auto& id_to_cnt : b) {
				result += (long long)id_to_cnt.second * abs(id_to_cnt.first - medium_id);
			}

			b.clear();
			b.emplace_back(i, a[i] - a0);
			total = a[i] - a0;
		}
	}
	return result;
}

int main()
{
#ifdef _MSC_VER
	FILE *file_stream;
	freopen_s(&file_stream, "b.in", "r", stdin);
#endif
	std::ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	long long total = 0;
	for (int i = 0; i < n; ++i) {
		total += a[i];
	}
	long long result = numeric_limits<long long>::max();
	for (long long p = 2; p * p <= total; ++p) {
		if (total % p == 0) {
			result = min(result, calc(a, p));
			while (total % p == 0) {
				total /= p;
			}
		}
	}
	if (total > 1) {
		result = min(result, calc(a, total));
	}
	if (result == numeric_limits<long long>::max()) {
		result = -1;
	}
	cout << result << endl;
	return 0;
}