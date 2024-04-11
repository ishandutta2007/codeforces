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
        A.clear();
        ind.clear();
        ll sum = 0;
        vector<bool> win(n, 0);
        rep(c1,0,n){
            cin >> a;
            sum += a;
            A.push_back(a);
            ind.push_back(c1);
        }
        sort(all(ind), comp);
        for(int c1 = n-1; c1 >= 0; c1--){
            int i = ind[c1];
            if(c1 == n-1){
                win[i] = 1;
            }
            else{
                if(sum >= A[ind[c1+1]] && win[ind[c1+1]])win[i] = 1;
            }
            sum -= A[i];
        }
        vi winners;
        rep(c1,0,n){
            if(win[c1])winners.push_back(c1);
        }
        cout << sz(winners) << "\n";
        trav(y, winners){
            cout << y+1 << " ";
        }cout << "\n";
    }

    return 0;
}