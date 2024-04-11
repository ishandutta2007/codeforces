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

vl A;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
   // freopen("input.txt","r",stdin);
   // freopen("autput.txt","w",stdout);
    ll a,b,c,d;

    cin >> n;

    ll mi = big*big;
    ll ma = -big*big;
    ll absum = 0;
    for(int c1 = 0; c1 < n; c1++){
        cin >> a;
        absum += abs(a);
        mi = min(mi,a);
        ma = max(ma,a);
    }
    if(n == 1){
        cout << mi << "\n";
        return 0;
    }
    if(ma < 0){
        cout << absum +2*ma << "\n";
        return 0;
    }
    if(mi > 0){
        cout << absum - 2*mi << "\n";
        return 0;
    }
    cout << absum << "\n";
    return 0;
}