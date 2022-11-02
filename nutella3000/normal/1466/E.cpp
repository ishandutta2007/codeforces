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

const int inf = 1e9 + 4;
const int mod = 1e9 + 7;

signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cout.precision(10);

	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for(int i = 0;i < n;i++)
			cin >> a[i];

		vector<int> cnt(60);
		for(int i = 0;i < n;i++) {
			for(int j = 0;j < 60;j++) {
				if ((a[i] >> j) & 1) cnt[j]++;
			}
		}
		int res = 0;
		for(int i = 0;i < n;i++) {
			int num1 = 0, num2 = 0;
			for(int j = 0;j < 60;j++) {
				if ((a[i] >> j) & 1) {
					num1 += (1ll << j) % mod * cnt[j] % mod;
					num2 += (1ll << j) % mod * n % mod;
				}else {
					num2 += (1ll << j) % mod * cnt[j] % mod;
				}
			}
			num1 %= mod;
			num2 %= mod;
			res += num1 * num2 % mod;
		}
		cout << res % mod << endl;
	}    
}