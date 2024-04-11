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

string s1,s2;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
   // freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,e;

    ll ans = 0;
    cin >> n >> k;


    cin >> s1;
    cin >> s2;
    c = 0;
    for(int c1 = 0; c1 < n; c1++){
        c *= 2;
        c -= (s1[c1]=='b');
        c += (s2[c1]=='b');
        if(c < 0)c = 0;
        if(c > k-1)c = k-1;
        ans += c+1;
    }
    cout << ans << "\n";

    return 0;
}