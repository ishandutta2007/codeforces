#include <bits/stdc++.h>
#include <random>
#define ll long long int
#define pb push_back
#define st first
#define nd second
#define pii pair<int,int>
#define mp make_pair
#define pll pair<long long,long long>
#define ld long double
#define ull unsigned long long

using namespace std;

const ll inf = 1e18;
const int nax = 1e6 + 5;
int k;
ll f[7];
ll dp[2][nax];

const int nax2 = 300001;

deque<pair<int, ll>> maxi[nax2];

void solve(){
    cin >> k;
    for(int i=0;i<6;i++) cin >> f[i];
    for(int j=0;j<nax;j++) dp[0][j] = -inf;
    for(int i=0;i<=(k-1)*3;i++){
        int w = i * 3;
        if(w < nax){
            dp[0][w] = f[0] * i;
        }
    }

    ll start = 1e6;
    for(int lay=1;lay<6;lay++){
        int mo = (lay & 1);
        for(int i=0;i<nax2;i++) maxi[i].clear();
        int unit = 3;
        for(int i=0;i<lay;i++) unit *= 10;
        for(int i=0;i<nax;i++){
            int id = i % unit;
            int pos = i / unit;
            while(maxi[id].size() && maxi[id].back().nd <= dp[1 - mo][i] + f[lay] * (start - pos)) maxi[id].pop_back();
            maxi[id].pb(mp(pos, dp[1 - mo][i] + f[lay] * (start - pos)));
            int canLookBack = (k - 1) * 3;
            while(maxi[id].front().st + canLookBack < pos) maxi[id].pop_front();
            ll value = maxi[id].front().nd;
            int posOpt = maxi[id].front().st;
            ll was = f[lay] * (start - posOpt);
            ll shouldBe = f[lay] * (pos - posOpt);
            value -= was;
            value += shouldBe;
            dp[mo][i] = value;
        }
    }

    for(int lay=0;lay<6;lay++){
        ll v = f[lay];
        int w = 1;
        for(int i=0;i<lay;i++) w *= 10;
        for(int i=nax-1;i>=0;i--){
            for(int d=0;d<=9;d++){
                if(i >= d * w) dp[1][i] = max(dp[1][i], dp[1][i - d * w]);
                if(d % 3 == 0 && i >= d * w){
                    dp[1][i] = max(dp[1][i], dp[1][i - d * w] + f[lay] * d / 3);
                }
            }
        }
    }
    int q; cin >> q;
    while(q--){
        int x; cin >> x;
        cout << dp[1][x] << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    // cin >> tt;
    while(tt--) solve();

    return 0;
}