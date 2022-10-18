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

#define ws ws_____________________
#define y1 y1_____________________
#define y0 y0_____________________
#define left left_________________
#define right right_______________
#define next next_________________
#define prev prev_________________
#define hash hash_________________

#define pb push_back
#define fst first
#define snd second
#define mp make_pair 
#define sz(C) ((int) (C).size())
#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; --i)
#define all(C) begin(C), end(C)

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef long double ld;
typedef complex<double> cd;

#define FILE_NAME "a"

const int INF = 1e9;

string read_token() {
	string s;
	cin >> s;
	return s;
}

map<string, int> num;

int get_num(const string& s) {
	if  (num.count(s)) {
		return num[s];
	}
	int res = sz(num);
	num[s] = res;
	return res;
}

struct Row {
	string var;
	vector<string> tokens;
	
	vi nums;
	int var_num;

	void read() {
		cin >> var;
		string tmp;
		cin >> tmp;
		assert(tmp == ":=");

		tokens.pb(read_token());
		if (isdigit(tokens.back().front())) {
			return;
		}
		forn(it, 2) {
			tokens.pb(read_token());
		}
		
		get_num(var);
	}

	int get_val(int b, int val_b, const vi& vals) const {
		if  (sz(tokens) == 1) {
			return tokens.front()[b] - '0';
		}
		int left = get_val(val_b, vals, 0);
		int right = get_val(val_b, vals, 2);
		string op = tokens[1];
		int res = -1;
		if  (op == "XOR") {
			res = left ^ right;
		} else if  (op == "OR") {
			res = left | right;
		} else if  (op == "AND") {
			res = left & right;
		}  else {
			assert(0);
		}
		return res;
	}

	int get_val(int val_b, const vi& vals, int pos) const {
		if  (tokens[pos] == "?") {
			return val_b;
		}
		return vals.at(nums[pos]);
	}

	void print() const {
		cout << var << " := ";
		for (auto t : tokens) {
			cout << t << " ";
		}
		cout << endl;
	}

	void prepare() {
		for (auto t : tokens) {
			nums.pb(get_num(t));
		}
		var_num = get_num(var);
	}
};

int n, m;
vector<Row> rows;

bool read() {
	if  (!(cin >> n >> m)) {
		return 0;
	}
	rows.resize(n);
	forn(i, n) {
		rows[i].read();
		// rows[i].print();
	}
	forn(i, n) {
		rows[i].prepare();
	}
	return 1;
}

pii get(int b) {
	int max_sum = -1;
	int max_bit = -1;

	int min_sum = INF;
	int min_bit = -1;

	forn(bit, 2) {
		vi val(sz(num), -1);
		int sum = 0;
		for (const auto& row : rows) {
			int cur = row.get_val(b, bit, val);
			sum += cur;
			val[row.var_num] = cur;
		}

		if  (sum > max_sum) {
			max_bit = bit;
			max_sum = sum;
		}
		if  (sum < min_sum) {
			min_bit = bit;
			min_sum = sum;
		}
	}

	return mp(min_bit, max_bit);
}

void solve() {
	string mn;
	string mx;
	forn(b, m) {
		pii cur = get(b);
		mn += cur.fst + '0';
		mx += cur.snd + '0';
	}	
	cout << mn << endl;
	cout << mx << endl;
}

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	while (read()) {
		solve();
	}

#ifdef LOCAL
	cerr.precision(5);
	cerr << "Time: " << fixed << (double) clock() / CLOCKS_PER_SEC << endl;
#endif
	return 0;
}