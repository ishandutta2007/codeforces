#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;

int main() {
	int n, d;
	cin >> n >> d;
	vector<int> arr(n);
	for (auto &i : arr) cin >> i;
	sort(arr.begin(), arr.end());
	int ptr = 0, m = 0;
	for (int i = 0; i < n; ++i) {
		while (arr[i] - arr[ptr] > d) ++ptr;
		m = max(m, i - ptr + 1);
	}
	cout << n - m;
	//system("pause");
    return 0;
}