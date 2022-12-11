#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e5 + 10;
const int LOG = 19;
ll dp[LOG][N][2][2];

pii get_id(int i, int j){ // layer..node
    int layer = max(i, j);
    int id;
    if(i == layer){
        id = j;
    }
    else{
        id = layer + (layer - i);
    }
    return mp(layer, id);

}

pii p[N][2];

ll dif(ll x, ll y){
    return max(x-y, y-x);
}


ll get_dist(int layer, int pos0, int pos1){
    return min(dif(p[layer][pos0].se,p[layer][0].se) + dif(p[layer+1][pos1].se, p[layer][0].se) + 1, dif(p[layer][pos0].se,p[layer][1].se) + dif(p[layer+1][pos1].se, p[layer][1].se + 2) + 1);
}


int main(){
    fastIO;
    //freopen("in.txt","r",stdin);
    int n;
    cin >> n;
    pii lef, rig;
    int i1, j1;
    for(int i = 1; i <= n - 1; i ++ ){
        cin >> i1 >> j1;
        p[i][0] = get_id(i1, j1);
        cin >> i1 >> j1;
        p[i][1] = get_id(i1, j1);
    }
    for(int lg = 0; lg < LOG; lg ++ ){
        for(int i = 1; i <= n; i ++ ){
            for(int p = 0 ; p < 2; p ++ ){
                for(int q = 0; q < 2; q ++ ){
                    dp[lg][i][p][q] = (ll)1e18;
                }
            }
        }
    }
    for(int i = 1; i <= n - 1; i ++ ){
        for(int p = 0 ; p < 2; p ++ ){
            for(int q = 0; q < 2; q ++ ){
                dp[0][i][p][q] = get_dist(i, p, q);
            }
        }
    }
    for(int lg = 1; lg < LOG; lg ++ ){
        for(int i = 1; i <= n - 1; i ++ ){
            if(i + (1 << lg) <= n){
                for(int p = 0; p < 2; p ++ ){
                    for(int mid = 0; mid < 2; mid ++ ){
                        for(int q = 0; q < 2; q ++ ){
                            dp[lg][i][p][q] = min(dp[lg][i][p][q], dp[lg - 1][i][p][mid] + dp[lg - 1][i + (1 << (lg - 1))][mid][q]);
                        }
                    }
                }
            }
        }
    }
    int q;
    cin >> q;
    pii q0, q1;
    for(int iq = 1; iq <= q; iq ++ ){
        cin >> i1 >> j1;
        q0 = get_id(i1, j1);
        cin >> i1 >> j1;
        q1 = get_id(i1, j1);
        if(q0.fi > q1.fi) swap(q0, q1);
        if(q0.fi == q1.fi){
            cout << dif(q1.se, q0.se) << "\n";
        }
        else{
            ll cur_dp[2];
            cur_dp[0] = dif(q0.se, p[q0.fi][0].se);
            cur_dp[1] = dif(q0.se, p[q0.fi][1].se);
            for(int lg = LOG - 1; lg >= 0; lg -- ){

                if(q0.fi + (1 << lg) < q1.fi){
                    ll nw_dp[2];
                    nw_dp[0] = nw_dp[1] = (ll)1e18;
                    for(int p = 0 ; p < 2; p ++ ){
                        for(int q = 0; q < 2; q ++ ){
                            nw_dp[q] = min(nw_dp[q], cur_dp[p] + dp[lg][q0.fi][p][q]);
                        }
                    }
                    q0.fi += (1 << lg);
                    cur_dp[0] = nw_dp[0];
                    cur_dp[1] = nw_dp[1];
                }
            }
            cout << min(cur_dp[0]+dif(p[q0.fi][0].se, q1.se)+1, cur_dp[1]+dif(p[q0.fi][1].se+2, q1.se)+1) << "\n";
        }
    }
    return 0;
}