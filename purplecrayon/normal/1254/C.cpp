#include <bits/extc++.h>
using namespace std;
using ll = long long;

const int N = 1005;

int n;
int nqq = 0;
long long aa[N];

long long qarea(int i, int j, int k) {
	nqq++;
	assert(nqq <= n * 3);
	cout << 1 << ' ' << i << ' ' << j << ' ' << k << endl;
	long long a2; cin >> a2; return a2; 
}

// > 0 = left
// < 0 = right
int qsign(int i, int j, int k) {
	nqq++;
	assert(nqq <= n * 3);
	cout << 2 << ' ' << i << ' ' << j << ' ' << k << endl;
	int s; cin >> s; return s;
}


int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	int nx = 2;
	for (int i = 3; i <= n; ++i)
		if (qsign(1, nx, i) < 0) // left
			nx = i;
	// cout << "nx = " << nx << endl;
	int fa = -1;
	for (int i = 2; i <= n; ++i)
		if (i != nx) {
			aa[i] = qarea(1, nx, i);
			if (fa == -1 || aa[i] > aa[fa])
				fa = i;
		}
	vector<int> ans;
	ans.push_back(1);
	ans.push_back(nx);
	vector<int> a, b;
	for (int i = 2; i <= n; ++i)
		if (i != nx && i != fa) {
			int k = qsign(1, fa, i);
			if (k < 0) {
				a.push_back(i);
			} else {
				b.push_back(i);
			}
		}
	sort(begin(a), end(a), [&](int i, int j) {
		return aa[i] < aa[j];
	});
	sort(begin(b), end(b), [&](int i, int j) {
		return aa[i] > aa[j];
	});
	for (int i : a)
		ans.push_back(i);
	ans.push_back(fa);
	for (int i : b)
		ans.push_back(i);
	cout << "0 ";
	for (int i : ans)
		cout << i << ' ';
	cout << endl;
}