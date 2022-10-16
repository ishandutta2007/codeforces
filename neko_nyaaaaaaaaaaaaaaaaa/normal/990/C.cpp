#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

map<ll, ll> l, r;
ll ans = 0, correct = 0;

int cor(string s) {
	int cur = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(') {cur++;}
		else {cur--;}
		
		if (cur < 0) return 0;
	}
	
	if (cur) return 0;
	
	correct++; return 1;
}

int op(string s) {
	int cur = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(') {cur++;}
		else {cur--;}
		
		if (cur < 0) return 0;
	}
	l[cur]++;
	return 1;
}

int clo(string s) {
	int cur = 0;
	for (int i = s.size()-1; i >= 0; i--) {
		if (s[i] == ')') {cur++;}
		else {cur--;}
		
		if (cur < 0) return 0;
	}
	r[cur]++;
	return 1;
}

int main() {
	ios::sync_with_stdio(0);
	
	int n;
	cin >> n;
	while (n--) {
		string s;
		cin >> s;
		
		if (cor(s)) continue;
		if (op(s)) continue;
		if (clo(s)) continue;
	}
	
	ans = correct*correct;
	for (int i = 1; i <= 300000; i++) {
		ans += l[i]*r[i];
	}
	cout << ans;
	
	return 0;
}