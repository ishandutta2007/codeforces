#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;

const ll big = 1000000007;

ll n,m,k,T;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d;

    cin >> n;
    vector<ll> A;
    ll mi = big;
    for(ll c1 = 0; c1 < n; c1++){
        cin >> a;
        mi = min(a,mi);
        A.push_back(a);
    }
    ll ans = n;
    ll prev = -12344444444;
    for(ll c1 = 0; c1 < n; c1++){
        if(A[c1] == mi){
            ans = min(ans, c1-prev);
            prev = c1;
        }

    }

    cout << ans << "\n";

    return 0;
}