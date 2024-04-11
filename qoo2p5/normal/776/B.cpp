#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = (int) 1e9 + 123;
const ll LINF = (ll) 1e18 + 123;
const ld EPS = 1e-8;
const int MOD = (int) 1e9 + 7;

#define sz(x) (int) x.size()

const int N = (int) 1e5 + 123;

const int K = 50;

int n;
int ans[N];
bool used[K];

void run() {
	cin >> n;
	ans[1] = 1;
	
	for (int i = 2; i <= n; i++) {
		fill(used, used + K, false);
		int x = i + 1;
		
		for (int p = 2; p * p <= x; p++) {
			if (x % p == 0) {
				//cerr << i + 1 << " " << p << endl;
				used[ans[p - 1]] = true;
			}
			while (x % p == 0) {
				x /= p;
			}
		}
		
		if (x != 1) {
			used[ans[x - 1]] = true;
		}
		
		ans[i] = 1;
		while (used[ans[i]]) {
			ans[i]++;
		}
	}
	
	int k = *max_element(ans + 1, ans + n + 1);
	cout << k << "\n";
	for (int i = 1; i <= n; i++) {
		cout << ans[i] << " ";
	}
	cout << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	run();
	return 0;
}