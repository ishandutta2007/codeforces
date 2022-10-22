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

const ll MAXN = 500001;

vl kind,A,B;

ll MAXX[MAXN] = {0};
ll ANS[MAXN] = {0};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
   // freopen("autput.txt","w",stdout);
    ll a,b,c,d;
    cin >> n;
    rep(c1,0,n){
        cin >> a;
        kind.push_back(0);
        A.push_back(a);
        B.push_back(c1);
        ANS[c1] = -1;
    }
    cin >> q;
    rep(c1,0,q){
        cin >> a;
        if(a == 1){
            kind.push_back(0);
            cin >> b >> c;
            A.push_back(c);
            B.push_back(b-1);
        }
        else{
            kind.push_back(1);
            cin >> b;
            A.push_back(b);
            B.push_back(-1);
        }
    }
    ll ma = -1;
    per(c1,sz(kind),0){
        if(kind[c1] == 1){
            ma = max(ma, A[c1]);
        }
        else{
            if(ANS[B[c1]] == -1){
                ANS[B[c1]] = max(A[c1],ma);
            }
        }
    }
    rep(c1,0,n){
        cout << ANS[c1] << " ";
    }cout << "\n";

    return 0;
}