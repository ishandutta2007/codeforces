#define fast ios::sync_with_stdio(false); cin.tie(0);
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define ff first
#define ss second

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

const int sz = 1e3;
int n;
int a[sz][sz];

int getCol() {
	int c;
	cin >> c;
	fflush(stdout);
	return c;
}

void place(int i, int j, int c) {
	cout << c << ' ' << i << ' ' << j << endl;
	fflush(stdout);
}

int main() {
	fast;
	cin >> n;
	vector<pii> ap, bp;
	foru(i, 0, n) {
		foru(j, 0, n) {
			if ((i + j) & 1)bp.pb({ i+1,j+1 });
			else ap.pb({ i+1,j+1 });
		}
	}
	int aind = 0, bind = 0;
	int asz = ap.size(), bsz = bp.size();
	foru(i, 0, n*n) {
		int col = getCol();
		if (aind == asz) {
			if (col == 2)place(bp[bind].ff, bp[bind].ss, 3);
			else place(bp[bind].ff, bp[bind].ss, 2);
			bind++;
		}
		else if (bind == bsz) {
			if (col == 1)place(ap[aind].ff, ap[aind].ss, 3);
			else place(ap[aind].ff, ap[aind].ss, 1);
			aind++;
		}
		else {
			if (col == 1) {
				place(bp[bind].ff, bp[bind].ss, 2);
				bind++;
			}
			else {
				place(ap[aind].ff, ap[aind].ss, 1);
				aind++;
			}
		}
	}
	return 0;
}