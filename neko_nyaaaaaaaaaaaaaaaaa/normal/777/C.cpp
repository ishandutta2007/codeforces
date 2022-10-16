#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()  {
    ios::sync_with_stdio(0);      
      
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n+1, vector<int>(m+1)), F(n+1, vector<int>(m+1));
    vector<int> G(n+1);
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }
    for (int j = 1; j <= m; j++) {F[0][j] = 0; a[0][j] = 0;}

    for (int i = 1; i <= n; i++){
        G[i] = 1;
        for (int j = 1; j<=m; j++){
            if (a[i][j] >= a[i-1][j]) F[i][j] = F[i-1][j] +1 ;
            else F[i][j] = 1;
            G[i] = max(G[i], F[i][j]);
        }
    }
    int k ;
    cin >> k;
    int l, r;
    while (k--) {
        cin >> l >> r;
        if (G[r] >= (r-l+1)) {cout << "Yes\n";}
        else {cout << "No\n";}
    }
}