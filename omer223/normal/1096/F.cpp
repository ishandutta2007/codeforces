#define _CRT_SECURE_NO_WARNINGS
#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
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
struct fen {
	vector<T> fenwick;
	int size;
	fen(int sz) {
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
	void add(int index, T add) {
		for (int k = index; k < size; k |= (~k & -~k)) {
			fenwick[k] = fenwick[k] + add;
		}
	}
	void update(int index, T nval) {
		add(index, nval - rangeQuery(index, index));
	}
	T query(int to) {
		T sum = 0;
		for (int curr = to + 1; curr > 0; curr ^= (curr & -curr)) {
			sum = sum + fenwick[curr - 1];
		}
		return sum;
	}
	T rangeQuery(int from, int to) {
		if (!from)return query(to);
		return query(to) - query(from - 1);
	}
	void print() {
		foru(i, 0, size) cout << query(i) << " ";
		cout << endl;
	}
};


template<class T>
struct seglazy {
	vector<pii> lohi;
	vector<T> values, delta;
	int n;
private:
	void pushDown(int i) {
		delta[2 * i] += delta[i];
		delta[2 * i + 1] += delta[i];
		delta[i] = 0;
	}
	void update(int i) {
		values[i] = (lohi[2 * i].second - lohi[2 * i].first + 1) * delta[2 * i] + values[2 * i] + (lohi[2 * i
			+ 1].second - lohi[2 * i + 1].first + 1) * delta[2 * i + 1] + values[2 * i + 1];
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
		else if (lohi[i].first >= a && lohi[i].second <= b) {
			int amt = lohi[i].second - lohi[i].first + 1;
			return values[i] + delta[i] * amt;
		}
		else {
			pushDown(i);
			T left = rangeQueryUtil(2 * i, a, b);
			T right = rangeQueryUtil(2 * i + 1, a, b);
			update(i);
			return left + right;
		}
	}
	void rangeUpdateUtil(int i, int a, int b, T val) {
		if (a > b || lohi[i].first > b || lohi[i].second < a)return;
		else if (lohi[i].first >= a && lohi[i].second <= b) delta[i] += val;
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

const ll mod = 998244353;

void imult(ll & lhs, const ll & rhs) {
    lhs = ((lhs % mod) * (rhs % mod)) % mod;
}

void iadd(ll & lhs, const ll & rhs) {
    lhs = ((lhs % mod) + (rhs % mod)) % mod;
}

void isubt(ll & lhs, const ll & rhs) {
    ll ret = (lhs - rhs) % mod;
    lhs = ret + (ret < 0 ? mod : 0);
}

ll bpw(const ll & lhs, const ll & rhs) {
    if (rhs == 0)return 1;
    ll ret = bpw(lhs, rhs >> 1);
    imult(ret, ret);
    if (rhs & 1) imult(ret, lhs);
    return ret;
}

ll inv(const ll & x) {
    return bpw(x, mod - 2);
}

ll mult(const ll & lhs, const ll & rhs) {
    return ((lhs % mod) * (rhs % mod)) % mod;
}

ll add(const ll & lhs, const ll & rhs) {
    return ((lhs % mod) + (rhs % mod)) % mod;
}

ll subt(const ll & lhs, const ll & rhs) {
    ll ret = (lhs - rhs) % mod;
    return ret + (ret < 0 ? mod : 0);
}

ll divv(const ll & lhs, const ll & rhs) {
    return mult(lhs, inv(rhs));
}

const int sz = 3e5;
int n;
vector<int> a, bads;
int minones = 0;

ll countinv() {
	fen<int> tre(n + 1);
	ll tot = 0;
	foru(i, 0, n) {
		if (a[i] != -1) {
			iadd(tot, tre.rangeQuery(a[i] + 1, n));
			tre.add(a[i], 1);
		}
	}
	return tot;
}

ll countsuf() {
	seglazy<ll> tre(minones);
	ll tot = 0;
	ford(i, n - 1, 0) {
		if (a[i] == -1) {
			iadd(tot, divv(tre.rangeQuery(0, minones - 1), minones));
		}
		else {
			auto pos = lower_bound(bads.begin(), bads.end(), a[i]);
			if (pos != bads.end())
				tre.rangeUpdate(pos - bads.begin(), minones - 1, 1);
		}
	}
	return tot;
}

ll countpre() {
	seglazy<ll> tre(minones);
	ll tot = 0;
	foru(i, 0, n) {
		if (a[i] == -1) {
			iadd(tot, divv(tre.rangeQuery(0, minones - 1), minones));
		}
		else {
			auto pos = lower_bound(bads.begin(), bads.end(), a[i]);
			if (pos != bads.begin()) {
				if (pos == bads.end())tre.rangeUpdate(0, minones - 1, 1);
				else tre.rangeUpdate(0, (pos - bads.begin() - 1), 1);
			}
		}
	}
	return tot;
}

int main() {
    fast;
    ll tot = 0;
    cin >> n;
	a.resize(n);
	vector<bool> vis(n+1);
    foru(i, 0, n) {
		cin >> a[i]; minones += (a[i] == -1);
		if (a[i] != -1)vis[a[i]] = 1;
    }
	foru(i, 1, n + 1) {
		if (!vis[i])bads.push_back(i);
	}
    tot = divv(mult(minones, minones - 1), 4);
    iadd(tot, countinv());
	if(minones)iadd(tot, countpre());
	if(minones)iadd(tot, countsuf());
	cout << tot;
    return 0;
}