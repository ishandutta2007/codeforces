#define _CRT_SECURE_NO_WARNINGS
#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (ll i = k; i < n; i++)
#define ford(i, k, n) for (ll i = k; i >= n; i--)
#define pb push_back
#define ff first
#define ss second
#define mp make_pair

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>
#include <queue>
#include <bitset>
#include <set>
#include <deque>
#include <stack>
#include <map>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<ll> vi;

const int sz = 1e6 + 5;
int n, m;
int a[sz];
int cnts[sz], cntsdiv[sz];

int main() {
	fast;
	cin >> n >> m;
	foru(i, 0, n) {
		cin >> a[i];
		if (a[i] <= 1e6)cnts[a[i]]++;
	}
	for (int i = 1; i <= 1e6; i++) {
		for (int j = i; j <= 1e6; j += i)cntsdiv[j] += cnts[i];
	}
	int mx = 0, mxi = 1;
	for (int i = 1; i <= m; i++) {
		if (mx < cntsdiv[i]) {
			mx = cntsdiv[i];
			mxi = i;
		}
	}
	cout << mxi << ' '<<mx<< '\n';
	foru(i, 0, n) {
		if (mxi % a[i] == 0)cout << i + 1 << ' ';
	}
	return 0;
}