#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {

    ios_base::sync_with_stdio(false);cin.tie(false);
    int n;
    cin >> n;
    int sk[n+1][n+1];
    for(int j = 0;j<=n;j++){
        for(int x = 0;x<=n;x++){
            sk[j][x] = 0;
        }
    }
    sk[1][1] = 1;
    for(int j = 1;j<=n;j++){
        for(int x = 1;x<=n;x++){
            sk[j][x] += sk[j-1][x] + sk[j][x-1];
        }
    }
    cout << sk[n][n];
    return 0;
}