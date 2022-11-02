#include <bits/stdc++.h>
        
using namespace std;
        
        
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

#define aidar asadulin
         
#define int long long
#define ll long long
#define mp make_pair
#define pii pair<int, int>
#define pip pair<int, pii>
#define all(b) b.begin(), b.end()
#define size(a) (int) (a.size())
#define chkmax(a, b) a = max(a, b)
#define chkmin(a, b) a = min(a, b)
#define ld double
        
const int inf = 5e9 + 7;
const int max_n = 3001;

struct group {
	int win, vote;
	group(int win = -1, int vote = 0) : win(win), vote(vote) {}

	group operator+() const {
		return group(win + (vote > 0));
	}

	group operator+(const group& a) const {
		return group(win + a.win, vote + a.vote);
	}

	bool operator<(const group& a) const {
		return win < a.win || (win == a.win && vote < a.vote);
	}
};

int n, m;
vector<int> gr[max_n];
vector<group> f[max_n];

vector<group> merge(vector<group>& v1, vector<group>& v2) {
	vector<group> v(size(v1) + size(v2));

	for(int i = 0;i < size(v1);i++) {
		for(int j = 0;j < size(v2);j++) {
			chkmax(v[i + j], v1[i] + v2[j]);
			chkmax(v[i + j + 1], v1[i] + +v2[j]);
		}
	}
	return v;
}

void dfs(int v, int pr) {
	for(int to : gr[v]) {
		if (to != pr) {
			dfs(to, v);
			f[v] = merge(f[v], f[to]);
		}
	}
}

void solve() {
	cin >> n >> m;
	for(int i = 0;i < n;i++) 
		f[i] = vector<group>(1, group(0, 0));
	for(int i = 0;i < n;i++)
		gr[i].clear();

	int v;
	for(int i = 0;i < n;i++)
		cin >> v, f[i][0].vote -= v;

	for(int i = 0;i < n;i++)
		cin >> v, f[i][0].vote += v;

	for(int i = 0;i < n - 1;i++) {
		int v1, v2;
		cin >> v1 >> v2;
		gr[--v1].emplace_back(--v2);
		gr[v2].emplace_back(v1);
	}
	dfs(0, -1);

	cout << (+f[0][m - 1]).win << endl;
}



signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cout.precision(10);

    int t;
    cin >> t;
    while(t--) {
    	solve();
    }
}