#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
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
#include <unordered_map>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
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
	void add(int index, T add) {
		for (int k = index; k < size; k |= (~k & -~k)) {
			fenwick[k] = fenwick[k] + add;
		}
	}
	T query(int to) {
		T sum = 0;
		for (int curr = to + 1; curr > 0; curr ^= (curr & -curr)) {
			sum = sum + fenwick[curr - 1];
		}
		return sum;
	}
	void print() {
		foru(i, 0, size) cout << query(i) << " ";
		cout << endl;
	}
};

const int sz = 1e5 + 5;

struct dish {
	int p, s, b;
	dish(int _p, int _s, int _b) :p(_p), s(_s), b(_b) {}
	dish(){}
};

struct person {
	int pref, inc;
	person(int _pref, int _inc) :pref(_pref), inc(_inc) {}
	person(){}
};

int n, m;
dish di[sz];
person pe[sz];

void input() {
	cin >> n >> m;
	vector<int> p(n+m), s = p, b = s;
	foru(i, 0, n) cin >> p[i];
	foru(i, 0, n) cin >> s[i];
	foru(i, 0, n) cin >> b[i], di[i] = dish(p[i], s[i], b[i]);
	foru(i, 0, m)cin >> p[i];
	foru(i, 0, m)cin >> s[i], pe[i] = person(s[i], p[i]);
}

fen<int>* ds[2];
vector<pii> dsvec[2];
int idxinv[2][sz];

void init() {
	foru(idx, 0, 2) {
		foru(i, 0, n) {
			int quan = (idx ? di[i].p + di[i].b : di[i].p - di[i].b);
			dsvec[idx].push_back({ quan,i });
		}
		sort(dsvec[idx].rbegin(), dsvec[idx].rend());
		foru(i, 0, n)idxinv[idx][dsvec[idx][i].ss] = i;
		ds[idx] = new fen<int>(n);
	}
}

void ins(int idx, int dsidx) {
	ds[dsidx]->add(idxinv[dsidx][idx], 1);
}

void del(int idx, int dsidx) {
	ds[dsidx]->add(idxinv[dsidx][idx], -1);
}

int query(int x, int y, int dsidx) {
	int quan = (dsidx == 1 ? y + x : y - x);
	int l = 1, r = n, bst = -1, mid;
	while (l <= r) {
		mid = (l + r + 1) / 2;
		if (dsvec[dsidx][mid - 1].ff > quan) {
			bst = mid - 1;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	if (bst == -1)return 0;
	else return ds[dsidx]->query(bst);
}

int main() {
	fast;
	input();
	init();
	vector<pair<int, pii>> ev;
	foru(i, 0, n) {
		ev.push_back({ di[i].s,{2,i} }); //open
		ev.push_back({ di[i].p,{0,i} }); //close
	}
	foru(i, 0, m) {
		ev.push_back({ pe[i].inc,{1,i} });
	}
	int curActive = 0;
	vector<int> ans(m, 0);
	sort(ev.rbegin(), ev.rend());
	for (auto ii : ev) {
		int coord = ii.ff, mode = ii.ss.ff, idx = ii.ss.ss;
		if (mode == 1) { //person
			ans[idx] = curActive;
			ans[idx] -= query(pe[idx].pref, pe[idx].inc, 0);
			ans[idx] -= query(pe[idx].pref, pe[idx].inc, 1);
		}
		else {
			if (mode == 2) { //open
				ins(idx, 0);
				ins(idx, 1);
				curActive++;
			}
			else { //close
				del(idx, 0);
				del(idx, 1);
				curActive--;
			}
		}
	}
	foru(i, 0, m)cout << ans[i] << ' ';
	cout << '\n';
	return 0;
}