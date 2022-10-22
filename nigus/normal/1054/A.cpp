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

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;
    ll x,y,z,t1,t2,t3;
    cin >> x >>y >> z >> t1 >> t2 >> t3;
    ll stairs = abs(x-y)*t1;

    ll elev = abs(x-y)*t2 + 3*t3;
    if(z != x){
        elev += abs(x-z)*t2;
    }

    if(elev <= stairs){
        cout << "YES\n";

    }
    else{
        cout << "NO\n";

    }

    return 0;
}