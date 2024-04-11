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
    	int n;
    	cin >> n;
    	vector<string> mat(n);
    	vector<vector<int>> fr(3, vector<int>(2));
    	int tot = 0;
    	for(i = 0; i < n; i++) {
    		cin >> mat[i];
    		for(j = 0; j < n; j++) {
    			if(mat[i][j] == '.') continue; 

    			int type = (mat[i][j] == 'X' ? 0 : 1);
    			fr[(i + j) % 3][type]++;
    			tot++;
    		}
    	}

    	vector<pair<int, int>> arr;
    	int ans = n * n;
    	for(int r0 = 0; r0 < 3; r0++) {
    		for(int r1 = 0; r1 < 3; r1++) {
    			if(r0 != r1) {
    				for(int t0 = 0; t0 < 2; t0++) {
    					int t1 = 1 - t0;
    					int cur = fr[r0][t1] + fr[r1][t0];
    					if(cur < ans) {
    						ans = cur;
    						arr = {{r0, t0}, {r1, t1}};
    					}
    				}
    			}
    		}
    	}

    	assert(ans <= tot / 3);
    	for(i = 0; i < n; i++) {
    		for(j = 0; j < n; j++) {
    			if(mat[i][j] == '.') continue;

    			int type = (mat[i][j] == 'X' ? 0 : 1);
    			int r = (i + j) % 3;
    			for(auto it : arr) {
    				if(it.first == r && it.second != type) {
    					if(mat[i][j] == 'X') {
    						mat[i][j] = 'O';
    					}
    					else {
    						mat[i][j] = 'X';
    					}
    					break;
    				}
    			}
    		}
    	}

    	for(i = 0; i < n; i++) {
    		cout << mat[i] << "\n";
    	}
    }
   	
	
    return 0;
}