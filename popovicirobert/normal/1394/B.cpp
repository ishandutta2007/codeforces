#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define Test(tt) cout << "Case #" << tt << ": "

using namespace std;


const int MAXN = (int) 2e5;
const int MAXK = 10;

vector<pair<int, int>> g[MAXN + 1];

bool bad[MAXK][MAXK][MAXK][MAXK];
int perm[MAXK];
int ans = 0;

void bkt(int pos, int k) {
	if(pos == k) {
		ans++;
	}
	else {
		for(int cur = 1; cur <= pos + 1; cur++) {
			perm[pos] = cur;

			bool ok = true;
			for(int j = 0; j <= pos; j++) {
				if(bad[j + 1][perm[j]][pos + 1][perm[pos]]) {
					ok = false;
				}
			}

			if(ok) {
				bkt(pos + 1, k);
			}
		}
	}
}

int cnt[MAXK][MAXK];


int main() {
#ifdef HOME
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
    int i, j, n, m, k;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
   	
    cin >> n >> m >> k;
    for(i = 1; i <= m; i++) {
    	int x, y, z;
    	cin >> x >> y >> z;
    	g[x].push_back({y, z});
    }

    vector<vector<pair<int, int>>> pairs(n + 1);
   	
   	for(i = 1; i <= n; i++) {
   		sort(g[i].begin(), g[i].end(), [](const pair<int, int>& a, const pair<int, int>& b) {
   				return a.second < b.second;
   		});

   		for(j = 0; j < (int)g[i].size(); j++) {
   			int nod = g[i][j].first;
   			pairs[nod].push_back({(int)g[i].size(), j + 1});
   		}
   	}


   	for(i = 1; i <= n; i++) {
   		for(auto it : pairs[i]) {
   			cnt[it.first][it.second]++;
   		}

   		for(int a = 1; a < MAXK; a++) {
   			for(int b = 1; b <= a; b++) {
   				if(cnt[a][b] == 0) continue;

   				if(cnt[a][b] > 1) {
   					bad[a][b][a][b] = 1;
   				}
   				else {
	   				for(int c = a + 1; c < MAXK; c++) {	
	   					for(int d = 1; d <= c; d++) {
	   						if(cnt[c][d] == 0) continue;

	   						bad[a][b][c][d] = 1;
	   					}
	   				}
   				}
   			}
   		}

   		for(auto it : pairs[i]) {
   			cnt[it.first][it.second]--;
   		}
   	}

   	bkt(0, k);

   	cout << ans;

    return 0;
}