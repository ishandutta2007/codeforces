#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define ff first
#define ss second

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <iomanip>
#include <queue>
#include <bitset>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


const int sz = 2e5;
int n, k;
pii pos[3 * sz];
int team[sz][3];
int skill[3 * sz], poskill[3 * sz];
bitset<3*sz> used;

void input() {
	cin >> n;
	foru(i, 0, 3 * n) {
		cin >> skill[i];
		poskill[--skill[i]] = i;
	}
	foru(i, 0, n) {
		foru(j, 0, 3) {
			cin >> team[i][j];
			--team[i][j];
		}
		sort(team[i], team[i] + 3, [](const int& lhs, const int& rhs) -> bool {
			return poskill[lhs] < poskill[rhs];
		});
		foru(j, 0, 3) {
			pos[team[i][j]] = { i,j };
		}
	}
	cin >> k;
	--k;
	used[k] = 1;
}

void solveEasy() {
	vector<int> ret;
	set<int> s;
	int teamId = pos[k].ff;
	foru(i, 0, teamId) {
		foru(j, 0, 3)s.insert(team[i][j]);
	}
	foru(j, 1, 3)s.insert(team[teamId][j]);
	while (!s.empty()) {
		int x = *s.begin(); s.erase(x);
		ret.pb(x+1);
		used[x] = 1;
		if ((x == team[teamId][1] || x == team[teamId][2]) && used[team[teamId][1]] && used[team[teamId][2]]) {
			foru(i, 0, 3 * n) {
				if (!used[i])s.insert(i);
			}
		}
	}
	for (int x : ret)cout << x << ' ';
	cout << '\n';
}

void solveHard() {
	foru(i, 0, 3 * n) {
		if (!used[i])cout << i + 1 << ' ';
	}
	cout << '\n';
}

int main() {
	fast;
	input();
	if (pos[k].ss == 0)solveEasy();
	else solveHard();
	return 0;
}