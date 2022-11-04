#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,abm,mmx,tune=native")
#include<vector>
#include<iostream>
#include<stack>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<string>
#include<tuple>
#include<bitset>
#include<queue>
#include<unordered_map>
#include<random>
#include<ctime>
//#include<complex>
#include<numeric>
typedef long long ll;
typedef long double ld;
typedef unsigned short us;
typedef unsigned long long ull;
//typedef complex<double> base;
using namespace std;
ll gcd(ll i, ll j) {
	if (j == 0)return i;
	else return gcd(j, i % j);
}
#ifdef _DEBUG
int __builtin_popcount(int x) { return x ? (__builtin_popcount(x >> 1) + (x & 1)) : 0; }
#endif
template<typename T> inline T getint() {
	T val = 0;
	char c;

	bool neg = false;
	while ((c = getchar()) && !(c >= '0' && c <= '9')) {
		neg |= c == '-';
	}

	do {
		val = (val * 10) + c - '0';
	} while ((c = getchar()) && (c >= '0' && c <= '9'));

	return val * (neg ? -1 : 1);
}
//#define int long long
const ll INF = 1e18 + 100;
const int mod = 31607;
const ld eps = 1e-10, pi = acosl(-1);
const ll maxN = 1e6, maxT = 4010, A = 179, mid = 150;
mt19937 mt_rand(time(0));
ll bp(ll et, ll b) {
	b %= mod - 1;
	ll res = 1;
	for (int i = 30; i >= 0; --i) {
		res = (res * res) % mod;
		if ((b & (1 << i)) != 0)res = (res * et) % mod;
	}
	return res;
}
void panic() {
	cout << "-1\n";
	exit(0);
}
int n;
bool is_cor;
vector<int>ans;
vector<int>color;
pair<bool, vector<pair<int, int>>>try_pair(int v, int u, const vector<vector<int>>& g) {
	vector<int>used(1 << n);
	used[v] = 1;
	used[u] = 2;
	queue<int>q1, q2;
	vector<pair<int, int>>res;
	q1.push(v);
	q2.push(u);
	int c1 = 0, c2 = 0;
	vector<int>ss;
	while (!q1.empty() || !q2.empty()) {
		queue<int>qq;
		while (!q1.empty()) {
			int b = q1.front();
			q1.pop();
			res.push_back({ b,-1 });
			for (auto x : g[b]) {
				if (used[x])
					continue;
				qq.push(x);
				used[x] = used[b];
				++c1;
			}
		}
		q1 = qq;
		while (!qq.empty())qq.pop();
		while (!q2.empty()) {
			int b = q2.front();
			q2.pop();
			ss.push_back(b);
			for (auto x : g[b]) {
				if (used[x])
					continue;
				qq.push(x);
				used[x] = used[b];
				++c2;
			}
		}
		q2 = qq;
	}
	if (c1 != c2)
		return { false,res };
	for (auto x : ss) {
		int cnt = 0;
		for (auto y : g[x]) {
			if (used[y] == 1)++cnt;
		}
		if (cnt != 1)
			return { false,res };
	}
	for (auto& pi : res) {
		int cnt = 0;
		for (auto y : g[pi.first]) {
			if (used[y] == 2) {
				++cnt;
				pi.second = y;
			}
		}
		if (cnt != 1)
			return { false,res };
	}
	ll ss1 = 0, ss2 = 0;
	for (auto x : res) {
		ss1 += g[x.first].size();
		ss2 += g[x.second].size();
	}
	if (ss1 != ss2)return
	{ false,res };
	return { true,res };
}
int is_it_pw_2(int v) {
	int cnt = 0;
	while (v % 2 == 0) {
		v /= 2;
		++cnt;
	}
	if (v != 1)return -1;
	return cnt;
}
int split_it(vector<vector<int>>g, set<int>s) {
	if (s.size() == 1) {
		ans[*s.begin()] = 0;
		return 1;
	}
	int v = *s.begin();
	vector<pair<int, int>>neib;
	for (auto x : g[v]) {
		bool f;
		tie(f, neib) = try_pair(v, x, g);
		if (f)
			break;
	}
	for (auto x : neib) {
		g[x.first].erase(find(g[x.first].begin(), g[x.first].end(), x.second));
		g[x.second].clear();
		s.erase(x.second);
	}
	int szz = split_it(g, s);
	int pp = -1;
	for (int i = 30; i >= 0; --i) {
		if ((szz & (1 << i)) != 0) {
			pp = 1 << i;
			break;
		}
	}
	int ts = szz - pp;
	for (auto x : neib) {
		ans[x.second] = ans[x.first] + s.size();
		if (s.size() * 2 == (1 << n)) {
			color[x.second] = color[x.first];
		}
		else {
			if (ts == 0) {
				color[x.second] = color[x.first] + pp;
			}
			else {
				if (color[x.first] >= pp) {
					int tmp = (color[x.first] - ts) % pp;
					color[x.second] = tmp;
				}
				else {
					int tmp = (color[x.first] + ts) % pp + pp;
					color[x.second] = tmp;
				}
			}
		}
	}
	return szz + 1;
}
void rbld() {
	vector<int>ps(ans.size());
	for (int i = 0; i < ans.size(); ++i)
		ps[ans[i]] = i;
	ans = ps;
}
void solve() {
	cin >> n;
	is_cor = (n == 1) || (n == 2) || (n == 4) || (n == 8) || (n == 16);
	int m = n * (1 << (n - 1));
	vector<vector<int>>g((1 << n), vector<int>());
	ans.assign((1 << n), 0);
	color.assign(1 << n, 0);
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	set<int>s;
	for (int i = 0; i < (1 << n); ++i)
		s.insert(i);
	split_it(g, s);
	for (int i = 0; i < (1 << n); ++i) {
		int tmp = ans[i];
		color[i] = 0;
		for (int j = 0; j < n; ++j) {
			if ((tmp & (1 << j)) != 0) {
				color[i] ^= j;
			}
		}
	}
	rbld();
	for (auto x : ans)cout << x << " "; cout << "\n";
	if (is_cor) {
		for (auto x : color) {
			cout << x << " ";
		}
		cout << "\n";
	}
	else cout << "-1\n";
	//for (int i = 0; i < (1 << n); ++i) {
	//	for (auto x : g[i]) {
	//		cout << color[x] << " ";
	//	}
	//	cout << "\n";
	//}
}
void gen_test() {
	cout << "1\n";
	cout << "8\n";
	int n = 8;
	for (int i = 0; i < n; ++i) {
		for (int st = 0; st < (1 << n); st += (1 << (i + 1))) {
			for (int add = 0; add < (1 << i); ++add) {
				cout << st + add << " " << st + add + (1 << i) << "\n";
			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout.precision(10);
	//srand(time(0));
#ifdef _DEBUG
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
	//freopen("gymnasts.in", "r", stdin); freopen("gymnasts.out", "w", stdout);
#endif
	/*gen_test();
	return 0;*/
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}