#include <bits/stdc++.h>

using namespace std;
int wall[202][202];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i=1;i<=n;i++){
            string s;
            cin >> s;
            for(int j=0;j<n;j++){
                if(s[j] == '1') wall[i][j+1] = 1;
                else wall[i][j+1] = 0;
            }
        }
        int ans = 0;

        if(wall[1][2] == 1) ans++;
        if(wall[2][1] == 1) ans++;
        if(wall[n-1][n] == 0) ans++;
        if(wall[n][n-1] == 0) ans++;

        if(ans > 2){
            cout << (4 - ans) << "\n";
            if(wall[1][2] == 0) cout << "1 2\n";
            if(wall[2][1] == 0) cout << "2 1\n";
            if(wall[n-1][n] == 1) cout << n-1 << " " << n << "\n";
            if(wall[n][n-1] == 1) cout << n << " " << n-1 << "\n";
        }
        else{
            cout << ans << "\n";
            if(wall[1][2] == 1) cout << "1 2\n";
            if(wall[2][1] == 1) cout << "2 1\n";
            if(wall[n-1][n] == 0) cout << n-1 << " " << n << "\n";
            if(wall[n][n-1] == 0) cout << n << " " << n-1 << "\n";
        }
    }
}