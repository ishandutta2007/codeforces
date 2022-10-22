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

vl A;

ll B[MAXN] = {0};
ll CS[MAXN] = {0};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("fhc.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d;
    cin >> n >> q >>k;
    rep(c1,0,n){
        cin >> a;
        A.push_back(a);
    }
    CS[0] = 0;
    rep(c1,0,n){
         if(c1 > 0 && c1 < n-1){
            B[c1] = A[c1+1]-A[c1-1]-2;
         }
         CS[c1+1] = CS[c1]+B[c1];
    }

    rep(c1,0,q){
        cin >> a >> b;
        a--;
        b--;

        if(a == b){
            cout << k-1 << "\n";
            continue;
        }

        ll ans = (A[a+1]-2) + (k-A[b-1]-1);
        if(b-a > 1)ans += CS[b]-CS[a+1];
        cout << ans << "\n";
    }
    return 0;
}