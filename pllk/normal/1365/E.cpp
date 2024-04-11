#include <iostream>

using namespace std;

typedef long long ll;

int n;
ll x[555];

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> x[i];
	ll u = 0;
	for (int a = 1; a <= n; a++) {
		for (int b = 1; b <= n; b++) {
			for (int c = 1; c <= n; c++) {
				u = max(u,x[a]|x[b]|x[c]);
			}
		}
	}
	cout << u << "\n";
}