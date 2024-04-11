#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <list>
#include <queue>
#include <unordered_map>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n, m, q;
vector<ll> a, b, bvals;
ll es = 0, os = 0;

void initBVals() {
	ll esb = 0, osb = 0;
	foru(i, 0, n) {
		if (i & 1)osb += b[i];
		else esb += b[i];
	}
	bvals.pb(esb - osb);
	foru(i, n, m) {
		if ((i - n) & 1)osb -= b[i - n];
		else esb -= b[i - n];
		if (i & 1)osb += b[i];
		else esb += b[i];
		int st = i - n + 1;
		if (st & 1)bvals.pb(osb - esb);
		else bvals.pb(esb - osb);
	}
	sort(bvals.begin(), bvals.end());
}

void input(){
	cin >> n >> m >> q;
	a.resize(n);
	foru(i, 0, n) {
		cin >> a[i];
		if (i & 1)os += a[i];
		else es += a[i];
	}
	b.resize(m);
	foru(i, 0, m)cin >> b[i];
}

inline ll closestTo(ll val) {
	int l = 1, r = m - n + 1, mid, bst = -1;
	while (l <= r) {
		mid = (l + r + 1) / 2;
		if (bvals[mid - 1] >= val) {
			bst = mid - 1;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	if (bst == -1)return bvals.back();
	else {
		if (!bst)return bvals[bst];
		ll aopt = abs(val - bvals[bst]), bopt = abs(val - bvals[bst - 1]);
		if (aopt > bopt)return bvals[bst - 1];
		else return bvals[bst];
	}
}

inline ll getVal() { return es - os; }

inline void query(int l, int r, ll amt) {
	int len = r - l + 1;
	es += (len / 2)*amt;
	os += (len / 2)*amt;
	if (len & 1) {
		if (l & 1)os += amt;
		else es += amt;
	}
}

int main() {
	fast;
	input();
	initBVals();
	ll tmp = getVal();
	cout << abs(closestTo(tmp) - tmp) << endl;
	while (q--) {
		int l, r, x;
		cin >> l >> r >> x;
		query(--l, --r, x);
		tmp = getVal();
		cout<<abs(closestTo(tmp)-tmp)<<endl;
	}
	return 0;
}