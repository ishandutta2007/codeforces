#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <list>
#include <bitset>
#include <numeric>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

template<class T>
struct seglazy {
	vector<pii> lohi;
	vector<T> values, delta;
	int n;
	const ll INF_VALUE = INT_MAX;
private:
	void pushDown(int i) {
		delta[2 * i] = delta[i]; //CHECK
		delta[2 * i + 1] = delta[i];
		delta[i] = -1;
	}
	void update(int i) {
		values[i] = (delta[2 * i] == -1 ? values[2 * i] : (lohi[2 * i].second - lohi[2 * i].first + 1)*delta[2 * i]) +
			(delta[2 * i + 1] == -1 ? values[2 * i + 1] : (lohi[2 * i + 1].second - lohi[2 * i + 1].first + 1)*delta[2 * i + 1]); //CHECK
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
		if (a > b || lohi[i].first > b || lohi[i].second < a)return 0; //CHECK
		else if (lohi[i].first >= a && lohi[i].second <= b) return (delta[i] == -1 ? values[i] : (lohi[i].second - lohi[i].first + 1)*delta[i]);
		else {
			if (delta[i] != -1)pushDown(i);
			T left = rangeQueryUtil(2 * i, a, b);
			T right = rangeQueryUtil(2 * i + 1, a, b);
			update(i);
			return left + right; //CHECK
		}
	}
	void rangeUpdateUtil(int i, int a, int b, T val) {
		if (a > b || lohi[i].first > b || lohi[i].second < a)return;
		else if (lohi[i].first >= a && lohi[i].second <= b)delta[i] = val;
		else {
			if (delta[i] != -1)pushDown(i);
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
		fill(delta.begin(), delta.end(), -1);
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
};

string s, f;
int n;

void solve() {
	int q;
	cin >> n >> q >> s >> f;
	vector<pii> qu;
	foru(i, 0, q) {
		pii tttt;
		cin >> tttt.ff >> tttt.ss;
		qu.pb(tttt);
	}
	vector<int> arr(n);
	foru(i, 0, n)arr[i] = (f[i] == '1');
	seglazy<int> sg(arr);
	reverse(qu.begin(), qu.end());
	bool bad = 0;
	for (pii query : qu) {
		int l = query.ff, r = query.ss; l--; r--;
		int amt = r - l + 1, ones = sg.rangeQuery(l, r);
		if (2*ones < amt) {
			sg.rangeUpdate(l, r, 0);
		}
		else if (2*(amt - ones) < amt) {
			sg.rangeUpdate(l, r, 1);
		}
		else {
			bad = 1;
			break;
		}
	}
	if (bad) {
		cout << "NO\n";
		return;
	}
	foru(i, 0, n) {
		if ('0' + sg.rangeQuery(i, i) != s[i]) {
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
	return;
}

int main() {
	fast;
	int t;
	cin >> t;
	while (t--)solve();
	return 0;
}