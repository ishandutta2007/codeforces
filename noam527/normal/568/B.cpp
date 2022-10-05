#include <bits/stdc++.h>
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 2e18;
const int OO = 1;
const int OOO = 1;
using namespace std;

const int N = 4004;

int ch[N][N] = {};
int P[N], Q[N];

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	ch[0][0] = 1;
	for (int i = 1; i < N; i++) {
		ch[i][0] = 1;
		for (int j = 1; j <= i; j++) {
			ch[i][j] = (ch[i - 1][j] + ch[i - 1][j - 1]) % md;
		}
	}
	P[0] = Q[0] = 1;
	for (int i = 1; i < N; i++) {
		P[i] = P[i - 1];
		Q[i] = 0;
		for (int k = 1; k <= i; k++) {
			P[i] = (P[i] + (ll)ch[i - 1][k - 1] * P[i - k]) % md;
			Q[i] = (Q[i] + (ll)ch[i - 1][k - 1] * Q[i - k]) % md;
		}
	}

	int n;
	cin >> n;
	cout << ((P[n] - Q[n]) % md + md) % md << '\n';
}