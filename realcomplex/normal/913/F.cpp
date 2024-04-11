#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 2020;
const int MOD = 998244353;

int L[N][N];

int mult(int a, int b){
    return (a * 1ll * b) % MOD;
}

void add(int &a, int b){
    a += b;
    if(a < 0)
        a += MOD;
    if(a >= MOD)
        a -= MOD;
}

int powr(int a, int b){
    if(b == 0) return 1;
    int p = powr(a,b/2);
    p = mult(p,p);
    if(b % 2 == 1) p = mult(p,a);
    return p;
}

int inv(int x){
    return powr(x, MOD-2);
}

int st[N];
int dp[N];

int main(){
    fastIO;
    int n;
    int a, b;
    cin >> n >> a >> b;
    int p = mult(a,inv(b));
    int ri = (1 - p + MOD) % MOD;
    L[0][0]=1;
    for(int i = 0 ; i < n; i ++ ){
        for(int j = 0 ; j <= i ; j ++ ){
            add(L[i+1][j], mult(L[i][j], powr(ri, j)));
            add(L[i+1][j+1], mult(L[i][j], powr(p, i-j)));
        }
    }
    for(int i = 1; i <= n; i ++ ){
        st[i]=1;
        for(int j = 1; j < i; j ++ ){
            add(st[i], -mult(st[j],L[i][j]));
        }
    }
    int gm;
    int prob;
    for(int i = 2; i <= n; i ++ ){
        for(int j = 1; j < i ; j ++ ){
            gm = (dp[j] + dp[i-j]) % MOD;
            prob = (st[j] * 1ll * L[i][j]) % MOD;
            add(gm, j*(i-j) + j*(j-1)/2);
            add(dp[i],mult(gm, prob));
        }
        gm = ((i*(i-1)/2) * 1ll * st[i]) % MOD;
        add(dp[i], gm);
        dp[i]=mult(dp[i],inv((1-st[i]+MOD)%MOD));
    }
    cout << dp[n] << "\n";
    return 0;
}