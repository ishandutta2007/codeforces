#include<bits/stdc++.h>
#define ll long long
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define vi vector < int >
#define sz(a) ((int) a.size())
#define double long double 
using namespace std;
const int N = (1 << 20), mod = 1e9 + 7;
int qpow (int x, int y = mod - 2) {
	int ret = 1;
	for(; y; x = (ll) x * x % mod, y >>= 1) if(y & 1) ret = (ll) ret * x % mod;
	return ret;
}
vector < double > delt[N], val[N];
double ns = 0;
int tp, n, k, pos[N];
map < pair < int, int >, int > mp; 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie (0);
	cout.precision(12), cout << fixed;
	cin >> n >> k;
	L(i, 1, n) {
		int x, y, d;
		cin >> x >> y;
		if(x == 0 && y == 0) continue;
		d = __gcd(abs(x), abs(y));
		auto s = make_pair(x / d, y / d);
		if(!mp[s]) mp[s] = ++tp;
		val[mp[s]].push_back(sqrt ((double) x * x + (double) y * y));
	}
	L(i, 1, tp) {
		sort (val[i].begin(), val[i].end());
		delt[i].resize(sz(val[i]));
		double sum = 0;
		int bf = k - 1, en = sz(val[i]) - 1, it = 0;
		L(j, 0, sz(val[i]) - 1) {
			if(bf < 0) {
				delt[i][j] = - sum * 2 + val[i][it] * bf;
				sum += val[i][it], it += 1;
			}
			else {
				delt[i][j] = val[i][en] * bf;
				bf -= 2, en -= 1;
			}
		}
	}
	priority_queue < pair < double, int > > q;
	L(i, 1, tp) q.push(make_pair(delt[i][0], i)); 
	L(g, 1, k) {
		if(g == k) ns += sz(q) ? max (q.top().first, (double) 0) : 0;
		else {
			auto p = q.top();
			q.pop(), ns += p.first;
			int t = p.second;
			pos[t] += 1;
			if(pos[t] != sz(delt[t])) q.push(make_pair(delt[t][pos[t]], t));
		} 
	}
	cout << ns << "\n";
	return 0;
}