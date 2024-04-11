#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
//#ifdef TEST
#define getchar_unlocked _getchar_nolock
#define putchar_unlocked _putchar_nolock
//#endif
#define int long long
#define ins insert
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define pf push_front
#define pp pop
#define ppb pop_back
#define ppf pop_front
#define eb emplace_back
#define g0(a) get<0>(a)
#define g1(a) get<1>(a)
#define g2(a) get<2>(a)
#define g3(a) get<3>(a)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef double db;
typedef long long ll;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef tree<pair<int, int>, null_type, less<pair<int, int> >, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<pair<int, int>, null_type, less<pair<int, int> >, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define i128 __int128_t

int N, A[200005], D[200005], ft[200005], ft2[200005];
i128 ans;
pair<int, int> T[200005];
set<int> H;

void read(int &v) {
	v = 0;
	char ch = getchar_unlocked();
	for (; '0' > ch || ch > '9'; ch = getchar_unlocked());
	for (; '0' <= ch && ch <= '9'; ch = getchar_unlocked())
		v = (v << 3) + (v << 1) + (ch & 15);
}

void print(i128 x) {
	if (x < 0) {
		putchar_unlocked('-');
		x = -x;
	}
	if (x > 9) print(x / 10);
	putchar_unlocked(x % 10 + '0');
}

inline int ls(int x) { return x & -x; }

int qry(int p) {
	//cout << "Q1 " << p << ' ';
	int r = 0;
	for (; p > 0; p -= ls(p)) r += ft[p];
	//cout << r << '\n';
	return r;
}

void upd(int p, int v) {
	//cout << "UPD " << p << ' ' << v << '\n';
	for (; p <= N; p += ls(p)) ft[p] += v;
}

int qry2(int p) {
	//cout << "Q2 " << p << ' ';
	int r = 0;
	for (; p > 0; p -= ls(p)) r += ft2[p];
	//cout << r << '\n';
	return r;
}

void upd2(int p, int v) {
	//cout << "UPD2 " << p << ' ' << v << '\n';
	for (; p <= N; p += ls(p)) ft2[p] += v;
}

main() {
	read(N);
	for (int i = 1; i <= N; i++) read(A[i]), T[i] = mp(A[i], i), H.insert(A[i]);
	sort(T + 1, T + 1 + N);
	for (int i = 1, cnt = 0; i <= N; i++) {
		if (T[i].first != T[i - 1].first) cnt++;
		D[T[i].second] = cnt;
	}
	for (int i = 1; i <= N; i++) {
		int bel = D[i] - 1, abv = D[i];
		if (H.find(A[i] - 1) != H.end()) bel--;
		if (H.find(A[i] + 1) != H.end()) abv++;
		upd(D[i], A[i]);
		upd2(D[i], 1);
		ans += (i128)qry2(bel) * (i128)A[i] - (i128)qry(bel) + (i128)(qry2(N) - qry2(abv)) * (i128)A[i] - (i128)(qry(N) - qry(abv));
		//cout << "IDX " << i << ' ' << ans << '\n';
	}
	print(ans);
}