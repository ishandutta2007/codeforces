#define _CRT_SECURE_NO_WARNINGS
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
#include <map>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int sz = 3e5;
int n, k;
string s;

int main() {
	fast;
	int x = 0;
	cin >> n >> k >> s;
	foru(i, 0, 26) {
		int ctr = 0, dist = 0;
		foru(j, 0, n) {
			if (s[j] == 'a' + i) {
				ctr++;
				if (ctr == k) {
					dist++;
					ctr = 0;
				}
			}
			else ctr = 0;
		}
		x = max(x, dist);
	}
	cout << x << '\n';
	return 0;
}