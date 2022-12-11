#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 30100;
const int LOG = 15;
const int C = 5;

const ll MAX = (ll)2e18 ;

vector<int> E[N][C];
ll W[N][C];
int P[N];

ll add(ll a, ll b){
    return min(a + b, MAX);
}


ll pf[C][N];
ll cmp[C][N][LOG];

void solve(){
    int n, c, q;
    cin >> n >> c >> q;
    for(int i = 1; i <= n + 1; i ++ ){
        for(int j = 0 ; j <= c; j ++ ){
            E[i][j].clear();
            W[i][j]=0;
            pf[j][i] = 0ll;
            cmp[j][i][0] = 0ll;
        }
    }
    for(int i = 1; i <= n; i ++ ){
        cin >> P[i];
    }
    for(int i = 0; i <= c; i ++ ){
        W[n + 1][i] = 1;
    }
    for(int i = n; i >= 1; i -- ){
        vector<pii> ord;
        for(int j = 0 ; j <= c; j ++ ){
            if(i + j <= n){
                ord.push_back(mp(P[i + j], j));
            }
        }
        sort(ord.begin(), ord.end());
        for(auto x : ord){
            for(int j = 0 ; j <= c; j ++ ){
                if(j + x.se > c) continue;
                E[i][j].push_back(x.se);
                W[i][j] = add(W[i][j], W[i + x.se + 1][j + x.se]);
            }
        }
    }
    ll w;
    for(int v = 0; v <= c; v ++ ){
        for(int i = 1; i <= n; i ++ ){
            pf[v][i] = pf[v][i - 1];
            w = 0;
            for(auto x : E[i][v]){
                if(x == 0) {
                    w = W[i + 1][v];
                    break;
                }
                pf[v][i] = add(pf[v][i], W[i + x + 1][v + x]);
            }
            cmp[v][i][0] = add(pf[v][i], w);
        }
    }
    for(int lg = 1; lg < LOG; lg ++ ){
        for(int v = 0; v <= c; v ++ ){
            for(int i = 1; i <= n; i ++ ){
                if((i + (1 << lg) - 1) > n) continue;
                cmp[v][i][lg] = min(cmp[v][i][lg-1], cmp[v][i+(1<<(lg-1))][lg - 1]);
            }
        }
    }
    int pi;
    ll qi;
    int ci, cj;
    int ai, aj;
    int sol;
    int nx;
    int tat;
    for(int iq = 1; iq <= q; iq ++ ){
        cin >> pi >> qi;
        if(W[1][0] < qi) {
            cout << "-1\n";
            continue;
        }
        sol = -1;
        ci = 1;
        cj = 0;
        while(ci <= n){
            if(pf[cj][ci] - pf[cj][ci - 1] < qi && cmp[cj][ci][0] >= qi + pf[cj][ci-1]){
                nx = ci;
                for(int j = LOG - 1; j >= 0 ; j -- ){
                    tat = (nx + (1 << j));
                    if(tat > n + 1) continue;
                    if(pf[cj][tat - 1] - pf[cj][ci - 1] < qi && cmp[cj][nx][j] >= qi + pf[cj][ci-1]){
                        nx = tat;
                    }
                }
                qi -= pf[cj][nx-1]-pf[cj][ci-1];
                if(ci <= pi && pi < nx){
                    sol = P[pi];
                }
                ci = nx;
            }
            else{
                for(auto x : E[ci][cj]){
                    if(W[ci + x + 1][cj + x] < qi){
                        qi -= W[ci + x + 1][cj + x];
                    }
                    else{
                        ai = ci + x + 1;
                        aj = cj + x;
                        if(ci <= pi && pi < ai){
                            sol = P[ci + x - (pi - ci)];
                        }
                        ci = ai;
                        cj = aj;
                        break;
                    }
                }
            }
        }
        cout << sol << "\n";
    }
}

int main(){
    fastIO;
    int tc;
    cin >> tc;
    for(int it = 1; it <= tc; it ++ )
        solve();
    return 0;
}