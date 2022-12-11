#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)4e5 + 100;
const int MOD = (int)1e9 + 7;

int A[2][N];
int P[2][N];
bool vis[N];

void solve(){
    int n;
    cin >> n;
    for(int i = 0 ;i < 2; i ++ ){
        for(int j = 1; j <= n ; j ++ ){
            cin >> A[i][j];
            P[i][A[i][j]] = j;
            vis[j]=false;
        }
    }
    ll res = 1ll;
    int go;
    int las;
    for(int i = 1; i <= n; i ++ ){
        if(vis[A[0][i]]) continue;
        res *= 2ll;
        res %= MOD;
        las = A[0][i];
        while(!vis[las]){
            vis[las] = true;
            las=A[0][P[1][las]];
        }
    }
    cout << res << "\n";
}

int main(){
    fastIO;
    int tc;
    cin >> tc;
    for(int iq = 1; iq <= tc; iq ++ ){
        solve();
    }
    return 0;
}