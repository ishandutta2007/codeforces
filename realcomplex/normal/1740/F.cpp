#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2010;
const int MOD = 998244353;

void add(int &x, int y){
    x += y;
    if(x >= MOD) x -= MOD;
    else if(x < 0) x += MOD;
}

int cnt[N];
int has[N];

int dp[N][N];
int ndp[N][N];

int main(){
    fastIO;
    //freopen("in.txt", "r", stdin);
    int n;
    cin >> n;
    int x;
    for(int i = 1; i <= n; i ++ ){
        cin >> x;
        cnt[x] ++ ;
    }
    for(int i = 1; i <= n; i ++ ){
        has[cnt[i]] ++ ;
    }
    for(int i = n; i >= 1; i -- ){
        has[i] += has[i + 1];
    }
    for(int i = 2; i <= n; i ++ ){
        has[i] += has[i - 1];
    }
    dp[0][n] = 1;
    int pp;
    int total;
    for(int pos = 1; pos <= n; pos ++ ){
        if(pos == 1) pp = n;
        else pp = n/(pos-1);

        for(int h = 0; h <= n; h ++ ){
            total = 0;
            for(int ad = 0; ad <= pp; ad ++ ) add(total, dp[h][ad]);
            for(int nx = 0; nx <= n/pos && h + nx <= has[pos]; nx ++ ){
                add(ndp[h + nx][nx], total);
                add(total, -dp[h][nx]);
            }
        }
        for(int h = 0 ; h <= n; h ++ ){
            for(int las = 0; las <= pp; las ++ ){
                dp[h][las] = ndp[h][las];
                ndp[h][las] = 0;
            }
        }
    }
    int res = 0;
    add(res, dp[n][0]);
    add(res, dp[n][1]);
    cout << res << "\n";
    return 0;
}