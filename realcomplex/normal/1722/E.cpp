#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1010;
ll dp[N][N];

ll rect(int i0, int j0, int i1, int j1){
    return dp[i1][j1] + dp[i0-1][j0-1] - dp[i0-1][j1] - dp[i1][j0-1];
}

int main(){
    int tc;
    cin >> tc;
    for(int iq = 1; iq <= tc; iq ++ ){
        int n, q;
        cin >> n >> q;
        int hi, wi;
        for(int i = 0 ; i < N ; i ++ ){
            for(int j = 0 ; j < N; j ++ ){
                dp[i][j] = 0;
            }
        }
        for(int i = 1; i <= n; i ++ ){
            cin >> hi >> wi;
            dp[hi][wi] += hi * 1ll * wi ;
        }
        for(int i = 1; i < N ; i ++ ){
            for(int j = 1; j < N ; j ++ ){
                dp[i][j] += dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
            }
        }
        int hs, ws, hb, wb;
        for(int i = 1; i <= q; i ++ ){
            cin >> hs >> ws >> hb >> wb;
            hb -- ;
            wb -- ;
            hs ++ ;
            ws ++ ;
            if(hs <= hb && ws <= wb){
                cout << rect(hs, ws, hb, wb) << "\n";
            }
            else{
                cout << "0\n";
            }
        }
    }
    return 0;
}