#include <bits/stdc++.h>
#define long long long
#define pii pair<int, int>
 
using namespace std;
const int inf = 1e9 + 7;
 


int main() {
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	int t;
	cin >> t;
	while(t--) {
		int n, m;
		cin >> n >> m;
		int sum = 0;
		for(int i = 0;i < n;i++) {
			int v;
			cin >> v;
			sum += v;
		}
		cout << min(sum, m) << '\n';
	}
}