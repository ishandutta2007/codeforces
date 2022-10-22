#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define arr array

int n, sameFirst, best, side=0;
string s;

bool isPal(string pal) {
	for (int i=0; i<pal.size()/2; ++i) {
		if (pal[i] != pal[pal.size()-i-1])
			return false;
	}
	return true;
}

void solve() {
	cin >> s;
	n = s.size();
	sameFirst=0;
	best=0;
	for (int i=1; i<=n/2; ++i) {
		if (s[i-1] == s[n-i])
			sameFirst++;
		else
			break;
	}
	for (int i=1; i<=n-2*sameFirst; ++i) {
		if (isPal(s.substr(sameFirst,i))) {
			best = i;
			side = 0;
		}
		else if (isPal(s.substr(n-sameFirst-i,i))) {
			best = i;
			side = 1;
		}
	}

	//display answer
	cout << s.substr(0,sameFirst);

	if (side==0)
		cout << s.substr(sameFirst, best);
	else
		cout << s.substr(n-sameFirst-best, best);

	cout << s.substr(n-sameFirst,sameFirst) << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}