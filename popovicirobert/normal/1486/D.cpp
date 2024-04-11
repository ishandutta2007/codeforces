#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define Test(tt) cout << "Case #" << tt << ": "
 
 
using namespace std;






int main() {
#ifdef HOME
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
    int n, k;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

	cin >> n >> k;

	vector<int> values(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> values[i];
	}

	vector<pair<int, int>> sums(n + 1);

	auto check = [&](int median) {
		sums[0] = {0, 0};
		for (int i = 1; i <= n; i++) {
			int value = (values[i] < median ? -1 : 1);
			sums[i] = {value + sums[i - 1].first, i};
		}
		sort(sums.begin(), sums.end());

		// sum >= -1

		int maxLength = 0, minPos = n;
		int position = 0;
		for (const auto& itr : sums) {
			while (position <= n && sums[position].first <= itr.first - 1) {
				minPos = min(minPos, sums[position].second);
				position++;
			}
			maxLength = max(maxLength, itr.second - minPos);
		}

		return maxLength;
	};

	int result = 0;
	for (int step = 1 << 17; step; step >>= 1) {
		if (check(result + step) >= k) {
			result += step;
		}
	}

	int minDiff = n + 1;
	for (int i = 1; i <= n; i++) {
		if (values[i] <= result) {
			minDiff = min(minDiff, result - values[i]);
		}
	}
	cout << result - minDiff;


    return 0;
}