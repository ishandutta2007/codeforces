#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#ifdef _WIN32
#define getchar_unlocked _getchar_nolock
#endif
#define int long long
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define ppb pop_back
#define eb emplace_back
#define g0(a) get<0>(a)
#define g1(a) get<1>(a)
#define g2(a) get<2>(a)
#define g3(a) get<3>(a)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef double db;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef tuple<int, int, int, int> iiii;
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int N, dep;
string S, out;
stack<int> st;
vector<int> vec[2];

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> S;
	int idx = 0;
	out.resize(N);
	for (char c : S) {
		if (c == '(') dep++, st.push(idx);
		else {
			vec[dep & 1].pb(st.top());
			vec[dep & 1].pb(idx);
			st.pop();
			dep--;
		}
		idx++;
	}
	for (int i = 0; i < vec[0].size(); i++) out[vec[0][i]] = '0';
	for (int i = 0; i < vec[1].size(); i++) out[vec[1][i]] = '1';
	cout << out << '\n';
}