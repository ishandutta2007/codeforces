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
 
const int MAXN = 100005;
int BIT[3*MAXN], lb[MAXN], rb[MAXN], ans[MAXN];
int get(int i) {
	int res = 0;
	while(i > 0) {
		res += BIT[i];
		i -= i & -i;
	}
	return res;
}
void add(int i, int v) {
	while(i < 3*MAXN) {
		BIT[i] += v;
		i += i & -i;
	}
}
int gcd(int x, int y) {
	if(x == 0) return y;
	return gcd(y%x, x);
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
	int n; cin >> n;
	vector<pii> v;
	F0R(i, n) {
		lb[i] = v.size();
		int m; cin >> m;
		vector<pii> p;
		F0R(i, m) {
			int a, b; cin >> a >> b;
			p.pb(mp(a,b));
		}
		F0R(i, m-1) {
			int a = p[i+1].f-p[i].f;
			int b = p[i+1].s-p[i].s;
			int g = abs(gcd(a,b));
			v.pb(mp(a/g,b/g));
		}
		int a = p[0].f-p[m-1].f;
		int b = p[0].s-p[m-1].s;
		int g = abs(gcd(a,b));
		v.pb(mp(a/g,b/g));
		rb[i] = v.size();
	}
	int m; cin >> m;
	vector<pair<pii,int>> q;
	F0R(i, m) {
		int a, b; cin >> a >> b;
		q.pb(mp(mp(b-1,a-1),i));
	}
	sort(q.begin(), q.end());
	int rr = 0;
	map<pii, int> map;
	for(auto x : q) {
		int l = lb[x.f.s], r = rb[x.f.f], i = x.s;
		while(rr < r) {
			if(map.find(v[rr]) != map.end()) add(map[v[rr]]+1, -1);
			map[v[rr]] = rr;
			add(rr+1, 1);
			rr++;
		}
		ans[i] = get(r) - get(l);
	}
	F0R(i, m) cout << ans[i] << endl;
	return 0;
}