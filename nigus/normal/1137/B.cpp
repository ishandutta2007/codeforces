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
const ll MAXN = 150000;

unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937 eng(seed);
uniform_int_distribution<> DD(0, 1000000000);

ll random(ll r){
    return DD(eng)%r;
}

string s,t;

ll F[2] = {0};
ll base,extra;

set<ll> S;

void prnt(ll i,ll j){
    for(int c1 = i; c1 < j; c1++){
        if(F[t[c1]-'0'] > 0){
            cout << t[c1];
            F[t[c1]-'0']--;
        }
        else{
            if(F[0] > 0){
                cout << 0;
                F[0]--;
            }
            else{
                if(F[1] > 0){
                    cout << 1;
                    F[1]--;
                }
                else{
                    return;
                }
            }
        }
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d,e;

    cin >> s >> t;
    for(int c1 = 0; c1 < s.length(); c1++){
        F[s[c1]-'0']++;
    }

    base = random(1000000000)*100000 + random(100000);
    extra = 1267;

    ll lp = 0;
    ll h = 0;
    for(int c1 = 0; c1 < t.length()-1; c1++){
        h *= extra;
        h += (t[c1]+1);
        h %= base;
        S.insert(h);
    }

    a = 1;
    h = 0;
    for(int c1 = t.length()-1; c1 >= 1; c1--){
        h += a*(t[c1]+1);
        h %= base;
        a *= extra;
        a %= base;
        if(S.find(h) != S.end()){
            lp = t.length()-c1;
        }
    }

    prnt(0,t.length());

    while(F[0] > 0 || F[1] > 0){
        prnt(lp,t.length());
    }

    return 0;
}