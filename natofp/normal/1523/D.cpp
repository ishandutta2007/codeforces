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

const int nax = 2e5 + 5;
std::default_random_engine generator;
std::uniform_int_distribution<int> distribution(1, 1000000);

int n,m,p;

int dawaj(){
    int dice_roll = distribution(generator);  // generates number in the range 1..6\r
    return dice_roll % n + 1;
}

ll a[nax];

ll best = 0;

int war[nax];

int d[1 << 15];
int cc[1 << 15];

void go(){
    fill(war, war + nax, -1);
    fill(cc, cc + (1 << 15), 0);
    fill(d, d + (1 << 15), 0);
    int kto = dawaj();
    ll mask = a[kto];
    int done = -1;
    vector<ll> values;
    for(int i=0;i<62;i++){
        if((1LL << i) & mask){
            done++;
            war[i] = done;
            values.pb(1LL<<i);
        }
    }
    for(int i=1;i<=n;i++){
        ll xd = 0;
        ll moje = (a[i] & mask);
        for(int j=0;j<62;j++){
            if((1LL<<j) & moje){
                xd += (1LL << war[j]);
            }
        }
        d[xd]++;
    }

    for(int j=0;j<(1<<15);j++){
        int s = j;
        int xd = d[j];
        while(s > 0){
            cc[s] += xd;
            s = (s - 1) & j;
        }
    }

    for(int j=0;j<(1<<15);j++){
        if(cc[j] >= (n+1)/2 && __builtin_popcount(j) > __builtin_popcount(best)){
            ll xd = 0;
            for(int i=0;i<15;i++){
                if(j & (1 <<i)) xd += values[i];
            }
            best = xd;
        }
    }
}

void solve(){
    cin >> n >> m >> p;
    for(int i=1;i<=n;i++){
        string s; cin >> s;
        reverse(s.begin(), s.end());
        ll cur = 0;
        ll w = 1;
        for(char x : s){
            cur += w * (x - '0');
            w *= 2;
        }
        a[i] = cur;
    }
    for(int j=1;j<=22;j++){
        go();
    }

    string ans = "";
    for(int k=0;k<m;k++){
        if(best & (1LL << k)) ans += "1";
        else ans += "0";
    }
    reverse(ans.begin(), ans.end());
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);



    int tt = 1;
    //cin >> tt;
    while(tt--) solve();

    return 0;
}