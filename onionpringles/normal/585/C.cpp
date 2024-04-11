#pragma warning(disable:4996)

#include <stdio.h>
#include <string.h>
#include <vector>
#define mp(a,b) make_pair(a,b)

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

vector<pair<ll,int> > ans;

int bad = 0;

void solve(ll x, ll y) {
	if (x > y) {
		if (x%y == 0) {
			if (y != 1) { bad = 1; return; }
			else {
				ans.push_back(mp(-1 + x / y, 1));
				return;
			}
		}
		ans.push_back(mp(x / y, 1));
		x = x%y;
		solve(x, y);
	}
	else if (x < y) {
		if (y%x == 0) {
			if (x != 1) {
				bad = 1;
				return;
			}
			else { ans.push_back(mp(-1 + y / x, 2)); return; }
		}
		ans.push_back(mp(y / x, 2));
		y = y%x;
		solve(x, y);
	}
	else {
		bad = 1;
		return;
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ll x, y;
	scanf("%I64d %I64d", &x, &y);
	solve(x, y);
	if (bad == 1) puts("Impossible");
	else {
		for (auto &x : ans) {
			printf("%I64d%c", x.first, x.second + 'A' - 1);
		}
	}
}