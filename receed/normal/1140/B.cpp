#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <random>
#include <bitset>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <queue>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;
using ld = long double;

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t, n;
	cin >> t;
	string s;
	rep(z, t) {
		cin >> n >> s;
		int p1 = 0, p2 = s.size() - 1;
		while (p1 < s.size() && s[p1] == '<')
			p1++;
		while (p2 >= 0 && s[p2] == '>')
			p2--;
		cout << min(p1, (int) s.size() - p2 - 1) << '\n';
	}	
}