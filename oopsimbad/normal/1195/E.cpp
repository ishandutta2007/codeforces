#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
 
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define f first
#define s second
#define mp make_pair
#define pb push_back
 
const int MAXN = 3005;
const ll MOD = 998244353;

deque<pair<ll,int>> q[MAXN], qq;
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n, m, a, b; cin >> n >> m >> a >> b;
	int g, x, y, z; cin >> g >> x >> y >> z;
	ll cur = g;
	ll ans = 0;
	F0R(i, n) {
		qq.clear();
		F0R(j, m) {
			while(!q[j].empty() && q[j].front().s + a <= i) q[j].pop_front();
			while(!q[j].empty() && q[j].back().f >= cur) q[j].pop_back();
			q[j].push_back(mp(cur, i));
			ll asdf = q[j].front().f;
			while(!qq.empty() && qq.front().s + b <= j) qq.pop_front();
			while(!qq.empty() && qq.back().f >= asdf) qq.pop_back();
			qq.push_back(mp(asdf, j));
			if(i >= a-1 && j >= b-1) ans += qq.front().f;
			cur = (cur * x + y) % z;
		}
	}
	cout << ans << endl;
	return 0;
}