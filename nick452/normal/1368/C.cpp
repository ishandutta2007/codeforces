#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<pair<int, int>> ret;
	if (n == 1) {
		ret.push_back(make_pair(0, 0));
		ret.push_back(make_pair(0, 1));
		ret.push_back(make_pair(0, 2));
		ret.push_back(make_pair(1, 0));
		ret.push_back(make_pair(1, 2));
		ret.push_back(make_pair(2, 0));
		ret.push_back(make_pair(2, 1));
		ret.push_back(make_pair(2, 2));
		ret.push_back(make_pair(2, 3));
		ret.push_back(make_pair(2, 4));
		ret.push_back(make_pair(3, 2));
		ret.push_back(make_pair(3, 4));
		ret.push_back(make_pair(4, 2));
		ret.push_back(make_pair(4, 3));
		ret.push_back(make_pair(4, 4));
	}
	else {
		int m = n / 2;
		int l = 2 + m * 4;
		for (int i = 0; i < l; i++) {
			ret.push_back(make_pair(1, i));
			ret.push_back(make_pair(4, i));
			if (i % 4 >= 2) {
				ret.push_back(make_pair(0, i));
				ret.push_back(make_pair(2, i));
			}
		}
		ret.push_back(make_pair(2, 0));
		ret.push_back(make_pair(3, 0));
		ret.push_back(make_pair(2, l - 1));
		ret.push_back(make_pair(3, l - 1));
		if (n % 2) {
			ret.push_back(make_pair(-1, -2));
			ret.push_back(make_pair(-1, -1));
			ret.push_back(make_pair(-1, -0));
			ret.push_back(make_pair(0, -2));
			ret.push_back(make_pair(0, 0));
			ret.push_back(make_pair(1, -2));
			ret.push_back(make_pair(1, -1));
		}
	}
	sort(ret.begin(), ret.end());
	printf("%d\n", (int)ret.size());
	for (auto p : ret) {
		printf("%d %d\n", p.first, p.second);
	}
}