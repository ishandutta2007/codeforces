#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define Test(tt) cout << "Case #" << tt << ": "

using namespace std;

const int MAXN = (int) 2e5;

vector<int> g[MAXN + 1];
int cnt[2];

void dfs(int nod, int par, int lvl) {
	cnt[lvl & 1]++;
	for(auto it : g[nod]) {
		if(it != par) {
			dfs(it, nod, lvl + 1);
		}
	}
}


int main() {
#ifdef HOME
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
    int i, n;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

	cin >> n;
	for(i = 0; i < n - 1; i++) {
		int x, y;
		cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}

	dfs(1, 0, 0);

	cout << min(cnt[0], cnt[1]) - 1;

    return 0;
}