#include <bits/stdc++.h>
 
using namespace std;
 
 
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
 
//#define GCC optimize("O3, Ofast")
//#define GCC optimize("unroll-loops")
#define aidar asadulin
  
#define int long long
#define ull long long
#define ll long long
#define mp make_pair
#define pii pair<int, int>
#define pip pair<int, pii>
#define fi first
#define se second
#define all(_v) _v.begin(), _v.end()
#define sz(a) (int) (a.size())
#define chkmax(a, b) a = max(a, b)
#define chkmin(a, b) a = min(a, b)
#define ld double
 
const int inf = 1e9 + 7;
const int max_n = 1e5 + 3;

int n, m, k;
vector<int> gr[max_n];
int used[max_n];
map<string, int> conv;

vector<int> f(string a) {
	vector<int> res;
	for(int i = 0;i < (1 << k);i++) {
		string b = a;
		for(int j = 0;j < k;j++) {
			if ((i >> j) & 1) b[j] = '_';
		}
		if (conv.count(b)) res.emplace_back(conv[b]);
	}
	return res;
}

vector<int> top;

bool dfs(int v) {
	if (used[v] == 1) return true;
	if (used[v] == 2) return false;
	used[v] = 1;
	for(int to : gr[v]) {
		if (dfs(to)) return true;
	}
	top.emplace_back(v);
	used[v] = 2;
	return false;
}

bool solve() {
	cin >> n >> m >> k;

	for(int i = 0;i < n;i++) {
		string s;
		cin >> s;
		conv[s] = i;
	}

	for(int it = 0;it < m;it++) {
		string s;
		int id;
		cin >> s >> id;
		id--;
		vector<int> to = f(s);
		bool cunt = false;
		for(int j : to)
			if (j == id) cunt = true;
		if (!cunt) return false;
		for(int j : to)
			if (j != id) gr[j].emplace_back(id);
	}

	for(int i = 0;i < n;i++) {
		if (!used[i]) if (dfs(i)) return false;
	}
	
	cout << "YES" << endl;

	for(int i : top)
		cout << i + 1 << " ";
	return true;
}

signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cout.precision(10);

    if (!solve()) cout << "NO";
}