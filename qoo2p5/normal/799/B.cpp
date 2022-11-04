#include <bits/stdc++.h>
  
using namespace std;
  
typedef long long ll;
typedef double ld;
  
const int INF = (int) 1e9 + 123;
const ll LINF = (ll) 1e18 + 123;
const ll MOD = (ll) 1e9 + 7;
const ld EPS = 1e-12;
  
#define sz(x) (int) (x).size()
#define mp make_pair
#define pb push_back
#define rep(i, s, t) for (int i = s; i < t; i++)
#define all(x) (x).begin(), (x).end()
#define ub(s, t, x) (int) (upper_bound(s, t, x) - s)
#define lb(s, t, x) (int) (lower_bound(s, t, x) - s)
  
template<typename A, typename B> bool mini(A &x, const B &y) {
    if (y < x) {
        x = y;
        return 1;
    }
    return 0;
}
  
template<typename A, typename B> bool maxi(A &x, const B &y) {
    if (y > x) {
        x = y;
        return 1;
    }
    return 0;
}
  
void add(ll &x, ll y) {
    x += y;
    if (x >= MOD) x -= MOD;
    if (x < 0) x += MOD;
}
  
ll sum(ll x, ll y) {
    add(x, y);
    return x;
}
  
void run();
  
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    run();
    return 0;
}
 
// SOLUTION //

const int N = (int) 2e5 + 123;

set<pair<int, int>> q[2][4];
int p[N], a[N], b[N];
 
void run() {
	int n;
	cin >> n;
	rep(i, 0, n)cin >> p[i];
	rep(i, 0, n)cin >> a[i];
	rep(i, 0, n)cin >> b[i];
	rep(i, 0, n) {
		q[0][a[i]].insert({p[i], i});
		q[1][b[i]].insert({p[i], i});
	}
	int m;
	cin >> m;
	rep(i, 0, m) {
		int c;
		cin >> c;
		pair<int, int> best = {INF, -INF};
		rep(j, 0, 2) {
			if (!q[j][c].empty()) {
				mini(best, *q[j][c].begin());
			}
		}
		if (best.first == INF) {
			cout << "-1 ";
		} else {
			q[0][a[best.second]].erase(best);
			q[1][b[best.second]].erase(best);
			cout << best.first << " ";
			
		}
	}
	cout << "\n";
}