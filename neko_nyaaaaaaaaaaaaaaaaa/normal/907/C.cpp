#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<int> a(26, 1);

bool check() {
	int count = 0;
	for (int i = 0; i < 26; i++) {
		if (a[i] == 1) {count++;}
	}
	return (count == 1);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	ll n;
	cin >> n;
	ll ans = 0;
	bool flag = 0;
	char answer;
	for (ll i = 1; i < n; i++) {
		string c, w;
		cin >> c >> w;
		
		if (flag) {
			if (c != ".") {ans++; continue;}
		}
		
		if (c == "!") {
			vector<bool> ch(26, 0);
			for (ll j = 0; j < w.size(); j++) {
				ch[w[j] - 'a'] = 1;
			}
			for (ll j = 0; j < 26; j++) {
				if (!ch[j]) {a[j] = 0;}
			}
			
		} else if (c == ".") {
			for (ll j = 0; j < w.size(); j++) {
				a[w[j] - 'a'] = 0;
			}
		} else if (c == "?") {
			a[w[0] - 'a'] = 0;
		}
		flag = check();
		if (flag) {
			for (ll j = 0; j < 26; j++) {
				if (a[j] == 1) {answer = a[j]; break;}
			}
		}
		
	}
	cout << ans;
	
	return 0;
}