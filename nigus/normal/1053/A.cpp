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
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<double,double> pdd;

const ll big = 1000000007;
const ll mod = 998244353;

ll n,m,k,q,T;

ll gcd(ll i, ll j){
    if(j == 0)return i;
    return gcd(j,i%j);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
   // freopen("input.txt","r",stdin);
   // freopen("autput.txt","w",stdout);
    ll a,b,c,d;

    cin >> n >> m >> k;

    ll N,M;
    N = n;
    M = M;

    ll g = gcd(n,k);
    n /= g;
    k /= g;

    g = gcd(m,k);
    m /= g;
    k /= g;

    if(k == 1){
        if(n < N){
            n *= 2;
        }
        else{
            m *= 2;
        }
        k *= 2;
    }

    if(k != 2){
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    cout << "0 0\n";
    cout << n << " 0\n";
    cout << "0 " << m << "\n";

    return 0;
}