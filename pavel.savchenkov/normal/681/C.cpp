#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <cstdlib>
#include <memory>
#include <queue>
#include <cassert>
#include <cmath>
#include <ctime>
#include <complex>
#include <bitset>
#include <fstream>
#include <unordered_map>
#include <unordered_set>
#include <numeric>

using namespace std;

#define pb push_back
#define fst first
#define snd second
#define mp make_pair 
#define sz(C) ((int) (C).size())
#define forn(i, n) for (int i = 0; i < (int) n; ++i)
#define ford(i, n) for (int i = ((int) n) - 1; i >= 0; --i)
#define y1 gftxdtrtfhyjfctrxujkvbhyjice
#define y0 ehfoiuvhefroerferjhfjkehfjke
#define left sdhfsjkshdjkfsdfgkqqweqweh
#define right yytrwtretywretwreytwreytwr
#define next jskdfksdhfjkdsjksdjkgf
#define prev koeuigrihjdkjdfj
#define hash kjfdkljkdhgjdkfhgurehg
#define all(C) begin(C), end(C)

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vector <int> > vvi;
typedef vector<pii> vii;
typedef long double ld;
typedef complex<double> cd;
typedef vector<cd> vcd;

#define FILE_NAME "a"


const int MAXN = 1e5 + 10;

const int INSERT = 0;
const int GET_MIN = 1;
const int REMOVE = 2;

struct Query {
	int type;
	int x;

	bool read() {
		string s;
		cin >> s;
		if  (s == "insert") {
			type = INSERT;
		} else if  (s == "getMin") {
			type = GET_MIN;
		} else {
			assert(s == "removeMin");
			type = REMOVE;
		}
		if  (type != REMOVE) {
			cin >> x;
		}
		return true;
	}

	void print() const {
		if  (type == INSERT) {
			cout << "insert " << x << '\n';
		} else if  (type == GET_MIN) {
			cout << "getMin " << x << '\n';
		} else {
			cout << "removeMin" << '\n';
		}
	}
};

Query qs[MAXN];
int n;

bool read() {
	cin >> n;
	forn(i, n) {
		qs[i].read();
	}
	return true;
}

multiset<int> s;

void solve() {
	vector<Query> ans;

	forn(i, n) {
		auto q = qs[i];
		if  (q.type == INSERT) {
			s.insert(q.x);
			ans.pb(q);
		} else if  (q.type == GET_MIN) {
			while (!s.empty() && *s.begin() < q.x) {
				ans.pb(Query{REMOVE, 0});
				s.erase(s.begin());
			}
			if  (s.empty() || *s.begin() != q.x) {
				ans.pb(Query{INSERT, q.x});
				s.insert(q.x);
			}
			ans.pb(q);
		} else {
			if  (s.empty()) {
				ans.pb(Query{INSERT, 1});
				s.insert(1);
			}
			ans.pb(q);
			s.erase(s.begin());
		}
	}

	cout << sz(ans) << '\n';
	for (auto q : ans) {
		q.print();
	}
}

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	ios_base::sync_with_stdio(false);

	while (read()) {
		solve();
		break;
	}

#ifdef LOCAL
	printf("Time: %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}