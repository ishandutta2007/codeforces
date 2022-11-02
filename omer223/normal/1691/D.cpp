#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define _CRT_SECURE_NO_WARNINGS
#define fast ios::sync_with_stdio(false); cin.tie(0);
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define ff first
#define ss second

#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
#include <stack>
#include <set>
#include <map>
#include <deque>
#include <queue>
#include <numeric>
#include <iomanip>
#include <string>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef long double ld;
typedef vector<int> vi;
typedef pair<ld, ld> pld;

template<class T>
struct seglazy {
	vector<pii> lohi;
	vector<T> values, delta;
	int n;
	ll INF_VALUE = -1e17;
private:
	void pushDown(int i) {
		delta[2 * i] += delta[i]; //CHECK
		delta[2 * i + 1] += delta[i];
		delta[i] = 0;
	}
	void update(int i) {
		values[i] = max(values[2 * i] + delta[2 * i], values[2 * i + 1] + delta[2 * i + 1]); //CHECK
	}
	void init(int i, int a, int b) {
		lohi[i].first = a;
		lohi[i].second = b;
		if (a >= b)return;
		int m = (a + b) / 2;
		init(2 * i, a, m);
		init(2 * i + 1, m + 1, b);
	}
	T rangeQueryUtil(int i, int a, int b) {
		if (a > b || lohi[i].first > b || lohi[i].second < a)return INF_VALUE; //CHECK
		else if (lohi[i].first >= a && lohi[i].second <= b) return values[i] + delta[i];
		else {
			pushDown(i);
			T left = rangeQueryUtil(2 * i, a, b);
			T right = rangeQueryUtil(2 * i + 1, a, b);
			update(i);
			return max(left, right); //CHECK
		}
	}
	void rangeUpdateUtil(int i, int a, int b, T val) {
		if (a > b || lohi[i].first > b || lohi[i].second < a)return;
		else if (lohi[i].first >= a && lohi[i].second <= b)delta[i] += val;
		else {
			pushDown(i);
			rangeUpdateUtil(2 * i, a, b, val);
			rangeUpdateUtil(2 * i + 1, a, b, val);
			update(i);
		}
	}
public:
	seglazy(int n) {
		this->n = n;
		lohi.resize(4 * n + 1);
		delta.resize(4 * n + 1);
		values.resize(4 * n + 1);
		fill(values.begin(), values.end(), 0);
		fill(delta.begin(), delta.end(), 0);
		init(1, 0, n - 1);
	}
	seglazy(vector<T> arr) {
		this->n = arr.size();
		lohi.resize(4 * n + 1);
		delta.resize(4 * n + 1);
		values.resize(4 * n + 1);
		fill(delta.begin(), delta.end(), 0);
		init(1, 0, n - 1);
		foru(i, 0, n) rangeUpdate(i, i, arr[i]);
	}
	void rangeUpdate(int from, int to, T val) {
		rangeUpdateUtil(1, from, to, val);
	}
	T rangeQuery(int from, int to) {
		return rangeQueryUtil(1, from, to);
	}
	void print() {
		foru(i, 0, n) {
			cout << rangeQuery(i, i) << ' ';
		}
		cout << '\n';
	}
};


void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    foru(i, 0, n)cin >> a[i];
	if (n == 1) {
		cout << "YES\n";
		return;
	}
    bool bad = 0;
    foru(i, 0, n - 1) {
        if (a[i] > 0 && a[i + 1] > 0) { bad = 1; }
    }
    if (bad) {
        cout << "NO\n";
        return;
    }
    //CEHCEK ZEORS
	/*
	10
7
1 -2 1 -2 3 -1 2
	*/
	foru(rep, 0, 2) {
		seglazy<ll> seg(n);
		vector<pii> ps;
		set<int> und;
		foru(i, 0, n)und.insert(i);
		foru(i, 0, n) {
			if (a[i] > 0)ps.push_back({ a[i],-i });
			else seg.rangeUpdate(i, n - 1, a[i]), und.erase(i);
		}
		//seg.print();
		sort(ps.begin(), ps.end());
		for (auto ii : ps) {
			int pos = -ii.ss, val = ii.ff, pos2;
			auto x = und.upper_bound(pos);
			if (x != und.end()) {
				pos2 = *x;
			}
			else {
				pos2 = n;
			}
			ll bst = seg.rangeQuery(pos + 1, pos2 - 1), phere = seg.rangeQuery(pos, pos);
			if (bst - phere > 0) {
				bad = 1;
			}
			und.erase(pos);
			seg.rangeUpdate(pos, n - 1, val);
			//seg.print();
		}
		reverse(a.begin(), a.end());
	}
	if (bad)cout << "NO\n";
	else cout << "YES\n";
}


int main() {
    fast;
    int t;
    cin >> t;
    while (t--)solve();
    return 0;
}