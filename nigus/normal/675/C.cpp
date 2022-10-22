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
vl A;

int main() {
    //ios_base::sync_with_stdio(0);
   // cin.tie(0);
   // freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,e;

    cin>> n;
    map<ll,ll> M;
    a = 0;
    ll ans = n-1;
    for(int c1 = 0; c1 < n; c1++){
        cin >> b;
        a += b;
        if(M.find(a) == M.end())M[a]=0;
        M[a]++;
        ans = min(ans, n-M[a]);
    }
    cout << ans << "\n";

    return 0;
}