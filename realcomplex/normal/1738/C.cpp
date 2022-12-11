#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 105;
int dp[N][N][2];

int ca, cb;
int solve(int u, int v, int i){
    if(dp[u][v][i] != -1) return dp[u][v][i];
    if(u == ca && v == cb){
        if(i == 0) dp[u][v][i] = true;
        else dp[u][v][i] = false;
        return dp[u][v][i];
    }
    int go = (u + v) % 2;
    if(go == 0){
        int g1 = false;
        int g2 = false;
        if(u + 1 <= ca)
            g1 = solve(u + 1, v, i);
        if(v + 1 <= cb)
            g2 = solve(u, v + 1, (i ^ 1));
        if(g1 || g2) dp[u][v][i] = true;
        else dp[u][v][i] = false;
    }
    else{
        int g1 = true;
        int g2 = true;
        if(u + 1 <= ca)
            g1 = solve(u + 1, v, i);
        if(v + 1 <= cb)
            g2 = solve(u, v + 1, i);
        if(g1 && g2) dp[u][v][i] = true;
        else dp[u][v][i] = false;
    }
    return dp[u][v][i];
}

void solve(){
    int n;
    cin >> n;
    ca = 0, cb = 0;
    int x;
    for(int i = 0 ; i <= n + 1; i ++ ){
        for(int j = 0 ; j <= n + 1; j ++ ){
            for(int e = 0; e < 2; e ++ ){
                dp[i][j][e]=-1;
            }
        }
    }
    for(int i = 1; i <= n; i ++ ){
        cin >> x;
        if(x % 2 == 0){
            ca ++ ;
        }
        else{
            cb ++ ;
        }
    }
    int res = solve(0, 0, 0);
    if(res == true)
        cout << "Alice\n";
    else
        cout << "Bob\n";
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