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


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
   // freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,e;

    cin >> b >> n;
    ll par = 0;
    for(int c1 = 0; c1 < n; c1++){
        cin >> a;
        if(c1 < n-1){
            par += (a*b);

        }
        else{
            par += a;
        }
        par %= 2;
    }
    if(par == 0){
        cout << "even\n";
    }
    else{
        cout << "odd\n";
    }

    return 0;
}