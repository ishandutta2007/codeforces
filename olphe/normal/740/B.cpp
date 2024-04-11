#include "iostream"
#include "algorithm"
using namespace std;

int m, n;
int a[101];
int s, e;
int box;
int ans;

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> s >> e;
		box = 0;
		for (int i = s; i <= e; i++) {
			box += a[i];
		}
		if (box > 0)ans += box;
	}
	cout << ans << "\n";
	return 0;
}