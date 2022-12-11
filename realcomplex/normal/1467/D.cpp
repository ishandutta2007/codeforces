#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 5005;
const int MOD = (int)1e9 + 7;
int dp[N][N];
int mlt[N];

void add(int &a, int b){
    a = (a + b) % MOD;
    if(a < 0) a += MOD;
}

int A[N];

int main(){
    fastIO;
    int n, k, q;
    cin >> n >> k >> q;
    for(int i = 1; i <= n; i ++ ){
        dp[i][0]=1;
    }
    for(int i = 1; i <= k; i ++ ){
        for(int j = 1; j <= n; j ++ ){
            add(dp[j][i],dp[j-1][i-1]);
            add(dp[j][i],dp[j+1][i-1]);
        }
    }
    for(int i = 0 ; i <= k ; i ++ ){
        for(int j = 1; j <= n; j ++ ){
            add(mlt[j],(dp[j][i]*1ll*dp[j][k-i])%MOD);
        }
    }
    int cur = 0;
    for(int i = 1 ; i <= n; i ++ ){
        cin >> A[i];
        add(cur, (A[i] * 1ll * mlt[i]) % MOD);
    }
    int id, nx;
    for(int i = 1; i <= q; i ++ ){
        cin >> id >> nx;
        add(cur, -(A[id] * 1ll * mlt[id])%MOD);
        A[id]=nx;
        add(cur, (A[id] * 1ll * mlt[id])%MOD);
        cout << cur << "\n";
    }
    return 0;
}