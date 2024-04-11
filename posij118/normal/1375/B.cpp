#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){

    int n, m;
    cin >> n >> m;

    int a[n][m];
    int ans[n][m];
    bool flag = 0;

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            int cnt = 4;

            if(i == 0 || i == n - 1) cnt--;
            if(j == 0 || j == m - 1) cnt--;

            cin >> a[i][j];
            if(a[i][j] > cnt) flag = 1;
            ans[i][j] = cnt;
        }
    }

    if(flag) cout << "NO" << endl;
    else{
        cout << "YES" << endl;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                cout << ans[i][j] << " ";
            }
            cout << endl;
        }
    }

    }

}