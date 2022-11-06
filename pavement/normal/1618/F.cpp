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
typedef long double ld;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef tuple<int, int, int, int> iiii;
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int X, Y;
string SX, SY, SX2, RSX2;

string rev(string S) {
	reverse(S.begin(), S.end());
	return S;
}

bool check(string S) {
	if (S == SY) return 1;
	string RS = rev(S + "1");
	for (int i = 0; i < 70; i++)
		for (int j = 0; j < 70; j++) {
			string T = "";
			for (int k = 0; k < i; k++) T += "1";
			T += RS;
			for (int k = 0; k < j; k++) T += "1";
			if (T == SY || rev(T) == SY) return 1;
		}
	return 0;
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> X >> Y;
	if (X == Y) return cout << "YES\n", 0;
	while (X) {
		if (X & 1ll) SX += "1";
		else SX += "0";
		X /= 2;
	}
	SX = rev(SX);
	while (Y) {
		if (Y & 1ll) SY += "1";
		else SY += "0";
		Y /= 2;
	}
	SY = rev(SY);
	SX2 = SX;
	while (!SX2.empty() && SX2.back() == '0') SX2.ppb();
	RSX2 = rev(SX2);
	if (check(SX) || check(SX2) || check(RSX2)) cout << "YES\n";
	else cout << "NO\n";
}