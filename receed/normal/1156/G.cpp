#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <random>
#include <bitset>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <queue>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;
using ld = long double;

map<string, int> cn;
map<vector<int>, int> gn;
const int N = 5001;
int tv[N], t1[N], t2[N], top[N], cs = 3005, fs = cs;
map<int, string> nc;
string ide = "aaaa", lop = "$^#&";
set<int> used;

int sadd(string s) {
	if (!cn.count(s)) {
		int sz = cn.size();
		cn[s] = sz;
		nc[sz] = s;
	}
	return cn[s];
}

string genn(int num) {
	if (nc.count(num))
		return nc[num];
	while (cn.count(ide)) {
		for (int i = 3; i >= 0; i--) {
			if (ide[i] == 'z')
				ide[i] = 'a';
			else {
				ide[i]++;
				break;
			}
		}
	}
	cn[ide] = num;
	nc[num] = ide;
	return ide;
}

vector<string> ans;

void dfs(int v) {
	if (v < fs || used.count(v))
		return;
	used.insert(v);
	dfs(t1[v]);
	dfs(t2[v]);
	ans.push_back(genn(v) + "=" + genn(t1[v]) + lop[top[v]] + genn(t2[v]));
}


int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	string s;
	map<char, int> mp = {{'$', 0}, {'^', 1}, {'#', 2}, {'&', 3}};
	cn["res"] = 0;
	nc[0] = "res";
	rep(i, cs)
		tv[i] = i;
	rep(i, n) {
		cin >> s;
		vector<string> ts(3);
		int op;
		int p = 0;
		for (char c : s) {
			if (c == '=')
				p++;
			else if (mp.count(c)) {
				op = mp[c];
				p++;
			}
			else
				ts[p].push_back(c);
		}
		if (p == 1) {
			int n1 = sadd(ts[0]), n2 = tv[sadd(ts[1])];
			tv[n1] = n2;
		}
		else {
			int n1 = sadd(ts[0]), n2 = tv[sadd(ts[1])], n3 = tv[sadd(ts[2])];
			vector<int> di = {n2, n3, op};
			if (!gn.count(di)) {
				t1[cs] = n2;
				t2[cs] = n3;
				top[cs] = op;
				gn[di] = cs++;
			}
			tv[n1] = gn[di];
		}
	}
	if (tv[0] >= fs)
		nc[tv[0]] = "res";
	dfs(tv[0]);
	if (tv[0] < fs && tv[0] != 0)
		ans.push_back("res=" + genn(tv[0]));
	cout << ans.size() << '\n';
	for (string rs : ans)
		cout << rs << '\n';
}