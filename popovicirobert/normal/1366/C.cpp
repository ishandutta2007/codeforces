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
   	int	t, i, j;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--) {
    	int n, m;
    	cin >> n >> m;

    	vector<vector<int>> fr(n + m, vector<int>(2));
    	for(i = 0; i < n; i++) {
    		for(j = 0; j < m; j++) {
    			int x;
    			cin >> x;
    			fr[i + j][x]++;
    		}
    	}

    	int beg = 0, end = n + m - 2;
    	int ans = 0;
    	while(beg < end) {
    		int one = fr[beg][1] + fr[end][1];
    		int zero = fr[beg][0] + fr[end][0];
    		ans += min(one, zero);
    		beg++, end--;
    	}

    	cout << ans << "\n";
    }
  	

    return 0;
}