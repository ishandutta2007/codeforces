#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int MOD;

const int N = 401;
int dp[2][N][N][2][2][2];

void add(int &a, int b){
    a += b;
    a %= MOD;
}

int main(){
    fastIO;
    int n;
    cin >> n >> MOD;
    dp[1][1][1][0][1][0]=1;
    int total = 0;
    int cur = 1;
    // cur was just calculated
    for(int i = 1; i < n; i ++ ){
        for(int len = 1; len <= i ; len ++ ){
            for(int pos = 1; pos <= len; pos ++ ){
                for(int a = 0; a < 2; a ++ ){
                    for(int b =0 ; b < 2; b ++ ){
                        for(int y = 0;y < 2; y ++ ){
                            dp[(cur^1)][len][pos][a][b][y]=0;
                        }
                    }
                }
            }
        }
        for(int len = 1; len <= i ; len ++ ){
            for(int l0 = 0 ;l0 < 2; l0 ++ ){
                for(int l1 = 0; l1 < 2; l1 ++ ){
                    for(int l2 = 0; l2 < 2; l2 ++ ){
                        if(l0 == 0 && l1 == 0) continue;
                        if(l1 == 0 && l2 == 0) continue;

                        if(l2 == 0){

                            total = 0;
                            for(int las = 1; las <= len ; las ++ ){
                                for(int R = 0; R < 2; R ++ )
                                    add(total, dp[cur][len][las][l0][l1][R]);
                            }
                            add(dp[(cur^1)][len][1][l1][l2][0], total);

                        }
                        else if(l1 == 0){

                            for(int las = 1; las <= len + 1; las ++ ){
                                add(dp[(cur^1)][len+1][las][l1][l2][0], dp[cur][len][1][l0][l1][0]);
                            }

                        }
                        else if(l0 == 0){
                            total = 0;
                            for(int las = 1; las <= len + 1 ; las ++ ){

                                add(dp[(cur^1)][len+1][las][l1][l2][0], total);

                                add(total, dp[cur][len][las][l0][l1][0]);
                                add(total, dp[cur][len][las][l0][l1][1]);
                            }
                            total = 0;
                            for(int las = len + 1; las >= 1; las -- ){
                                add(total, dp[cur][len][las][l0][l1][1]);
                                add(total, dp[cur][len][las][l0][l1][0]);

                                add(dp[(cur^1)][len+1][las][l1][l2][1], total);
                            }
                        }
                        else{

                            total = 0;
                            for(int las = 1; las <= len + 1; las ++ ){
                                add(dp[(cur^1)][len+1][las][l1][l2][0], total);
                                for(int R = 0; R < 2; R ++ ){
                                    add(total, dp[cur][len][las][l0][l1][R]);
                                }
                            }
                            total = 0;
                            for(int las = len + 1; las >= 1; las -- ){
                                add(total, dp[cur][len][las][l0][l1][1]);

                                add(dp[(cur^1)][len+1][las][l1][l2][1], total);
                            }

                        }
                    }
                }
            }
        }
        cur ^= 1;
    }
    int outp = 0;
    for(int len = 1; len <= n; len ++ ){
        for(int pv = 0; pv < 2; pv ++ ){
            for(int las = 1; las <= n; las ++ ){
                for(int R = 0; R < 2; R ++ ){
                    add(outp, dp[cur][len][las][pv][1][R]);
                }
            }
        }
    }
    cout << outp << "\n";
    return 0;
}