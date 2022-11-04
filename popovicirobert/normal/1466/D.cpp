#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define Test(tt) cout << "Case #" << tt << ": "
 
 
using namespace std;




int main() {
#ifdef HOME
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
    int t, i;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

	cin >> t;
	while(t--) {
		int n;
		cin >> n;

		vector<pair<int, int>> vals(n + 1);
		for(i = 1; i <= n; i++) {
			cin >> vals[i].first;
		}

		vector<int> deg(n + 1);
		for(i = 1; i < n; i++) {
			int x, y;
			cin >> x >> y;
			deg[x]++;
			deg[y]++;
		}

		for(i = 1; i <= n; i++) {
			vals[i].second = deg[i] - 1;
		}
		sort(vals.rbegin(), vals.rend());

		ll ans = 0;
		for(auto it : vals) {
			ans += it.first;
		}
		cout << ans << " ";

		int pos = 0;
		for(int k = 2; k < n; k++) {
			while(pos <= n && vals[pos].second == 0) {
				pos++;
			}
			if(pos <= n) {
				vals[pos].second--;
				ans += vals[pos].first;
			}
			cout << ans << " ";
		}
		cout << "\n";
	}

	
    return 0;
}