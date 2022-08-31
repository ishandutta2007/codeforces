#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int> 
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
using namespace std;

const int N = 1 << 20, mod = 998244353;

int qpow(int x, int y = mod - 2) {
	int res = 1;
	for(; y; x = (ll) x * x % mod, y >>= 1) if(y & 1) res = (ll) res * x % mod;
	return res;
}

struct largue {
	vector < int > x, y; 
	void insert (int vx, int vy) {
		x.push_back(vx);
		y.push_back(vy);
	}
	int query (int w) {
		int ret = 0, n = sz(x);
		L(i, 0, n - 1) {
			int g = 1;
			L(j, 0, n - 1) if (j != i) g = (ll) g * (x[j] - x[i] + mod) % mod;
			g = (ll) qpow (g) * y[i] % mod;
			L(j, 0, n - 1) if (j != i) g = (ll) g * (x[j] - w % mod + mod) % mod;
			(ret += g) %= mod;
		}
		return ret;
	}
} ;

int n, t, x[N], y[N], arr[N], atot, ns;

int tp;
pair < int, int > dt[N];

int getv(int o) {
	vector < pair < int, pair < int, int > > > vc;
	L(i, 1, n) {
		vc.emplace_back(make_pair(y[i] - o, make_pair(x[i] - o, 1)));
		vc.emplace_back(make_pair(y[i] - o, make_pair(x[i] + o + 1, -1)));
		vc.emplace_back(make_pair(y[i] + o + 1, make_pair(x[i] - o, -1)));
		vc.emplace_back(make_pair(y[i] + o + 1, make_pair(x[i] + o + 1, 1)));
	}
	
	sort(vc.begin(), vc.end());

	int ns = 0;
	tp = 0;
	L(i, 0, sz(vc) - 2) {
		dt[++tp] = vc[i].second;
		R(j, tp, 2) 
			if(dt[j] < dt[j - 1]) swap(dt[j], dt[j - 1]);
			else break;
		
		if(vc[i].first == vc[i + 1].first) continue ;
		int sum = 0, cur = 0;
		L(j, 1, tp) {
			cur += dt[j].second;
			if(cur) sum += dt[j + 1].first - dt[j].first;
		}
		(ns += (ll) sum * (vc[i + 1].first - vc[i].first) % mod) %= mod;
	} 
	
	return ns;
}

int val[N];
int main () {
	ios :: sync_with_stdio(false);
	cin.tie (0); cout.tie (0);
	cin >> n >> t;
	
	L(i, 1, n) {
		cin >> x[i] >> y[i];
	}
	L(i, 1, n) 
		L(j, i + 1, n) if((max(abs(x[i] - x[j]), abs(y[i] - y[j])) - 1) / 2 <= t)
			arr[++atot] = (max(abs(x[i] - x[j]), abs(y[i] - y[j])) - 1) / 2;
	
	arr[++atot] = t;
	sort(arr + 1, arr + atot + 1);
	atot = unique(arr + 1, arr + atot + 1) - arr - 1; 
	
	arr[0] = -1;
	
	ns = (ll) getv(t) * (t + 1) % mod;
	
	L(i, 1, atot) {
		
		largue S;
		int sum = 0;
		L(j, 1, 4) 
			(sum += getv(j + arr[i - 1])) %= mod, S.insert(j + arr[i - 1], sum);
		
		(ns += mod - S.query(arr[i])) %= mod;
	}
	
	cout << ns << '\n';
	return 0;
}