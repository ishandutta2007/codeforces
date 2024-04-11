#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define Test(tt) cout << "Case #" << tt << ": "

using namespace std;




int main() {
#ifdef HOME
    ifstream cin("B.in");
    ofstream cout("B.out");
#endif
    int t, i, j;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

   	cin >> t;
   	while(t--) {
   		int na, nb, nc; cin >> na >> nb >> nc;
   		vector<vector<int>> arr(4);
   		arr[1].resize(na);
   		arr[2].resize(nb);
   		arr[3].resize(nc);
   		for(i = 1; i <= 3; i++) {
   			for(auto &it : arr[i]) {
   				cin >> it;
   			}
   			sort(arr[i].begin(), arr[i].end());
   		}

   		auto solve = [&](int a, int b, int c) {
   			ll ans = 3e18;
   			int pa = 0, pc = 0;
   			for(auto it : arr[b]) {
   				while(pa < (int)arr[a].size() && arr[a][pa] <= it) {
   					pa++;
   				}
   				while(pc < (int)arr[c].size() && arr[c][pc] < it) {
   					pc++;
   				}
   				if(pa > 0) {
   					pa--;
   					if(pc < (int)arr[c].size()) {
   						ans = min(ans, 1LL * (it - arr[a][pa]) * (it - arr[a][pa]) + 1LL * (arr[c][pc] - it) * (arr[c][pc] - it) + 1LL * (arr[c][pc] - arr[a][pa]) * (arr[c][pc] - arr[a][pa]));
   					}
   				}
   			}
   			return ans;
   		};

   		vector<int> p(3);
   		iota(p.begin(), p.end(), 1);
   		ll ans = 3e18;
   		for(i = 0; i < 6; i++) {
   			ans = min(ans, solve(p[0], p[1], p[2]));
   			next_permutation(p.begin(), p.end());
   		}

   		cout << ans << "\n";
   	}

    return 0;
}