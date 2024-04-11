#include <bits/stdc++.h>
using namespace std;

#define int long long

const int alpha = 12;
const char first = 'a';

struct aho_corasick{
	struct Vertex {
		int next[alpha], go[alpha];
		int p = -1, link = -1;
		char pch;
		int leaf = 0, h = 0;

		Vertex(int p = -1, char ch = '$') : p(p), pch(ch) {
			fill(begin(next), end(next), -1);
			fill(begin(go), end(go), -1);
		}
	};

	vector<Vertex> t = vector<Vertex>(1);

	void add_string(string s, int val) {
		int v = 0, hei = 0;
		for (char ch : s) {
			int c = ch - first;
			if (t[v].next[c] == -1) {
				t[v].next[c] = t.size();
				t.emplace_back(v, ch);
			}
			v = t[v].next[c];
			hei++; t[v].h = hei;
		}
		t[v].leaf += val;
	}

	int get_link(int v) {
		if (t[v].link == -1) {
			if (v == 0 || t[v].p == 0)
				t[v].link = 0;
			else
				t[v].link = go(get_link(t[v].p), t[v].pch);
		}
		return t[v].link;
	}

	int go(int v, char ch) {
		int c = ch - first;
		if (t[v].go[c] == -1) {
			if (t[v].next[c] != -1)
				t[v].go[c] = t[v].next[c];
			else
				t[v].go[c] = v == 0 ? 0 : go(get_link(v), ch);
		}
		return t[v].go[c];
	} 

	int val(int v) {
		return t[v].leaf;
	}
};

string getPattern(string s) {
	string ans; ans.push_back(s[0]); ans.push_back(s[1]);

	for (int i = 2; i < s.size(); i++) {
		char pr = s[i-1], cr = s[i];
		int p1 = -1, p2 = -1;
		for (int j = 0; j < ans.size(); j++) {
			if (ans[j] == pr) p1 = j;
			if (ans[j] == cr) p2 = j;
		}

		if (p2 != -1) {
			if (abs(p1 - p2) != 1) {
				return "aa";
			}
		} else if (p2 == -1) {
			if (p1 == 0) {
				ans.insert(ans.begin(), cr);
			} else if (p1+1 == ans.size()) {
				ans.push_back(cr);
			} else {
				return "aa";
			}
		} else {
			return "aa";
		}
	}

	return ans;
}

const int INF = 1e18;
int val[5005];
int dp[4096][5005], prv[4096][5005], crh[4096][5005];

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	aho_corasick ahcs;
	int n; cin >> n;
	while (n--) {
		int c; string s; cin >> c >> s;
		string pat = getPattern(s);
		if (pat != "aa") {
			ahcs.add_string(pat, c);
			reverse(pat.begin(), pat.end());
			ahcs.add_string(pat, c);
		}
	}

	int nd = ahcs.t.size();
	for (int i = 0; i < nd; i++) {
		ahcs.get_link(i);
		val[i] = ahcs.t[i].leaf;
	}
	for (int h = 0; h <= 12; h++) {
		for (int i = 0; i < nd; i++) {
			if (ahcs.t[i].h != h) continue;
			
			int lk = ahcs.get_link(i);
			if (lk != -1) {
				val[i] += val[lk];
			}
		}
	}
	

	for (int i = 0; i < (1 << 12); i++) {
		for (int j = 0; j < nd; j++) {
			dp[i][j] = -INF;
		}
	}
	dp[0][0] = 0;

	for (int i = 0; i < (1 << 12); i++) {
		for (int j = 0; j < 12; j++) {
			if (i & (1 << j)) continue;
			for (int k = 0; k < nd; k++) {
				int newnode = ahcs.go(k, (char)(j + 'a'));
				int newval = dp[i][k] + val[newnode];
				if (newval > dp[i|(1 << j)][newnode]) {
					dp[i|(1 << j)][newnode] = newval;
					prv[i|(1 << j)][newnode] = k;
					crh[i|(1 << j)][newnode] = j;
				}
			}
		}
	}

	int endTime = 0;
	for (int i = 1; i < nd; i++) {
		if (dp[(1 << 12) - 1][i] > dp[(1 << 12) - 1][endTime]) {
			endTime = i;
		}
	}

	cerr << dp[(1 << 12) - 1][endTime] << '\n';

	int msk = (1 << 12) - 1, ndc = endTime; string ans;
	for (int i = 0; i < 12; i++) {
		int nxtnd = prv[msk][ndc];
		int cr = crh[msk][ndc];

		msk ^= (1 << cr);
		ndc = nxtnd;
		ans.push_back('a' + cr);
	}
	cout << ans << '\n';

	return 0;
}