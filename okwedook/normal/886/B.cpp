#include <bits/stdc++.h>

using namespace std;
 
int main() {
	int n;
	cin >> n;
	vector<int> arr(n);
	int ans = 0;
	for (int &i : arr) cin >> i;
	map<int, bool> last;
	for (int i = n - 1; i >= 0; --i)
		if (last[arr[i]] == false){
			last[arr[i]] = true;
			ans = arr[i];
		}
	cout << ans;
    return 0;
}