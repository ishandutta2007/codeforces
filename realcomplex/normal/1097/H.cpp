#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);


int mod;
ll d;
vector<int> gg;

const int N = 62;
ll dp[N][N][2];
map<ll, vector<ll>> has;

void calc(ll mm){
    if(has.count(mm)) return;
    ll go = mm;
    vector<int> digs;
    while(go > 0){
        digs.push_back(go % d);
        go /= d;
    }
    reverse(digs.begin(), digs.end());
    int m = digs.size();
    for(int i = 0 ; i <= m ; i ++ ){
        for(int j = 0 ; j < mod; j ++ ){
            for(int t = 0; t < 2; t ++ ){
                dp[i][j][t] = 0;
            }
        }
    }
    dp[0][0][0]=1;
    for(int i = 0 ; i < m; i ++ ){ // index
        for(int j = 0 ; j < mod; j ++ ){ // sum
            for(int t = 0; t < 2; t ++ ){
                if(dp[i][j][t]==0) continue;
                for(int nx = 0 ;nx < d; nx ++ ){
                    if(t == 0 && nx > digs[i]) break;
                    dp[i+1][(j + gg[nx]) % mod][t | (nx < digs[i])] += dp[i][j][t];
                }
            }
        }
    }
    for(int i = 0 ; i < mod; i ++ ){
        has[mm].push_back(dp[m][i][0] + dp[m][i][1]);
    }
}

ll solve(vector<ll> x, ll lim){
    if(lim < 0 || x.empty()) return 0ll;
    if(x.size() == 1){
        if(x[0] == 0) return 0ll;
        calc(lim);
        ll ff = 0;
        for(int i = 0 ; i < mod; i ++ ){
            if((x[0] & (1ll << i))){
                ff += has[lim][i];
            }
        }
        return ff;
    }
    int n = x.size();
    ll nset;
    ll cur;
    int shf;
    ll answ = 0;
    for(int dn = 0; dn < d; dn ++ ){
        if(dn > lim) break;
        vector<ll> nex((n - 1 + dn) / d + 1, (1ll << mod) - 1);
        for(int i = 0 ; i < n; i ++ ){
            nset = x[i];
            shf = gg[(dn + i) % d];
            cur = (nset >> shf);
            nset &= (1ll << shf) - 1;
            cur |= (nset << (mod - shf));
            nex[(dn + i) / d] &= cur;
        }
        answ += solve(nex, (lim - dn) / d);
    }
    return answ;
}


int main(){
    fastIO;
    //freopen("in.txt", "r", stdin);
    cin >> d >> mod;
    gg.resize(d);
    for(int i = 0 ; i < d; i ++ ){
        cin >> gg[i];
    }
    int n;
    cin >> n;
    vector<ll> x(n);
    ll p;
    int xx;
    for(int i = 0 ; i < n; i ++ ){
        cin >> xx;
        x[i] = (1ll << (xx + 1)) - 1;
    }
    ll li;
    ll ri;
    cin >> li >> ri;
    li -- ;
    ri --;
    ri = (ri - n + 1);
    cout << solve(x, ri) - solve(x, li - 1) << "\n";
    return 0;
}