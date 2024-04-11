#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define arr array

int n, ans=0;
multiset<int> box;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i=0, a; i<n; ++i) {
		cin >> a;
		box.insert(a);
	}	
	while(!box.empty()) {
		ans++;
		int cnt=0;
		bool ok=1;
		while (ok&&!box.empty()) {
			ok=0;
			for (auto it=box.begin(); it!=box.end(); ++it) {
				if (*it>=cnt) {
					cnt++;
					ok=1;
					box.erase(it);
					break;
				}
			}
		}
	}
	cout << ans;
	return 0;
}