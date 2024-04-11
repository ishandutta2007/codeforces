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

int cnt[60];
int t;

int f(char i) {
	return (1 << (i - 'a'));
}

void scan() {
	int n;
	cin >> n >> t;
	string s;
	cin >> s;
	t -= f(s[n - 1]);
	t += f(s[n - 2]);

	t = abs(t);
	//cout << t << endl;

	for(int i = 0;i < n - 2;i++) {
		int a = s[i] - 'a';

		t += (1 << a);

		cnt[a + 1]++;
	}
	//cout << t << endl;
}

void solve() {
	scan();
	bool bad = false;
	for(int i = 0;i < 59;i++) {
		//cout << i << " " << cnt[i] << endl;
		if (cnt[i] == 0 && (t & (1ll << i)) != 0) {
			bad = true;
			//cout << i << endl;
		}
		if (t & (1ll << i)) {
			cnt[i]--;
		}
		cnt[i + 1] += cnt[i] / 2;
	}
	if (bad) cout << "No" << endl;
	else cout << "Yes" << endl;
}

signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cout.precision(10);


    solve();
}