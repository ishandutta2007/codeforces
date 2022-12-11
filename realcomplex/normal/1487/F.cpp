#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int N = 52;
const int M = 5 * N + 2;
const int C = 30;
const int INF = (int)1e9;
int dp[2][M][M][C * 2]; // [len][+minus][-minus]

int main(){
    string t;
    cin >> t;
    reverse(t.begin(), t.end());
    t.push_back('0');
    int n = t.size();
    vector<int> digs(n);
    for(int i = 0 ; i < n; i ++ ){
        digs[i]=t[i]-'0';
    }
    for(int p = 0 ; p < 1; p ++ ){
        for(int i = 0 ; i < M; i ++ ){
            for(int j = 0; j < M; j ++) {
                for(int q = 0; q < C * 2; q ++ ){
                    dp[p][i][j][q] = INF;
                }
            }
        }
    }
    int md;
    int bit = 0;
    int rem;
    for(int p = 0 ; p < M-1; p ++ ){
        for(int q = 0 ; q < M-1; q ++ ){
            md = ((p - q) % 10 + 10) % 10;
            if(md == digs[0]){
                rem = (p - q) / 10;
                if((p - q) % 10 != 0 && p - q < 0) rem -- ;
                dp[0][p][q][rem + C] = p + q;
                dp[0][p][q][rem + C] = min({dp[0][p][q][rem + C], dp[0][p+1][q][rem + C],dp[0][p][q+1][rem + C]});
            }
        }
    }
    for(int p = M - 2; p >= 0 ; p -- ){
        for(int q = M - 2; q >= 0 ; q -- ){
            for(int las = 0; las < C * 2; las ++ ){
                dp[0][p][q][las] = min({dp[0][p][q][las], dp[0][p+1][q][las], dp[0][p][q+1][las]});
            }
        }
    }
    int rcr;
    for(int i = 1; i < n; i ++ ){
        bit ^= 1;
        for(int p = 0 ;p < M ;p ++ ){
            for(int q = 0; q < M; q ++ ){
                for(int pv = 0; pv < C * 2; pv ++ ){
                    dp[bit][p][q][pv] = INF;
                }
            }
        }
        for(int p = 0 ; p < M ; p ++ ){
            for(int q = 0; q < M ; q ++ ){
                for(int pv = 0; pv < C * 2; pv ++ ){
                    rcr = pv - C;
                    if(((p - q + rcr) % 10 + 10) % 10 == digs[i]){
                        rem = (p - q + rcr) / 10;
                        if((p - q + rcr) % 10 != 0 && (p - q + rcr) < 0) rem --;
                        dp[bit][p][q][rem + C] = min(dp[bit][p][q][rem + C],dp[(bit^1)][p][q][pv] + p + q);
                    }
                }
            }
        }
        for(int p = M - 2; p >= 0 ; p -- ){
            for(int q = M - 2 ; q >= 0 ; q -- ){
                for(int las = 0; las < C * 2; las ++ ){
                    dp[bit][p][q][las] = min({dp[bit][p][q][las], dp[bit][p+1][q][las], dp[bit][p][q+1][las]});
                }
            }
        }
    }
    int sol = INF;
    for(int p = 0; p < M ; p ++ ){
        for(int q = 0; q < M; q ++ ){
            sol = min(sol, dp[bit][p][q][C]);
        }
    }
    cout << sol << "\n";
    return 0;
}