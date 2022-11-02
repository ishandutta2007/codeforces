#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int &i : arr) cin >> i;
	set<int> ss;
	int ans = 1;
	for (int i : arr) {
		if (ss.find(i) != ss.end())
			ans++;
		ss.insert(i);
	}
	cout << ans;
	//system("pause");
	return 0;
}