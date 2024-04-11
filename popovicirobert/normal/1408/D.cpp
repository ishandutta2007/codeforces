#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define Test(tt) cout << "Case #" << tt << ": "
 
 
using namespace std;

const int MAXSIZE = (int) 1e6;

vector<pair<int, int>> X[MAXSIZE + 5];


int main() {
#ifdef HOME
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
    int i, j, n, m;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;
    vector<pair<int, int>> R(n), S(m);
    for(i = 0; i < n; i++) {
    	cin >> R[i].first >> R[i].second;
    }
    for(i = 0; i < m; i++) {
    	cin >> S[i].first >> S[i].second;
    }
    for(i = 0; i < n; i++) {
    	for(j = 0; j < m; j++) {
    		if(S[j].first - R[i].first >= 0)
    			X[S[j].first - R[i].first].push_back({i, j});
    	}
    }

    int mx = 0, ans = MAXSIZE + 1;
   	for(int x = MAXSIZE + 1; x >= 0; x--) {
   		for(auto it : X[x]) {
   			mx = max(mx, S[it.second].second - R[it.first].second + 1);
   		}
   		ans = min(ans, mx + x);
   	}

   	cout << ans;

    return 0;
}