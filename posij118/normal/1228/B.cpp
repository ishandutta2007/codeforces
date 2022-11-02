#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;

int main(){
    int n, m;
    cin >> n >> m;

    int ans = 1;
    int cnt[n][m], cnt2[n][m];
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cnt[i][j] = 0;
            cnt2[i][j] = 0;
        }
    }

    for(int i = 0; i<n; i++){
        int x;
        cin >> x;

        for(int j = 0; j<x; j++){
            cnt[i][j]++;
        }

        if(x < m) cnt2[i][x]++;
    }

    for(int i = 0; i<m; i++){
        int x;
        cin >> x;

        for(int j = 0; j<x; j++){
            cnt[j][i]++;
        }

        if(x < n) cnt2[x][i]++;
    }

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(cnt[i][j] && cnt2[i][j]){
                cout << 0;
                return 0;
            }

            if(!(cnt[i][j] || cnt2[i][j])){
                ans *= 2;
                ans %= M;
            }
        }
    }

    cout << ans;
}