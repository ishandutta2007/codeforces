#define _CRT_SECURE_NO_WARNINGS
#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define mp make_pair

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <list>
#include <numeric>
#include <complex>
#include <cmath>

using namespace std;
using T = pair<int, int>;
const int inf = 1e9 + 7;
inline T action(T a, T b) {
	return (a.first < b.first ? a : b); //CHECK
}
struct segmentree {
private:
	vector<T> segment;
	int size;
public:
	segmentree(int sz) {
		size = sz;
		segment.resize(2 * sz);
		for (int k = 0; k < 2 * sz; k++) segment[k] = { inf, -1 };
	}
	segmentree(vector<T> arr) {
		size = arr.size();
		segment.resize(2 * size);
		for (int k = 0; k < size; k++)
			segment[size + k] = arr[k];
		for (int k = size - 1; k > 0; k--)
			segment[k] = action(segment[2 * k], segment[2 * k + 1]);
	}
	void update(int index, T val) {
		int t = index + size;
		segment[t] = val;
		while (t >= 1) {
			t >>= 1;
			segment[t] = action(segment[2 * t], segment[2 * t + 1]);
		}
	}
	T query(int fromIncluded, int toNotIncluded) { //NOT INCLUDED
		T sum = { inf, -1 }; //CHECK
		fromIncluded += size;
		toNotIncluded += size;
		while (fromIncluded < toNotIncluded) {
			if (fromIncluded % 2 == 1) {
				sum = action(sum, segment[fromIncluded]);
				fromIncluded++;
			}
			if (toNotIncluded % 2 == 1) {
				sum = action(sum, segment[toNotIncluded - 1]);
				toNotIncluded--;
			}
			fromIncluded /= 2;
			toNotIncluded /= 2;
		}
		return sum;
	}
};
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n, m;
vector<int> a;
vector<segmentree> segVec;

void input() {
	scanf("%d %d", &n, &m);
	a.resize(n);
	foru(i, 0, n)scanf("%d", &a[i]);
}

void initSegs() {
	vector<int> b(a);
	foru(digs, 0, 10) {
		segmentree tmpSeg(n);
		foru(i, 0, n) {
			if (b[i] % 10 != 0)tmpSeg.update(i, { a[i],i });
			b[i] /= 10;
		}
		segVec.pb(tmpSeg);
	}
}

void updateVal(int i, int x) {
	a[i] = x;
	foru(digs, 0, 10) {
		if (x % 10)segVec[digs].update(i, { a[i],i });
		else segVec[digs].update(i, { inf,-1 });
		x /= 10;
	}
}

int findTwoMin(int digs, int l, int r) {
	pii f = segVec[digs].query(l, r + 1);
	if (f.second == -1)return -1;
	pii sl = { inf,-1 }, sr = { inf, -1 };
	if (f.second != r) {
		sr = segVec[digs].query(f.second + 1, r + 1);
	}
	if (f.second != l) {
		sl = segVec[digs].query(l, f.second);
	}
	pii comb = action(sl, sr);
	if (comb.second == -1)return -1;
	else return f.first + comb.first;
}

int main() {
	//fast;
	input();
	initSegs();
	while (m--) {
		int type;
		scanf("%d", &type);
		switch (type) {
		case 1:
			int i, x;
			scanf("%d %d", &i, &x);
			updateVal(--i, x);
			break;
		case 2:
			int l, r;
			scanf("%d %d", &l, &r); l--; r--;
			int ret = 2 * inf;
			foru(digs, 0, 10) {
				int tmp = findTwoMin(digs, l, r);
				if (tmp != -1)ret = min(ret, tmp);
			}
			if (ret >= 2 * inf)printf("-1\n");
			else printf("%d\n", ret);
		}
	}
	return 0;
}