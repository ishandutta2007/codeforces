#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 505;
const int inf = (int)1e9;
int dp[N][N][N];

int A[N];

int soln = 0;
void maxi(int &A, int B){
    A = max(A, B);
    soln = max(soln, B);
}

int n;


int main(){
    fastIO;
    //freopen("in.txt", "r", stdin);
    cin >> n;
    for(int i = 1; i <= n; i ++ ){
        cin >> A[i];
    }
    for(int i = 0 ; i <= n; i ++ ){
        for(int j = 0 ; j <= n; j ++ ){
            for(int k = 0 ; k <= n; k ++ )
                dp[i][j][k] = -inf;
        }
    }
    dp[0][0][0] = 0;
    int high;
    int use;
    int ggo = 0;
    for(int i = 0 ; i < n; i ++ ){
        for(int j = 0 ; j <= i + 1; j ++ ){
            high = -inf;
            for(int k = 0 ; k <= n; k ++ ){
                if(dp[i][j][k] >= 0){
                    maxi(dp[i + 1][j][k], dp[i][j][k] + A[k]);
                }
                if(k > i && high >= 0){
                    use = k - i - 2;
                    if(j >= use){
                        maxi(dp[i + 1][j - use][k], high + A[k]);
                    }
                }
                high = max(high, dp[i][j][k]);
            }
        }
    }
    cout << soln << "\n";
    return 0;
}