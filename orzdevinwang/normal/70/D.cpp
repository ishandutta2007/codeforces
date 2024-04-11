#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define db double
#define pii pair<int, int>
#define sz(a) ((int) (a).size())
#define x first
#define y second
using namespace std;
const int N = 1e5 + 7;
ll det (pii p, pii q) {
	return (ll) p.x * q.y - (ll) p.y * q.x;
}
template <class T> struct Hull {
	T cmp; 
	map<int, int> mp;
	bool check(pii p) {
		auto w = mp.lower_bound(p.x);
		if(w == mp.end()) return false;
		if(p.x == w -> x) return ! cmp(p.y, w -> y);
		if(w == mp.begin()) return false;
		auto a = w; -- a;
		return ! cmp(det(pii(a -> x - p.x, a -> y - p.y), pii(w -> x - p.x, w -> y - p.y)), 0);
	}
	bool remove(map<int, int> :: iterator w) {
		if(w == mp.begin()) return false;
		auto a = w, b = w; --a, ++b;
		if(b == mp.end()) return false; 
		if(! cmp(det(pii(a -> x - w -> x, a -> y - w -> y), pii(b -> x - w -> x, b -> y - w -> y)), 0)) 
			return mp.erase(w), true;
		return false;
	}
	bool insert(pii p) {
		if(check(p)) return false;
		mp[p.x] = p.y;
		auto w = mp.find(p.x);
		if(w != mp.begin()) for(-- w; remove(w ++); -- w);
		if(++ w != mp.end()) for(; remove(w --); ++ w);
		return true;
	}
};
Hull <greater<ll>> u;
Hull <less<ll>> d;
int n;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for(; n; --n) {
		int opt; pii p;
		cin >> opt >> p.x >> p.y;
		if(opt == 1) u.insert(p), d.insert(p);
		else if(u.check(p) && d.check(p)) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}