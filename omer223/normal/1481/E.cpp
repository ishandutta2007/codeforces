#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <list>
#include <bitset>
#include <set>
#include <queue>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int sz = 1e6;
int n;
int a[sz];
int dp[sz], cnts[sz];
int loc[sz][2];

int main() {
	fast;
	cin >> n;
	foru(i, 0, n) {
		cin >> a[i]; a[i]--;
	}
	foru(i, 0, n) { foru(j, 0, 2)loc[i][j] = -1; }
	foru(i, 0, n) {
		if (loc[a[i]][0] == -1)loc[a[i]][0] = i;
		loc[a[i]][1] = i;
	}
	ford(i, n - 1, 0) {
		cnts[a[i]]++;
		dp[i] = dp[i + 1];
		if (i == loc[a[i]][0]) dp[i] = max(dp[i], dp[loc[a[i]][1] + 1] + cnts[a[i]]);
		else dp[i] = max(dp[i], cnts[a[i]]);
	}
	cout << n - dp[0] << '\n';
	return 0;
}

/*
50
3 6
*ab
b*b
aa*
*/