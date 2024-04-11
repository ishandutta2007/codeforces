#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e6 + 10;


int main(){
    fastIO;
    int n, m;
    cin >> n >> m;
    if(n == 1){
        cout << 0 << "\n";
    }
    else if(n == 2){
        vector<int> q(m);
        char f;
        for(int i = 0 ; i < 2; i ++ ){
            for(int j = 0 ; j < m ; j ++ ){
                cin >> f;
                q[j] ^= (f - '0');
            }
        }
        int ans = m;
        for(int f = 0; f < 2; f ++ ){
            int cnt = 0;
            for(int j = 0 ; j < m ; j ++ ){
                cnt += ((j&1)==f)^q[j];
            }
            ans = min(ans, cnt);
        }
        cout << ans << "\n";
    }
    else if(n == 3){
        vector<int> las_dp(8), nw_dp(8);
        vector<vector<int>> pq;
        pq.resize(n);
        char ff;
        for(int i = 0 ; i < n; i ++ ){
            pq[i].resize(m);
            for(int j = 0 ; j < m ; j ++ ){
                cin >> ff;
                pq[i][j] = ff-'0';
            }
        }
        int msk;
        int a, b, c, d, e, f;
        for(int i = 0 ; i < m; i ++ ){
            for(int k = 0 ; k < 8 ; k ++ ){
                nw_dp[k] = (int)1e9;
            }
            msk = 0;
            for(int j = 0 ; j < n; j ++ ){
                msk |= (pq[j][i] * (1 << j));
            }
            for(int las = 0 ; las < 8; las ++ ){
                if(las_dp[las] == (int)1e9) continue;
                for(int nx = 0; nx < 8 ; nx ++ ){
                    a = (las & 1) > 0;
                    b = (nx & 1) > 0;
                    c = (las & 2) > 0;
                    d = (nx & 2) > 0;
                    e = (las & 4) > 0;
                    f = (nx & 4) > 0;
                    if((a ^ b ^ c ^ d) != 1 || (c ^ d ^ e ^ f) != 1) continue;
                    nw_dp[nx] = min(nw_dp[nx], __builtin_popcount(nx ^ msk) + las_dp[las]);
                }
            }
            for(int k = 0 ; k < 8 ; k ++ )
                las_dp[k] = nw_dp[k];
        }
        int ans = (int)1e9;
        for(int k = 0 ; k < 8 ; k ++ ){
            ans = min(ans, las_dp[k]);
        }
        cout << ans << "\n";
    }
    else{
        cout << "-1\n";
        return 0;
    }
    return 0;
}