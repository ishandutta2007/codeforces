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

const int N = 200002;
int a[N], pl[N], pr[N], p[N];

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		p[a[i]] = i;
	}
	vector<int> st {0};
	for (int i = 1; i <= n; i++) {
		while (st.size() > 1 && a[st.back()] < a[i])
			st.pop_back();
		pl[i] = st.back();
		st.push_back(i);
	}
	st = {n + 1};
	for (int i = n; i > 0; i--) {
		while (st.size() > 1 && a[st.back()] < a[i])
			st.pop_back();
		pr[i] = st.back();
		st.push_back(i);
	}
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		if (i - pl[i] < pr[i] - i)
			for (int j = pl[i] + 1; j < i; j++) {
				int x = a[i] - a[j];
				if (x > 0 && i < p[x] && p[x] < pr[i])
					ans++;
			}
		else 
			for (int j = i + 1; j < pr[i]; j++) {
				int x = a[i] - a[j];
				if (x > 0 && pl[i] < p[x] && p[x] < i)
					ans++;
			}
	}
	cout << ans;
}