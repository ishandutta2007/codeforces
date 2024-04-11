#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define hash dhsjakhd
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef long double ld;

ll n,m,T,k,q;
const ll big = 1000000007;

unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937 eng(seed);
uniform_int_distribution<> DD(0, 1000000000);

ll random(ll r){
    return (ll(DD(eng))*1000000000 + ll(DD(eng)))%r;
}

ll NDIG[100001] = {0};
ll START[100001] = {0};

pll nex(ll st, ll r){
    pll ans = {0,0};
    /*
    while(st > 220){
        st -= 55;
    }
    */
    st %= 11;
    for(int c1 = 0; c1 < st; c1++){
        ans.first += r;
        r++;
        r %= 11;
    }
    ans.second = r;
    return ans;
}

const ll MOD = 11;

ll NER[MOD][MOD] = {0};

ll ner(ll step, ll start){
    ll ans = 0;
    for(int c1 = 0; c1 < step; c1++){
        ans += (start-c1+MOD)%MOD;
    }
    NER[step][start] = ans;
    return ans;
}


ll nex2(ll k1, ll layer, ll cs, ll i){
   // ll i = s[i2]-'0';
    if(i >= k1)return -1;
    ll extra = i+1;
    ll kp = (k1 - (cs - NDIG[layer]) + 111111)%MOD;
    ll start = (k1+MOD-1)%MOD;
    ll steps = (k1-(cs-NDIG[layer]) + 111110)%MOD;

    ll k2 = extra + NER[steps][start];

  //  if(k1 == 5)cerr << start << " " << steps << "\n";

   // cerr << start << " " << steps << "   gfdg\n";
    k2 += cs;
    k2 %= MOD;
    return k2;
}

string s;

bool DPC[100001][11][11] = {0};
ll DP[100001][11][11]= {0};

ll dp(ll i, ll k_old, ll cs){

   // cerr << i << " " << k_old << "  " << cs << "\n";

    if(s[i]-'0' >= k_old)return 0;
    if(i == n)return 0;
    if(DPC[i][k_old][cs])return DP[i][k_old][cs];
    ll layer = 0;
    if(cs == 9)layer = 1;
    if(cs == 10)layer = 2;
    ll nexk = nex2(k_old, layer, cs, s[i]-'0');
    ll cs2 = 10;
    if(cs == 0 || cs == 10)cs2 = 9;

    ll ans = 1 + dp(i+1, nexk, cs2);
    DP[i][k_old][cs] = ans;
    DPC[i][k_old][cs] = 1;
    return ans;
}






int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d;

    for(int c1 = 0; c1 < MOD; c1++){
        for(int c2 = 0; c2 < MOD; c2++){
            NER[c1][c2] = ner(c1,c2);
        }
    }

    pll P = {9,1};
    ll cs = 0;
    for(int c1 = 1; c1 < 100001; c1++){
        NDIG[c1] = P.first;
        START[c1] = P.second;
      //  cerr << cs << " " << P.first << "\n";
        cs += P.first;
        cs %= 11;
        P = nex(P.first, P.second);
    }

    cin >> s;
/*
    string alfa = "0123456789";
    s = "";
    for(int c1 = 0; c1 < 100000; c1++){
        s += alfa[rand()%10];
       // s += '9';
    }
*/
    ll ans = 0;
    n = s.length();

    for(int c1 = 0; c1 < n; c1++){
        k = s[c1]-'0';
        if(k == 0)continue;
        ans += 1 + dp(c1+1,k,9);
    }

    cout << ans << "\n";

    return 0;
}