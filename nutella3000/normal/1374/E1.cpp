#include <bits/stdc++.h>
using namespace std;
  
#define int long long
#define pii pair<int, int>
#define sz(a) ((int)a.size())  
typedef long double ld;
const int inf = 1e18 + 7;
 
int n, k;
vector<int> a[4];
vector<int> id(4);


signed main() {
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
  	#endif
 
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> k;

    for(int i = 0;i < 4;i++) {
    	a[i].emplace_back(inf);
    }

    for(int i = 0;i < n;i++) {
    	int t, q, w;
    	cin >> t >> q >> w;
    	a[q * 2 + w].emplace_back(t);
    }

    for(int i = 0;i < 4;i++) sort(a[i].begin(), a[i].end());

    int time = 0;
	for(int i = 0;i < k;i++) {
		int v1 = a[1][id[1]] + a[2][id[2]];
		int v2 = a[3][id[3]]; 
		if (v1 < v2) {
			id[1]++;
			id[2]++;
			time += v1;
		}else {
			id[3]++;
			time += v2;
		}
		//cout << id[1] << " " << id[2] << " " << id[3] << endl;
		if (time >= inf) break;
	}

	if (time >= inf) cout << -1;
	else cout << time << endl;
}