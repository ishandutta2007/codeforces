#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int &i : arr) cin >> i;
	int last = n - 1;
	vector<bool> killed(n, false);
	for (int i = n - 1; i >= 0 && last > 0; --i) {
		if (arr[i] == 0) continue;
		for (int j = max(0, i - arr[i]); j < last && j < i; ++j)
			killed[j] = true;
		last = min(last, i - arr[i]);
	} 
	int ans = 0;
	for (auto i : killed) ans += !i;
	cout << ans; 
	//system("pause");
    return 0;
}