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

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef pair<ll, ll> pll;

const int sz = 3e3;
int x, umbNum, rain;
vector<pii> seg;
vector<pii> umb;
ll dp[sz][sz];
int umbLoc[sz];
bitset<sz> isRain;

void input() {
	cin >> x >> rain >> umbNum;
	foru(i, 0, rain) {
		int l, r;
		cin >> l >> r;
		seg.pb({ l,r });
		foru(j, l, r)isRain[j] = 1;
	}
	sort(seg.begin(), seg.end());
	foru(i, 0, sz)umbLoc[i] = -1;
	foru(i, 0, umbNum) {
		int loc, w;
		cin >> loc >> w;
		if (umbLoc[loc] == -1 || umbLoc[loc] > w)umbLoc[loc] = w;
	}
	umb.pb({ -1,0 });
	foru(i, 0, sz) {
		if (umbLoc[i] != -1) {
			umb.pb({ i, umbLoc[i] });
			umbLoc[i] = umb.size() - 1;
		}
	}
	umbNum = umb.size() - 1;
	foru(i, 0, sz) {
		foru(j, 0, sz)dp[i][j] = 1e17;
	}
}


int main() {
	fast;
	input();
	ford(i, x, 0) {
		ford(myUmb, umbNum, 0) {
			if (i == x)dp[i][myUmb] = 0;
			else {
				if (myUmb == 2) {
					myUmb++;
					myUmb--;
				}
				if (umb[myUmb].first > i)continue;
				if (myUmb) dp[i][myUmb] = dp[i + 1][myUmb] + umb[myUmb].second;
				if (umbLoc[i] != -1)dp[i][myUmb] = min(dp[i][myUmb], dp[i][umbLoc[i]]);
				if (!isRain[i])dp[i][myUmb] = min(dp[i][myUmb], dp[i + 1][0]);
			}
		}
	}
	cout << (dp[0][0]>1e10?-1:dp[0][0]) << endl;
	return 0;
}