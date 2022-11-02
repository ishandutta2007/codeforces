#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define mp make_pair

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <bitset>
#include <numeric>
#include <set>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef pair<ll, ll> pll;
template<class T>
struct segmentree {
private:
	vector<T> seg, original;
	int n;
	T action(const T& lhs, const T& rhs) {
		return lhs + rhs;
	}
	void build(int i, int l, int r) {
		if (l > r)return;
		else if (l == r)seg[i] = original[l];
		else {
			int mid = (l + r) / 2;
			build(2 * i, l, mid);
			build(2 * i + 1, mid + 1, r);
			seg[i] = action(seg[2 * i], seg[2 * i + 1]);
		}
	}
	T queryUtil(int i, int cl, int cr, int l, int r) {
		if (l > r)return 0; //CHECK
		else if (l == cl && r == cr)return seg[i];
		else {
			int mid = (cl + cr) / 2;
			T a = queryUtil(2 * i, cl, mid, l, min(mid, r)),
				b = queryUtil(2 * i + 1, mid + 1, cr, max(mid + 1, l), r);
			return action(a, b);
		}
	}
	void updateUtil(int i, int l, int r, int pos, T val) {
		if (l == r)seg[i] = val;
		else {
			int mid = (l + r) / 2;
			if (pos <= mid)updateUtil(2 * i, l, mid, pos, val);
			else updateUtil(2 * i + 1, mid + 1, r, pos, val);
			seg[i] = action(seg[2 * i], seg[2 * i + 1]);
		}
	}
	int sumInd(int i, int l, int r, int sum) {
		if (l == r)return l;
		else {
			int mid = (l + r) / 2;
			if (seg[2 * i] >= sum)return sumInd(2 * i, l, mid, sum);
			else return sumInd(2 * i + 1, mid + 1, r, sum - seg[2 * i]);
		}
	}
public:
	segmentree(int size) {
		n = size;
		seg.resize(4 * n);
		fill(seg.begin(), seg.end(), 0);
	}
	segmentree(vector<T> orig) {
		original = orig;
		n = orig.size();
		seg.resize(4 * n);
		build(1, 0, n - 1);
	}
	T query(int sum) {
		return sumInd(1, 0, n - 1, sum);
	}
	void update(int i, T val) {
		updateUtil(1, 0, n - 1, i, val);
	}
	void print() {
		foru(i, 0, n)cout << queryUtil(1, 0, n - 1, i, i);
		cout << endl;
	}
};

const int sz = 1e6 + 5;
int n, m, cnt = 0, cri = 0;
int a[sz];
vector<int> v;
bitset<sz> bs;

int main() {
	fast;
	cin >> n >> m;
	int l = 1, r = m, mid, bst = -1;
	segmentree<int> seg(n);
	foru(i, 0, m)cin >> a[i];
	foru(i, 0, n) {
		int type;
		cin >> type;
		switch (type) {
		case -1:
			l = 1, r = m, bst = -1;
			while (l <= r) {
				mid = (l + r + 1) / 2;
				if (a[mid - 1] <= cnt) {
					bst = mid;
					l = mid + 1;
				}
				else r = mid - 1;
			}
			ford(j, bst-1, 0) {
				int ind = seg.query(a[j]);
				cnt--;
				bs[ind] = 1;
				seg.update(ind, 0);
			}
			break;
		default:
			v.pb(type);
			cnt++;
			seg.update(cri++, 1);
			break;
		}
	}
	string s = "";
	foru(i, 0, v.size()) {
		if (!bs[i])s.pb(v[i] + '0');
	}
	if (s.length() == 0) cout << "Poor stack!" << endl;
	else cout << s << endl;
	
	return 0;
}