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
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<double,double> pdd;

const ll big = 1000000007;
const ll mod = 998244353;

ll n,m,k,q;

ll F[26] = {0};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
   // freopen("input.txt","r",stdin);
   // freopen("autput.txt","w",stdout);
    ll a,b,c,d;

    cin >> n >> k;
    string s;
    cin >> s;

    for(int c1 = 0; c1 <n; c1++){
        F[s[c1]-'A']++;
    }
    ll ans = big;
    for(int c1 = 0; c1 < k; c1++){
        ans = min(ans,F[c1]);
    }

    cout << ans*k << "\n";
    return 0;
}