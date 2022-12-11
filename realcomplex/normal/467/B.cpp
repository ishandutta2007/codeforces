#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {

    ios_base::sync_with_stdio(false);cin.tie(false);
    int n,m,k;
    cin >> n >> m >> k;
    int t[m+1];
    for(int j = 0;j<=m;j++){
        cin >> t[j];
    }
    int friends = 0;
    for(int x = 0;x<m;x++){
        if(__builtin_popcount(t[m]^t[x]) <= k){
            friends++;
        }
    }
    cout << friends;
    return 0;
}