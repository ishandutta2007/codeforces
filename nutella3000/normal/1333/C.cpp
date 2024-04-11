#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
  
using namespace std;
const int inf = 1e9 + 7;



signed main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;
	int last = 0;
	map<int, int> temp;
	temp[0] = 0;


	int res = 0;

	int v = 0;
	for(int i = 0;i < n;i++) {
		int q;
		cin >> q;
		v += q;

		if (temp.find(v) != temp.end()) {
			last = max(last, temp[v] + 1);
		}
		temp[v] = i + 1;
		res += i - last + 1;
	}	

	cout << res;
}