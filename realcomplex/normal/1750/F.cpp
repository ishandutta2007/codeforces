#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first 
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 5010;
const int M = N * 2;
int bad[N][M];
int old[N][M];
int dp[N];
int mod;

void add(int &x, int y){
    x += y;
    if(x >= mod) x -= mod;
    else if(x < 0) x += mod;
}

int get_sum(int id, int l, int r){
    int res = bad[id][r];
    if(l > 0) add(res, -bad[id][l - 1]);
    return res;
}

int main(){
    fastIO;
    int n;
    cin >> n >> mod;
    int m = n;
    dp[1]=1;
    
    int p = 1;
    int nw;
    for(int i = 2; i <= n; i ++) {

        add(bad[i][n - i + 2], dp[i - 1]);
        for(int x = -i; x <= +i; x ++ ){
            add(bad[i][n + x], get_sum(i - 1, n + x - 1, n + x - 1));
        }
        for(int ones = 1; ones + 1 < i; ones ++ ){
            // for(int v = n + ones + 1; v <= n + i; v ++ ){
            //     add(bad[i][n - ones + 1], (get_sum(i - ones - 1, v, v) * 1ll * dp[ones]) % mod);
            // }
            nw = bad[i - ones - 1][n + i];
            add(nw, -bad[i - ones - 1][n + ones]);
            nw = (nw * 1ll * dp[ones]) % mod;
            add(bad[i][n - ones + 1], nw);
        }
        dp[i] = p;
        for(int las = 1; las < i ; las ++ ){
            // for(int k = n + las + 1; k <= n + i ; k ++ ){
            //     add(dp[i], -(get_sum(i - las, k, k) * 1ll * dp[las]) % mod);
            // }
            nw = bad[i - las][n + i];
            add(nw, -bad[i - las][n + las]);
            nw = (nw * 1ll * dp[las]) % mod;
            add(dp[i], -nw);
        }
        for(int iq = 1; iq <= 2 * n; iq ++ ){
            add(bad[i][iq], bad[i][iq - 1]);
        }
        p = (p * 2ll) % mod;
    }
    cout << dp[n] << "\n";
    return 0;
}