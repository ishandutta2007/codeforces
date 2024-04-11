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

const int MAXN = 100001;

vl W, D, ind;

bool comp(ll i, ll j){
    return W[i] > W[j];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("fhc.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d;

    cin >> T;

    rep(c4,0,T){
        cin >> n;
        W.clear();
        D.clear();
        ind.clear();
        ll ans = 0;
        rep(c1,0,n){
            cin >> a;
            ans+=a;
            W.push_back(a);
            D.push_back(-1);
            ind.push_back(c1);
        }
        rep(c1,0,n-1){
            cin >> a >> b;
            a--;
            b--;
            D[a]++;
            D[b]++;
        }
        int ma = 0;
        sort(all(ind), comp);
        rep(c1,0,n-1){
            cout << ans << " ";
            while(D[ind[ma]] == 0){
                ma++;
                if(ma == n)break;
            }
            if(ma < n){
                D[ind[ma]]--;
                ans += W[ind[ma]];
            }
        }cout << "\n";
    }

    return 0;
}