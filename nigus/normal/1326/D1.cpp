#pragma GCC optimize("O3")   //
#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define per(i, b, a) for(int i = b - 1; i >= a; i--)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef long double ld;

unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937 eng(seed);

uniform_int_distribution<> DD(0, (1ll << 31));

ll random2(){
    return (ll(DD(eng))*(1ll << 31) + ll(DD(eng))) & ((1ll << 62ll)-1);
}

ll n,m,k,q,T;

const ll big = 1000000007;
const ll big2 = 1000000009;
const ll mod =  998244353;

const int MAXN = 200001;
string s;

bool is_pal(ll i, ll j){
    for(int c1 = 0; c1 < j-i+1; c1++){
        if(s[c1+i] != s[j-c1])return 0;
    }
    return 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d,e;

    cin >> T;
    rep(_,0,T){
        cin >> s;
        n = s.length();
        string extra = "";
        ll l = 0;
        ll r = n-1;
        if(is_pal(0,n-1)){
            cout << s << "\n";
            continue;
        }
        while(s[l] == s[r]){
            extra += s[l];
            l++;
            r--;
        }

        ll ma = 0;
        ll L = -1;
        ll R = -1;

        rep(c1,l,r){
            if(c1-l+1 > ma && is_pal(l, c1)){
                ma = c1-l+1;
                L = l;
                R = c1;
            }
        }

        rep(c1,l,r){
            if(r-c1+1 > ma && is_pal(c1, r)){
                ma = r-c1+1;
                L = c1;
                R = r;
            }
        }

        string ans = extra;
     //   cerr << "   reyw\n";
        if(L != -1){
            for(int c1 = L; c1 <= R; c1++){
                ans += s[c1];
            }
        }
       // cerr << ans << "  312\n";
        for(int c1 = 0; c1 < sz(extra); c1++){
            ans += extra[sz(extra)-c1-1];
        }
        cout << ans << "\n";

    }

    return 0;
}