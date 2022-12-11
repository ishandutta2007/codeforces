#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 10010;
ll dp[2][N][3];
char a[N];
char b[N];
int flip[N];

void mini(ll &x, ll y){
    x=min(x,y);
}

void solve(){
    int n;
    ll x, y;
    cin >> n >> x >> y;
    for(int i = 0 ; i < 2; i ++ ){
        for(int j = 0 ; j <= 2 * n; j ++ ){
            for(int p = 0 ; p < 3; p ++ ){
                dp[i][j][p] = (ll)1e18;
            }
        }
    }
    dp[0][0][0] = 0;
    for(int i = 1; i <= n; i ++ ){
        cin >> a[i];
    }
    for(int i = 1; i <= n; i ++ ){
        cin >> b[i];
    }
    flip[0] = 0;
    for(int i = 1; i <= n; i ++ ){
        flip[i] = (a[i] != b[i]);
    }
    ll pv;
    int bit = 0;
    for(int i = 1; i <= n; i ++) {
        bit ^= 1;
        for(int v = 0; v <= 2 * n; v ++ ){
            for(int w = 0; w < 3; w ++ ){
                dp[bit][v][w] = (ll)1e18;
            }
        }
        for(int j = 0 ; j <= 2 * i; j ++ ){
            for(int las = 0 ; las < 3; las ++ ){
                if(dp[(bit^1)][j][las] != (ll)1e18){
                    pv = dp[(bit^1)][j][las];
                    for(int cur = flip[i]; cur < 3; cur += 2 ){
                        mini(dp[bit][j + cur][cur], pv);
                        if(cur >= 1) {
                            if(las > 0)mini(dp[bit][j + cur - 2][cur - 1], pv + x);
                            if(j - las > 0) mini(dp[bit][j + cur - 2][cur - 1], pv + y);
                        }
                        if(cur >= 2){
                            if(las > 1) mini(dp[bit][j + cur - 4][cur - 2], pv + 2ll * x);
                            if(j - las > 1) mini(dp[bit][j + cur - 4][cur - 2], pv + 2ll * y);
                            if(las > 0 && j - las > 0) mini(dp[bit][j + cur - 4][cur - 2], pv + x + y);
                        }
                    }
                }
            }
        }
    }
    if(dp[bit][0][0] == (ll)1e18){
        cout << "-1\n";
        return;
    }
    cout << dp[bit][0][0] << "\n";
}

int main(){
    fastIO;
    //freopen("in.txt", "r", stdin);
    int tc;
    cin >> tc;
    for(int iq = 1; iq <= tc; iq ++ ){
        solve();
    }
    return 0;
}