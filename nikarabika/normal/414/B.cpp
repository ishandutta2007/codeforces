#include <bits/stdc++.h>

using namespace std;

#define rep(i, t) for(ll (i) = 0; (i) < (ll)(t); (i)++)
#define reu(i, s, e) for(ll (i) = (ll)(s); (i) <= (ll)(e); (i)++)
#define rer(i, s, e) for(ll (i) = (ll)(s); (i) < (ll)(e); (i)++)
#define For(i, v) for(__typeof((v).begin()) (i) = (v).begin(); (i) != (v).end(); (i) ++)
#define mset(arr, val) memset(arr, (val), sizeof arr)
#define PB push_back
#define MP make_pair
#define p1 first
#define p2 second

typedef long long int ll;
typedef pair<int, int> pie;

const ll D = 1e9 + 7;
ll ans = 0;
const int maxn = 2e3 + 100;
ll c[maxn][maxn];

void C(int i, int j){
    if(i == 0 or j == 0){
        c[i][j] = 1;
        return;
    }
    if(c[i][j - 1] == -1)
        C(i, j - 1);
    if(c[i - 1][j] == -1)
        C(i - 1, j);
    c[i][j] = (c[i][j - 1] + c[i - 1][j]) % D;
    c[j][i] = (c[i][j - 1] + c[i - 1][j]) % D;
}

int main(){
    ios_base::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    rep(i, maxn)
        rep(j, maxn)
            c[i][j] = -1;
    reu(i, 1, n){
        ll result = 1;
        int num = i, div = 2;
        while(num > 1){
            int x = 0;
            while(num % div == 0){
                num /= div;
                x ++;
            }
            if(c[k - 1][x] == -1)
                C(k - 1, x);
            //cerr << k - 1 << ' ' << x << ' ' << c[k - 1][x] << endl;
            result *= c[k - 1][x];
            result %= D;
            div ++;
        }
        ans = (ans + result) % D;
    }
    cout << ans << endl;
    return 0;
}