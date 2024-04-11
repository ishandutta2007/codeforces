#include <bits/stdc++.h>
#define ff first
#define ss second
#define puba push_back
#define szof(_x) ((int) (_x).size())
#define bend(_x) (_x).begin(), (_x).end()
#define TASK_NAME ""           

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const ll MOD1 = 1e9 + 9, P = 239, MOD2 = 1e9 + 7;
const int MAXN = 1e5 + 5, MAXL = 100;

int n;
vector<string> sites;
map<string, int> id;
vector<tuple<int, int, int>> hashs;
vector<tuple<int, int, int>> here[MAXN];
map<pii, vector<int>> groups;
ll arrp1[MAXN];
ll arrp2[MAXN];
char s[MAXL];

int main() {
	//freopen(TASK_NAME ".in", "r", stdin);
	//freopen(TASK_NAME ".out", "w", stdout);

	scanf("%d", &n);

	int c = 0;
	for (int i = 0; i < n; ++i) {
	 	scanf("%s", s);
	 	int l = strlen(s);
	 	string site = "http://";
	 	int j;
	 	for (j = 7; j < l && s[j] != '/'; ++j) {
	 	 	site += s[j];
	 	}

	 	ll h1 = 0;
	 	ll h2 = 0;
	 	int hl = 0;
	 	for (; j < l; ++j) {
	 		 h1 = (h1 * P + s[j]) % MOD1;
	 		 h2 = (h2 * P + s[j]) % MOD2;
	 		 ++hl;
	 	}
		if (!id.count(site)) {
		 	id[site] = c++;
		 	sites.puba(site);
		}
		hashs.puba(make_tuple(h1, h2, hl));
		//cerr << "add " << id[site] << " " << h << endl;
		here[id[site]].puba(make_tuple(h1, h2, hl));
	}
	
	for (int i = 0; i < szof(id); ++i) {
	 	sort(bend(here[i]));
	 	here[i].resize(unique(bend(here[i])) - here[i].begin());
	 	//cerr << i << " " << sites[i] << endl;
	 	/*
	 	for (int j: here[i]) {
	 	    cerr << j << " ";
	 	}	
	 	cerr << endl;*/
	}

	sort(bend(hashs));
	hashs.resize(unique(bend(hashs)) - hashs.begin());

	arrp1[0] = 1;
	for (int i = 1; i < MAXN; ++i) {
	 	arrp1[i] = (ll) arrp1[i - 1] * P % MOD1;
	}
	arrp2[0] = 1;
	for (int i = 1; i < MAXN; ++i) {
	 	arrp2[i] = (ll) arrp2[i - 1] * P % MOD2;
	}

	for (int i = 0; i < szof(id); ++i) {
		ll h1 = 0;
		ll h2 = 0;
		for (auto h: here[i]) {
		 	int pos = lower_bound(bend(hashs), h) - hashs.begin();
		 	h1 = (h1 + arrp1[pos]) % MOD1;
			h2 = (h2 + arrp2[pos]) % MOD2;
		}
		groups[{h1, h2}].puba(i);
	}

	vector<string> ans;
	for (auto& p: groups) {
	  	if (szof(p.ss) <= 1) {
	  	 	continue;
	  	}
	  	string now;
	  	for (int num: p.ss) {
	  	 	now += sites[num];
	  	 	now += " ";
	  	}
	  	ans.puba(now);
	}	

	cout << szof(ans) << "\n";
	for (auto& a: ans) {
	    cout << a << "\n";
	}	


	return 0;
}