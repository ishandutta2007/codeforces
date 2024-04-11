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
ll n,k,m,d;

int main() {

    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,e;
    cin >> n;
    vl A;
    b = 0;
    for(int c1 = 0; c1 < n; c1++){
        cin >> a;
        b+=a;
        A.push_back(a);
    }
    c = 0;
    for(int c1 = 0; c1 < n; c1++){
        c += A[c1];
        if(2*c >= b){
            cout << c1+1 << "\n";
            break;
        }
    }

    return 0;
}