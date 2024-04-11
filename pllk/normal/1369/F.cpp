#include <iostream>

using namespace std;

typedef long long ll;

int lose(ll s, ll e);

int win(ll s, ll e) {
	if (e%2 == 0) {
		if (s <= e/2) return lose(s,e/2);
		else return s%2 != e%2;
	} else {
		return s%2 == 0;
	}
}

int lose(ll s, ll e) {
	if (s <= e/2) return win(s,e/2);
	else return 1;
}

ll s[101010];
ll e[101010];

int fwin[101010];
int flose[101010];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> s[i] >> e[i];
	fwin[n] = win(s[n],e[n]);
	flose[n] = lose(s[n],e[n]);
	for (int i = n-1; i >= 1; i--) {
		int w = win(s[i],e[i]);
		int l = lose(s[i],e[i]);
		fwin[i] = (w && !fwin[i+1]) || (l && fwin[i+1]);
		flose[i] = (w && !flose[i+1]) || (l && flose[i+1]);
	}
	cout << fwin[1] << " " << flose[1] << "\n";
}