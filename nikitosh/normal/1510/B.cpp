#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define sz(x) (int)((x).size())
#define forn(i,n) for(int i = 0; i < (n); i++)
#define fornr(i,n) for(int i = (n) - 1; i >= 0; --i)
#define forab(i,a,b) for(int i = (a); i < (b); i++)
#define all(c) (c).begin(), (c).end()

using ll = long long;
using vi = vector<int>;
using pii = pair<int,int>;

const int N = 1 << 11;

int n, m, paired[2 * N], used[2 * N];
vi g[N];

bool dfs(int v) {
	if (used[v]) return false;
	used[v] = 1;
	for(int to : g[v]) {
		if (paired[to] == -1 || dfs(paired[to])) {
			paired[to] = v, paired[v] = to;
			return true;
		}
	}
	return false;
}

int kuhn() {
	int ans = 0;
	forn(i, n + m) paired[i] = -1;
	for(int run = 1; run;) {
		run = 0;
		fill(used, used + n + m, 0);
		forn(i, n) {
			if (!used[i] && paired[i] == -1 && dfs(i)) {
				ans++, run = 1;
				break;
			}
		}
	}
	return ans;
}

bool cmp(int a, int b) {
	return __builtin_popcount(a) > __builtin_popcount(b);
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int d;
	cin >> d >> n;
	m = n;	
	vector<int> masks;
	forn(i, n) {
		string s;
		cin >> s;
		int mask = 0;
		forn(j, d) {
			if (s[j] == '1') {
				mask |= (1 << j);	
			}
		}
		masks.pb(mask);
	}
	sort(all(masks), &cmp);
	forn(i, n) {
		forn(j, n) {
			if (i == j) continue;
			int m1 = masks[i];
			int m2 = masks[j];
			if ((m1 & m2) == m1) {
				g[i].pb(n + j);
//				cerr << bitset<3>(m1) << " " << bitset<3>(m2) << '\n';
			}
		}
	}
	kuhn();
	vector<int> nxt(n, -1);
	vector<int> init(n, 1);
	forn(i, n) {
		if (paired[i] != -1) {
			nxt[i] = paired[i] - n;
			init[nxt[i]] = 0;
//			cerr << i << " " << nxt[i] << " "  << init[nxt[i]] << '\n';
		}
	}
	
/*	forn(i, n) {
		cerr << bitset<3>(masks[i]) << '\n';
	}*/
	vector<char> ans;
	int needReset = 0;
	forn(i, sz(masks)) {
		if (init[i]) {
			if (needReset) {
				ans.pb('R');
			}
			int prev = 0;
			int ind = i;
			while(1) {
				int delta = masks[ind] ^ prev;
				forn(k, d) {
					if ((delta >> k) & 1) {
						ans.pb(char('0' + k));
					}
				}
				prev = masks[ind];
				if (nxt[ind] == -1) {
					break;
				}
				ind = nxt[ind];
			}
			needReset = 1;
		}
	}
	cout << sz(ans) << '\n';
	for(auto c : ans) cout << c << " ";
	cout << '\n';
	return 0;
}