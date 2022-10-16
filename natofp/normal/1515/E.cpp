#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define st first
#define nd second
#define pii pair<int,int>
#define mp make_pair
#define pll pair<long long,long long>

using namespace std;

int n;
int mod;

const int nax = 405;

int dp[nax][nax];


ll binom[nax][nax];
void prep(){
    binom[0][0] = 1;
    for(int i=1;i<nax;i++){
        binom[i][0] = 1;
        for(int j=1;j<nax;j++){
            binom[i][j] = binom[i - 1][j] + binom[i - 1][j - 1];
            if(binom[i][j] >= mod) binom[i][j] -= mod;
        }
    }
}

ll pom[nax];

void solve(){
    cin >> n >> mod;
    prep();
    // dp[i][j] na prefiksie i j segmentow :)
    // i w i sie jakis konczy

    for(int i=1;i<nax;i++){
        pom[i] = 0;
        for(int j=1;j<=i;j++){
            pom[i] += binom[i - 1][j - 1];
            pom[i] %= mod;
        }
    }

    for(int i=1;i<=n;i++){
        dp[i][1] = pom[i];
    }
    for(int seg=2;seg<=n;seg++){
        for(int i=1;i<=n;i++){
            for(int j=i;j>=3;j--){
                ll pop = dp[j - 2][seg - 1];
                //cout<<"A"<<endl;
                ll ruchy = j - 2 - (seg - 2);
                if(ruchy < 0) continue;
                //cout<<"B"<<endl;
                ll teraz = (i - j + 1);
                ll opt = binom[ruchy + teraz][teraz] * pom[teraz];
                opt %= mod;
                opt *= pop;
                opt %= mod;
                dp[i][seg] += opt;
                dp[i][seg] %= mod;
            }
        }
    }
    ll ans = 0;
    for(int i=1;i<nax;i++){
        ans += dp[n][i];
        ans %= mod;
    }
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tt = 1;
    // cin >> tt;
    while(tt--) solve();

    return 0;
}