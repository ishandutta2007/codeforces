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

int n, c, d;
pair<pair<int, int>, pair<int, int>> pc[N], pd[N];

void upd(pair<pair<int, int>, pair<int, int>> &x, pair<int, int> y) {
	pair<int, int> q[3] = {x.first, x.second, y};
	sort(q, q + 3);
	x.first = q[2];
	x.second = q[1];
}

void upd(pair<pair<int, int>, pair<int, int>> &x, pair<pair<int, int>, pair<int, int>> &y) {
	upd(x, y.first);
	upd(x, y.second);
}
 
void run() {
	cin >> n >> c >> d;
	fill(pc, pc + N, mp(mp(-INF, -INF), mp(-INF, -INF)));
	fill(pd, pd + N, mp(mp(-INF, -INF), mp(-INF, -INF)));
	
	rep(i, 0, n) {
		int b, p;
		cin >> b >> p;
		char c;
		cin >> c;
		if (c == 'C') {
			upd(pc[p], mp(b, i));
		} else {
			upd(pd[p], mp(b, i));
		}
	}
	
	rep(i, 1, N) {
		upd(pc[i], pc[i - 1]);
		upd(pd[i], pd[i - 1]);
	}
	
	int ans = 0;
	
	rep(i, 1, c + 1) {
		{ // C, C
			pair<int, int> my = pc[i].first;
			auto other = pc[c - i];
			if (my.second == other.first.second) {
				maxi(ans, my.first + other.second.first);
			} else {
				maxi(ans, my.first + other.first.first);
			}
		}
		
		{ // C, D
			pair<int, int> my = pc[i].first;
			pair<int, int> other = pd[d].first;
			maxi(ans, my.first + other.first);
		}
	}
	
	rep(i, 1, d + 1) {
		{ // D, D
			pair<int, int> my = pd[i].first;
			auto other = pd[d - i];
			if (my.second == other.first.second) {
				maxi(ans, my.first + other.second.first);
			} else {
				maxi(ans, my.first + other.first.first);
			}
		}
		
		{ // D, C
			pair<int, int> my = pd[i].first;
			pair<int, int> other = pc[c].first;
			maxi(ans, my.first + other.first);
		}
	}
	
	cout << ans << "\n";
}