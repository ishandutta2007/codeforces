#define _CRT_SECURE_NO_WARNINGS
#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (ll i = k; i < n; i++)
#define ford(i, k, n) for (ll i = k; i >= n; i--)
#define pb push_back
#define ff first
#define ss second

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>
#include <queue>
#include <bitset>
#include <set>
#include <deque>
#include <stack>
#include <map>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;
typedef pair<ll, ll> pll;

template<class T>
struct fen {
	vector<T> fenwick;
	ll size;
	fen(ll sz) {
		size = sz;
		fenwick.resize(size);
		foru(i, 0, size)fenwick[i] = 0;
	}
	fen(vector<T> arr) {
		size = arr.size();
		fenwick.resize(size);
		foru(i, 0, size)fenwick[i](0);
		foru(i, 0, size)update(i, arr[i]);
	}
	void add(ll index, T add) {
		for (ll k = index; k < size; k |= (~k & -~k)) {
			fenwick[k] = fenwick[k] + add;
		}
	}
	void update(ll index, T nval) {
		add(index, nval - rangeQuery(index, index));
	}
	T query(ll to) {
		if (to < 0)return 0;
		T sum = 0;
		for (ll curr = to + 1; curr > 0; curr ^= (curr & -curr)) {
			sum = sum + fenwick[curr - 1];
		}
		return sum;
	}
	T rangeQuery(ll from, ll to) {
		if (from > to)return 0;
		if (!from)return query(to);
		return query(to) - query(from - 1);
	}
	void prll() {
		foru(i, 0, size) cout << query(i) << " ";
		cout << endl;
	}
};

const ll sz = 2e5 + 5;
ll n;
pii xv[sz];
vector<int> tmp;
map<int, int> rkspeed;

int main() {
    fast;
    cin >> n;
    foru(i, 0, n)cin >> xv[i].ff;
    foru(i, 0, n)cin >> xv[i].ss;
    sort(xv, xv + n);
	foru(i, 0, n)tmp.push_back(xv[i].ss);
	sort(tmp.begin(), tmp.end());
	vector<int> t2{ tmp[0] };
	foru(i, 1, n) {
		if (tmp[i] != t2.back())t2.push_back(tmp[i]);
	}
	foru(i, 0, t2.size())rkspeed[t2[i]] = i;
	fen<int> fcnt(n);
	fen<ll> sums(n);
	ll tot = 0;
	foru(i, 0, n) {
		int mrk = rkspeed[xv[i].ss];
		ll bamt = fcnt.query(mrk);
		tot += bamt * xv[i].ff - sums.query(mrk);
		fcnt.add(mrk, 1);
		sums.add(mrk, xv[i].ff);
	}
    cout << tot;
    
    return 0;
}