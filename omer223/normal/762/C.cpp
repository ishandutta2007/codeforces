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


using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
string a, b;
vector<int> lr, rl;
void init() {
	int la = a.length(), lb = b.length(), ind = 0;
	foru(i, 0, lb) {
		if (ind == la)lr.pb(-1);
		else {
			bool found = 0;
			while (ind < la) {
				if (a[ind] == b[i]) {
					lr.pb(ind++);
					found = 1;
					break;
				}
				ind++;
			}
			if (!found)lr.pb(-1);
		}
	}
	ind = la - 1;
	ford(i, lb - 1, 0) {
		if (ind == -1)rl.pb(-1);
		else {
			bool found = 0;
			while (ind >= 0) {
				if (a[ind] == b[i]) {
					rl.pb(ind--);
					found = 1;
					break;
				}
				ind--;
			}
			if (!found)rl.pb(-1);
		}
	}
	reverse(rl.begin(), rl.end());
}

int main() {
	fast;
	cin >> a >> b;
	init();
	ll bl = 1, br = b.length() - 1, mid, bst = 0, bstl = -1, bstr = -1;
	if (lr[b.length() - 1] != -1) {
		cout << b << endl;
		return 0;
	}
	while (bl <= br) {
		mid = (bl + br + 1) / 2;
		if (lr[b.length() - mid - 1] != -1) {
			bstl = b.length() - mid;
			bstr = b.length() - 1;
			br = mid - 1;
		}
		else if (rl[mid] != -1) {
			bstl = 0;
			bstr = mid - 1;
			br = mid - 1;
		}
		else if (mid == b.length() - 1) {
			bl = mid + 1;
		}
		else {
			ll l = 1, r = mid, gl, gr;
			bool found = 0;
			while (r < b.length() - 1) {
				gl = lr[l - 1], gr = rl[r + 1];
				if (gl != -1 && gr != -1 && gl < gr) {
					bstl = l;
					bstr = r;
					found = 1;
					break;
				}
				l++; r++;
			}
			if (found) br = mid - 1;
			else bl = mid + 1;
		}
	}
	if (bstl == -1) {
		cout << "-" << endl;
	}
	else {
		string lhs = (bstl ? b.substr(0, bstl) : ""), rhs = "";
		int rs = b.length() - 1 - bstr;
		if (rs)rhs = b.substr(bstr + 1, rs);
		cout << lhs + rhs << endl;
	}
	return 0;
}