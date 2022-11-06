#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
#ifndef print
#define print(...)
#define trace(...)
#define endl '\n'
#endif
#define pb push_back
#define fi first
#define se second
#define int long long
typedef long long ll;
typedef long double f80;
#define double long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define sz(x) ((long long)x.size())
#define fr(a,b,c) for(int a=b; a<=c; a++)
#define rep(a,b,c) for(int a=b; a<c; a++)
#define trav(a,x) for(auto &a:x)
#define all(con) con.begin(),con.end()
const ll infl = 0x3f3f3f3f3f3f3f3fLL;
const int infi = 0x3f3f3f3f;
//const int mod = 998244353;
const int mod = 1000000007;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oset;
auto clk = clock();
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) { uniform_int_distribution<int> uid(0, lim - 1); return uid(rang); }
int powm(int a, int b) { int res = 1; while (b) { if (b & 1) res = (res * a) % mod; a = (a * a) % mod; b >>= 1; } return res; }

int getans(string s) {
	int ma = 0;
	int cu = 0;
	int n = s.size();
	for (int i = 0; i < n; ++i) {
		if (s[i] == '1') {
			cu++;
		} else {
			cu = 0;
		}
		ma = max(ma, cu);
	}
	return ma;
}

int findans(string s) {
	int ans = 0;
	int n = s.size();
	for (int i = 0; i < n; ++i) {
		for (int j = i; j < n; ++j) {
			ans += getans(s.substr(i, j - i + 1));
		}
	}
	return ans;
}

void prin(stack<pii> st) {
	print("--");
	while (!st.empty()) {
		print(st.top());
		st.pop();
	}
	print("--");
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10); srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	int n; cin >> n;
	string s; cin >> s;
	// int n = s.size();
	stack<pii> st;
	int curl = 0;
	int cura = 0;
	int total_ans = 0;
	int max_length = 0;
	// int right_ans = findans(s);
	for (int i = 0; i < n; ++i) {
		if (s[i] == '0') {
			// cura = cura + max_length;
			total_ans += cura;
			curl = 0;
			// print(cura);
			continue;
		}

		curl++;
		max_length = max(max_length, curl);
		int j = i - (curl - 1);
		cura += curl;
		// print(i, j, cura);
		if (!st.empty() && st.top().se == i - 1) st.pop();
		if (!st.empty() && st.top().fi < curl) {
			auto p = st.top();
			st.pop();
			int start = p.fi - p.se + 1;
			cura += (j - start);
			j = start;
		}
		// print(j, cura);
		if (!st.empty()) {
			auto p = st.top();
			int start = p.se - (curl - 1) + 1;
			// print(start);
			cura += (j - start);
		} else {
			cura += j;
		}
		// print(j, cura);
		// print(cura);
		total_ans += cura;
		if (!st.empty() && st.top().fi == curl) {
			st.pop(); 
			st.push({curl, i});
		} else if (st.empty() || st.top().fi > curl)
			st.push({curl, i});
		// prin(st);
	}
	cout << total_ans << '\n';
	// print(total_ans, right_ans);
}