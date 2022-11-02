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


using namespace std;
using T = long long;

struct segmentree {
private:
	vector<T> segment;
	int size;
	T action(T a, T b) {
		return a + b; //CHECK
	}
public:
	segmentree(int sz) {
		size = sz;
		segment.resize(2 * sz);
		for (int k = 0; k < 2 * sz; k++) segment[k] = 0;
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
	void add(int index, T val) {
		int t = index + size;
		segment[t] = segment[t] + val;
		while (t > 1) {
			t >>= 1;
			segment[t] = action(segment[2 * t], segment[2 * t + 1]);
		}
	}
	T query(int fromIncluded, int toNotIncluded) { //NOT INCLUDED
		T sum = 0; //CHECK
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

const int sz = 3e5, mxr = 1e6;
int n, m;
pii sect[sz];
ll ans[sz];
vector<int> mem[mxr + 1];
vector<pii> parts;
vector<pair<pii, int>> qu;
int opens[mxr + 2];

void sweepline() {
	sort(parts.begin(), parts.end());
	int cur = 0, ind = 0, ptr = 0, partsSize = parts.size();
	while (ind < partsSize && ptr <= mxr+1) {
		while (ind < partsSize && parts[ind].first == ptr) {
			if (parts[ind].second)cur++;
			else cur--;
			ind++;
		}
		opens[ptr++] = cur;
	}
}

void calc() {
	int queries = qu.size(), ptr = 0, ind = 0;
	sort(qu.begin(), qu.end());
	segmentree seg(mxr + 5);
	while (ptr <= mxr && ind < queries) {
		for (int x : mem[ptr])seg.add(x, 1);
		while (ind < queries&&qu[ind].first.first == ptr) {
			ans[qu[ind].second] -= seg.query(qu[ind].first.second, mxr + 5);
			ind++;
		}
		ptr++;
	}
}

int main() {
	fast;
	cin >> n >> m;
	foru(i, 0, n) {
		cin >> sect[i].first >> sect[i].second;
		mem[sect[i].first].pb(sect[i].second);
		parts.pb({ sect[i].first,1 });
		parts.pb({ sect[i].second + 1,0 });
	}
	sweepline();
	int xi, prv;
	foru(i, 0, m) {
		int tmp;
		cin >> tmp;
		foru(j, 0, tmp) {
			cin >> xi;
			ans[i] += opens[xi];
			if (j)qu.pb({ {prv,xi},i });
			prv = xi;
		}
	}
	calc();
	foru(i, 0, m)cout << ans[i] << '\n';
	return 0;
}