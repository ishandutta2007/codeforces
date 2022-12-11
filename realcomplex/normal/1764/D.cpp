#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int mod;
const int N = 5050;
int C[N][N];

void add(int &x, int y){
    x += y;
    if(x >= mod) x -= mod;
}
int P[N];
int W[N];

void solve(){
    int n;
    cin >> n >> mod;
    if(n == 3){
        cout << 3 << "\n";
        return;
    }
    P[0]=1;
    for(int i = 0 ; i <= n; i ++ ){
        C[i][0] = 1;
        if(i) P[i] = (P[i-1] * 1ll * i) % mod;
    }
    for(int i = 1; i <= n; i ++ ){
        for(int k = 1; k <= i ; k ++ ){
            add(C[i][k], C[i - 1][k]);
            add(C[i][k], C[i - 1][k - 1]);
        }
    }
    int k = n / 2;
    int res = 0;
    for(int tot = k; tot <= n - 1; tot ++ ){
        if(tot + 1 == n){
            W[tot] = P[tot - 1];
        }
        else{
            for(int l = 0 ; l <= n - tot - 2; l ++ ){
                add(W[tot], (P[tot + l - 1] * 1ll * C[n - tot - 2][l]) % mod);
            }
        }
    }
    for(int i = 0 ; i <= k - 1; i ++ ){
        for(int j = 0 ; j <= k - 1 ; j ++ ){
            if(i + j + 1 >= k){
                //cout << i << " " << j << " " << W[i + j + 1] << "\n";
                add(res, W[i + j + 1]);
            }
        }
    }
    res = (res * 1ll * n) % mod;
    cout << res << "\n";
}

int main(){
    fastIO;
    //freopen("in.txt", "r", stdin);
    solve();
    return 0;
}