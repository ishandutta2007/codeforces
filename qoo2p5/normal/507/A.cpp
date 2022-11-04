#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct instrument {
	int time, index;

	bool operator<(const instrument &other) const {
		return time < other.time;
	}
};

int n, k;


int main() {
	ios::sync_with_stdio(false);

	cin >> n >> k;
	vector<instrument> items(n);
	for(int i = 1; i <= n; i++) {
		int t;
		cin >> t;
		items[i-1] = {t, i};
	}

	sort(items.begin(), items.end());

	vector<int> learn;
	int s = 0;
	int count = 0;
	for(; count < n; count++) {
		instrument current = items[count];
		s += current.time;

		if(s > k) {
			break;
		}

		learn.push_back(current.index);
	}

	cout << count << endl;
	for(int i = 0; i < count; i++) {
		cout << learn[i] << " ";
	}
	cout << endl;

	return 0;
}