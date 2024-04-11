#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;

const ll big = 1000000007;

ll n,m,k,T;

ll FAC[1001] = {0};
ll INV[1001] = {0};

vector<ll> H;

ll DP[1001] = {0};
bool DPC[1001] = {0};

ll upp(ll i, ll j){
    if(j == 0)return 1;
    ll h = upp(i,j/2);
    if(j%2 == 0)return (h*h)%big;
    return (i*((h*h)%big))%big;
}

ll bin(ll i, ll j){
    if(i < j || i < 0 || j < 0)return 0;
    return (FAC[i]*((INV[i-j]*INV[j])%big))%big;
}

ll dp(ll i){
    if(i == 0)return 1;
    if(DPC[i])return DP[i];
    ll ans = 0;
    for(ll c1 = 1; c1 <= i; c1++){
        ans += bin(i-1,c1-1)*dp(i-c1);
        ans %= big;
    }
    DP[i] = ans;
    DPC[i] = 1;
    return ans;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d;

    ll t = 1;
    for(ll c1 = 0; c1 < 1001; c1++){
        FAC[c1] = t;
        INV[c1] = upp(t,big-2);
        t *= c1+1;
        t %= big;
    }

    cin >> m >> n;
    for(ll c1 = 0; c1 < m; c1++){
        H.push_back(0);
    }
    string s;
    t = 1;
    for(ll c1 = 0; c1 < n; c1++){
        cin >> s;
        for(ll c2 = 0; c2 < m; c2++){
            if(s[c2] == '1'){
                H[c2] += t;
            }
        }
        t *= 2;
    }
    sort(all(H));
    ll prev = H[0];

    ll now = 0;
    ll ans = 1;
    for(ll c1 = 0; c1 < m; c1++){
        if(H[c1] != prev){
            ans *= dp(now);
            ans %= big;
            now = 1;
        }
        else{
            now++;
        }
        prev = H[c1];
    }
    ans *= dp(now);
    ans %= big;
    cout << ans << "\n";
    return 0;
}