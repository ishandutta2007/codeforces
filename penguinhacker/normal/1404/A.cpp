#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

void print(bool b) {cout << (b?"YES":"NO") << "\n";}

int n, k;
string s;
void solve() {
	cin >> n >> k >> s;
	vector<int> w(k, -1);
	for (int i=0; i<n; ++i) {
		if (s[i]!='?') {
			w[i%k]=s[i]-'0';
		}
	}
	for (int i=0; i<n; ++i) {
		if (s[i]!='?'&&s[i]-'0'!=w[i%k]) {
			print(0);
			return;
		}
	}
	vector<int> cnt(2, 0);
	for (int i : w) {
		if (i!=-1) {
			++cnt[i];
		}
	}
	print(cnt[0]<=k/2&&cnt[1]<=k/2);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		solve();
	}
	return 0;
}