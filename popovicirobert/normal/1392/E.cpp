#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define Test(tt) cout << "Case #" << tt << ": "

using namespace std;




int main() {
#ifdef HOME
    //ifstream cin("A.in");
    //ofstream cout("A.out");
#endif
    int i, j, n, q;
    //ios::sync_with_stdio(false);
    //cin.tie(0), cout.tie(0);
   	
    cin >> n;

    vector<vector<ll>> mat(n, vector<ll>(n, 0));
    for(i = 0; i < n; i++) {
    	for(j = 0; j < n; j++) {
    		if(j % 2 == 0) {
    			mat[i][j] = (1LL << (i + j));
    		}
    		cout << mat[i][j] << " ";
    	}
    	cout << endl;
    }

    /*
	1 0 4
	2 0 8
	4 0 16
    */
   	
    cin >> q;
    while(q--) {
    	ll sum;
    	cin >> sum;

    	int l = 0, c = 0;
    	while(min(l, c) < n - 1) {
    		cout << l + 1 << " " << c + 1 << endl;
    		sum -= mat[l][c];

    		if(c == n - 1) {
    			l++;
    		}
    		else if(l == n - 1) {
    			c++;
    		}
    		else if(c % 2 == 0) {
    			if(sum & mat[l + 1][c]) {
    				l++;
    			}
    			else {
    				c++;
    			}
    		}
    		else {
    			if(sum & mat[l][c + 1]) {
    				c++;
    			}
    			else {
    				l++;
    			}
    		}
    	}

    	cout << n << " " << n << endl;
    }

    return 0;
}