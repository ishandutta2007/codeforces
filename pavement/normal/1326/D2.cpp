#include <bits/stdc++.h>
using namespace std;

int d1[1000005], d2[1000005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	string s;
	cin >> t;
	while (t--) {
		cin >> s;
		for (int i = 0, l = 0, r = -1; i < s.size(); i++) {
			int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
			while (0 <= i - k && i + k < s.size() && s[i - k] == s[i + k]) {
				k++;
			}
			d1[i] = k--;
			if (i + k > r) {
				l = i - k;
				r = i + k;
			}
		}
		for (int i = 0, l = 0, r = -1; i < s.size(); i++) {
			int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
			while (0 <= i - k - 1 && i + k < s.size() && s[i - k - 1] == s[i + k]) {
				k++;
			}
			d2[i] = k--;
			if (i + k > r) {
				l = i - k - 1;
				r = i + k ;
			}
		}
		int l = 0, r = s.size() - 1, m = 0, ansl = -1e9, ansr = -1e9;
		bool ansly = 0, ansry = 0;
		for (; l <= r; )
			if (s[l] == s[r]) l++, r--;
			else break;
		//cout << l << ' ' << r << '\n';
		//for (int i = 0; i < s.size(); i++) cout << d2[i] << ' ';
		//cout << '\n';
		for (int i = l; i <= r; i++) {
			//cout << m << '\n';
			int act = i - max(l, i - d1[i] + 1) + 1;
			//cout << "D1 " << i << ' ' << i - act + 1 << ' ' << i + act - 1 << '\n';
			if (i - act + 1 == l && i + act - 1 <= r && (act - 1) * 2 + 1 >= m) {
				ansl = i + act - 1;
				ansly = 1;
				//cout << "UPD " << (act - 1) * 2 + 1 << '\n';
				m = (act - 1) * 2 + 1;
			}
			if (!d2[i]) continue;
			act = i - max(l, i - d2[i]) + 1;
			//cout << "D2 " << act << ' ' << i << ' ' << i - act + 1 << ' ' << i + act - 2 << ' ' << (i + act - 2) - (i - act + 1) + 1 << ' ' << m << '\n';
			if (i - act + 1 == l && i + act - 2 <= r && (i + act - 2) - (i - act + 1) + 1 >= m) {
				ansl = i + act - 2;
				ansly = 1;
				//cout << "UPD\n";
				m = (i + act - 2) - (i - act + 1) + 1;
			}
		}
		for (int i = r; i >= l; i--) {
			//cout << m << '\n';
			int act = min(r, i + d1[i] - 1) - i + 1;
			//cout << "D1 " << i << ' ' << i - act + 1 << ' ' << i + act - 1 << '\n';
			if (i + act - 1 == r && i - act + 1 >= l && (act - 1) * 2 + 1 >= m) {
				ansly = ansl = 0;
				ansr = i - act + 1;
				ansry = 1;
				//cout << "UPD\n";
				m = (act - 1) * 2 + 1;
			}
			if (!d2[i]) continue;
			act = min(r, i + d2[i] - 1) - i + 2;
			//cout << "D2 " << i << ' ' << i - act + 1 << ' ' << i + act - 2 << '\n';
			//cout << i - act << ' ' << l << '\n';
			if (i + act - 2 == r && i - act + 1 >= l && (i + act - 2) - (i - act + 1) + 1 >= m) {
				ansly = ansl = 0;
				ansr = i - act + 1;
				ansry = 1;
				//cout << "UPD\n";
				m = (i + act - 2) - (i - act + 1) + 1;
			}
		}
		if (!ansly && !ansry) {
			if (l > r) {
				cout << s << '\n';
			} else {
				for (int i = 0; i < l; i++) cout << s[i];
				for (int i = r + 1; i < s.size(); i++) cout << s[i];
				cout << '\n';
			}
		} else if (ansly) {
			for (int i = 0; i <= ansl; i++) cout << s[i];
			for (int i = r + 1; i < s.size(); i++) cout << s[i];
			cout << '\n';
		} else {
			for (int i = 0; i < l; i++) cout << s[i];
			for (int i = ansr; i < s.size(); i++) cout << s[i];
			cout << '\n';
		}
	}
}

/*
1
tyyhhbbat
*/