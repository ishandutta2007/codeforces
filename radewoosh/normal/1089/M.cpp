#ifndef LOCAL
#pragma GCC optimize("O3")
#endif
#include <bits/stdc++.h>
using namespace std;
#define sim template <class c
#define mor > muu & operator<<(
#define ris return *this
#define R22(r) sim> typename enable_if<1 r sizeof(dud<c>(0)),muu&>::type operator<<(c g) {
sim> struct rge {c b, e;};
sim> rge<c> range(c i, c j) {return rge<c>{i, j};}
sim> auto dud(c*r)->decltype(cerr << *r);
sim> char dud(...);
struct muu {
	#ifdef LOCAL
	stringstream a;
	~muu() {cerr << a.str() << endl;}
	R22(<) a << boolalpha << g; ris;}
	R22(==) ris << range(begin(g), end(g));}
	sim mor rge<c> u) {
		a << "[";
		for (c i = u.b; i != u.e; ++i)
			*this << ", " + 2 * (i == u.b) << *i;
		ris << "]";
	}
	sim, class m mor pair<m,c> r) {ris << "(" << r.first << ", " << r.second << ")";}
	#else
	sim mor const c &){ris;}
	#endif
	muu & operator()(){ris;}
};
#define imie(r) "[" #r ": " << (r) << "] "
#define debug (muu() << __FUNCTION__ << "#" << __LINE__ << ": " )
const int nax = 9;
using pii = pair <int, int>;
int a[nax][nax];
bool used[nax];
char ans[100][100][100];
int n;
int deg(int x) {
	int aa = 0;
	for (int i = 0; i < n; ++i)
		aa += a[x][i];
	return aa;
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			scanf("%d", &a[i][j]);
	for (int i = 0; i < n; ++i)
		a[i][i] = true;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			for (int k = 0; k < n; ++k)
				if (a[j][i] && a[i][k])
					a[j][k] = true;
	vector <vector <int> > coms;
	for (int i = 0; i < n; ++i) {
		if (used[i]) continue;
		coms.emplace_back();
		for (int j = 0; j < n; ++j)
			if (a[i][j] && a[j][i]) {
				coms.back().push_back(j);
				used[j] = true;
			}
	}
	sort(coms.begin(), coms.end(), [](vector <int> x, vector <int> y){return deg(x[0]) > deg(y[0]);});
	debug << imie(coms);
	vector <pii> edges;
	int ile = coms.size();
	for (int i = 0; i < ile; ++i)
		for (int j = i + 1; j < ile; ++j) {
			if (a[coms[i][0]][coms[j][0]])
				edges.emplace_back(i, j);
		}
	int l = max<int>(n, 2 * edges.size() + 1);
	int layers = coms.size() * 2 - 1;
	debug << imie(edges);
	int x = l;
	int y = 3;
	int z = layers;
	for (int i = 0; i < z; ++i) {
		char c = (i & 1) ? '#' : '.';
		for (int j = 0; j < x; ++j)
			for (int k = 0; k < y; ++k)
				ans[j][k][i] = c;
	}
	for (int i = 0; i < (int) coms.size(); ++i) {
		int e = 0;
		for (int xx : coms[i])
			ans[e++][0][i * 2] = xx + '1';
	}
	int wh = 1;
	for (auto e : edges) {
		for (int i = 2 * e.first; i <= 2 * e.second; ++i)
			ans[wh][2][i] = '.';
		for (int i = 2 * e.first + 1; i < 2 * e.second; ++i)
			ans[wh - 1][2][i] = ans[wh][1][i] = ans[wh + 1][2][i] = '#';
		wh += 2;
	}
	printf("%d %d %d\n", y, x, z);
	for (int i = 0; i < z; ++i) {
		for (int j = 0; j < x; ++j) {
			for (int k = 0; k < y; ++k)
				printf("%c", ans[j][k][i]);
			printf("\n");
		}
		printf("\n");
	}
}