#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define fi first
#define se second

const int MAXN = 505;
int dp[MAXN][MAXN];
int col[MAXN][MAXN];
int row[MAXN][MAXN];
char conf[MAXN][MAXN];

int main(){

    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m;
    cin >> n >> m;
    for(int j = 1;j<=n;j++){
        for(int x = 1;x<=m;x++){
            cin >> conf[j][x];
            row[j][x] = row[j][x-1];
            col[j][x] = col[j-1][x];
            dp[j][x] = dp[j-1][x]+dp[j][x-1]-dp[j-1][x-1];
            if(conf[j][x]=='#')continue;
            if(conf[j-1][x] == '.'){
                dp[j][x]++;
                row[j][x]++;
            }
            if(conf[j][x-1] == '.'){
                dp[j][x]++;
                col[j][x]++;
            }
        }
    }
    int f1,f2,f3,f4;
    int ans;
    int q;
    cin >> q;
    for(int j = 0;j<q;j++){
        cin >> f1 >> f2 >> f3 >> f4;
        ans = dp[f3][f4]-dp[f1-1][f4]-dp[f3][f2-1]+dp[f1-1][f2-1];
        ans -= col[f3][f2]-col[f1-1][f2];
        ans -= row[f1][f4]-row[f1][f2-1];
        cout << ans << "\n";
    }
    return 0;
}