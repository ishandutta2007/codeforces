#include <iostream>

using namespace std;

#define N 10000000
int aa[N+1];
int ff[N+1];
int gg[N+1];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	for (int i = 2; i <= N; i++) {
		if (aa[i]) continue;
		for (int j = i; j <= N; j += i) {
			aa[j] = i;
		}
	}
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		int a = aa[x];
		int f = 1, g = 1;
		while (x != 1) {
			if (aa[x] == a) f *= aa[x];
			else g *= aa[x];
			x /= aa[x];
		}
		if (f == 1 || g == 1) ff[i] = gg[i] = -1;
		else {ff[i] = f; gg[i] = g;}
	}
	for (int i = 1; i <= n; i++) cout << ff[i] << " ";
	cout << "\n";
	for (int i = 1; i <= n; i++) cout << gg[i] << " ";
	cout << "\n";
}