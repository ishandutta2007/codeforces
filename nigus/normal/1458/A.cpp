#pragma GCC optimize("O3")   //
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

const int MAXN = 300001;

vl A,B;

ll gcd(ll i, ll j){
    if(j == 0)return i;
    return gcd(j,i%j);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("fhc.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d;

    cin >> n >> m;
    rep(c1,0,n){
        cin >> a;
        A.push_back(a);
    }
    sort(all(A));
    ll g = 0;
    rep(c1,0,n){
        g = gcd(g, A[c1]-A[0]);
    }
    rep(c1,0,m){
        cin >> b;
        B.push_back(b);
    }
    rep(c1,0,m){
        cout << gcd(g, B[c1]+A[0]) << " ";
    }cout << "\n";

    return 0;
}