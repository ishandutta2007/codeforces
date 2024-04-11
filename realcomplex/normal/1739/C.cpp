#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 65;
const int MOD = 998244353;
int C[N][N];

void add(int &x, int y){
    x = (x + y) % MOD;
    if(x < 0) x += MOD;
}

void solve(){
    int n;
    cin >> n;
    int res1 = 0, res2 = 0;
    int par = 0;
    for(int i = n; i >= 1; i -= 2 ){
        if(par == 0){
            add(res1, C[i - 1][(i - 1) / 2]);
            add(res2, C[i - 2][i/2]);
        }
        else{
            add(res2, C[i - 1][(i - 1) / 2]);
            add(res1, C[i - 2][i/2]);
        }
        par ^= 1;
    }
    cout << res1 << " " << res2 << " " << 1 << "\n";
}



int main(){
    fastIO;
    //freopen("in.txt", "r", stdin);
    for(int i = 0; i < N; i ++ ){
        C[i][0]=1;
        for(int j = 1; j <= i ; j ++ ){
            add(C[i][j], C[i-1][j-1]);
            add(C[i][j], C[i-1][j]);
        }
    }
    int tc;
    cin >> tc;
    for(int iq = 1; iq <= tc; iq ++ ){
        solve();
    }
    return 0;
}