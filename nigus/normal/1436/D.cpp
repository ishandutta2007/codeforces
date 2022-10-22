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

const int MAXN = 200001;

vector<vi> C(MAXN, vi());

ll space[MAXN] = {0};
ll A[MAXN] = {0};

ll inf = big*big;

ll add(ll x, ll y){
    if(x+y >= inf)return inf;
    return x+y;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("fhc.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c;

    cin >> n;
    rep(c1,1,n){
        cin >> a;
        a--;
        C[a].push_back(c1);
    }
    ll suma = 0;
    rep(c1,0,n){
        cin >> a;
        A[c1] = a;
        suma += a;
    }
    if(suma == 0){
        cout << "0\n";
        return 0;
    }

    ll l = 0;
    ll r = big*n*2;

    while(l < r-1){
        ll mid = (l+r)/2;
        for(int c1 = n-1; c1 >= 0; c1--){
            if(sz(C[c1]) == 0){
                space[c1] = mid-A[c1];
            }
            else{
                space[c1] = 0;
                trav(y, C[c1]){
                    space[c1] = add(space[c1], space[y]);
                }
                space[c1] -= A[c1];
            }
        }
        bool bad = 0;
        trav(s, space){
            if(s<0)bad=1;
        }
        if(bad){
            l = mid;
        }
        else{
            r = mid;
        }
    }
    cout << r << "\n";

    return 0;
}