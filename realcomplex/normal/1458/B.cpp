#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef long double ld;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 101;
const int M = N * N;
int dp[N][M];

int main(){
    for(int i = 0 ; i < N ; i ++) {
        for(int j = 0 ; j < M ; j ++ ){
            dp[i][j]=-1;
        }
    }
    dp[0][0]=0;
    int n;
    cin >> n;
    int a, b;
    int dif;
    int sum = 0;
    for(int i = 1; i <= n; i ++ ){
        cin >> b >> a;
        sum += a;
        dif = b - a;
        for(int j = i-1 ; j >= 0 ; j -- ) {
            for(int x = 0 ; x < M ; x ++ ){
                if(dp[j][x] == -1) continue;
                dp[j + 1][x + dif] = max(dp[j+1][x+dif],dp[j][x]+a);
            }
        }
    }
    ld s1, s2;
    ld soln = 0.0;
    for(int k = 1; k <= n ; k ++ ){
        soln = 0.0;
        for(int x = 0; x < M ; x ++ ){
            if(dp[k][x]==-1) continue;
            s1 = dp[k][x];
            s2 = min((ld)x,ld(sum-dp[k][x])/2.0);
            soln = max(soln,s1+s2);
        }
        cout << fixed << setprecision(10) << soln << " ";
    }
    cout << "\n";
    return 0;
}