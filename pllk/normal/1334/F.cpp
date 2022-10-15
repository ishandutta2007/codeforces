#include <iostream>

using namespace std;

typedef long long ll;

#define N (1<<20)
ll pp[2*N];

void add(int k, int x) {
	k += N;
	pp[k] += x;
	for (k /= 2; k >= 1; k /= 2) {
		pp[k] = pp[2*k]+pp[2*k+1];
	}
}

ll sum(int a, int b) {
	a += N; b += N;
	ll s = 0;
	while (a <= b) {
		if (a%2 == 1) s += pp[a++];
		if (b%2 == 0) s += pp[b--];
		a /= 2; b /= 2;
	}
	return s;
}

int n;
int a[505050];
ll p[505050];
int m;
int b[505050];
int bp[505050];

ll dp[505050];
int dv[505050];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> p[i];
	cin >> m;
	for (int i = 1; i <= m; i++) {
		cin >> b[i];
		bp[b[i]] = i;
	}
	ll uu = 0;
	for (int i = 1; i <= n; i++) {
		int z = bp[a[i]];
		if (z != 0 && (z == 1 || dv[z-1])) {
			ll dd = 0;
			if (p[i] < 0) dd -= p[i];
			if (z == 1) {
				dd += sum(1,b[m]);
				if (z != m) dd -= sum(b[z]+1,b[m]);
			} else {
				dd += dp[z-1];
				dd += sum(b[z-1]+1,b[m]);
				if (z != m) dd -= sum(b[z]+1,b[m]);
			}
			if (dv[z] == 0) dp[z] = dd;
			else dp[z] = min(dp[z],dd);
			dv[z] = 1;
		}
		if (p[i] < 0 || a[i] > b[m]) {
			uu += p[i];
		} else {
			add(a[i],p[i]);
		}
	}
	if (dv[m]) {
		cout << "YES\n";
		cout << dp[m]+uu << "\n";
	} else {
		cout << "NO\n";
	}
}