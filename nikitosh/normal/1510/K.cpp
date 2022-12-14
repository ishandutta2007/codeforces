#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define sz(x) (int)((x).size())
#define forn(i,n) for(int i = 0; i < (n); i++)
#define fornr(i,n) for(int i = (n) - 1; i >= 0; --i)
#define forab(i,a,b) for(int i = (a); i < (b); i++)
#define all(c) (c).begin(), (c).end()

using ll = long long;
using vi = vector<int>;
using pii = pair<int,int>;

const int INF = 1e9 + 7;

bool sorted(vector<pii> &a, int n) {
	forn(i, 2 * n) {
		if (a[i].fst != i) {
			return false;
		}
	}
	return true;
}

int solve(vector<pii> a, int n, int s) {
	int cnt = 0;
	while(!sorted(a, n)) {
		if (cnt) {
			bool bad = true;
			forn(i, 2 * n) {
				if (a[i].snd != i) {
					bad = false;
					break;
				}
			}
			if (bad) {
				return INF;
			}	
		}
		if (s & 1) {
			forn(i, n) {
				swap(a[2 * i], a[2 * i + 1]);
			}
		} else {
			forn(i, n) {
				swap(a[i], a[n + i]);
			}
		}
		s++;
		cnt++;
	}
	return cnt;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	vector<pii> a(2 * n);
	forn(i, 2 * n) {
		cin >> a[i].fst;
		a[i].fst--;
		a[i].snd = i;
	}
	int ans = min(solve(a, n, 0), solve(a, n, 1));
	if (ans == INF) {
		cout << -1 << '\n';
	} else {
		cout << ans << '\n';
	}
	return 0;
}