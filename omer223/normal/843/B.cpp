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
#include <unordered_map>
#include <set>
#include <queue>
#include <cmath>
#include <math.h>
#include <random>
#include <unordered_set>
#include <ctime>
#include <cstdlib>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;

int n, st, x;
vector<pair<pii, int>> qans;

inline pll ask(int i) {
	cout << "? " << i << endl;
	fflush(stdout);
	pll ans;
	cin >> ans.first >> ans.second;
	return ans;
}

void answer(int ans) {
	cout << "! " << ans << endl;
	fflush(stdout);
}

int main() {
	fast;
	srand(time(NULL));
	cin >> n >> st >> x;
	int guesses = sqrt(n);
	vector<int> v;
	foru(i, 0, n)v.pb(i + 1);
	shuffle(v.begin(), v.end(), default_random_engine(NULL));
	foru(i, 0, guesses) qans.pb({ ask(v[i]), v[i] });
	sort(qans.begin(), qans.end());
	if (qans[0].first.first > x) {
		int curNxt = st, curNum = -1;
		while (curNum < x) {
			pll tmpP = ask(curNxt);
			curNum = tmpP.first;
			curNxt = tmpP.second;
		}
		answer(curNum);
		return 0;
	}
	else if (qans.back().first.first < x) {
		int curNxt = qans.back().first.second, curNum = qans.back().first.first;
		while (curNxt != -1 && curNum < x) {
			pll tmpP = ask(curNxt);
			curNum = tmpP.first;
			curNxt = tmpP.second;
		}
		if (curNum >= x)answer(curNum);
		else answer(-1);
		return 0;
	}
	else {
		foru(i, 0, guesses) {
			if (qans[i].first.first == x) {
				answer(x);
				return 0;
			}
			else if (qans[i].first.first > x) {
				int curNxt = qans[i - 1].first.second, curNum = qans[i - 1].first.first;
				while (curNum < x) {
					pll tmpP = ask(curNxt);
					curNum = tmpP.first;
					curNxt = tmpP.second;
				}
				answer(curNum);
				return 0;
			}
		}
	}
	return 0;
}