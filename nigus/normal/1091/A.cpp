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

ll n,m,T,k,d;
const ll big = 1000000007;
const ll big2 = 998244353;

bool mark[2340] = {0};

int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
   // freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,e;
    cin >> a >> b >> c;

    b--;
    c-=2;

    ll neck = min(a,min(b,c));

    ll ans = 3*neck+3;

    if(neck <= 0){
        ans = 0;
    }

    cout << ans << "\n";

    return 0;
}