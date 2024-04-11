#include <bits/stdc++.h>
#define ff first
#define ss second
#define puba push_back
#define szof(x) ((int) (x).size())
#define bend(x) (x).begin(), (x).end()

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

int n;
vector<pii> trie;
vector<int> here;
vector<int> rest;

int dfs(int v, int roof, int val) {
	rest[v] = 0;
 	if (trie[v].ff != -1) {
 	 	dfs(trie[v].ff, roof, val * 2);
 	 	rest[v] += rest[trie[v].ff];
 	}
 	if (trie[v].ss != -1) {
 	 	dfs(trie[v].ss, roof, val * 2 + 1);
 	 	rest[v] += rest[trie[v].ss];
 	}
 	rest[v] += here[v];
 	if (val <= roof) {
 	 	rest[v] = max(0, rest[v] - 1);
 	}
 	return 0;
}

vector<int> ans;

int dfs2(int v, int roof, int val) {
	rest[v] = 0;
 	if (trie[v].ff != -1) {
 	 	dfs2(trie[v].ff, roof, val * 2);
 	 	rest[v] += rest[trie[v].ff];
 	}
 	if (trie[v].ss != -1) {
 	 	dfs2(trie[v].ss, roof, val * 2 + 1);
 	 	rest[v] += rest[trie[v].ss];
 	}
 	rest[v] += here[v];
 	if (val <= roof && rest[v]) {
 	 	rest[v] = max(0, rest[v] - 1);
 	 	ans.puba(val);
 	}
 	return 0;
}

int main() {
	trie.puba({-1, -1});
	here.puba(0);
	scanf("%d", &n);
	
	for (int i = 0; i < n; ++i) {
	 	int num;
	 	scanf("%d", &num);

	 	vector<int> v;
	 	while (num) {
	 	 	v.puba(num & 1);
	 	 	num >>= 1;
	 	}

	 	/*
	 	for (int d: v) {
	 	 	cerr << d;
	 	}
	 	cerr << endl;
	 	*/
	 	v.pop_back();
	 	int pos = 0;
	 	while (szof(v)) {
	 		//cerr << pos << endl;
			if (v.back() == 0) {
			 	if (trie[pos].ff == -1) {
			 		trie[pos].ff = szof(trie);
			 		trie.puba({-1, -1});
			 		here.puba(0);
			   	}
			   	pos = trie[pos].ff;
			} else {
				if (trie[pos].ss == -1) {
			 		trie[pos].ss = szof(trie);
			 		trie.puba({-1, -1});
			 		here.puba(0);
			   	}
			   	pos = trie[pos].ss;
			}	
			v.pop_back();
	 	}	
	 	here[pos] = 1;
	 	//cerr << i << endl;
	}

	rest.resize(szof(trie));

	int l = 0, r = 1e9 + 5;
	while (r - l > 1) {
	 	int mid = (l + r) / 2;
	 	dfs(0, mid, 1);
	 	if (rest[0] == 0) {
	 	 	r = mid;
	 	} else {
	 	 	l = mid;
	 	}
	}

	dfs2(0, r, 1);

	for (int num: ans) {
	 	cout << num << " ";
	}
	cout << "\n";

	#ifdef LOCAL
		cerr << "time: " << clock() << endl;
	#endif
	return 0;
}