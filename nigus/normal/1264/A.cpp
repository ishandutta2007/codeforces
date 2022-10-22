
#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define per(i, b, a) for(int i = b - 1; i >= a; i--)
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

unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937 eng(seed);

uniform_int_distribution<> DD(0, (1ll << 31));

ll random2(){
    return (ll(DD(eng))*(1ll << 31) + ll(DD(eng))) & ((1ll << 62ll)-1);
}

ll n,m,T,k,q;

const ll big = 1000000007;
const ll big2 = 1000000009;
const ll mod =  998244353;

const int MAXN = 200001;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d,e;
    cin >> T;

    rep(c4,0,T){
        cin >> n;
        vi A;
        rep(c1,0,n){
            cin >> a;
            A.push_back(a);
        }
        m = n;
        vi B;

        B.push_back(1);
        rep(c1,1,n){
            if(A[c1] != A[c1-1]){
                B.push_back(0);
            }
            B[sz(B)-1]++;
        }
        n = sz(B);
        ll g = B[0];
        ll i = 1;
        ll s = 0;
        while(s <= g){
            if(i >= n)break;
            s += B[i];
            i++;
        }
        ll b = 0;
        while(2*(s + b + g + B[i]) <= m){
            if(i >= n)break;
            b += B[i];
            i++;
        }
        if(b <= g || s <= g || 2*(s+b+g) > m){
            s = 0;
            g = 0;
            b = 0;
        }

        cout << g << " " << s << " " << b << "\n";

    }

    return 0;
}