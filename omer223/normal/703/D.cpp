#define _CRT_SECURE_NO_WARNINGS
#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define mp make_pair

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <math.h>
#include <unordered_map>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ppp;
typedef pair<ppp, int> pii;
typedef pair<ll, ll> pll;
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
		foru(i, 0, size)fenwick[i] = 0;
		foru(i, 0, size)update(i, arr[i]);
	}
	void add(int index, T add) {
		for (int k = index; k < size; k |= (~k & -~k)) {
			fenwick[k] ^= add;
		}
	}
	void update(int index, T nval) {
		add(index, nval ^ rangeQuery(index, index));
	}
	T query(int to) {
		T sum = 0;
		for (int curr = to + 1; curr > 0; curr ^= (curr & -curr)) {
			sum ^= fenwick[curr - 1];
		}
		return sum;
	}
	T rangeQuery(int from, int to) {
		if (!from)return query(to);
		return query(to) ^ query(from - 1);
	}
	void print() {
		foru(i, 0, size) cout << query(i) << " ";
		cout << endl;
	}
};


const int sz = 1e6;
int n;
int a[sz], ans[sz], pre[sz];
unordered_map<int, int> lst;

int query(int l, int r) {
	return pre[r] ^ (l ? pre[l - 1] : 0);
}

int main() {
	scanf("%d", &n);
	foru(i, 0, n) {
		scanf("%d", &a[i]);
		if (!i)pre[i] = a[i];
		else pre[i] = pre[i - 1] ^ a[i];
	}
	int q, l, r;
	vector<pii> v;
	scanf("%d", &q);
	foru(i,0,q) {
		scanf("%d %d", &l, &r); l--; r--;
		v.pb({ mp(l, r), i });
	}
	sort(v.begin(),v.end(), 
		[](const pii& lhs, const pii& rhs) -> bool {
		if (lhs.first.second != rhs.first.second)return lhs.first.second < rhs.first.second;
		else return lhs.first.first < rhs.first.first;
	});
	fen<int> f(n);
	r = 0;
	foru(i, 0, q) {
		if (!i || v[i].first.second >= r) {
			for (; r <= v[i].first.second; r++) {
				if (lst.find(a[r]) != lst.end())f.add(lst[a[r]], a[r]);
				f.update(r, a[r]);
				lst[a[r]] = r;
			}
		}
		ans[v[i].second] = query(v[i].first.first, v[i].first.second) ^ f.rangeQuery(v[i].first.first, v[i].first.second);
	}
	foru(i, 0, q)printf("%d\n", ans[i]);
	return 0;
}