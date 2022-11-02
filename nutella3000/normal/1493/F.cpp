#include <bits/stdc++.h>
        
using namespace std;
        
        
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

#define aidar asadulin
         
#define int long long
#define ll long long
#define mp make_pair
#define pii pair<int, int>
#define pip pair<int, pii>
#define fi first
#define se second
#define size(a) (int) (a.size())
#define chkmax(a, b) a = max(a, b)
#define chkmin(a, b) a = min(a, b)
#define ld double
        
const int inf = 5e9 + 7;

int n, m;

int cou;

int f(int h, int w, int i1, int j1, int i2, int j2) {
	cou--;
	if (cou < 0) n /= (n - n);

	cout << "? " << h << " " << w << " " << i1 + 1 << " " << j1 + 1 << " " << i2 + 1 << " " << j2 + 1 << endl;
	int q;
	cin >> q;
	return q;
}

bool g(int id, int num, int sz) {
	int st = num;
	while(st < sz) {
		int r = min(st, sz - st);
		if (id == 0 && !f(r, m, 0, 0, st, 0)) return false;
		else if (id == 1 && !f(n, r, 0, 0, 0, st)) return false;
		st += r;
	}
	return true;
}

vector<int> facting(int a) {
	vector<int> res;
	for(int i = 2;i <= a;i++) {
		while (a % i == 0) {
			res.emplace_back(i);
			a /= i;
		}
	}
	return res;
}

int q(int id, vector<int> a) {
	int num = (id == 0 ? n : m);
	int sz = num;
	for(int i : a) {
		if (g(id, num / i, sz)) {
			num /= i;
			sz /= i;
		}else {

		}
	}

	return num;
}

void solve() {
	cin >> n >> m;
	cou = 3 * __lg(n + m);

	vector<int> r1 = facting(n), r2 = facting(m);

	int v1 = q(0, r1), v2 = q(1, r2);

	int e1 = 0, e2 = 0;

	for(int i = v1;i <= n;i += v1)
		if (n % i == 0) e1++;
	for(int i = v2;i <= m;i += v2)
		if (m % i == 0) e2++;

	cout << "! " << e1 * e2 << endl;

}



signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cout.precision(10);

    solve();
}