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

ll n,m,k,T;


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c;

    ll x,y;
    cin >> n >> x >> y;

    ll z = 0;
    ll prev = -1;
    string s;
    cin >> s;
    for(ll c1 = 0; c1 < n; c1++){
         a = s[c1]-'0';
         if(a == 0 && a != prev){
             z++;
         }
         prev = a;
    }


    if(z == 0){
        cout << "0\n";
    }
    else{

        ll ans = (z-1)*min(x,y) + y;
        cout << ans << "\n";

    }

    return 0;
}