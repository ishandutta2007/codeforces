#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
     
using namespace std;
     
typedef long long ll;
typedef pair<int, int> pii;
     
#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
     
mt19937 rnd(chrono::steady_clock().now().time_since_epoch().count());

const int N = (int)2e5 + 9;
const ll inf = (ll)1e18;

ll dp[N][10];
int upd;

void update(vector<ll> cd){
    if(cd.empty())
        return;
    ll sum;
    int pp;
    do{
        for(int v = 0 ; v < 10; v ++ ){
            sum = dp[upd - 1][v];
            pp = v;
            for(auto p : cd){
                pp ++ ;
                if(pp == 10) sum += 2ll * p;
                else sum += p;
                pp %= 10;
            }
            dp[upd][pp] = max(dp[upd][pp], sum);
        }
    }while(next_permutation(cd.begin(), cd.end()));
    
}

int main(){
    fastIO;
    for(int i = 0 ; i < N; i ++ ) for(int j = 0 ; j < 10 ; j ++ )
        dp[i][j] = -inf;
    dp[0][0] = 0;
    int n;
    cin >> n;
    int k;
    vector<ll> t[4];
    ll c, d;
    upd = 1;
    for(int i = 0 ; i < n; i ++ ){
        cin >> k;
        for(int e = 0;e < 10; e ++ )
            dp[upd][e] = dp[upd-1][e];
        for(int j = 0 ; j < 4; j ++ )
            t[j].clear();
        for(int j = 1; j <= k ; j ++ ){
            cin >> c >> d;
            t[c].push_back(d);
        }
        for(int j = 1; j <= 3 ;j ++ ){
            sort(t[j].begin(), t[j].end());
            reverse(t[j].begin(), t[j].end());
        }
        for(int p = 0; p <= 3; p ++ ){
            for(int z = 0; z <= 1; z ++ ){
                for(int w = 0 ;w <=1 ;w ++ ){
                    if(p + z * 2 + w * 3 <= 3){
                        vector<ll> tri;
                        for(int j = 0 ; j < min(p, (int)t[1].size());j ++ ){
                            tri.push_back(t[1][j]);
                        }
                        for(int j = 0 ; j < min(z, (int)t[2].size()); j++){
                            tri.push_back(t[2][j]);
                        }
                        for(int j = 0 ; j < min(w, (int)t[3].size()); j ++ ){
                            tri.push_back(t[3][j]);
                        }
                        sort(tri.begin(), tri.end());
                        update(tri);
                    }
                }
            }
        }
        
        upd ++ ;
    }
    ll res = -inf;
    for(int i = 0; i < 10 ; i ++ ){
        res = max(res, dp[upd - 1][i]);
    }
    cout << res << "\n";
    return 0;
}