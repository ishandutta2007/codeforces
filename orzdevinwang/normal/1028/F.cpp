#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define sz(a) ((int) (a).size())
#define vi vector < int >
#define me(a, x) memset(a, x, sizeof(a))
#define ull unsigned long long 
using namespace std;
const int N = 1e6 + 7;
ll inf = 1e9 + 7;
map < pair < int, int >, int > qwq;
map < ll, set < pair < int, int > > > mp;
void cg(int A, int B, int w) {
	int g = __gcd(A, B);
	A /= g, B /= g;
	qwq[make_pair(A, B)] += w;
}
void calc(ll d, pair < int, int > g, int w) {
	cg(g.first, g.second, w);
	for(auto o : mp[d]) 
		cg(o.first + g.first, o.second + g.second, w * 2);
}
int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t, xn = 0;
	cin >> t;
	while(t--) {
		int op, x, y;
		cin >> op >> x >> y;
		ll dis = (ll) x * x + (ll) y * y; 
		if(op == 1) {
			calc(dis, make_pair(x, y), 1);
			mp[dis].insert(make_pair(x, y));
			xn += 1;
		} else if(op == 2) {
			mp[dis].erase(make_pair(x, y));
			calc(dis, make_pair(x, y), -1);
			xn -= 1;
		} else if(op == 3) {
			int g = __gcd(x, y);
			x /= g, y /= g;
			cout << xn - qwq[make_pair(x, y)] << '\n';
		}
	}
	return 0;
}