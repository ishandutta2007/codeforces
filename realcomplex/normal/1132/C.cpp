#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 5005;
int dp[N][N];
int mx[N];

void upd(int &a, int b){
    a = max(a, b);
}

int main(){
    fastIO;
    int n, q;
    cin >> n >> q;
    int li, ri;
    for(int i = 0 ;i < q; i ++ ){
        cin >> li >> ri;
        mx[li] = max(mx[li], ri);
    }
    for(int i = 1; i <= n; i ++ )
        mx[i] = max(mx[i - 1], mx[i]);
    for(int i = 1; i <= n; i ++ ){
        for(int j = 0 ; j <= q-2; j ++ ){
            upd(dp[i][j], dp[i-1][j]);
            if(j > 0){
                if(mx[i] == 0)
                    continue;
                upd(dp[mx[i]][j],  dp[i-1][j-1] + (mx[i] - i  + 1));
            }
        }
    }
    int answ = 0;
    for(int i = 0 ; i <= q - 2; i ++ )
        answ = max(answ, dp[n][i]);
    cout << answ;
    return 0;
}