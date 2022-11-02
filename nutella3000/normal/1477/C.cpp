#include <bits/stdc++.h>

using namespace std;


mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

//#define GCC optimize("O3, Ofast")
//#define GCC optimize("unroll-loops")
#define aidar asadulin
 
#define int long long
#define ull long long
#define ll long long
#define mp make_pair
#define pii pair<int, int>
#define pip pair<int, pii>
#define fi first
#define se second
#define all(_v) _v.begin(), _v.end()
#define sz(a) (int) (a.size())
#define chkmax(a, b) a = max(a, b)
#define chkmin(a, b) a = min(a, b)
#define ld double

const int inf = 1e9 + 7;
const double eps = 1e-9;

const int max_n = 1e4 + 3;

int n;
int x[max_n], y[max_n];

bool f(int id1, int id2, int id3) {
	int x1 = x[id2] - x[id1], y1 = y[id2] - y[id1], x2 = x[id3] - x[id2], y2 = y[id3] - y[id2];
	return ((x1 * x2 + y1 * y2)) < 0;
}


void solve() {
	cin >> n;
	for(int i = 0;i < n;i++) {
		cin >> x[i] >> y[i];
	}

	vector<int> a;

	for(int i = 0;i < n;i++) {
		if (sz(a) < 2) a.emplace_back(i);
		else if (sz(a) == 2) {
			int B = a.back();
			a.pop_back();
			int A = a.back();
			int C = i;
			if (!f(A, B, C)) {
				swap(B, C);
			}
			a.emplace_back(B);
			a.emplace_back(C);
		}else {

			vector<int> b;
			int C = i, B = a.back();
			a.pop_back();
			while(true) {
				if (sz(a) == 0) {
					a.emplace_back(B);
					a.emplace_back(C);
					break;
				}
				int A = a.back();
				a.pop_back();
				if (f(A, B, C)) {
					a.emplace_back(A);
					a.emplace_back(B);
					a.emplace_back(C);
					break;
				}
				b.emplace_back(B);
				B = A;
			}
			for(int i = sz(b) - 1;i >= 0;i--)
				a.emplace_back(b[i]);
		}
	}

	for(int i : a)
		cout << i + 1 << " ";
	cout << endl;
}




signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cout.precision(10);

    solve();
}