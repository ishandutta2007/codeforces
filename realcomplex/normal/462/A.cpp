#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {

    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n;
    cin >> n;
    int l[n+2][n+2];
    for(int i = 0;i<=n+1;i++){
        for(int j = 0;j<=n+1;j++){
            l[i][j] = 0;
        }
    }
    char s;
    for(int j = 1;j<=n;j++){
        for(int i = 1;i<=n;i++){
            cin >> s;
            if(s == 'o'){
                l[j][i]++;
            }
        }
    }
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            if((l[i][j-1]+l[i][j+1]+l[i-1][j]+l[i+1][j])%2==1){
                cout << "NO";
                exit(0);
            }
        }
    }
    cout << "YES";
    return 0;
}