#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<vi> vvi;

int main() {
	ios::sync_with_stdio(false);
	
	string a, b;
	cin >> a >> b;

	int n = a.size();
	if (n != b.size())
		cout << "NO\n";
	else {
		int c1 = 0, c2 = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] == '1')
				c1 += 1;
			if (b[i] == '1')
				c2 += 1;
		}

		if (c1 > 0 and c2 > 0 or (c1 == 0 and c2 == 0))
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}