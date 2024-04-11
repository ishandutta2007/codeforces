#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pi pair<int, int>
const int MOD=1e9+7;



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--) {
		int n;
		bool pos = 1;
		cin >> n;
		pi curr = {0, 0};
		while(n--) {
			int a, b;
			cin >> a >> b;
			if (a<curr.first||b<curr.second||a-curr.first<b-curr.second)
				pos = 0;
			curr = {a, b};
		}
		cout << (pos?"YES":"NO") << '\n';
	}
	return 0;
}