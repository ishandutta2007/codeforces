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
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

   
    int n;
    cin >> n;
    vector<int> p(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }

    vector<vector<int>> sol(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++) {
        sol[i][i] = p[i];
        
        int l = i, c = i;
        int steps = 0;
        while (steps < p[i] - 1) {
            if (c > 1 && sol[l][c - 1] == 0) {
                c--;
            } else if (l < n && sol[l + 1][c] == 0) {
                l++;
            } else {
                assert(0);
            }

            steps++;
            sol[l][c] = p[i];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cout << sol[i][j] << " ";
        }
        cout << "\n";
    }
    
    return 0;
}