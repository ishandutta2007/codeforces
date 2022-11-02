#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    string a, b;
    cin >> a >> b;

    int lcs[n + 1][m + 1];

    int ans = 0;

    for(int i = 0; i<=n; i++){
        lcs[i][0] = 0;
    }

    for(int i = 0; i<=m; i++){
        lcs[0][i] = 0;

    }

    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=m; j++){
            if(a[i - 1] == b[j - 1]){
                lcs[i][j] = lcs[i - 1][j - 1] + 2;
                ans = max(ans, lcs[i][j]);
            }

            else{
                lcs[i][j] = max(max(lcs[i - 1][j], lcs[i][j - 1]), 1) -1;
            }
        }
    }

    cout << ans;

}