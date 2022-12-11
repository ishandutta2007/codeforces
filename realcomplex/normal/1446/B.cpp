#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 5005;
char s[N], t[N];
int dp[N][N];

int main(){
    fastIO;
    int n, m;
    cin >> n >> m;
    for(int i=  1; i <= n; i ++ ){
        cin >> s[i];
    }
    for(int i = 1; i <= m ; i ++ ){
        cin >> t[i];
    }
    int sol = 0;
    for(int i = 1; i <= n; i ++ ){
        for(int j = 1; j <= m ; j ++ ){
            dp[i][j] = max(0, dp[i-1][j-1]+4*(s[i]==t[j])-2);
            dp[i][j] = max(dp[i][j], dp[i-1][j]-1);
            dp[i][j] = max(dp[i][j], dp[i][j-1]-1);
            sol = max(sol, dp[i][j]);
        }
    }
    cout << sol << "\n";
    return 0;
}