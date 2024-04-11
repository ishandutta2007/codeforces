#pragma GCC optimize("O3")   //
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
typedef unsigned long long ull;
 
unsigned seed = chrono::system_clock::now().time_since_epoch().count();
mt19937 eng(seed);
ll random2(){
    return (1ll << 31ll)*eng()+eng();
}
 
const ll big = 1000000007;
const ll big2 = 1000000009;
const ll mod =  998244353;
const int MAXN = 200001;

ll n;
const int LOW = (1 << 15);
vi A;
vector<vi> X(101, vi());
vector<vi> Y(101, vi());
vl YH(LOW,0);
map<ll,ll> M;
const ll base = 12783;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    rep(c1,0,n){
        int a;
        cin >> a;
        A.push_back(a);
        rep(c2,0,LOW){
            int a_lo = (a&(LOW-1));
            int a_hi = (a-a_lo)/LOW;
            X[c1].push_back(__builtin_popcount(a_lo^c2));
            Y[c1].push_back(__builtin_popcount(a_hi^c2));
            YH[c2] *= base;
            YH[c2] += Y[c1].back();
        }
    }
    rep(c1,0,LOW){
        M[YH[c1]] = c1;
    }

    rep(x,0,LOW){
        rep(want,0,31){
            ll h = 0;
            bool fail = 0;
            rep(c1,0,n){
                h *= base;
                h += want-X[c1][x];
            }
            if(M.find(h) != M.end()){
                cout << M[h]*LOW+x << "\n";
                return 0;
            }
        }
    }
    cout << "-1\n";
 
    return 0;
}