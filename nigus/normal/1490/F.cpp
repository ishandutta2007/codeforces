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

vl A, ind;

bool comp(ll i, ll j){
    return A[i] < A[j];
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
        map<int,int> M;
        vi nums;
        rep(c1,0,n){
            cin >> a;
            if(M.find(a) == M.end()){
                M[a] = 0;
                nums.push_back(a);
            }
            M[a]++;
        }
        ll ans = n;
        vi F;
        trav(y, nums){
            F.push_back(M[y]);
        }
        sort(all(F));
        ll sum = n;
        ll extra = 0;
        ll dist = sz(F);
        trav(f, F){
            ll temp = extra + sum - dist*f;
            ans = min(ans, temp);
            extra += f;
            sum -= f;
            dist--;
        }
        cout << ans << "\n";
    }

    return 0;
}