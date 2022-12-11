#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main(){
    fastIO;
    int tc;
    cin >> tc;
    int dp[2][2], nw[2][2];
    for(int id = 0; id < tc; id ++ ){
        int n;
        cin >> n;
        string t;
        cin >> t;
        vector<int> bit;
        for(int i = 0; i < t.size(); i ++ ){
            if(t[i] == 'L')
                bit.push_back(0);
            else
                bit.push_back(1);
        }
        int ans = n;
        for(int e = 0; e < 2; e ++ ){
            for(int f = 0; f < 2; f ++ ){
                dp[0][0]=dp[1][1]=dp[0][1]=dp[1][0]=(int)1e9;
                dp[e][f]=(bit[0]!=e)+(bit[1]!=f);
                for(int i = 2; i < n; i ++ ){
                    nw[0][0]=nw[1][1]=nw[0][1]=nw[1][0]=(int)1e9;
                    for(int p = 0 ;p < 2; p ++ ){
                        for(int q = 0; q < 2; q ++ ){
                            for(int nx = 0; nx < 2; nx ++ ){
                                if(p == q && q == nx) continue;
                                nw[q][nx] = min(nw[q][nx], dp[p][q] + (bit[i] != nx));
                            }
                        }
                    }
                    for(int p = 0; p < 2; p ++ ){
                        for(int q =0 ; q < 2; q ++ ){
                            dp[p][q]=nw[p][q];
                        }
                    }
                }
                for(int p = 0; p < 2; p ++ ){
                    for(int q = 0; q < 2; q ++ ){
                        if(p == q && q == e) continue;
                        if(q == e && e == f) continue;
                        ans = min(ans, dp[p][q]);
                    }
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}