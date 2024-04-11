#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, acnt, bcnt;
vector<int> ab, ba;
string a, b;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> a >> b;
	for (int i = 0; i < n; i++) {
		if (a[i] == 'a') acnt++;
		else bcnt++;
		if (b[i] == 'a') acnt++;
		else bcnt++;
		if (a[i] == 'a' && b[i] == 'b') ab.push_back(i + 1);
		else if (a[i] == 'b' && b[i] == 'a') ba.push_back(i + 1);
	}
	if (ab.size() % 2 != ba.size() % 2) {
		cout << "-1\n";
		return 0;
	}
	cout << (ab.size() + ba.size()) / 2 + (ab.size() & 1) << '\n';
	if (ab.size() % 2 == 0) {
		for (int i = 0; i < ab.size() / 2; i++)
			cout << ab[i] << ' ' << ab[ab.size() - i - 1] << '\n';
		for (int i = 0; i < ba.size() / 2; i++)
			cout << ba[i] << ' ' << ba[ba.size() - i - 1] << '\n';
	} else {
		for (int i = 0; i < ab.size() / 2; i++)
			cout << ab[i] << ' ' << ab[ab.size() - i - 1] << '\n';
		for (int i = 0; i < ba.size() / 2; i++)
			cout << ba[i] << ' ' << ba[ba.size() - i - 1] << '\n';
		cout << ab[ab.size() / 2] << ' ' << ab[ab.size() / 2] << '\n';
		cout << ab[ab.size() / 2] << ' ' << ba[ba.size() / 2] << '\n';
	}
}