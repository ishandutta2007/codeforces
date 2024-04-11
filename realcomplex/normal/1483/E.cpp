#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair

const int N = 60;
ll dp[N][N];
ll local;
int asked_q = 0;

int get(ll m){
    cout << "? " << m << endl;
    string sol;
    cin >> sol;
    asked_q ++ ;
    if(sol[0] == 'L')
        return true;
    else
        return false;
}

void solve(){
    ll m = 1;
    ll cur = 1ll;
    while(1){
        if(m > (ll)1e14) break;
        if(get(m)) {
            cur+=m;
            m *= 2ll;
        }
        else{
            cur=0;
            break;
        }
    }
    ll lef = m/2;
    ll rig = min((ll)1e14, m - 1);
    int iq = 55;
    int cuts = (lef >= cur);
    ll use;
    ll nex;
    while(lef + 1 < rig){
        while(dp[iq-1][cuts] >= rig - lef + 1) iq -- ;
        if(cuts == 0){
            cur += lef;
            get(lef);
            iq -- ;
            cuts ++ ;
            continue;
        }
        nex = lef + dp[iq - 1][cuts - 1];
        while(cur < nex){
            get(lef);
            cur += lef;
        }
        if(get(nex)){
            lef = nex;
            cur += nex;
            cuts ++ ;
            iq -- ;
        }
        else{
            rig = nex - 1;
            cur -= nex;
            cuts -- ;
            iq -- ;
        }
    }
    if(lef < rig){
        while(cur < rig){
            get(lef);
            cur += lef;
        }
        if(get(rig)) lef = rig;
    }
    cout << "! " << lef << endl;
}

int main(){
    for(int i = 0 ; i < N ; i ++ ){
        for(int j = 0 ; j < N; j ++ ){
            if(i == 0){
                dp[i][j] = 1;
            }
            else{
                if(j > 0) dp[i][j] += dp[i-1][j-1];
                if(j + 1 < N) dp[i][j] += dp[i-1][j+1];
            }
        }
    }
    int tc;
    cin >> tc;
    for(int iq = 1; iq <= tc; iq ++ ){
        solve();
    }
    return 0;
}