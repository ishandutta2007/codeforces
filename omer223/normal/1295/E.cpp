#define _CRT_SECURE_NO_WARNINGS
#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (ll i = k; i < n; i++)
#define ford(i, k, n) for (ll i = k; i >= n; i--)
#define pb push_back
#define ff first
#define ss second
#define mp make_pair

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
#include <iomanip>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<ll> vi;

template<class T>
struct seglazy {
	vector<pii> lohi;
	vector<T> values, delta;
	int n;
	ll INF_VALUE = 1e15;
private:
	void pushDown(int i) {
		delta[2 * i] += delta[i]; //CHECK
		delta[2 * i + 1] += delta[i];
		delta[i] = 0;
	}
	void update(int i) {
		values[i] = min(values[2 * i] + delta[2 * i], values[2 * i + 1] + delta[2 * i + 1]); //CHECK
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
			return min(left, right); //CHECK
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
		foru(i, 0, n)
			cout << this->rangeQuery(i, i) << ' ';
		cout << '\n';
	}
};

const int sz = 2e5 + 5;
ll n, p[sz], a[sz];

int main() {
	fast;
	cin >> n;
	foru(i, 0, n) cin >> p[i];
	foru(i, 0, n)cin >> a[i];
	ll ret = min(a[0], a[n - 1]);
	seglazy<ll> seg(n + 1);
	foru(i, 0, n) {
		seg.rangeUpdate(p[i], n, a[i]);
	}
	foru(i, 0, n) {
		seg.rangeUpdate(p[i], n, -a[i]);
		seg.rangeUpdate(0, p[i] - 1, a[i]);
		if(i!=n-1)ret = min(ret, seg.rangeQuery(0, n));
	}
	cout << ret << '\n';
	return 0;
}