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
    int t, i, j;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

   	cin >> t;
   	while(t--) {
   		int n, k;
   		cin >> n >> k;

   		vector<vector<bool>> sol(n, vector<bool>(n, 0));

   		for(i = 0; i < n; i++) {
   			int l = 0, c = i;
   			while(sol[l][c] == 0 && k > 0) {
   				k--;
   				sol[l][c] = 1;
   				l = (l + 1) % n;
   				c = (c + 1) % n;
   			}
   		}

   		vector<int> row(n), col(n);
   		for(i = 0; i < n; i++) {
   			for(j = 0; j < n; j++) {
   				row[i] += sol[i][j];
   				col[j] += sol[i][j];
   			}
   		}

   		sort(row.begin(), row.end());
   		sort(col.begin(), col.end());

   		ll ans = 1LL * (row[n - 1] - row[0]) * (row[n - 1] - row[0]) +
   				 1LL * (col[n - 1] - col[0]) * (col[n - 1] - col[0]);

   		cout << ans << "\n";
   		for(i = 0; i < n; i++) {
   			for(j = 0; j < n; j++) {
   				cout << sol[i][j];
   			}
   			cout << "\n";
   		}

   	}


    return 0;
}