#include <bits/stdc++.h>
using namespace std;
#define int long long

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T, A, B;
	cin >> T;
	while (T--) {
		cin >> A >> B;
		string s = to_string(B);
		bool a = 0;
		for (char c : s)
			if (c != '9') a = 1;
		if (!a) cout << A * s.size()<< '\n';
		else cout << A * (s.size() - 1) << '\n';
	}
}