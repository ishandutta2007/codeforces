#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 510;
ll C[N][N];

void solve(){
    int n;
    cin >> n;
    for(int i = 1; i <= 2 * n; i ++ ){
        for(int j = 1; j <= 2 * n; j ++ ){
            cin >> C[i][j];
        }
    }
    ll res = 0;
    for(int i = n + 1; i <= 2 * n; i ++ ){
        for(int j = n + 1; j <= 2 * n; j ++) {
            res += C[i][j];
        }
    }
    res += min({C[1][n+1], C[1][2*n], C[n][n+1], C[n][2*n], C[n+1][1], C[2*n][1], C[n+1][n], C[2 * n][n]});
    cout << res << "\n";
}

int main(){
    //fastIO;
    int tc;
    cin >> tc;
    for(int iq = 1; iq <= tc; iq ++ ){
        solve();
    }
    return 0;
}