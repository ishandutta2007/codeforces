#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pair2;
typedef pair<int, pair<int, int> > pair3;
typedef pair<int, pair<int, pair<int, int> > > pair4;
#define MAXN 2013
#define INF 1000000000000000000LL
#define MOD 1000000007LL
#define IINF 1000000000
#define mp make_pair
#define pb push_back
#define remove pop
#define all(x) x.begin(), x.end()

//2sat solver is from KACTL

/**
 * Author: Emil Lenngren, Simon Lindholm
 * Date: 2011-11-29
 * Source:
 * Description: Calculates a valid assignment to boolean variables a, b, c,... to a 2-SAT problem, so that an expression of the type $(a\|\|b)\&\&(!a\|\|c)\&\&(d\|\|!b)\&\&...$ becomes true, or reports that it is unsatisfiable.
 * Negated variables are represented by bit-inversions (\texttt{\tilde{}x}).
 * Usage:
 *  TwoSat ts(number of boolean variables);
 *  ts.either(0, \tilde3); // Var 0 is true or var 3 is false
 *  ts.set_value(2); // Var 2 is true
 *  ts.at_most_one({0,\tilde1,2}); // <= 1 of vars 0, \tilde1 and 2 are true
 *  ts.solve(); // Returns true iff it is solvable
 *  ts.values[0..N-1] holds the assigned values to the vars
 * Time: O(N+E), where N is the number of boolean variables, and E is the number of clauses.
 */
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define sz(x) (int)(x).size()
typedef pair<int, int> pii;
typedef vector<int> vi;

struct TwoSat {
	int N;
	vector<vector<int> > gr;
	vector<int> values; // 0 = false, 1 = true

	TwoSat(int n = 0) : N(n), gr(2*n) {}

	int add_var() { // (optional)
		gr.emplace_back();
		gr.emplace_back();
		return N++;
	}

	void either(int f, int j) {
		f = max(2*f, -1-2*f);
		j = max(2*j, -1-2*j);
		gr[f].push_back(j^1);
		gr[j].push_back(f^1);
	}
	void set_value(int x) { either(x, x); }

	void at_most_one(const vi& li) { // (optional)
		if (sz(li) <= 1) return;
		int cur = ~li[0];
		rep(i,2,sz(li)) {
			int next = add_var();
			either(cur, ~li[i]);
			either(cur, next);
			either(~li[i], next);
			cur = ~next;
		}
		either(cur, ~li[1]);
	}

	vi val, comp, z; int time = 0;
	int dfs(int i) {
		int low = val[i] = ++time, x; z.push_back(i);
		trav(e, gr[i]) if (!comp[e])
			low = min(low, val[e] ?: dfs(e));
		if (low == val[i]) do {
			x = z.back(); z.pop_back();
			comp[x] = low;
			if (values[x>>1] == -1)
				values[x>>1] = x&1;
		} while (x != i);
		return val[i] = low;
	}

	bool solve() {
		values.assign(N, -1);
		val.assign(2*N, 0); comp = val;
		rep(i,0,2*N) if (!comp[i]) dfs(i);
		rep(i,0,N) if (comp[2*i] == comp[2*i+1]) return 0;
		return 1;
	}

	void solverxor(int x, int y) {
		either(x,y);
		at_most_one({x,y});
	}

};

int n;
int startArray[MAXN][MAXN];
int endArray[MAXN][MAXN];
int wand[MAXN];


int main() {
	if (fopen("FILENAME.in", "r")) {
		freopen("FILENAME.in", "r", stdin);
		freopen("FILENAME.out", "w", stdout);
	}
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < n; j++) {
			startArray[i][j] = s[j] - '0';
		}
	}

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < n; j++) {
			endArray[i][j] = s[j] - '0';
		}
	}

	string s;
	cin >> s;
	for (int i = 0; i < n; i++) {
		wand[i] = s[i] - '0';
	}

	TwoSat solver(2 * n); //Parity of times applied to each row/col
	/*
	cout << "testing solver " << endl;
	solver.set_value(0);
	//solver.set_value(~0);

	cout << "result is " << solver.solve() << endl;
	for (int i = 0; i < n; i++) {
		cout << solver.values[i] << endl;
	}
	cout << "end testing " << endl;*/

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int delta = 0;
			if (startArray[i][j] != endArray[i][j]) {
				delta = 1;
			}

			//cout << "check " << i << ' ' << j << " delta is " << delta << endl;

			//both apply
			if (wand[i] == 1 && wand[j] == 1) {
				if (delta == 1) {
					//either A is one or B is one but not both
					//A XOR B = (A NAND (A NAND B)) NAND (B NAND (A NAND B))
					//cout << "xor " << i << ' ' << (n + j) << endl;
					solver.solverxor(i, n + j);
				} else {
					//BOth are zero OR both are 2

					//cout << "not xor " << i << ' ' << (n + j) << endl;
					solver.solverxor(~i, n + j);
				}
			} else if (wand[i] == 1) {
				//Vertical
				if (delta == 1) {
					//cout << "set true " << (n + j) << endl;
					solver.set_value(n + j);
				} else {
					solver.set_value(~(n + j));
					//cout << "set false " << (n + j) << endl;
				}
			} else if (wand[j] == 1) {
				//Horizontal
				int index = i;
				if (delta == 1) solver.set_value(index);
				else solver.set_value(~index);
			} else if (delta == 1) {
				cout << -1 << endl;
				return 0;
			}
		}
	}

	//cout << "YEET" << endl;

	if (!solver.solve()) {
		cout << "-1" << endl;
		return 0;
	}

	int cnt = 0;
	for (int i = 0; i < 2 * n; i++) {
		if (solver.values[i]) {
			cnt++;
		}
	}

	cout << cnt << '\n';
	for (int i = 0; i < n; i++) {
		if (solver.values[i]) {
			cout << "row " << i << '\n';
		}
	}

	for (int i = 0; i < n; i++) {
		if (solver.values[n + i]) {
			cout << "col " << i << '\n';
		}
	}
}