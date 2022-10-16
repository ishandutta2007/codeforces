#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	
	ll n, a, b, sum = 0;
	cin >> n >> a >> b;
	vector<ll> s(n);
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	
	sort(s.begin() + 1, s.end());
	
	int ans = 1;
	ll S = s[0];
	for (int i = 1; i < n; i++) {
      	if (s[0] * a >= b * (S + s[i])) {
            	ans++;
            	S += s[i];
      	} else break;
	}
	cout << n - ans;
	
	return 0;
}