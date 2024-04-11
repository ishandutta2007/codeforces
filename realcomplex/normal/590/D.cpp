#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 151;

int dp[N][N * N];

void upd(int &a, int b){
    a = min(a, b);
}

int main(){
    fastIO;
    for(int i = 0 ; i < N ; i ++ )for(int j = 0 ; j < N * N ; j ++ ) dp[i][j] = (int)2e9 + 9;
    int n, k, s;
    cin >> n >> k >> s;
    dp[0][0] = 0;
    int c;
    for(int i = 1; i <= n; i ++ ){
        cin >> c;
        for(int t = k; t >= 1;  t -- ){
            for(int l = i ;  l <= n * n; l ++ ){
                dp[t][l] = min(dp[t][l],dp[t - 1][l - i] + c);
            }
        }
    }
    int q = k * (k + 1) / 2;
    int answ = (int)2e9 + 9;
    for(int t = q; t <= n * n; t ++ ){
        if(t - q <= s){
            answ = min(answ, dp[k][t]);
        }
    }
    cout << answ;
    return 0;
}