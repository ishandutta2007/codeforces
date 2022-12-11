#include <algorithm>
#include <iostream>
#include <set>

int main() {

	int n;
	std::cin >> n;

	int data[n];
	for (int i = 0; i < n; ++i) {
		std::cin >> data[i];
	}

	std::sort(data, data + n);

	std::multiset<int> val;
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		if (!val.empty() && data[i] > *val.begin()) {
			val.erase(val.begin());
			++ans;
		}
		val.insert(data[i]);
	}

	std::cout << ans << std::endl;

	return 0;
}