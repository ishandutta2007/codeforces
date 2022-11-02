#include <bits/stdc++.h>

using namespace std;


mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

#define aidar asadulin
 
#define int long long
#define ll long long
#define mp make_pair
#define pii pair<int, int>
#define pip pair<int, pii>
#define fi first
#define se second
#define all(_v) _v.begin(), _v.end()
#define sz(a) (int) (a.size())
#define chkmax(a, b) a = max(a, b)
#define chkmin(a, b) a = min(a, b)
#define ld double

const int inf = 1e9 + 32123;
const int max_n = 101;


int n;
int a[max_n], b[max_n];

int dp1[max_n][max_n * max_n], dp2[max_n][max_n * max_n];


void solve() {
	cin >> n;
	int sum = 0;
	for(int i = 0;i < n;i++) {
		cin >> a[i] >> b[i];
		sum += a[i];
	}

	for(int j = 0;j <= n;j++) {
		for(int sum_a = 1;sum_a < max_n * max_n;sum_a++) {
			dp2[j][sum_a] = -inf;
			dp1[j][sum_a] = -inf;
		}
	}

	for(int i = 0;i < n;i++) {
		for(int j = 0;j <= n;j++) {
			for(int sum_a = 0;sum_a < max_n * max_n;sum_a++) {
				dp1[j][sum_a] = dp2[j][sum_a] + b[i];
				if (sum_a >= a[i] && j >= 1) chkmax(dp1[j][sum_a], dp2[j - 1][sum_a - a[i]] + b[i] * 2);
			}
		}

		for(int j = 0;j <= n;j++) {
			for(int sum_a = 0;sum_a < max_n * max_n;sum_a++)
				dp2[j][sum_a] = dp1[j][sum_a];
		}
	}

	for(int i = 1;i <= n;i++) {
		double q = 0;
		for(int sum_a = 0;sum_a < max_n * max_n;sum_a++) {
			double w = q;
			chkmax(q, min((double)dp1[i][sum_a] / 2, (double)sum_a));
			//if (w != q) cout << i << " " << q << " " << sum_a << endl;
		}

		cout << q << " ";
	}
}


signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cout.precision(10);

    solve();
}