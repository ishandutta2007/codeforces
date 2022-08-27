#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define pii pair<int, int>
#define x first
#define y second
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 1e5 + 7, mod = 998244353;
template<typename T> inline void cmax(T &x, T y) { if(x < y) x = y; }
template<typename T> inline void cmin(T &x, T y) { if(y < x) x = y; }
using namespace std;
int n, m, sm, k[N], pos[N], cnt[N], mx;
vector<int> v[N];
void Main() {
	cin >> n >> m, sm = (m + 1) / 2;
	L(i, 1, n) cnt[i] = 0;
	L(i, 1, m) {
		cin >> k[i], pos[i] = 0;
		v[i].resize(k[i]);
		L(j, 0, k[i] - 1) cin >> v[i][j];
		cnt[v[i][0]] ++;
	}
	mx = 1;
	L(i, 2, n) if(cnt[i] > cnt[mx]) mx = i;
	if(cnt[mx] > sm) {
		L(i, 1, m) if(k[i] > 1 && v[i][0] == mx) {
			cnt[mx] --, pos[i] = 1;
			if(cnt[mx] <= sm) break;
		}
		if(cnt[mx] > sm) {
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
	L(i, 1, m) cout << v[i][pos[i]] << " ";
	cout << "\n";
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	while(T--) Main();
	return 0;
}