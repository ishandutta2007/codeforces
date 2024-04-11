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

ll n,m,T,k;
const ll big = 1000000007;
const ll big2 = 998244353;

vl D;

ll POS[500001] = {0};
ll NEG[500001] = {0};
ll zz = 0;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,e;

    cin >> n;

    for(int c1 = 0; c1 < n; c1++){
        string s;
        cin >> s;
        a = 0;
        ll mi = 0;
        for(int c2 = 0; c2 < s.length(); c2++){
            if(s[c2] == '(')a++;
            if(s[c2] == ')')a--;
            mi = min(a,mi);
        }
        if(mi >= min(0ll,a)){
            if(a < 0)NEG[-a]++;
            if(a > 0)POS[a]++;
            if(a == 0)zz++;
        }
    }

    ll ans = zz/2;
    for(int c1 = 0; c1 < 500001; c1++){
        ans += min(NEG[c1],POS[c1]);
    }

    cout << ans << "\n";

    return 0;
}