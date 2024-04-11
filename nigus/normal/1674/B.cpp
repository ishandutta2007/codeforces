#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define per(i, b, a) for(int i = b - 1; i >= a; i--)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef long double ld;
typedef unsigned long long ull;

unsigned seed = chrono::system_clock::now().time_since_epoch().count();
mt19937 eng(seed);

ll random2(){
    return (1ll << 31ll)*eng()+eng();
}

ll n,m,k,q,T;

const ll big = 1000000007;
const ll big2 = 1000000009;
const ll mod =  998244353;

const int MAXN = 200006;



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

   // freopen("fhc.txt","r",stdin);
   // freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;

    vector<pii> A;

    rep(c1,0,26){
        rep(c2,0,26){
            if(c1 != c2){
            A.push_back({c1,c2});
            }
        }
    }
    cin >> n;
    rep(c1,0,n){
        string s;
        cin >> s;
        a = s[0]-'a';
        b = s[1]-'a';
        rep(c2,0,sz(A)){
            if(A[c2].first == a && A[c2].second == b){
                cout << c2+1 << "\n";
            }
        }
    }

    return 0;
}