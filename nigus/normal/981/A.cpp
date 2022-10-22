#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;

const ll big = 1000000007;
const ll mod = 998244353;

ll n,m,q,p;
ll T;

string s;
bool pal(ll l , ll r){
    for(int c1 = l; c1 <= r; c1++){
        if(s[c1] != s[r-c1])return 0;
    }
    return 1;
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,e;


    cin >> s;
    ll ans = 0;
    n = s.length();
    for(int c1 = 0; c1 < n; c1++){
        for(int c2 = c1; c2 < n; c2++){
            if(!pal(c1,c2)){
                ans = max(ans, ll(c2-c1)+1ll);
            }
        }
    }
    cout << ans << "\n";

    return 0;
}