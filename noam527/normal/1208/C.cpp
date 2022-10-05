#include <bits/stdc++.h>
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 1e18;
const int OO = 1;
const int OOO = 1;
using namespace std;

int n;
int a[1005][1005];

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	int nxt = 0;
	for (int i = 0; i < 4; i++) for (int j = 0; j < 4; j++)
		a[i][j] = nxt++;
	for (int k = 4; k < n; k += 4) {
		for (int i = 0; i < k + 4; i++)
			for (int j = k; j < k + 4; j++)
				a[i][j] = nxt++;
		for (int j = 0; j < k; j++)
			for (int i = k; i < k + 4; i++)
				a[i][j] = nxt++;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) cout << a[i][j] << " "; cout << '\n';
	}
}