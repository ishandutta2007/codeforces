#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define Test(tt) cout << "Case #" << tt << ": "

using namespace std;

const int INF = (int) 1e9;


int main() {
#ifdef HOME
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
    int i, j, n, m, t;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> m >> t;

    vector<string> mat(n + 1);
    for(i = 1; i <= n; i++) {
    	cin >> mat[i];
    	mat[i] = " " + mat[i];
    }

    queue<pair<int, int>> Q;
    vector<int> dl = {-1, 0, 1, 0}, dc = {0, -1, 0, 1};

    auto in = [&](int l, int c) {
    	return l > 0 && c > 0 && l <= n && c <= m;
    };

    vector<vector<int>> dst(n + 1, vector<int>(m + 1, INF));

    for(i = 1; i <= n; i++) {
    	for(j = 1; j <= m; j++) {
    		for(int p = 0; p < 4; p++) {
    			int l = i + dl[p], c = j + dc[p];
    			if(in(l, c) && mat[i][j] == mat[l][c]) {
    				dst[i][j] = 0;
    			}
    		}
    		if(dst[i][j] == 0) {
    			Q.push({i, j});
    		}
    	}
    }


    while(Q.size()) {
    	auto cur = Q.front();
    	Q.pop();

    	for(int p = 0; p < 4; p++) {
    		int l = cur.first + dl[p];
    		int c = cur.second + dc[p];

    		if(in(l, c) && dst[l][c] == INF) {
    			dst[l][c] = dst[cur.first][cur.second] + 1;
    			Q.push({l, c});
    		}
    	}
    }

    while(t--) {
    	int l, c;
    	ll p;
    	cin >> l >> c >> p;

    	int cur = mat[l][c] - '0';

    	if(dst[l][c] == INF) {
    		cout << cur << "\n";
    	}
    	else {
    		cout << (cur + max(0LL, p - dst[l][c])) % 2 << "\n";
    	}
    }

    return 0;
}