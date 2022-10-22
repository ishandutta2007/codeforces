#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n, m, k;
		string a, b;
		cin >> n >> m >> k >> a >> b;
		int which=0;
		int cnt=0;
		sort(a.rbegin(), a.rend());
		sort(b.rbegin(), b.rend());
		while(a.size()&&b.size()) {
			if (a.back()<b.back()&&!(which==0&&cnt==k)||(which==1&&cnt==k)) {
				cout << a.back();
				a.pop_back();
				if (which==1)
					cnt=0;
				which=0;
				++cnt;
			} else {
				cout << b.back();
				b.pop_back();
				if (which==0)
					cnt=0;
				which=1;
				++cnt;
			}
		}
		cout << "\n";
	}
	return 0;
}