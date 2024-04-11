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

int T, H, M, hours, minutes;
char h1, h2, tmp, m1, m2;

string rev(char r) {
	if (r == '1') return "1";
	if (r == '2') return "5";
	if (r == '5') return "2";
	if (r == '8') return "8";
	return "0";
}

bool can(int h, int m) {
	//cout << h << ' ' << m << '\n';
	string th = to_string(h), tm = to_string(m), nh = "", nm = "";
	if (h < 10) th = '0' + th;
	if (m < 10) tm = '0' + tm;
	for (char c : th)
		if (c == '3' || c == '4' || c == '6' || c == '7' || c == '9') return 0;
	for (char c : tm)
		if (c == '3' || c == '4' || c == '6' || c == '7' || c == '9') return 0;
	nh = rev(tm[1]) + rev(tm[0]);
	nm = rev(th[1]) + rev(th[0]);
	if (stoi(nh) < H && stoi(nm) < M) return 1;
	return 0;
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> H >> M;
		cin >> h1 >> h2 >> tmp >> m1 >> m2;
		hours = (h1 - '0') * 10 + (h2 - '0');
		minutes = (m1 - '0') * 10 + (m2 - '0');
		while (true) {
			if (can(hours, minutes)) break;
			if (minutes == M - 1) {
				hours++;
				minutes = 0;
			} else minutes++;
			if (hours == H) hours = 0;
		}
		string th = to_string(hours), tm = to_string(minutes);
		if (hours < 10) th = '0' + th;
		if (minutes < 10) tm = '0' + tm;
		cout << th << ":" << tm << '\n';
	}
}