#include <iostream>

using namespace std;

void lol() {
	int n, k;
	string s;
	cin >> n >> k >> s;
	int r = n;
	for (int i = 0; i < (k+1)/2; i++) {
		int c[128] = {0};
		for (int j = 0; j < n/k; j++) {
			c[s[j*k+i]]++;
			if (k%2 != 1 || i != (k+1)/2-1) {
				c[s[j*k+k-1-i]]++;
			}
		}
		int m = 0;
		for (char z = 'a'; z <= 'z'; z++) {
			m = max(m,c[z]);
		}
		r -= m;
	}
	cout << r << "\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) lol();
}