#define MOD 1000000007
#define fast ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define mp make_pair
#define has(set, x) set.find(x) != set.end()
#define nohas(set, x) set.find(x) == set.end()
#define inc(mpp, x) {if(has(mpp, x)) mpp[x]++; else mpp.insert(mp(x,1));}
#define decc(mpp, x) {if(has(mpp, x)) {if(mpp[x] > 1) mpp[x]--; else mpp.erase(x);}}
#define F first
#define S second
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vvi vector<vi>
#define um unordered_map
#define us unordered_set
#include <iostream>
#include <list>
#include <queue>
#include <vector>
#include <map>
#include <string>
#include <cmath>
#include <math.h>
#include <unordered_map>
#include <iomanip>
#include <set>
#include <unordered_set>
#include <fstream>
#include <algorithm>
#include <chrono>
#include <stack>
#include <numeric>
#include <queue>
#include <bitset>
using namespace std;
const int INF = 1 << 29;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
inline int two(int n) { return 1 << n; }
ll extgcd(ll a, ll b, ll& x, ll& y) { if (b == 0) { x = 1; y = 0; return a; } else { int g = extgcd(b, a%b, y, x); y -= a / b * x; return g; } }
template<class T>
struct seglazy {
private:
	vector<pii> lohi;
	vector<T> values, delta;
	int n;
	ll INF_VALUE = -INT_MAX;
	void pushDown(int i) {
		delta[2 * i] += delta[i];
		delta[2 * i + 1] += delta[i];
		delta[i] = 0;
	}
	void update(int i) {
		values[i] = max(values[2 * i] + delta[2 * i], values[2 * i + 1] + delta[2 * i + 1]);
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
		if (a > b || lohi[i].first > b || lohi[i].second < a)return INF_VALUE;
		else if (lohi[i].first >= a && lohi[i].second <= b) return values[i] + delta[i];
		else {
			pushDown(i);
			T left = rangeQueryUtil(2 * i, a, b);
			T right = rangeQueryUtil(2 * i + 1, a, b);
			update(i);
			return max(left, right);
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
};
const int sz = 2e5 + 5;

tuple<ll, ll, ll> ms[sz];
pll a[sz], b[sz];
ll n, m, p, bestprofituntil[sz];

void input() {
	cin >> n >> m >> p;
	foru(i, 0, n)cin >> a[i].first >> a[i].second;
	foru(i, 0, m)cin >> b[i].first >> b[i].second;
	foru(i, 0, p) {
		ll pp, qq, rr;
		cin >> pp >> qq >> rr;
		ms[i] = make_tuple(qq, pp, rr);
	}
	sort(a, a + n);
	sort(b, b + m);
	sort(ms, ms + p);
}

ll calcDp() {
	ll bestProfit = -1e18;
	int iter = 0;
	seglazy<ll> prof(n);
	foru(i, 0, n)prof.rangeUpdate(i, i, -a[i].second);
	foru(i, 0, m) {
		ll curr = -b[i].second;
		while (iter < p&&get<0>(ms[iter]) < b[i].first) {
			int l = 1, r = n, mid, bst = -1;
			while (l <= r) {
				mid = (l + r + 1) / 2;
				if (a[mid - 1].first > get<1>(ms[iter])) {
					bst = mid - 1;
					r = mid - 1;
				}
				else l = mid + 1;
			}
			if (bst != -1) prof.rangeUpdate(bst, n - 1, get<2>(ms[iter]));
			iter++;
		}
		bestProfit = max(bestProfit, curr + prof.rangeQuery(0, n - 1));
	}
	return bestProfit;
}

int main() {
	fast;
	ifstream in("input.txt");
	ofstream out("output.txt");
	input();
	cout << calcDp() << endl;
	return 0;
}