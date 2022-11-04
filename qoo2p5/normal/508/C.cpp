#include <iostream>

using namespace std;

int m, t, r;
bool w[1000];
int candles[1000];

int main() {
	ios::sync_with_stdio(false);

	cin >> m >> t >> r;

	for(int i = 0; i < m; i++) {
		int x;
		cin >> x;
		w[x] = true;
	}

	if(t < r) {
		cout << -1 << endl;
		return 0;
	}

	int ans = 0;

	for(int i = 1; i <= 400; i++) {
		if(w[i]) {
			int need = r - candles[i];
			ans += need;

			for(int j = i - need; j < i; j++) {
				for(int z = max(j+1, 1); z <= j + t; z++) {
					candles[z]++;
				}
			}
		}
	}

	cout << ans << endl;

	return 0;
}