#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	
	int n;
	cin >> n;
	vector<ll> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	string s;
	cin >> s;
	ll l = -1e9-1, r = 1e9+1;
 	for (int i = 0; i <= n-5; i++) {
 		if (s[i] == '0' && s[i+1] == '0' && s[i+2] == '0' && s[i+3] == '0' && s[i+4] == '1') {
 			for (int j = i; j < i+5; j++) {
 				l = max(l, a[j]);
 			} 
 		} else if (s[i] != '0' && s[i+1] != '0' && s[i+2] != '0' && s[i+3] != '0' && s[i+4] != '1') {
 			for (int j = i; j < i+5; j++) {
 				r = min(r, a[j]);
 			} 
 		}
 	}
 	cout << ++l << " " << --r;
 	
	return 0;
}