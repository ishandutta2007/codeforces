#include <iostream>
#include <vector>
#include <set>
#include <tuple>
#include <map>
using namespace std;

typedef vector<int> vi;

#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define has(c,i) ((c).find(i) != (c).end())
#define pb push_back
#define sz(c) int((c).size())

const int maxN = 100000;
vi adj[maxN];
int p[maxN];
bool done[maxN], inB[maxN];
map<int, int> q;

int main() {
	int n, a, b;
	cin >> n >> a >> b;
	if (a == b) b = -1;

	FOR(i, 0, n) {
		cin >> p[i];
		q[p[i]] = i;
		done[i] = false;
	}
	FOR(i, 0, n) {
		if (has(q, a - p[i])) adj[i].pb(q[a - p[i]]);
		if (has(q, b - p[i])) adj[i].pb(q[b - p[i]]);
	}
	bool ok = true;
	FOR(i, 0, n) {
		if (sz(adj[i]) == 0) {
			ok = false;
			break;
		} 
		else if (sz(adj[i]) == 1 && !done[i]) {
			vi comp;
			int prev = i, cur = adj[i][0];
			comp.pb(prev);
			comp.pb(cur);
			while (true) {
				if (sz(adj[cur]) == 1) break;
				int nxt = (adj[cur][0] == prev) ? adj[cur][1] : adj[cur][0];
				comp.pb(nxt);
				prev = cur;
				cur = nxt;
			}
			done[i] = true;
			done[comp[sz(comp) - 1]] = true;
			if (sz(comp) % 2 == 0) {
				bool inb = (p[comp[0]] + p[comp[1]] == b);
				FOR(i, 0, sz(comp)) inB[comp[i]] = inb;
			}
			else {
				ok = false;
				break;
			}
		}
	}

	if (ok) {
		cout << "YES" << endl;
		cout << inB[0];
		FOR(i, 1, n) cout << " " << inB[i];
		cout << endl;
	}
	else {
		cout << "NO" << endl;
	}

}