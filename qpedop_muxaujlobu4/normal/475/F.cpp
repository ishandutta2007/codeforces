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
typedef unsigned long long ull;
//typedef complex<double> base;
using namespace std;
ll gcd(ll i, ll j) {
	if (i < j)swap(i, j);
	if (j == 0)return i;
	else return gcd(j, i % j);
}
#ifdef _DEBUG
int __builtin_popcount(int x) { return x ? (__builtin_popcount(x >> 1) + (x & 1)) : 0; }
ll __builtin_popcount(ll x) { return x ? (__builtin_popcount(x >> 1) + (x & 1)) : 0; }
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
const int mod = 1000000007;
const ld eps = 1e-9, pi = acos(-1);
const int maxN = 300005, maxT = 2e9, A = 179;
ll bp(ll et, ll b) {
	ll res = 1;
	for (int i = 30; i >= 0; --i) {
		res = (res * res) % mod;
		if ((b & (1 << i)) != 0)res = (res * et) % mod;
	}
	return res;
}
int res = 0;
queue<vector<pair<int, int>>>st;
void govno(const vector<pair<int, int>>&a) {
	set<pair<int, int>>sx, sy;
	set<int>allx, ally;
	multiset<int>vx, vy;
	int n = a.size();
	for (int i = 0; i < n; ++i) {
		sx.insert({ a[i].first,i });
		sy.insert({ a[i].second,i });
		vx.insert(a[i].first);
		vy.insert(a[i].second);
		allx.insert(a[i].first);
		ally.insert(a[i].second);
	}
	while (true) {
		auto lx = allx.begin();
		auto rx = allx.end();
		--rx;
		auto ly = ally.begin();
		auto ry = ally.end();
		--ry;
		vector<int>to_del;
		while ((*lx) + 1 < (*rx) && (*ly) + 1 < (*ry)) {
			if ((*lx) + 1 < (*rx)) {
				int l = (*lx), r = (*rx);
				if (!allx.count(l + 1)) {
					auto it = sx.lower_bound({ l + 1,0 });
					while (it != sx.begin()) {
						--it;
						to_del.push_back((*it).second);
					}
					break;
				}
				if (!allx.count(r - 1)) {
					auto it = sx.lower_bound({ r,0 });
					while (it != sx.end()) {
						to_del.push_back((*it).second);
						++it;
					}
					break;
				}
				++lx;
				//++ly;
				--rx;
			}
			if ((*ly) + 1 < (*ry)) {
				int l = (*ly), r = (*ry);
				if (!ally.count(l + 1)) {
					auto it = sy.lower_bound({ l + 1,0 });
					while (it != sy.begin()) {
						--it;
						to_del.push_back((*it).second);
					}
					break;
				}
				if (!ally.count(r - 1)) {
					auto it = sy.lower_bound({ r,0 });
					while (it != sy.end()) {
						to_del.push_back((*it).second);
						++it;
					}
					break;
				}
				++ly;
				//++ly;
				--ry;
			}
		}
		if (to_del.empty()) {
			while ((*lx) + 1 < (*rx)) {
				int l = (*lx), r = (*rx);
				if (!allx.count(l + 1)) {
					auto it = sx.lower_bound({ l + 1,0 });
					while (it != sx.begin()) {
						--it;
						to_del.push_back((*it).second);
					}
					break;
				}
				if (!allx.count(r - 1)) {
					auto it = sx.lower_bound({ r,0 });
					while (it != sx.end()) {
						to_del.push_back((*it).second);
						++it;
					}
					break;
				}
				++lx;
				//++ly;
				--rx;
			}
		}
		if (to_del.empty()) {
			while ((*ly) + 1 < (*ry)) {
				int l = (*ly), r = (*ry);
				if (!ally.count(l + 1)) {
					auto it = sy.lower_bound({ l + 1,0 });
					while (it != sy.begin()) {
						--it;
						to_del.push_back((*it).second);
					}
					break;
				}
				if (!ally.count(r - 1)) {
					auto it = sy.lower_bound({ r,0 });
					while (it != sy.end()) {
						to_del.push_back((*it).second);
						++it;
					}
					break;
				}
				++ly;
				//++ly;
				--ry;
			}
		}
		if (to_del.empty())break;
		vector<pair<int, int>>tmp;
		for (auto x : to_del) {
			sx.erase({ a[x].first,x });
			sy.erase({ a[x].second,x });
			vx.erase(vx.find(a[x].first));
			vy.erase(vy.find(a[x].second));
			tmp.push_back(a[x]);
			if (vx.find(tmp.back().first) == vx.end())allx.erase(tmp.back().first);
			if (vy.find(tmp.back().second) == vy.end())ally.erase(tmp.back().second);
		}
		st.push(tmp);
	}
	++res;
}
void solve() {
	int n = getint<int>();
	vector<pair<int, int>>a(n);
	for (auto& x : a) {
		x.first = rand();
		x.second = rand() % 20;
		x.first = getint<int>();
		x.second = getint<int>();
	}
	st.push(a);
	while (!st.empty()) {
		govno(st.front());
		st.pop();
	}
	cout << res << "\n";
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout.precision(10);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
	//freopen("labyrinth.in", "r", stdin); freopen("labyrinth.out", "w", stdout);
#endif
	int t = 1;
	//cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}