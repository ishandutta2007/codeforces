#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int MOD = (int)1e9 + 7;
const int N = (int)1e5 + 9;

int mult(int a, int b){ 
    return (a * 1ll * b) % MOD;
}

void add(int &a, int b){
    a = (a + b);
    if(a >= MOD)
        a -= MOD;
}

int powr(int a, int k){
    if(k==0)
        return 1;
    int f = powr(a,k/2);
    f = mult(f, f);
    if(k & 1)
        f = mult(f, a);
    return f;
}

int f[N];
int c[N];

int dp[N][2];

int g(int n){
    if(n % 2 == 0)
        return mult(n/2, n - 1);
    else
        return mult(n, (n-1)/2);
}

int main(){
    fastIO;
    int n, m;
    cin >> n >> m;
    int dv = 1;
    for(int i = 1; i <= n; i ++ ){
        cin >> f[i];
        if(f[i] == 0) dv = mult(dv, m);
    }
    for(int i = 1; i <= n; i ++ ){
        cin >> c[i];
        if(c[i] == 0) dv = mult(dv, m);
    }
    dv = powr(dv, MOD - 2);
    dp[0][0] = 1;
    dp[0][1] = 0;
    for(int i = 1; i <= n; i ++ ){
        if(f[i] == 0 && c[i] == 0){
            dp[i][0] = mult(dp[i - 1][0], m);
            dp[i][1] = mult(dp[i - 1][1], mult(m,m));
            add(dp[i][1], mult(dp[i-1][0], g(m)));
        }
        else if(f[i] == 0){
            dp[i][0] = dp[i - 1][0];
            dp[i][1] = mult(dp[i - 1][1], m);
            add(dp[i][1], mult(dp[i-1][0], m - c[i]));
        }
        else if(c[i] == 0){
            dp[i][0] = dp[i - 1][0];
            dp[i][1] = mult(dp[i - 1][1], m);
            add(dp[i][1], mult(dp[i - 1][0], f[i] - 1));
        }
        else{
            if(f[i] == c[i]){
                dp[i][0] = dp[i - 1][0];
                dp[i][1] = dp[i - 1][1];
            }
            else if(f[i] > c[i]){
                dp[i][0] = 0 ;
                dp[i][1] = dp[i-1][0];
                add(dp[i][1], dp[i-1][1]);
            }
            else{
                dp[i][0] = 0;
                dp[i][1] = dp[i - 1][1];
            }
        }
    }
    cout << mult(dp[n][1], dv);
    return 0;
}