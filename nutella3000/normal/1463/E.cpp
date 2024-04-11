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
        
const int inf = 5e9 + 7;
const int max_n = 3e5 + 3;

int n;
vector<int> gr[max_n];
vector<int> ver[max_n];

void dfs1(int v, int c) {
	ver[c].emplace_back(v);
	for(int to : gr[v])
		dfs1(to, c);
} 

deque<int> ord;
int used[max_n];

bool topsort(int v) {
	if (used[v] == 1) return false;
	if (used[v] == 2) return true;
	used[v] = 1;
	for(int to : gr[v]) {
		if (!topsort(to)) {
			used[v] = 2;
			return false;
		}
	}
	used[v] = 2;
	ord.emplace_front(v);
	return true;
}


int tin[max_n], tout[max_n], T = 0;

void predfs(int v) {
	tin[v] = T++;
	for(int to : gr[v])
		predfs(to);
	tout[v] = T++;
}

void solve() {
	int k;
	cin >> n >> k;
	vector<int> p(n);
	int root = 0;
	for(int i = 0;i < n;i++) {
		cin >> p[i], --p[i];
		if (p[i] != -1) gr[p[i]].emplace_back(i);
		else root = i;
	}
	predfs(root);
	for(int i = 0;i < n;i++)
		gr[i].clear();


	vector<int> in(n);

	for(int i = 0;i < k;i++) {
		int x, y;
		cin >> x >> y;
		gr[--x].emplace_back(--y);
		in[y]++;
	}
	int c = 0;
	for(int i = 0;i < n;i++) 
		if (in[i] == 0) dfs1(i, c++);
	
	vector<int> pos(n);

	int cnt = 0;
	vector<bool> baba(n);
	for(int i = 0;i < c;i++) {
		for(int j : ver[i]) {
			pos[j] = i, cnt++;
			if (p[j] != -1) baba[p[j]] = true;
			if (baba[j]) {
				cout << "0\n";
				return;
			}
		}
		for(int j : ver[i])
			if (p[j] != -1) baba[p[j]] = false;
	}

	if (cnt != n) {
		cout << "0\n";
		return;
	}
 	
 	for(int i = 0;i < n;i++)
 		gr[i].clear();

	for(int i = 0;i < n;i++) {
		if (p[i] == -1) continue;
		int v = pos[p[i]], to = pos[i];
		if (v != to) gr[v].emplace_back(to);
		//cout << "new_gr: " << v << " " << to << endl;
	}

	for(int i = 0;i < c;i++) {
		if (!used[i] && !topsort(i)) {
			cout << "0\n";
			return;
		}
	}
	for(int i : ord) {
		for(int j : ver[i])
			cout << j + 1 << " ";
	}
	cout << endl;
}


signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cout.precision(10);

   	solve();
}