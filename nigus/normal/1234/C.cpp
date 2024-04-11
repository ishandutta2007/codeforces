#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef long double ld;

unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937 eng(seed);
uniform_int_distribution<> DD(0, 1000000000);

ll random(ll r){
    return (1000000000 * ll(DD(eng)) + DD(eng))%r;
}

ll n,m,T,k,q;
const ll big = 1000000007;
const ll MAXN = 300001;

int main() {
   // ios_base::sync_with_stdio(0);
    //cin.tie(0);

    ll a,b,c;

    cin >> q;
    rep(c1,0,q){
        string s1, s2;
        cin >> n;
        cin >> s1 >> s2;
        vector<string> s;
        s.push_back(s1);
        s.push_back(s2);
        ll y = 0;
        n = s1.length();
        bool fail = 0;
        rep(c2,0,n){
            if((s[y][c2]-'0') > 2 && (s[y^1][c2]-'0') > 2){
                y ^= 1;
            }
            else{
                if((s[y][c2]-'0') > 2){
                    fail = 1;
                    break;
                }
            }
        }
        if(y != 1)fail = 1;
        if(fail){
            cout << "NO\n";
        }
        else{
            cout << "YES\n";
        }
    }


    return 0;
}