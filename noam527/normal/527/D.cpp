#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#define last(x, y) (x)[(x).size() - y]
#define endl '\n'
#define flush fflush(stdout), cout.flush()
#define fast ios::sync_with_stdio(0), cin.tie(0)
#define debug cout << "ok" << endl
#define in(X) ((X) - '0')
const int md = 1e9 + 7;
typedef long long ll;
typedef long double ldb;
using namespace std;

struct range {
	int l, r;
	range(int l = 0, int r = 0) : l(l), r(r) {};
	bool operator <(const range &x) {
		return l < x.l;
	}
};

int main() {
	fast;
	int n;
	cin >> n;
	vector<range> a, b;
	for (int i = 0, x, w; i < n; i++)
		cin >> x >> w, a.push_back(range{ x - w, x + w });
	sort(a.begin(), a.end());
	b.push_back(a[0]);
	for (int i = 1; i < n; i++) {
		while (b.size() > 0 && a[i].r < last(b, 1).r) b.pop_back();
		b.push_back(a[i]);
	}
	vector<range> clique;
	clique.push_back(b[0]);
	for (int i = 1; i < b.size(); i++)
		if (b[i].l >= last(clique, 1).r) clique.push_back(b[i]);
	cout << clique.size() << endl;
}