#define _CRT_SECURE_NO_WARNINGS
#define fast ios::sync_with_stdio(false); cin.tie(0);
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define ff first
#define ss second

#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
#include <stack>
#include <set>
#include <string>
#include <queue>
#include <map>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef pair<ld, ld> pld;



int main() {
	fast;
	int n;
	cin >> n;
	int sm = 0, x;
	foru(i, 0, n) {
		cin >> x;
		sm += x;
	}
	cout << sm << '\n';
	return 0;
}