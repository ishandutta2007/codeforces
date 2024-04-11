#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <string>
#include <time.h>
#include <stack>
#include <queue>
#include <random>
#include <fstream>
#define endl '\n'
#define flush fflush(stdout), cout.flush()
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define debug cout << "ok" << endl
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7, inf = 1e9 + 7;
const ll hs = 199;
const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

const int maxn = 3e5 + 3;

int n, a[maxn], l[maxn], r[maxn];
vector<int> st;

int main() {
	fast;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	
	st = { -1 };
	for (int i = 0; i < n; i++) {
		while (st.back() > -1 && a[st.back()] % a[i] == 0) st.pop_back();
		l[i] = st.back() + 1;
		st.push_back(i);
	}

	st = { n };
	for (int i = n - 1; i >= 0; i--) {
		while (st.back() < n && a[st.back()] % a[i] == 0) st.pop_back();
		r[i] = st.back() - 1;
		st.push_back(i);
	}

	int mx = -1;
	for (int i = 0; i < n; i++) mx = max(mx, r[i] - l[i]);

	set<int> ans;
	for (int i = 0; i < n; i++)
		if (mx == r[i] - l[i]) ans.insert(l[i] + 1);

	cout << ans.size() << " " << mx << endl;
	for (const auto &i : ans) cout << i << " "; cout << endl;
}