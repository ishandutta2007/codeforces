#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long n, m, ans, cnt, skap;
    ans = 0;
    cin >> n >> m;

    int p1[m], p2[m];
    int inv[m][n + 1];

    int a[m][n + 1];
    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            cin >> a[i][j];
            inv[i][a[i][j] - 1] = j;
            if(a[i][j] == a[0][0]){
                p1[i] = j;
                p2[i] = j;
            }
        }
    }

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(p1[j] == -1){
                for(int k = 0; k<m; k++){
                        p2[k] = inv[k][a[0][i] - 1];
                    }
                break;
            }
        }

        for(int j = 0; j<m; j++){
            p1[j] = inv[j][a[0][i] - 1];
        }

        cnt = p2[0] - p1[0] + 1;

        while(1){
            skap = 0;
            for(int j = 0; j<m; j++){
                p2[j]++;
            }

            if(p2[0] == n){
                ans += cnt;
                for(int k = 0; k<m; k++){
                    p2[k]--;
                }
                break;
            }

            for(int j = 1; j<m; j++){
                if(p2[j] == n){
                    ans += cnt;
                    skap = 1;
                    for(int k = 0; k<m; k++){
                        p2[k]--;
                        if(cnt == 1) p1[k] = -1;
                    }
                    break;
                }

                if(a[j][p2[j]] != a[0][p2[0]]){
                    ans += cnt;
                    skap = 1;
                    for(int k = 0; k<m; k++){
                        p2[k]--;
                        if(cnt == 1) p1[k] = -1;
                    }
                    break;
                }
            }

            if(skap == 1) break;
            cnt++;
            
        }
    }

    cout << ans << endl;

    /*for(int i = 0; i<m; i++){
        cout << p1[i] << " ";
    }
    cout << endl;

    for(int i = 0; i<m; i++){
        cout << p2[i] << " ";
    }
    cout << endl;
    */





}