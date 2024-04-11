#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define Test(tt) cout << "Case #" << tt << ": "

using namespace std;


int main() {
#ifdef HOME
    ifstream cin("C.in");
    ofstream cout("C.out");
#endif
    int t, i, n, m;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
	
	cin >> t;
 
    while(t--) {
        cin >> n >> m;
 
        vector <bool> vis(3 * n + 1);
        vector <int> sol;
 
        for(i = 1; i <= m; i++) {
            int x, y;
            cin >> x >> y;
            if(vis[x] == 0 && vis[y] == 0) {
                sol.push_back(i);
                vis[x] = vis[y] = 1;
            }
        }
 
        if(sol.size() >= n) {
            cout << "Matching\n";
            for(i = 0; i < n; i++) {
                cout << sol[i] << " ";
            }
            cout << "\n";
        }
        else {
            cout << "IndSet\n";
            int cnt = 0;
            for(i = 1; i <= 3 * n; i++) {
                if(vis[i] == 0 && cnt < n) {
                    cout << i << " ";
                    cnt++;
                }
            }
            cout << "\n";
        }
    }
		

    return 0;
}