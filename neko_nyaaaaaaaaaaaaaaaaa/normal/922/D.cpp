#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll f(string s) {
      ll scount = 0;
	ll ans = 0; 
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 's') {scount += 1; continue;}
		else {
			ans += scount;
		}
	}
	return ans;
}

bool comp(string s1, string s2) {
	return f(s1+s2) > f(s2+s1);
}

int main() {
	ios::sync_with_stdio(0);
	
	int n;
	cin >> n;
	vector<string> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end(), comp);
	string s = "";
	for (int i = 0; i < n; i++) {
		s += a[i];
	}
	cout << f(s);
	
	return 0;
}